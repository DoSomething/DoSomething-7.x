<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityClubsFollowUpSurveyResponseSecond extends ConductorActivity {

  // Array of responses indicating an acceptance of the invite
  protected $accept_responses = array();

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $success_message = t('Be awesome.');
    $state->setContext('sms_response', $success_message);

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

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers() {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }
}
