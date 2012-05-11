<?php

/**
 * Activity to process the last user response at the end of the school-ask
 * workflow. Depending on response, will either return user to a previous
 * state to ask for school again, or continue on to the next activity.
 */
class ConductorActivityDSProcessSchoolResponse extends ConductorActivity {

  public function run($workflow) {
    $state = $this->getState();

    // If we already have the school id, just skip this step
    $school_id = $state->getContext('school_id');
    if (!empty($school_id) ) {
      $state->markCompeted();
      return;
    }

    $recv_sid_status = $state->getContext('ds_receive_school_id_status');
    if ($recv_sid_status == 'OK') {
      // Then just continue to the next step
    }
    else {
      $message = $state->getContext('recv_school_id:message');
      $message_words = explode(' ', $message);
      // Process only the first word. Ignore everything else.
      $message = array_shift($message_words);
      $message = strtoupper($message);

      if ($message == 'AGAIN') {
        // TODO: how to send back to 'ask_school_name' activity?
        ;
      }
      else {
        // TODO: how to set to go to next activity, especially if outputs change previously
        ;
      }
    }

    $state->markCompeted();
  }
}
