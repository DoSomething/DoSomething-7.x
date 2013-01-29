<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityClubsFollowUpSurveyResponse extends ConductorActivity {

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

    if ($state->getContext($this->name . ':message') === FALSE) {    // Invite accepted
        if (self::hasAcceptResponse($_REQUEST['args'])) {
          $this->removeOutput('end');
          $success_message .= t('1. Tell us briefly about the most awesome sauce campaign or project your club ever completed? (in less than 140 characters)');
          $state->setContext('sms_response', $success_message);
          $state->markSuspended();
        }
        else {
          $this->removeOutput('process_next_answer');
          $state->setContext('sms_response', t('No problem.  Thanks!'));
          $state->markCompleted();
        }
    }
    else {
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

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers() {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }
}
