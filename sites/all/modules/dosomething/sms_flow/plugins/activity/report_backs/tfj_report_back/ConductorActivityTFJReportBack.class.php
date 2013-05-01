<?php

/**
 * Submit to the Teens for Jeans report back webform.
 */
class ConductorActivityTFJReportBack extends ConductorActivity {

  // NID of the webform to submit to
  public $webform_nid = 0;

  // Mobile Commons opt-in path to send to users when report back succeeds
  public $completion_opt_in;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $num_jeans = $state->getContext('ask_jeans:message');
    $num_people = $state->getContext('ask_people:message');
    $mms_url = $state->getContext('ask_photo:mms');
    $school_sid = $state->getContext('school_sid');

    // Get or create a user account by the user's cell phone number
    $profile_changed = FALSE;
    $account = dosomething_api_user_lookup($mobile);
    if (!$account) {
      $account = new stdClass;
      $account->name = $mobile;

      $suffix = 0;
      $base_name = $account->name;
      while (user_load_by_name($acount->name)) {
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
      $profile_changed = TRUE;
    }

    // Use account to load the profile, if profile's not yet loaded
    if (!$profile && $account) {
      $profile = profile2_load_by_user($account, 'main');
    }

    // Set school reference to the user's profile if it's not already set
    if ($profile && !isset($profile->field_school_reference[LANGUAGE_NONE][0]['target_id'])) {
      $profile->field_school_reference[LANGUAGE_NONE][0]['target_id'] = $school_sid;
      $profile_changed = TRUE;
    }

    // Save any profile changes
    if ($profile_changed) {
      try {
        profile2_save($profile);
      }
      catch( Exception $e ) {}
    }

    try {
        // Build report back submission and submit
        $submission = new stdClass;
        $submission->bundle = 'campaign_report_back';
        $submission->nid = $this->webform_nid;
        $submission->data = array();
        $submission->uid = $account->uid;
        $submission->submitted = REQUEST_TIME;
        $submission->remote_addr = ip_address();
        $submission->is_draft = FALSE;
        $submission->sid = NULL;

        // Save user responses to 
        $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);
        $wrapper->value()->data[1]['value'][0] = $num_jeans;
        $wrapper->value()->data[2]['value'][0] = $num_people;

        // Download and save image
        if (!empty($mms_url)) {
          $f_name = 'public://' . basename($mms_url);
          $attach_contents = file_get_contents($mms_url);
          if ($attach_contents !== FALSE) {
            $attach_data = file_save_data($attach_contents, $f_name);
            $attach_array = get_object_vars($attach_data);
            $wrapper->value()->field_webform_pictures[LANGUAGE_NONE][] = $attach_array;
          }
          else {
            watchdog('sms_flow', t('Unable to get contents from %url for user %mobile', array('%url' => $mms_url, '%mobile' => $mobile)));
          }
        }

        $wrapper->save();
    } 
    catch(Exception $e) {}

    // Send user to MC opt-in path to complete workflow
    dosomething_general_mobile_commons_subscribe($mobile, $this->completion_opt_in);
    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }

}
