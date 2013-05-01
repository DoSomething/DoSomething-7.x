<?php

/**
 *
 */
class ConductorActivityBetaReportBack extends ConductorActivity {

  const REPORT_BACK_NID = 727418;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $trash_pickup = $state->getContext('ask_trash_pickup:message');
    $people_involved = $state->getContext('ask_people_involved:message');
    $zip = $state->getContext('ask_zip:message');
    $picture = $state->getContext('ask_picture:mms');

    // Get or create user's account
    $account = dosomething_api_user_lookup($mobile);
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

      $account = user_save($account);

      $profile_values = array('type' => 'main');
      $profile = profile2_create($profile_values);
      $profile->uid = $account->uid;
      $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;

      try {
        profile2_save($profile);
      }
      catch( Exception $e ) {}
    }

    // Build report back submission and submit
    $submission = new stdClass;
    $submission->bundle = 'campaign_report_back';
    $submission->nid = self::REPORT_BACK_NID;
    $submission->data = array();
    $submission->uid = $account->uid;
    $submission->submitted = REQUEST_TIME;
    $submission->remote_addr = ip_address();
    $submission->is_draft = FALSE;
    $submission->sid = NULL;

    // Save user responses to 
    $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);
    $wrapper->value()->data[4]['value'][0] = $zip;
    $wrapper->value()->data[5]['value'][0] = $trash_pickup;
    $wrapper->value()->data[6]['value'][0] = $people_involved;

    // Download and save image
    if (!empty($picture)) {
      $f_name = 'public://' . basename($picture);
      $attach_contents = file_get_contents($picture);
      $attach_data = file_save_data($attach_contents, $f_name);
      $attach_array = get_object_vars($attach_data);
      $wrapper->value()->field_webform_pictures[LANGUAGE_NONE][] = $attach_array;
    }

    $wrapper->save();
    
    $state->setContext('sms_response', 'Thanks for your report back!');
    $state->markCompleted();
  }

}