<?php

/**
 * Process the user's answer to the last question. 
 */
class ConductorActivityWYRProcessQSetAnswers extends ConductorActivity {

  // Unique identifier for the SMS game
  public $game_id;

  // Type of entry to submit to the sms_flow_records table
  public $type_override;

  // Opt-in path that has triggered this workflow. And in turn should also
  // be forwarded along to any invited friends.
  public $incoming_opt_in_path;

  // Array of valid answers for option 1
  public $opt1_valid_answers = array();

  // Array of valid answers for option 2
  public $opt2_valid_answers = array();

  // Response sent back to user
  public $sms_response;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $ftaf_number = $state->getContext($this->name . ':message');
    if ($ftaf_number === FALSE) {
      // Normalize answer
      $q3_answer = self::normalizeAnswer($_REQUEST['profile_wyr_q3_answer']);

      // Update Mobile Commons with normalized answer
      self::updateMobileCommonsProfile($mobile, 'wyr_q3_answer', $q3_answer);

      // Get any previous answers for this user from the DB
      $answers = sms_flow_game_get_answers($mobile, $this->game_id);

      if (empty($answers)) {
        $answers = array();
      }
      
      // TODO: is this ok? or should we be getting the answers from mCommons thru their API 
      $q1_answer = $_REQUEST['profile_wyr_q1_answer'];
      $q2_answer = $_REQUEST['profile_wyr_q2_answer'];

      // Save new answers to the DB
      $answers[$this->incoming_opt_in_path] = array();
      $answers[$this->incoming_opt_in_path][] = $q1_answer;
      $answers[$this->incoming_opt_in_path][] = $q2_answer;
      $answers[$this->incoming_opt_in_path][] = $q3_answer;

      sms_flow_game_set_answers($mobile, $this->game_id, $answers);

      // Find Alpha inviter, if any, and send Alpha the feedback message
      $alpha_mobile = sms_flow_find_alpha(substr($mobile, -10), $this->game_id, $this->type_override);
      if ($alpha_mobile) {
        $alpha_msg = "Your friend ($mobile) said they'd rather {{ wyr_q1_answer }}, {{ wyr_q2_answer }}, and {{ wyr_q3_answer }}. Want to play more. Text WYR.";
        sms_mobile_commons_send($alpha_mobile, $alpha_msg);
      }

      // Send response back to the user
      $state->setContext('sms_response', $this->sms_response);
      $state->markSuspended();
    }
    else {
      $state->setContext('ftaf_prompt:message', $ftaf_number);
      $state->setContext('ftaf_beta_optin', $this->incoming_opt_in_path);
      $state->setContext('ftaf_id_override', $this->game_id);
      $state->setContext('ftaf_type_override', $this->type_override);
      $state->setContext('ftaf_sms_flow_args', $test);

      $state->markCompleted();
    }
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
   * Search through possible answers, and if one matches, return the value at
   * the first index of the array to be the answer.
   */
  private function normalizeAnswer($answer) {
    $answer = strtolower($answer);
    if (in_array($answer, $this->opt1_valid_answers)) {
      return $this->opt1_valid_answers[0];
    }
    elseif (in_array($answer, $this->opt2_valid_answers)) {
      return $this->opt2_valid_answers[0];
    }
    else {
      return NULL;
    }
  }

  /**
   * Updates Mobile Commons profile
   */
  private function updateMobileCommonsProfile($mobile, $update_field, $update_value) {
    $url = "https://secure.mcommons.com/api/profile_update";

    $fields = array(
      'phone_number' => urlencode($mobile),
      $update_field => urlencode($update_value),
    );

    $fields_query = http_build_query($fields);

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_POST, count($fields));
    curl_setopt($ch, CURLOPT_POSTFIELDS, $fields_query);
    curl_exec($ch);
    curl_close($ch);
  }
}