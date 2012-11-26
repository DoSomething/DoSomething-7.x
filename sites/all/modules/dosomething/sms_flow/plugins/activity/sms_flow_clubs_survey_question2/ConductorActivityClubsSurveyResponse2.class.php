<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityClubsSurveyNextResponse extends ConductorActivity {

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

      $responses = array(
        'a' => t("We're sad to hear that.  Is there anything we could have done to support you better?"),
        'b' => t("We would love to help! Check out our resources for club leaders at dosomething.org/clubresources or txt us back with specific questions."),
        'c' => t("Congrats on graduating! You can choose an ew club leader for your Club profile page at DoSomething.org/MyClub to pass on the torch."),
        'd' => t("Haha.  I forget things too.  Ur DoSomething.org Club is a great way to get involved in cause campaigns.  Log back onto DoSomething.org/MyClub to check urs out!"),
      );

      $responded = $responses[strtolower($_REQUEST['args'])];
      $state->setContext('sms_response', $responded);
      $state->markCompleted();
    }
    else {
      $state->setContext('sms_response', 'ahhhh');
      $state->markCompleted();
    }
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
