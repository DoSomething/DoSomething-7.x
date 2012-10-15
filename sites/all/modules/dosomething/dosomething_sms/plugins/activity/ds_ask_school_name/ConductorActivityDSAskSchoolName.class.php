<?php

/**
 * Checks whether we have the user's school_id. If we do, then it skips this
 * step. Otherwise, prompts user to enter state and school name and waits
 * for the response.
 */
class ConductorActivityDSAskSchoolName extends ConductorActivitySMSPrompt {

  public function run($workflow) {
    $state = $this->getState();

    // If we already have the school id, just skip this step
    $school_id = $state->getContext('school_id');
    if (!empty($school_id)) {
      $state->markCompleted();
      return;
    }

    // Otherwise, prompt the user for a response
    parent::run();
  }

}