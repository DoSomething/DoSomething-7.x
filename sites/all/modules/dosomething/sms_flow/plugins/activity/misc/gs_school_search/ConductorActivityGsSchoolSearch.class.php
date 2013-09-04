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
      
      $state->markSuspended();
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
      
      $state->markSuspended();
    }
    // No results found
    else {
      $response = t($this->no_school_found_msg, array(
        '@school_name' => $schoolName,
        '@school_state' => $schoolState));
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
    // If Y, save school gsid to context 'school_sid'
    if (self::isYesResponse($userResponse)) {
      $results = $state->getContext('gs_school_search_results');

      $state->setContext('selected_school_name', $results[0]->name);
      $state->setContext('school_sid', $results[0]->gsid);

      self::selectNextOutput(OutputType::CONT);
    }
    // If #, check if valid, then save school gsid to context 'school_sid'
    elseif (self::isValidSchoolIndex($userResponse)) {
      $results = $state->getContext('gs_school_search_results');

      $schoolIndex = $userResponse - 1; // Displayed value is +1 of actual index value
      $state->setContext('selected_school_name', $results[$schoolIndex]->name);
      $state->setContext('school_sid', $results[$schoolIndex]->gsid);

      self::selectNextOutput(OutputType::CONT);
    }
    else {
      // If user did not follow directions and texted back their school name instead
      // of the number, then try to handle it here
      $schoolMatch = self::findSchoolNameMatch($userResponse);
      if ($schoolMatch) {
        $state->setContext('selected_school_name', $schoolMatch->name);
        $state->setContext('school_sid', $schoolMatch->gsid);

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

    if ($firstWord == 'Y'
        || $firstWord == 'YA'
        || $firstWord == 'YEA'
        || $firstWord == 'YES') {
      return TRUE;
    }
    else {
      return FALSE;
    }
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