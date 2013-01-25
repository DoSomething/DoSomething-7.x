<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityClubsFollowUpSurveyFin extends ConductorActivity {

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $followup = array(
      'awesome' => $state->getContext('clubs_survey_followup_response:message'), // Are your active club members listed on your DoSomething.org Club Profile page? Y or N
      'active' => $state->getContext('process_next_answer:message'), // Does your club focus on A) general community volunteering or B) a specific cause/organization/project?
      'focus' => $state->getContext('process_club_focus:message'), // Does your club focus on A) general community volunteering or B) a specific cause/organization/project?
      'specifics' => $state->getContext('process_club_focus_nest:message'), // Before we get to question #4 can you tell us briefly what specific cause, organization, or project your club focuses on? (in less than 140 characters
      'advice' => $state->getContext('process_clubs_last_question:message'), // Last question, do you have any advice for other students looking to start (or join) a DS club
    );
    
    db_update('dosomething_clubs_survey')
      ->fields(array(
        'followup' => serialize($followup),
      ))
      ->condition('cell', $mobile)
      ->execute();

    $success_message .= t('Thanks so much for taking our survey, it gives us a much better idea of how our team can support your awesome clubs! - Crystal, DoSomething.org');
    $state->setContext('sms_response', $success_message);
    $state->markCompleted();
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
