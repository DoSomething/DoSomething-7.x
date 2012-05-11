<?php

/**
 * Activity to process and submit report back for the Epic 2012 workflow.
 */
class ConductorActivityDSCreateEpic2012ReportBack extends ConductorActivity {

  // nid of the webform node to associate report backs with
  const REPORT_BACK_NID = 719308;

  public function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Executed after user completes the workflow process. Create user
   * object and report back webform submission.
   */
  public function run() {
    $state = $this->getState();

    // Get values from the workflow
    $mobile = $state->getContext('sms_number');
    $school_id = $state->getContext('school_id');
    $books = $state->getContext('get_books:message');
    $volunteers = $state->getContext('get_volunteers:message');
    $donators = $state->getContext('get_donators:message');
    $first_name = $state->getContext('get_first_name:message');
    $last_name = $state->getContext('get_last_name:message');

    // If we have a user with this mobile, update their info.
    $account = dosomething_general_find_user_by_cell($mobile);

    // Otherwise, create a new account
    if (!$account) {
      $account = new stdClass;
      $account->name = $mobile;

      $suffix = 0;
      $base_name = $account->name;
      while (user_load_by_name($account->name)) {
        $suffix++;
        $account->name = $base_name . '-' . $suffix;
      }
      $account->mail = $mobile . '@mobile';
      $account->status = 1;
      user_save($account);
      $profile_values = array(
        'type' => 'main',
        'field_user_mobile' => array(
          LANGUAGE_NONE => array(
            'value' => $mobile,
          ),
        ),
      );
      $profile = profile2_create($profile_values);
      $profile->uid = $account->uid;
      // profile2_save() has been seen to fail on the local dev box. Not sure if
      // it will also fail when this code goes live. But just in case, we don't
      // want to kill the process prevent this data from being submitted.
      try {
        profile2_save($profile);
      }
      catch( Exception $e ) {
      }
    }

    // Build report-back submission
    $submission = new stdClass;
    $submission->bundle = 'campaign_report_back';
    $submission->nid = self::REPORT_BACK_NID;
    $submission->data = array();
    $submission->uid = $account->uid;
    $submission->submitted = REQUEST_TIME;
    $submission->remote_addr = ip_address();
    $submission->is_draft = FALSE;
    $submission->sid = NULL;

    $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);

    // Had to inspect the submissions posted to webform_entity_pages_webform_submission_page()
    // and that array's data array to figure out what variable is expected where
    $wrapper->value()->data[1]['value'][0] = $first_name;
    $wrapper->value()->data[2]['value'][0] = $last_name;
    $wrapper->value()->data[3]['value'][0] = $books;
    $wrapper->value()->data[6]['value'][0] = $volunteers;
    $wrapper->value()->data[4]['value'][0] = $donators;

    if (!empty($school_id)) {
      $school_id_state = self::getStateFromID($school_id);
      $school_id_num = self::getNumFromID($school_id);

      // DB query to ds_school table to find matching sid to submit to webform
      $unique_sid = db_query('SELECT sid FROM {ds_school} WHERE school_id = :schoolID AND state = :state', array(':schoolID' => $school_id_num, ':state' => $school_id_state))->fetchField();

      if (!empty($unique_sid)) { 
        // School ID is submitted differently since it's an entity field ... or something
        $wrapper->field_webform_school_reference->set($unique_sid);
      }
    }

    // Final message
    $state->setContext('sms_response', t('Thanks for participating in the Epic Book Drive! You\'re now eligible to win more awesome stuff!'));

    $wrapper->save();

    $state->markCompeted();
  }

  /**
   * Takes the school ID from mCommons and returns the state
   * @param $school_id the school ID retrieved for this user from mCommons
   * @return Two-letter state abbreviation from the ID
   */
  private function getStateFromID($school_id) {
    // First two characters should be the state
    $school_id = trim($school_id);
    return substr($school_id, 0, 2);
  }

  /**
   * Takes the school ID from mCommons and returns the numeric school id
   * @param $school_id the school ID retrieved for this user from mCommons
   * @return Basically the school ID with the state trimmed off that can be 
   *  matched up with school_id in the ds_school table
   */
  private function getNumFromID($school_id) {
    // Numbers after the first two characters will be the school_id
    $school_id = trim($school_id);
    return substr($school_id, 2);
  }
}
