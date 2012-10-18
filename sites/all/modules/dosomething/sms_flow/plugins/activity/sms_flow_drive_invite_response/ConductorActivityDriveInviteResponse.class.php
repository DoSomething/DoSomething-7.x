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

    $response_words = explode(' ', $_REQUEST['args']);
    $first_response = array_shift($response_words);

    // Invite accepted
    if (self::hasAcceptResponse($first_response)) {
      // find_user_by_cell() doesn't handle international codes when searching by profile's
      // field_user_mobile value. Only handles international code with an @mobile email address
      $account = dosomething_general_find_user_by_cell($mobile);
      if (!$account && strlen($mobile) > 10) {
        $mobile = substr($mobile, -10);
        $account = dosomething_general_find_user_by_cell($mobile);
      }
      
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

      $state->setContext('sms_response', $this->invite_rejected_message);
    }

    $state->markCompleted();
  }

  private function hasAcceptResponse($response) {
    $response = strtolower($response);
    foreach($this->accept_responses as $val) {
      if ($val == $response) {
        return TRUE;
      }
    }

    return FALSE;
  }

}
