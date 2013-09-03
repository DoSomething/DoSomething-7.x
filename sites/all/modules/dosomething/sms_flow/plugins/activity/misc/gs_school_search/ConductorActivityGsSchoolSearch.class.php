<?php

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

    // One result found
    if ($numResults == 1) {
      $response = t($this->one_school_found_msg, array(
        '@school_name' => $results[0]->name,
        '@school_street' => $results[0]->street,
        '@school_city' => $results[0]->city,
        '@school_state' => $results[0]->state));
      $state->setContext('sms_response', $response);
      
      // $state->markSuspended();
      self::selectNextActivity(TRUE);
    }
    // Multiple results found
    elseif ($numResults > 1) {
      $response = t($this->schools_found_msg . "\n", array('@num_results' => $numResults));
      for ($i = 0; $i < $numResults; $i++) {
        $displayNum = $i + 1; // Start with 1 instead of 0
        $schoolName = $results[$i]->name;
        $schoolStreet = $results[$i]->street;
        $schoolCity = $results[$i]->city;
        $schoolState = $results[$i]->state;
        $response .= t("$displayNum) $schoolName. $schoolStreet, $schoolCity, $schoolState\n");
      }
      $state->setContext('sms_response', $response);
      
      // $state->markSuspended();
      self::selectNextActivity(TRUE);
    }
    // No results found
    else {
      $response = t($this->no_school_found_msg, array(
        '@school_name' => $schoolName,
        '@school_state' => $schoolState));
      $state->setContext('sms_response', $response);

      self::selectNextActivity(TRUE);
    }
  }

  /**
   * Setup activity to go to 'end' activity or whatever other activity is available
   */
  private function selectNextActivity($bGoToEnd) {
    $state = $this->getState();
    if ($bGoToEnd) {
      // Remove any outputs that are not 'end'
      $numOutputs = count($this->outputs);
      foreach ($this->outputs as $key => $activityName) {
        if ($activityName != 'end') {
          $this->removeOutput($activityName);
        }
      }
    }
    else {
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
    $userResponse = strtoupper($userResponse);
    // if Y, save school gsid to context 'school_sid'
    if ($userResponse == 'Y') {
      $results = $state->getContext('gs_school_search_results');
      $state->setContext('school_sid', $results[0]->gsid);

      self::selectNextActivity(FALSE);
    }
    // if #, check if valid, then save school gsid to context 'school_sid'
    elseif (self::isValidSchoolSelection($userResponse)) {
      $results = $state->getContext('gs_school_search_results');

      $userSelection = $userResponse - 1; // Displayed value is +1 of actual index value
      $state->setContext('school_sid', $results[$userSelection]->gsid);

      self::selectNextActivity(FALSE);
    }
    // if anything else, return invalid response, go to end
    else {
      $state->setContext('sms_response', $this->invalid_response_msg);
      self::selectNextActivity(TRUE);
    }
  }

  /**
   * Ensure user's school selection is within the bounds of the results found.
   */
  private function isValidSchoolSelection($userResponse) {
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
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers(ConductorWorkflow $workflow = NULL) {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }

}