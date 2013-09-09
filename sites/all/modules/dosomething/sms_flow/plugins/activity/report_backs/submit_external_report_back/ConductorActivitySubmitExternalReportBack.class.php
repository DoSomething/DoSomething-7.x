<?php

/**
 * Submits a report back form to an external service. Currently only supports
 * sending application/json content.
 */
class ConductorActivitySubmitExternalReportBack extends ConductorActivity {

  // HTTP request type - either POST or PUT.
  public $http_request_type;

  // Array of key/value pairs where key = the name of the context to pull data
  // from. And value = the name of the field the data should be submitted to.
  // Some key names are reserved for special cases: gsid, uid, append_query.
  public $submission_fields = array();

  // URL to submit to.
  public $submission_url;

  // Response to send back to the user upon successful submission.
  public $success_response;

  // (Optional) URL for looking up submissions created by this user. Particularly
  // useful when needing to PUT/UPDATE previously created submissions.
  public $uid_lookup_url;

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $user = sms_flow_get_or_create_user_by_cell($mobile);

    // Cycle through field to build the query content
    $query = array();
    foreach ($this->submission_fields as $contextName => $fieldName) {
      // 'gsid' builds a string with school name and its gsid
      if ($contextName == 'gsid') {
        // Combine school name with school sid
        $schoolName = $state->getContext('selected_school_name');
        $schoolGsid = $state->getContext('school_gsid');
        $fieldValue = "$schoolName ($schoolGsid)";

        $tmp = array();
        parse_str("$fieldName=$fieldValue", $tmp);
        $query = array_merge_recursive($query, $tmp);
      }
      // 'uid' gets this user's uid
      elseif ($contextName == 'uid') {
        if ($user && $user->uid) {
          $tmp = array();
          parse_str("$fieldName=$user->uid", $tmp);
          $query = array_merge_recursive($query, $tmp);
        }
      }
      // 'append_query' is a string of explicitly set key/value pairs for the query
      elseif ($contextName == 'append_query') {
        $tmp = array();
        parse_str($fieldName, $tmp);
        $query = array_merge_recursive($query, $tmp);
      }
      // General case will lookup data in the context name given and apply it to the field name
      else {
        $fieldValue = $state->getContext($contextName);
        $tmp = array();
        parse_str("$fieldName=$fieldValue", $tmp);
        $query = array_merge_recursive($query, $tmp);
      }
    }

    // Submit the content
    if ($this->http_request_type == 'POST') {
      self::submitPost($query);
    }
    elseif ($this->http_request_type == 'PUT') {
      self::submitPut($query, $user->uid);
    }

    // Send confirmation message to user
    if (is_numeric($this->success_response)) {
      // If value is numeric, assume it's a Mobile Commons opt-in path id
      dosomething_general_mobile_commons_subscribe($mobile, $this->success_response);
      $state->setContext('ignore_no_response_error', TRUE);
    }
    else {
      $state->setContext('sms_response', $this->success_response);
    }

    $state->markCompleted();
  }

  /**
   * POST submission
   *
   * @param $query Array of the content to POST
   */
  private function submitPost($query) {
    $state = $this->getState();
  
    // BEGIN HACK :(
    // Execute a school lookup so that create_and_share database will insert schools into database
    // Otherwise this school might not be available/known on the create_and_share side
    $schoolName = $state->getContext('selected_school_name');
    $schoolState = $state->getContext('selected_school_state');
    $lookupUrl = 'http://campaigns.dosomething.org/fedup/posts/school_lookup?term=' . urlencode($schoolName) . '&state=' . urlencode($schoolState);
    $chLookup = curl_init($lookupUrl);
    curl_setopt_array($chLookup, array(
      CURLOPT_HTTPHEADER => array('Content-Type: application/json'),
      CURLOPT_RETURNTRANSFER => TRUE,
    ));
    $lookupResponse = curl_exec($chLookup);
    curl_close($chLookup);
    // END HACK :)

    // Alright, now continue with the POST submission
    $jsonContent = json_encode($query);

    $ch = curl_init($this->submission_url);
    curl_setopt_array($ch, array(
      CURLOPT_HTTPHEADER => array('Content-Type: application/json'),
      CURLOPT_POST => TRUE,
      CURLOPT_POSTFIELDS => $jsonContent,
      CURLOPT_RETURNTRANSFER => TRUE,
    ));
    $response = curl_exec($ch);
    curl_close($ch);
  }

  /**
   * PUT submission. Will use the uid_lookup_url to find the post ID of the
   * submission to update.
   *
   * @param $query Array of the content to PUT
   * @param $uid UID of the user to look for previous submissions with
   */
  private function submitPut($query, $uid) {
    // GET the post id using the user's uid
    $lookupUrl = $this->uid_lookup_url . "&uid=$uid";
    $chLookup = curl_init($lookupUrl);
    curl_setopt_array($chLookup, array(
      CURLOPT_HTTPHEADER => array('Content-Type: application/json'),
      CURLOPT_RETURNTRANSFER => TRUE,
    ));
    $lookupResponse = curl_exec($chLookup);
    curl_close($chLookup);

    // If submissions are found, then continue with the PUT
    $submissions = json_decode($lookupResponse);
    if (count($submissions) > 0) {
      // @todo Is just using the first submission in the array a safe assumption to make?
      $sub = $submissions[0];
      $postId = $sub->id;
      $this->submission_url = str_replace('@postId', $postId, $this->submission_url);

      // Update the post with the found post id
      $jsonContent = json_encode($query);
      $ch = curl_init($this->submission_url);
      curl_setopt_array($ch, array(
        CURLOPT_CUSTOMREQUEST => 'PUT',
        CURLOPT_HTTPHEADER => array('Content-Type: application/json'),
        CURLOPT_POSTFIELDS => $jsonContent,
        CURLOPT_RETURNTRANSFER => TRUE,
      ));
      $response = curl_exec($ch);
      curl_close($ch);
    }    
  }
}