<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityClubsFollowUpSurveyResponseFourth extends ConductorActivity {

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    if (strtolower($state->getContext('process_club_focus:message')) == 'b') {
      if ($state->getContext($this->name . ':message') === FALSE) {
          $success_message .= t('Before we get to question #4 can you tell us briefly what specific cause, organization, or project your club focuses on? (in less than 140 characters).');
          $state->setContext('sms_response', $success_message);
          $state->markSuspended();
      }
      else {
        $state->markCompleted();
      }
    }
    else {
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
}
