<?php

/**
 * Intended to be triggered at the end of a Would You Rather question set. Determines
 * the reply message to the user based on their answer. Also, sends a message
 * to the Alpha inviter (if any) for this user with the user's answers.
 */
class ConductorActivityWYRQsetEnd extends ConductorActivity {

  /**
   * Unique game ID for the WYR game.
   *
   * @var int
   * @see sms_flow_game_constants.inc
   */
  public $gameId;

  /**
   * The set of valid answers for the last question of each set. Also defines
   * what the response should be given the user's answer.
   *
   * @var array
   */
  private $validAnswers = array(
    '164009' => array(
      'opt1_valid_answers' => array('walk a mile barefoot', 'a', 'a.', 'a)'),
      'opt2_valid_answers' => array('get kissed by mom', 'b', 'b.', 'b)'),
      'opt1_response' => 164017,
      'opt2_response' => 164019,
    ),
    '164011' => array(
      'opt1_valid_answers' => array('date at McDs', 'a', 'a.', 'a)'),
      'opt2_valid_answers' => array('pick up date on a scooter', 'b', 'b.', 'b)'),
      'opt1_response' => 164021,
      'opt2_response' => 164023,
    ),
    '164013' => array(
      'opt1_valid_answers' => array('wear the same clothes for a yr', 'a', 'a.', 'a)'),
      'opt2_valid_answers' => array('chew gum for a month', 'b', 'b.', 'b)'),
      'opt1_response' => 164025,
      'opt2_response' => 164027,
    ),
  );

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $incomingOptInPath = check_plain($_REQUEST['opt_in_path_id']);

    // Get the first 3 WYR answers saved on Mobile Commons
    $q1Answer = self::getMobileCommonsProfileValue($mobile, 'profile_wyr_q1_answer');
    $q2Answer = self::getMobileCommonsProfileValue($mobile, 'profile_wyr_q2_answer');
    $q3Answer = self::getMobileCommonsProfileValue($mobile, 'profile_wyr_q3_answer');

    // Since question 4 isn't setup as a multiple choice on the Mobile Commons end,
    // the answer we get won't be normalized. Normalization will have to happen here.
    $userAnswerId = 0;
    $q4Answer = check_plain($_REQUEST['args']);
    $q4Answer = self::normalizeAnswer($incomingOptInPath, $q4Answer, $userAnswerId);

    // Get any previous answers for this user from the DB
    $answers = sms_flow_game_get_answers($mobile, $this->gameId);

    if (empty($answers)) {
      $answers = array();
    }

    // Build array of the new answers to save to the DB
    if (!empty($q1Answer) && !empty($q2Answer) && !empty($q3Answer) && !empty($q4Answer)) {
      // Save new answers to the DB
      $answers[$incomingOptInPath] = array();
      $answers[$incomingOptInPath][] = $q1Answer;
      $answers[$incomingOptInPath][] = $q2Answer;
      $answers[$incomingOptInPath][] = $q3Answer;
      $answers[$incomingOptInPath][] = $q4Answer;
    }

    if ($incomingOptInPath > 0 && count($answers[$incomingOptInPath]) > 0) {
      // Save the new answers to the DB
      try {
        sms_flow_game_set_answers($mobile, $this->gameId, $answers);
      }
      catch (Exception $e) {
        // In case of DB error (ex: data string of answers is too long)
        watchdog('sms_flow_game', 'ConductorActivityWYRQsetEnd exception ' . $e->getMessage() . ', game id: ' . $this->gameId . ', mobile: ' . $mobile);
      }

      // Find the alpha inviter, if any
      $alphaMobile = sms_flow_find_alpha(substr($mobile, -10), $this->gameId, 'sms_game');
      if ($alphaMobile) {
        // Build and send message to the alpha
        $alphaMsg = "Your friend ($mobile) said they'd rather $q1Answer, $q2Answer, $q3Answer, and $q4Answer. Want to play more? Text WYR.";
        sms_mobile_commons_send($alphaMobile, $alphaMsg);
      }
    }

    // Send response back to the user based on their answer
    if ($userAnswerId == 1 && isset($this->validAnswers[$incomingOptInPath]['opt1_response'])) {
      sms_mobile_commons_opt_in($mobile, $this->validAnswers[$incomingOptInPath]['opt1_response']);
    }
    elseif ($userAnswerId == 2 && isset($this->validAnswers[$incomingOptInPath]['opt2_response'])) {
      sms_mobile_commons_opt_in($mobile, $this->validAnswers[$incomingOptInPath]['opt2_response']);
    }
    elseif (isset($this->validAnswers[$incomingOptInPath]['invalid_response'])) {
      sms_mobile_commons_opt_in($mobile, $this->validAnswers[$incomingOptInPath]['invalid_response']);
    }

    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers() {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }

  /**
   * Translates the user answer to a string that can be sent to the Alpha inviter
   * and saved to the database.
   *
   * @param int $optInPath
   *   The opt-in path the answer is coming from.
   * @param string $answer
   *   The user-provided answer.
   * @param int &$userAnswerId
   *   ID indicating what answer the user gave. 1 = option A, 2 = option B, 0 = invalid answer.
   */
  private function normalizeAnswer($optInPath, $answer, &$userAnswerId) {
    $answer = strtolower($answer);

    if (in_array($answer, $this->validAnswers[$optInPath]['opt1_valid_answers'])) {
      $userAnswerId = 1;
      return $this->validAnswers[$optInPath]['opt1_valid_answers'][0];
    }
    elseif (in_array($answer, $this->validAnswers[$optInPath]['opt2_valid_answers'])) {
      $userAnswerId = 2;
      return $this->validAnswers[$optInPath]['opt2_valid_answers'][0];
    }
    else {
      $userAnswerId = 0;
      return NULL;
    }
  }

  /**
   * Gets value from Mobile Commons profile field. Checks the $_REQUEST
   * parameters first. If not there, then goes straight to the profile.
   */
  private function getMobileCommonsProfileValue($mobile, $field_name) {
    // Pull the value from $_REQUEST parameters if they're there
    if (!empty($_REQUEST[$field_name])) {
      return check_plain($_REQUEST[$field_name]);
    }
    // Otherwise go to Mobile Commons for the value
    else {
      $xml = sms_mobile_commons_profile_summary($mobile);

      // Strip off 'profile_' from the beginning of the string
      $field_name = str_replace('profile_', '', $field_name);
      return self::getFieldValueFromXml($xml, $field_name);
    }
  }

  /**
   * Use regex to parse xml and pull field value out
   */
  private function getFieldValueFromXml($xml, $field_name) {
    $pattern = '#\<custom_column name\="' . $field_name . '"\>(.*?)\<\/custom_column\>#is';
    preg_match($pattern, $xml, $patternMatches);
    if (count($patternMatches) >= 2) {
      return trim($patternMatches[1]);
    }

    return NULL;
  }
}
