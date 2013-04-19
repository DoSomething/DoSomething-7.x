<?php

/**
 * Parses user message and sends back a response if match is found. If no match
 * is found, should just remain silent unless a $no_match_response is specified.
 */
class ConductorActivityOutOfFlowResponder extends ConductorActivity {

  // Nested array of responses and their matching criteria.
  // Expected structure:
  //  array(
  //    array(
  //      'phrase_match' => array('phrase 1', 'phrase 2'),
  //      'AND_match'    => array(
  //        array('word1A', 'word1B'),
  //        array('word2A', 'word2B', 'phrase 2 C'),
  //        ...
  //      ),
  //      'word_match'   => array('word1', 'word2', ...),
  //      'response'     => string. Message to send back to user if match is found.
  //      'response_negative' => string. Message to send back to user if match is found and user message is a negative form.
  //                             ex: User responds with, "I do NOT love you"
  //      'trigger_opt_out'   => mixed. Could be either a single number or array of numbers for campaign ids to opt out of.
  //    )
  //  )
  // 
  // Sets at the beginning of the array will match against the user response 
  // first and take priority over later sets.
  public $response_sets = array();

  // Response to send to the user if no match is found
  public $no_match_response = '';

  // Maximum allowed string edit distance to trigger a successful match
  public $match_threshold = 1;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $userMessage = $_REQUEST['args'];

    // Single quote to be removed instead of replacing with whitespace to conserve integrity of word
    $userMessage = preg_replace('/\'/', '', $userMessage);
    // Remove all non alphanumeric characters from the user message
    $userMessage = preg_replace('/[^A-Za-z0-9 ]/', ' ', $userMessage);
    // Matches multi-character whitespace with a single space
    $userMessage = preg_replace('/\s+/', ' ', $userMessage);
    $userMessage = check_plain($userMessage);

    // Break message into array of individual words
    $userWords = explode(' ', $userMessage);

    $bMatchFound = FALSE;
    $bIgnoreNegativeForm = FALSE;
    $isNegativeForm = FALSE;
    $matchingSet = -1;

    do {
      for ($i = 0; $i < count($this->response_sets) && !$bMatchFound; $i++) {
        $set = $this->response_sets[$i];

        // Search for exactly matched responses
        foreach ($set['exact_match'] as $exactMatch) {
          if ((!$bDoDistanceCheck && strcasecmp($userMessage, $exactMatch) == 0)
              || ($bDoDistanceCheck && self::stringEditDistance($exactMatch, $userMessage) <= $this->match_threshold)) {
            $bMatchFound = TRUE;

            if (self::hasNegativeFormWord($$exactMatch)) {
              $bIgnoreNegativeForm = TRUE;
            }

            break;
          }
        }

        // Search for phrases within the user message
        if (!$bMatchFound && !$bDoDistanceCheck) {
          foreach ($set['phrase_match'] as $matchPhrase) {
            if (stripos($userMessage, $matchPhrase) !== FALSE) {
              $bMatchFound = TRUE;

              if (self::hasNegativeFormWord($matchPhrase)) {
                $bIgnoreNegativeForm = TRUE;
              }

              break;
            }
          }
        }

        // Search for sets of words in the user message to match against
        if (!$bMatchFound && !$bDoDistanceCheck) {
          foreach ($set['AND_match'] as $matchSet) {
            $bSetMatches = TRUE;
            foreach ($matchSet as $matchWord) {
              if (!self::in_arrayi($matchWord, $userWords)) {
                $bSetMatches = FALSE;
                break;
              }
            }

            if ($bSetMatches) {
              $bMatchFound = TRUE;
              break;
            }
          }
        }

        // Search for exactly matched words
        if (!$bMatchFound) {
          foreach ($set['word_match'] as $matchWord) {
            foreach ($userWords as $userWord) {
              if ((!$bDoDistanceCheck && strcasecmp($matchWord, $userWord) == 0)
                  || ($bDoDistanceCheck && self::stringEditDistance($matchWord, $userWord) <= $this->match_threshold)) {
                $bMatchFound = TRUE;
                break;
              }
            }

            if ($bMatchFound) {
              break;
            }
          }
        }

        // Check if user response is in negative form
        // ie - "I do love you" vs "I do not love you"
        if ($bMatchFound && !$bIgnoreNegativeForm) {
          if (self::hasNegativeFormWord($userWords)) {
            // Negative form response found. Make sure we have a response for that kind of message.
            if (isset($set['response_negative'])) {
              $isNegativeForm = TRUE;
            }
            else {
              $bMatchFound = FALSE;
            }
          }
        }

        // Match is found. No need to check the rest.
        if ($bMatchFound) {
            $matchingSet = $i;
            break;
        }
      }

      // If we've already done a runthrough with the distance check, then ensure we exit out of the while loop
      if ($bDoDistanceCheck) {
        $bExecutedDistanceCheck = TRUE;
      }
      else {
        $bDoDistanceCheck = TRUE;
      }
    } while (!$bMatchFound && !$bExecutedDistanceCheck);

    // Reply back to the user with the appropriate response if available
    if ($bMatchFound && $matchingSet >= 0) {
      $set = $this->response_sets[$matchingSet];

      if ($set['trigger_opt_out'] > 0) {
        sms_mobile_commons_campaign_opt_out($mobile, $set['trigger_opt_out']);
        $response = self::selectResponse($set['response']);
      }
      elseif ($isNegativeForm) {
        $response = self::selectResponse($set['response_negative']);
      }
      else {
        $response = self::selectResponse($set['response']);
      }

      $state->setContext('sms_response', $response);
    }
    elseif (!empty($this->no_match_response)) {
      $state->setContext('sms_response', $this->no_match_response);
    }
    else {
      $state->setContext('ignore_no_response_error', TRUE);
    }

    $state->markCompleted();
  }

  // Case-insensitive version of in_array()
  function in_arrayi($needle, $haystack) {
    foreach ($haystack as $value) {
      if (strtolower($value) == strtolower($needle)) {
        return TRUE;
      }
    }

    return FALSE;
  }

  // Determine if negative-form word exists in $needles
  function hasNegativeFormWord($needles) {
    $negativeFormWords = array('no', 'not');

    // If $needles is a string, convert it into an array of its words
    if (is_string($needles)) {
      $needles = explode(' ', $needles);
    }

    foreach ($negativeFormWords as $matchWord) {
      if (self::in_arrayi($matchWord, $needles)) {
        return TRUE;
      }
    }

    return FALSE;
  }

  // Selects a random response if multiple are given, or if $response is a string, just returns it back
  function selectResponse($response) {
    if (is_array($response)) {
      $selectedIdx = array_rand($response);
      return $response[$selectedIdx];
    }
    else {
      return $response;
    }
  }

  // Distance formula to determine a measure of difference between two strings
  // - Based off the Damerau-Levenshtein distance algorithm
  // - http://en.wikipedia.org/wiki/Damerau%E2%80%93Levenshtein_distance
  function stringEditDistance($source, $target) {
    $sourceLen = strlen($source);
    $targetLen = strlen($target);

    if (empty($source)) {
      if (empty($target)) {
        return 0;
      }
      else {
        return $targetLen;
      }
    }
    elseif (empty($target)) {
      return $sourceLen;
    }

    // If target word is under a certain length, then just do a direct compare
    if ($targetLen <= 4 || $sourceLen <= 4) {
      if (strcasecmp($source, $target) == 0)
        return 0;
      else
        return 999;
    }

    // If string lengths are larger than the threshold, then just early fail out
    // String length diffs larger than the threshold will have a minimum score of that diff
    if (abs($targetLen - $sourceLen) > $this->match_threshold) {
      return 999;
    }

    // Convert strings to same case
    $source = strtolower($source);
    $target = strtolower($target);

    // Setup $score double array
    $score = array();
    for ($i = 0; $i < $sourceLen + 2; $i++) {
      $score[$i] = array();
    }

    $inf = $sourceLen + $targetLen;
    $score[0][0] = $inf;

    for ($i = 0; $i < $sourceLen; $i++) {
      $score[$i + 1][0] = $inf;
      $score[$i + 1][1] = $i;
    }
    for ($j = 0; $j < $targetLen; $j++) {
      $score[0][$j + 1] = $inf;
      $score[1][$j + 1] = $j;
    }

    $dictionary = array();
    $combined = $source . $target;
    for ($i = 0; $i < strlen($combined); $i++) {
      // Ignore spaces
      if ($combined[$i] != ' ') {
        $letter = $combined[$i];
        if (!array_key_exists($letter, $dictionary)) {
          $dictionary[$letter] = 0;
        }
      }
    }

    for ($i = 1; $i <= $sourceLen; $i++) {
      $db = 0;
      for ($j = 1; $j <= $targetLen; $j++) {
        $i1 = $dictionary[$target[j - 1]];
        $j1 = $db;

        if ($source[$i - 1] == $target[$j - 1]) {
          $score[$i + 1][$j + 1] = $score[$i][$j];
          $db = $j;
        }
        else {
          $score[$i + 1][$j + 1] = min($score[$i][$j], min($score[$i + 1][$j], $score[$i][$j + 1])) + 1;
        }

        $score[$i + 1][$j + 1] = min($score[$i + 1][$j + 1], $score[$i1][$j1] + ($i - $i1 - 1) + 1 + ($j - $j1 - 1));
      }

      $dictionary[$source[$i - 1]] = $i;
    }

    $i = $sourceLen + 1;
    $j = $targetLen + 1;
    return $score[$i][$j];
  }
}