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
  //      'AND_match'   => array(
  //        array('word1A', 'word1B'),
  //        array('word2A', 'word2B', 'phrase 2 C'),
  //        ...
  //      ),
  //      'word_match' => array('word1', 'word2', ...),
  //      'negation'    => boolean. If TRUE, matches succeed only if the user message is a negation.
  //                       ex: "I do NOT love you"
  //      'response'    => string. Message to send back to user if match is found.
  //    )
  //  )
  // 
  // Sets at the beginning of the array will match against the user response 
  // first and take priority over later sets.
  public $response_sets = array();

  public $no_match_response = '';

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $userMessage = check_plain($_REQUEST['args']);

    // Remove all non alphanumeric characters from the user message
    $userMessage = preg_replace('/[^A-Za-z0-9 ]/', ' ', $userMessage);
    // Matches multi-character whitespace with a single space
    $userMessage = preg_replace('/\s+/', ' ', $userMessage);

    // Break message into array of individual words
    $userWords = explode(' ', $userMessage);

    $bMatchFound = FALSE;
    $matchingSet = -1;
    for ($i = 0; $i < count($this->response_sets) && !$bMatchFound; $i++) {
      $set = $this->response_sets[$i];

      // Search for exactly matched phrases
      foreach ($set['phrase_match'] as $matchPhrase) {
        if (stripos($userMessage, $matchPhrase) >= 0) {
          $bMatchFound = TRUE;
          break;
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

      if ($bMatchFound && $set['negation']) {
        $isNegation = FALSE;
        $negationWords = array('no', 'not', 'n\'t');
        foreach ($negationWords as $matchWord) {
          if (self::in_arrayi($matchWord, $userWords)) {
            $isNegation = TRUE;
            break;
          }
        }

        if (!$isNegation) {
          $bMatchFound = FALSE;
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
      $response = $this->response_sets[$matchingSet]['response'];
      if (is_array($response)) {
        // Select a random response
        $selectedIdx = rand(0, count($response) - 1);
        $selectedResponse = $response[$selectedIdx];
        $state->setContext('sms_response', $selectedResponse);
      }
      else {
        $state->setContext('sms_response', $response);
      }
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

}