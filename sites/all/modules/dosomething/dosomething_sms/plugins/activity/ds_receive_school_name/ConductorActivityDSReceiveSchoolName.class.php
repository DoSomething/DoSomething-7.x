<?php

/**
 * Process user's search query and return a list of schools that match, if any.
 */
class ConductorActivityDSReceiveSchoolName extends ConductorActivitySMSPrompt {

  public function run($workflow) {
    $activity_state = $this->getState();

    // If we already have the school id, just skip this step
    $school_id = $activity_state->getContext('school_id');
    if (!empty($school_id)) {
      $activity_state->markCompeted();
      return;
    }

    $bAlreadyRan = $activity_state->getContext('ds_receive_school_name_status');
    if ($bAlreadyRan != 'PROCESSED') {
      $activity_state->setContext('ds_receive_school_name_status', 'PROCESSED');
      $bFoundSchools = FALSE;

      // Process user's message to search for greatschools ids
      $message = $activity_state->getContext('ask_school_name:message');
      $message_words = explode(' ', $message);

      // First word expected to be a state abbreviation
      $school_state = array_shift($message_words);
      $state_list = array('AK','AL','AR','AZ','CA','CO','CT','DC','DE','FL','GA','HI','IA','ID','IL','IN','KS','KY','LA','MA','MD','ME','MI','MN','MO','MS','MT','NC','ND','NE','NH','NJ','NM','NV','NY','OH','OK','OR','PA','RI','SC','SD','TN','TX','UT','VA','VT','WA','WI','WV','WY');
      if (strlen($school_state) == 2 && in_array(strtoupper($school_state), $state_list)) {
        // Verified first word's a state, search with the rest of the query now
        $url = 'http://api.greatschools.org/search/schools?key=pgs9xjxdf8azkiwzxsswmwxx&limit=6&state=' . $school_state . '&q=';

        $message = array();
        $search_term = implode(' ', $message_words);
        while (count($message_words) > 0) {
          // Submit search and retrieve xml result
          $ch = curl_init();
          curl_setopt($ch,CURLOPT_RETURNTRANSFER, 1);
          curl_setopt($ch,CURLOPT_SSL_VERIFYPEER, false);
          curl_setopt($ch,CURLOPT_URL,$url.urlencode($search_term));
          $sxml = curl_exec($ch);
          curl_close($ch);

          if (!empty($sxml)) {
            $sxml = new SimpleXMLElement($sxml);

            if (count($sxml->school) > 0) {
              // Schools found. Build header, body, and footer message text.
              $return_msg = 'Text us your school ID (ex: NY1234), we found ' . count($sxml->school) . " matches\n";
              foreach ($sxml->school as $school) {
                $return_msg .= $school->state . $school->gsId . ' - ' . $school->name . "\n";
              }
              $return_msg .= "or text NOID if you don't see it.";

              // Set message as 'question' for ConductorActivitySMSPrompt to handle
              $this->question = $return_msg;

              $bFoundSchools = TRUE;
              break;
            }
          }

          // If last search did not succeed, pop off a search word and search again
          array_pop($message_words);
          $search_term = implode(' ', $message_words);
        }
      }

      if ($bFoundSchools) {
        $activity_state->setContext('schools_search_result', 'SUCCESS');
      }
      else {
        // Set context to indicate no schools were found. Error message will be
        // provided in the next activity ConductorActivityDSReceiveSchoolID
        $activity_state->setContext('schools_search_result', 'FAILED');
        $activity_state->markCompeted();
      }
    }

    // Parent class will handle sending the message and waiting for response
    if ($activity_state->getStatus() != ConductorActivityState::COMPLETED)
      parent::run();
  }

}
