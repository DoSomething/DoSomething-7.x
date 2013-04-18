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
  //    )
  //  )
  // 
  // Sets at the beginning of the array will match against the user response 
  // first and take priority over later sets.
  public $response_sets = array();

  // Response to send to the user if no match is found
  public $no_match_response = '';

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
    for ($i = 0; $i < count($this->response_sets) && !$bMatchFound; $i++) {
      $set = $this->response_sets[$i];

      // Search for exactly matched responses
      foreach ($set['exact_match'] as $exactMatch) {
        if (strcasecmp($userMessage, $exactMatch) == 0) {
          $bMatchFound = TRUE;
          $bIgnoreNegativeForm = TRUE;
          break;
        }
      }

      // Search for phrases within the user message
      if (!$bMatchFound) {
        foreach ($set['phrase_match'] as $matchPhrase) {
          if (stripos($userMessage, $matchPhrase) !== FALSE) {
            $bMatchFound = TRUE;
            break;
          }
        }
      }

      // Search for sets of words in the user message to match against
      if (!$bMatchFound) {
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
          if (self::in_arrayi($matchWord, $userWords)) {
            $bMatchFound = TRUE;
            break;
          }
        }
      }

      // Check if user response is in negative form
      // ie - "I do love you" vs "I do not love you"
      if ($bMatchFound && !$bIgnoreNegativeForm) {
        $negativeFormWords = array('no', 'not', 'n\'t');
        foreach ($negativeFormWords as $matchWord) {
          if (self::in_arrayi($matchWord, $userWords)) {
            // Negative form response found. Make sure we have a response for that kind of message.
            if (isset($set['response_negative'])) {
              $isNegativeForm = TRUE;
            }
            else {
              $bMatchFound = FALSE;
            }
            break;
          }
        }
      }

      // Match is found. No need to check the rest.
      if ($bMatchFound) {
          $matchingSet = $i;
          break;
      }
    }

    // Reply back to the user with the appropriate response if available
    if ($bMatchFound && $matchingSet >= 0) {
      $set = $this->response_sets[$matchingSet];

      if ($isNegativeForm) {
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

  // Selects a random response if multiple are given, or if $response is a string, just returns it back
  function selectResponse($response) {
    if (is_array($response)) {
      $selectedIdx = rand(0, count($response) - 1);
      return $response[$selectedIdx];
    }
    else {
      return $response;
    }
  }
}