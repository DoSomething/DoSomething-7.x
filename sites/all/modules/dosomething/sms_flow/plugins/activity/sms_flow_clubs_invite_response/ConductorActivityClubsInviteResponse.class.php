<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityClubsInviteResponse extends ConductorActivity {

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
    if (self::hasAcceptResponse($_REQUEST['args']) || $_REQUEST['args'] == '') {
      $account = dosomething_api_user_lookup($mobile);

      // No account found. Output should be 'ask_name'
      if (!$account) {
        $this->removeOutput('clubs_process_beta');
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
      $this->removeOutput('clubs_process_beta');

      $state->setContext('sms_response', $this->invite_rejected_message);
    }

    $state->markCompleted();
  }

  private function hasAcceptResponse($response) {
    $response = strtolower($response);
    $response = trim($response);

    if (in_array($response, $this->accept_responses)) {
      return TRUE;
    }
    return FALSE;
  }
}