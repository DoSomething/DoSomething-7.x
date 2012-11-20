<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityDriveInviteResponse extends ConductorActivity {

  // Array of responses indicating an acceptance of the invite
  public $accept_responses = array();

  // Message returned to the user if they reject the invite
  public $invite_rejected_message = '';

  public function option_definition() {
    $options = parent::option_definition();
    $options['accept_responses'] = array('default' => array());
    $options['invite_rejected_message'] = array('default' => '');
    return $options;
  }

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Invite accepted
    if (self::hasAcceptResponse($_REQUEST['args'])) {
      $account = _sms_flow_find_user_by_cell($mobile);
      
      // No account found. Output should be 'ask_name'
      if (!$account) {
        $this->removeOutput('process_beta');
        $this->removeOutput('end');
      }
      // Account found. Output should be 'process_beta'
      else {
        $this->removeOutput('ask_name');
        $this->removeOutput('end');
      }
    }
    // Invite rejected. Output should be 'end'
    else {
      $this->removeOutput('ask_name');
      $this->removeOutput('process_beta');

      // Defense against cases where people should've gone from process_beta to sms_flow_ftaf, but didn't
      preg_match_all('#(?:1)?(?<numbers>\d{3}\d{3}\d{4})#i', preg_replace('#[^0-9]#', '', $_REQUEST['args']), $numbers);
      if (!empty($numbers['numbers'])) {
        $num_detected_msg = 'Oops. Did you mean to invite someone to your drive? Text TFJINVITE and try to invite again. Trying to join a drive? Text TFJJOIN to try to join again.';
        $state->setContext('sms_response', $num_detected_msg);
      }
      else {
        $state->setContext('sms_response', $this->invite_rejected_message);
      }
    }

    $state->markCompleted();
  }

  private function hasAcceptResponse($response) {
    $response = strtolower($response);
    foreach($this->accept_responses as $val) {
      if (stripos($response, $val) === 0) {
        return TRUE;
      }
    }

    return FALSE;
  }

}
