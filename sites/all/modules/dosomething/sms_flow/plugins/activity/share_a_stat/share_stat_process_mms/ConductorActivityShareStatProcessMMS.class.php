<?php

/**
 * Determine if MMS was received and route to the next appropriate opt-in path.
 */
class ConductorActivityShareStatProcessMMS extends ConductorActivity {

  // Nested array of opt-in paths and their destinations
  // = array(
  //     <incoming opt-in path> => array (
  //       'mms' => mms opt-in path
  //       'no_mms' => no mms opt-in path
  //     ),
  //     ...
  //   )
  public $routes;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $opt_in_path = intval($_REQUEST['opt_in_path_id']);
    $mms_url = check_plain($_REQUEST['mms_image_url']);
    $next_path = 0;

    if (array_key_exists($opt_in_path, $this->routes)) {
      if (!empty($mms_url)) {
        $next_path = $this->routes[$opt_in_path]['mms'];
      }
      else {
        $next_path = $this->routes[$opt_in_path]['no_mms'];
      }
    }
    else {
      watchdog('sms_flow', 'share_stat_mms activity triggered from invalid opt in path: ' . $opt_in_path);
    }

    if ($next_path > 0) {
      dosomething_general_mobile_commons_subscribe($mobile, $next_path);
    }
    else {
      watchdog('sms_flow', "share_stat_mms ignoring attempt to subscribe $mobile to opt-in path: $next_path");
    }

    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }

}
