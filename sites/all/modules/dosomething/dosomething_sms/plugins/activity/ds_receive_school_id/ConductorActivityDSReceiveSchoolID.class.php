<?php

/**
 * Receive user's school ID response.
 */
class ConductorActivityDSReceiveSchoolID extends ConductorActivitySMSPrompt {
  
  public function run($workflow) {
    $state = $this->getState();

    // If we already have the school id, just skip this step
    $school_id = $state->getContext('school_id');
    if (!empty($school_id) ) {
      $state->markCompeted();
      return;
    }

    $bAlreadyRan = $state->getContext('ds_receive_school_id_status');
    if ($bAlreadyRan != 'PROCESSED') {
      $state->setContext('ds_receive_school_id_status', 'PROCESSED');

      $schools_search_result = $state->getContext('schools_search_result');
      if ($schools_search_result == 'SUCCESS') {
        $message = $state->getContext('recv_school_name:message');
        $message_words = explode(' ', $message);
        // Process only the first word. Ignore everything else.
        $message = array_shift($message_words);
        $message = strtoupper($message);

        if ($message == 'NOID') {
          // User didn't see ID
          //$this->question = t('Sorry we couldn\'t find your school. Text AGAIN to try again or GO to continue.');
          $this->question = t('Sorry we couldn\'t find your school. Text GO to continue.');
        }
        else {
          // Assume we've got a greatschools id
          $school_state = substr($message, 0, 2);
          $school_id = substr($message, 2, strlen($message)-2);

          if (is_numeric($school_id)) {
            // School is valid, no need to respond. Just continue to the next step.
            $state->setContext('school_id', $school_state . $school_id);
            $state->setContext('ds_receive_school_id_status', 'OK');
            $state->markCompeted();
          }
          else {
            // Unknown response
            //$this->question = t('Sorry there were no matches found. Text AGAIN to try again or GO to continue.');
            $this->question = t('Sorry there were no matches found. Text GO to continue.');
          }
        }
      }
      else {
        // No schools found
        //$this->question = t('Sorry there were no matches found. Text AGAIN to try again or GO to continue.');
        $this->question = t('Sorry there were no matches found. Text AGAIN to try again or GO to continue.');
      } 
    }

    if ($state->getStatus() != ConductorActivityState::COMPLETED) {
      parent::run();
    }
  }
}

