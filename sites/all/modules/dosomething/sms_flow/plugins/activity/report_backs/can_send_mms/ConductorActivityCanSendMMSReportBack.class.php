<?php

/**
 * Handles response to whether or not user can send MMS. Depending on whether or not
 * they're able to, send user to an opt-in path that'll have the appropriate messaging.
 */
class ConductorActivityCanSendMMSReportBack extends ConductorActivity {

  // Map of incoming opt-in paths and their output paths
  public $routes;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $user_response = check_plain($_REQUEST['args']);
    $opt_in_path = intval($_REQUEST['opt_in_path_id']);

    if (array_key_exists($opt_in_path, $this->routes)) {
      $user_words = explode(' ', $user_response);
      $user_first_word = strtolower(array_shift($user_words));
      $yes_answers = array('y', 'yes', 'ya', 'yea');
      if (in_array($user_first_word, $yes_answers) && $this->routes[$opt_in_path]['yes'] > 0) {
       dosomething_general_mobile_commons_subscribe($mobile, $this->routes[$opt_in_path]['yes']);
        $state->setContext('ignore_no_response_error', TRUE);
      }
      elseif ($this->routes[$opt_in_path]['no'] > 0) {
       dosomething_general_mobile_commons_subscribe($mobile, $this->routes[$opt_in_path]['no']);
        $state->setContext('ignore_no_response_error', TRUE);
      }
      else {
        $state->setContext('sms_response', t('TODO: Some other sort of error message'));
        watchdog('sms_flow', "Invalid workflow or opt-in path output for path ($opt_in_path).");
      }
    }
    else {
      $state->setContext('sms_response', t('TODO: Some sort of error message about something not being setup on our end'));
      watchdog('sms_flow', "Incoming opt-in ($opt_in_path) path not handled by ConductorActivityCanSendMMSReportBack");
    }

    $state->markCompleted();
  }

}
