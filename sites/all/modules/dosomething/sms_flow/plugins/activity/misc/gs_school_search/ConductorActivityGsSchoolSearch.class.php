<?php

/**
 * Enum-style class specifiying type of output this activity should go to next.
 */
class OutputType {
  const END = 0;
  const CONT = 1;
}

/**
 * Given school and state values from previous activities in a Conductor workflow,
 * search for schools, display results, and handle user responses to those results.
 */
class ConductorActivityGsSchoolSearch extends ConductorActivity {

  // Activity name where school state was asked for
  public $state_activity_name = '';

  // Activity name where school name was asked for
  public $school_activity_name = '';

  // Max results to return from the search
  public $max_results = 6;

  // Array of key-value pairs of mData IDs and the keywords associated with them.
  // Used by the return messages to let users know what keyword to use to try again.
  public $mdata_keywords;

  // Message to return if no results are found
  public $no_school_found_msg;

  // Message to return if a single result is found
  public $one_school_found_msg;

  // Message prepended before the list of results when multiple schools are found
  public $schools_found_msg;

  // Message to return if user replies with an invalid response
  public $invalid_response_msg;

  public function run() {
    $state = $this->getState();

    $userResponse = $state->getContext($this->name . ':message');
    // If no response found, then it's first time through the activity. Execute the search.
    if ($userResponse === FALSE) {
      self::searchForSchool();
    }
    // If we have a response, it's to the school search results.
    else {
      self::handleUserResponse($userResponse);
    }
  }

  /**
   * To be run on initial execution of this activity. Searches for school
   * and returns any results found.
   */
  private function searchForSchool() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $schoolState = trim(strtoupper($state->getContext($this->state_activity_name . ':message')));
    $schoolName = trim($state->getContext($this->school_activity_name . ':message'));

    $searchData = array(
      'query' => $schoolName,
      'state' => $schoolState,
      'limit' => $this->max_results,
    );

    $url = 'http://lofischools.herokuapp.com/search?'
        . 'query=' . urlencode($schoolName)
        . '&state=' . urlencode($schoolState)
        . '&limit=' . $this->max_results;
    $opts = array(
      'http' => array(
        'method' => 'GET'
      )
    );

    $context = stream_context_create($opts);
    $jsonResults = file_get_contents($url, FALSE, $context);
    $resultsObj = json_decode($jsonResults);
    $results = $resultsObj->results;
    $numResults = count($results);
    
    // Save the search results to context for access later
    if ($numResults > 0) {
      $state->setContext('gs_school_search_results', $results);
    }

    // Get the restart keyword, if any, based on the mdata ID
    $restartKeyword = "";
    foreach($this->mdata_keywords as $mdataId => $mDataKeyword) {
      if (intval($_REQUEST['mdata_id']) == $mdataId) {
        $restartKeyword = $mDataKeyword;
      }
    }

    // One result found
    if ($numResults == 1) {
      $response = t($this->one_school_found_msg, array(
        '@school_name' => $results[0]->name,
        '@school_street' => $results[0]->street,
        '@school_city' => $results[0]->city,
        '@school_state' => $results[0]->state,
        '@keyword' => $restartKeyword));
      $state->setContext('sms_response', $response);
      
      $state->markSuspended();
    }
    // Multiple results found
    elseif ($numResults > 1) {
      $response = t($this->schools_found_msg, array('@num_results' => $numResults, '@keyword' => $restartKeyword)) . "\n";
      for ($i = 0; $i < $numResults; $i++) {
        $displayNum = $i + 1; // Start with 1 instead of 0
        $schoolName = $results[$i]->name;
        $schoolStreet = $results[$i]->street;
        $schoolCity = $results[$i]->city;
        $schoolState = $results[$i]->state;

        // Add the school result to the message returned to the user
        $response .= t('@num) @name in @city, @state.', array('@num' => $displayNum, '@name' => $schoolName, '@city' => $schoolCity, '@state' => $schoolState)) . "\n";
      }
      $state->setContext('sms_response', $response);
      
      $state->markSuspended();
    }
    // No results found
    else {
      $response = t($this->no_school_found_msg, array(
        '@school_name' => $schoolName,
        '@school_state' => $schoolState,
        '@keyword' => $restartKeyword));
      $state->setContext('sms_response', $response);

      // End the workflow by going to the 'end' activity
      self::selectNextOutput(OutputType::END);
    }
  }

  /**
   * Setup activity to go to 'end' activity or whatever other activity is available
   */
  private function selectNextOutput($nextOutput) {
    $state = $this->getState();
    if ($nextOutput == OutputType::END) {
      // Remove any outputs that are not 'end'
      $numOutputs = count($this->outputs);
      foreach ($this->outputs as $key => $activityName) {
        if ($activityName != 'end') {
          $this->removeOutput($activityName);
        }
      }
    }
    else {
      // Save school to user's profile before moving on to next activity
      $mobile = $state->getContext('sms_number');
      $user = sms_flow_get_or_create_user_by_cell($mobile);
      if ($user) {
        $profile = profile2_load_by_user($user, 'main');
        if ($profile) {
          $gsid = $state->getContext('school_gsid');

          // Profile expects the DS sid, not the Great School id
          $sid = db_query('SELECT sid FROM ds_school WHERE `gsid` = :gsid', array(':gsid' => $gsid))->fetchField();
          if ($sid > 0) {
            $profile->field_school_reference[LANGUAGE_NONE][0]['target_id'] = $sid;
            try {
              profile2_save($profile);
            }
            catch (Exception $e) {}
          }
        }
      }

      $this->removeOutput('end');
    }

    // Next activity's selected, so this one is now complete
    $state->markCompleted();
  }

  /**
   * Handle the user's response to the results from the school search
   */
  private function handleUserResponse($userResponse) {
    $state = $this->getState();
    $userResponse = strtoupper(trim($userResponse));
    // If Y, save school gsid to context 'school_gsid'
    if (self::isYesResponse($userResponse)) {
      $results = $state->getContext('gs_school_search_results');

      $state->setContext('selected_school_name', $results[0]->name);
      $state->setContext('selected_school_state', $results[0]->state);
      $state->setContext('school_gsid', $results[0]->gsid);

      self::selectNextOutput(OutputType::CONT);
    }
    // If #, check if valid, then save school gsid to context 'school_gsid'
    elseif (self::isValidSchoolIndex($userResponse)) {
      $results = $state->getContext('gs_school_search_results');

      $schoolIndex = $userResponse - 1; // Displayed value is +1 of actual index value
      $state->setContext('selected_school_name', $results[$schoolIndex]->name);
      $state->setContext('selected_school_state', $results[$schoolIndex]->state);
      $state->setContext('school_gsid', $results[$schoolIndex]->gsid);

      self::selectNextOutput(OutputType::CONT);
    }
    else {
      // If user did not follow directions and texted back their school name instead
      // of the number, then try to handle it here
      $schoolMatch = self::findSchoolNameMatch($userResponse);
      if ($schoolMatch) {
        $state->setContext('selected_school_name', $schoolMatch->name);
        $state->setContext('school_gsid', $schoolMatch->gsid);

        self::selectNextOutput(OutputType::CONT);
      }
      // If anything else, return invalid response, go to end
      else {
        $state->setContext('sms_response', $this->invalid_response_msg);

        self::selectNextOutput(OutputType::END);
      }
    }
  }

  /**
   * Determine whether or not user response qualifies as a 'Yes'
   *
   * @return TRUE if qualified as a 'Yes'. Otherwise, FALSE.
   */
  private function isYesResponse($userResponse) {
    $words = explode(' ', $userResponse);
    $firstWord = $words[0];

    return in_array($firstWord, array('Y', 'YA', 'YEA', 'YES'));
  }

  /**
   * Ensure user's school selection is within the bounds of the results found.
   *
   * @return TRUE if user's selection is valid. Otherwise, FALSE.
   */
  private function isValidSchoolIndex($userResponse) {
    $state = $this->getState();

    if (is_numeric($userResponse)) {
      $results = $state->getContext('gs_school_search_results');
      if ($userResponse > 0 && $userResponse <= count($results)) {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Goes through search results checking if any of the school names match
   * the user's response.
   *
   * @return Object with school data if match is found. Otherwise, FALSE.
   */
  private function findSchoolNameMatch($userResponse) {
    $state = $this->getState();
    $results = $state->getContext('gs_school_search_results');
    $userResponse = trim($userResponse);

    foreach ($results as $schoolData) {
      $schoolName = strtoupper($schoolData->name);

      if (stripos($schoolName, $userResponse) !== FALSE) {
        return $schoolData;
      }
    }

    return FALSE;
  }

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers(ConductorWorkflow $workflow = NULL) {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }

}