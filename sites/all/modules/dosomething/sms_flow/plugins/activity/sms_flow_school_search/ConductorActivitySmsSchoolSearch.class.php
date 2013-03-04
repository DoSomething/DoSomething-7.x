<?php

/**
 * Given school level, state, and school name query, return list of matching schools
 */
class ConductorActivitySmsSchoolSearch extends ConductorActivity {

  const MAX_RESULTS = 3;

  // Message sent to user if they input an invalid school ID
  public $invalid_id_message;

  // Message sent to user if no school is found
  public $no_school_message;

  // Appended to message when schools are found
  public $schools_found_post_message;

  private $state_abbr_map = array(
    'alabama' => 'AL',
    'alaska' => 'AK',
    'arizona' => 'AZ',
    'arkansas' => 'AR',
    'california' => 'CA',
    'colorado' => 'CO',
    'connecticut' => 'CT',
    'delaware' => 'DE',
    'florida' => 'FL',
    'georgia' => 'GA',
    'hawaii' => 'HI',
    'idaho' => 'ID',
    'illinois' => 'IL',
    'indiana' => 'IN',
    'iowa' => 'IA',
    'kansas' => 'KS',
    'kentucky' => 'KY',
    'louisiana' => 'LA',
    'maine' => 'ME',
    'maryland' => 'MD',
    'massachusetts' => 'MA',
    'michigan' => 'MI',
    'minnesota' => 'MN',
    'mississippi' => 'MS',
    'missouri' => 'MO',
    'montana' => 'MT',
    'nebraska' => 'NE',
    'nevada' => 'NV',
    'new hampshire' => 'NH',
    'new jersey' => 'NJ',
    'new mexico' => 'NM',
    'new york' => 'NY',
    'north carolina' => 'NC',
    'north dakota' => 'ND',
    'ohio' => 'OH',
    'oklahoma' => 'OK',
    'oregon' => 'OR',
    'pennsylvania' => 'PA',
    'rhode island' => 'RI',
    'south carolina' => 'SC',
    'south dakota' => 'SD',
    'tennessee' => 'TN',
    'texas' => 'TX',
    'utah' => 'UT',
    'vermont' => 'VT',
    'virginia' => 'VA',
    'washington' => 'WA',
    'west virginia' => 'WV',
    'wisconsin' => 'WI',
    'wyoming' => 'WY',

    'american samoa' => 'AS',
    'district of columbia' => 'DC',
    'federated states of micronesia' => 'FM',
    'guam' => 'GU',
    'marshall islands' => 'MH',
    'northern mariana islands' => 'MP',
    'palau' => 'PW',
    'puerto rico' => 'PR',
    'virgin islands' => 'VI',
  );
  
  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // First time through, user has not replied to this activity yet
    $user_reply = $state->getContext($this->name . ':message');
    if ($user_reply === FALSE) {
      $school_level = strtolower($state->getContext('ask_school_level:message'));
      $school_state = strtolower($state->getContext('ask_school_state:message'));
      $school_name = strtolower($state->getContext('ask_school_name:message'));

      // Sanitize the input
      $school_level = self::checkSchoolLevel($school_level);
      $school_state = self::checkSchoolState($school_state);

      if ($school_level && $school_state && $school_name) {
        $data = dosomething_school_sms_query($school_level, $school_state, $school_name);

        if (count($data) == 0) {
          $response = $this->no_school_message;

          $this->removeOutput('check_account_exists');
          $state->markCompleted();
        }
        else {
          $num_schools = count($data) > self::MAX_RESULTS ? self::MAX_RESULTS : count($data);

          if ($num_schools > 1) {
            $response = "We found " . $num_schools . " schools.\n";
          }
          else {
            $response = "We found " . $num_schools . " school.\n";
          }

          $sids = array();
          for ($i = 0; $i < $num_schools; $i++) {
            $response .= $i+1 . ') ' . $data[$i]['name'] . '. ' . $data[$i]['street'] . ', ' . $data[$i]['city'] . ', ' . $data[$i]['state'] . '. ID#: ' . $data[$i]['sid'] . " \n";
            $sids[] = $data[$i]['sid'];
          }

          $response .= $this->schools_found_post_message;
          $state->setContext('school_search_results', $sids);
          $state->markSuspended();
        }
      }
      else {
        $response = $this->no_school_message;

        $this->removeOutput('check_account_exists');
        $state->markCompleted();
      }

      $state->setContext('sms_response', $response);
    }
    // Second time through, user has replied to activity with either school id or something else
    else {
      $words = explode(' ', $user_reply);
      $first_word = $words[0];
      $sid_reply = intval($first_word);

      $school_sid = 0;
      if ($sid_reply > 0 && $sid_reply <= self::MAX_RESULTS) {
        $found_sids = $state->getContext('school_search_results');
        $school_sid = $found_sids[$sid_reply - 1];
      }
      else {
        $school_sid = self::checkSchoolSID($first_word);
      }

      if ($school_sid) {
        $state->setContext('school_sid', $school_sid);

        $this->removeOutput('end');
      }
      else {
        $response = $this->invalid_id_message;
        $state->setContext('sms_response', $response);

        $this->removeOutput('check_account_exists');
      }

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

  /**
   * The ds_schools database table that we'll be querying expects high school => 1 and college => 2
   */
  private function checkSchoolLevel($level) {
    $first_char = substr($level, 0, 1);

    $is_high_school = FALSE;
    $is_college = FALSE;

    if ($first_char == '1') {
      $is_high_school = TRUE;
    }
    elseif ($first_char == '2') {
      $is_college = TRUE;
    }
    else {
      $hs_answers = array('high', 'hs', 'hgih');
      for ($i = 0; $i < count($hs_answers); $i++) {
        if (strpos($level, $hs_answers[$i]) !== FALSE) {
          $is_high_school = TRUE;
        }
      }

      $college_answers = array('college', 'university');
      for ($i = 0; $i < count($college_answers); $i++) {
        if (strpos($level, $college_answers[$i]) !== FALSE) {
          $is_college = TRUE;
        }
      }
    }
    
    if ($is_high_school) {
      return 1;
    }
    elseif ($is_college) {
      return 2;
    }
    else {
      return 0;
    }
  }

  private function checkSchoolState($state) {
    $state_abbr = FALSE;

    if (strlen($state) !== 2) {
      // Map this state to its abbreviation
      $keys = array_key_exists($state, $this->state_abbr_map);
      if (!empty($keys)) {
        $state_abbr = $this->state_abbr_map[$state];
      }
    }
    else {
      // Ensure state is actually valid
      $state = strtoupper($state);
      $values = array_search($state, $this->state_abbr_map);
      if (!empty($values)) {
        $state_abbr = $state;
      }
    }

    return $state_abbr;
  }

  private function checkSchoolSID($sid) {
    if (is_numeric($sid) && dosomething_school_find_by_sid($sid)) {
      return $sid;
    }
    else {
      return FALSE;
    }
  }

}