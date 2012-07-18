<?php

/**
 * Activity takes blood pressure and zip code from previous activities in the
 * flow, submits that data to a webform, and sends different responses to the
 * user depending on the blood pressure numbers.
 */
class ConductorActivityDSIHeartDadCheckedResponse extends ConductorActivity {
  // nid of the webform to submit the zipcodes to
  const ZIPCODE_WEBFORM_NID = 722458;

  public function run() {
    $msg_not_tested = t('U still have time to take pressure off dad! Check dad\'s pressure @ ur local drug store. Txt CHECKED w/ ur zip & his blood pressure #s to win $4k!');
    // TODO: do we care about Hypotension? (90/60 or less)
    // Normal blood pressure (less than 120/80)
    $msg_normal = "Awesome, looks like his health is in tip top shape. Keep it that way! Check out our site for more tips on keeping dad healthy at iheartdad.org/FAQs";
    // Pre Hypertension (120-139/80-89)
    $msg_pre_hypertension = "Dad’s pressure is a little high but no worries! Check out our guide on our website at iheartdad.org/FAQs for tips on keeping dad's pressure low";
    // Hypertension (140/90 and higher)
    $msg_hypertension = "Dad’s pressure is on the rise but no worries! Have him schedule an appt w/a trusted doc & check out iheartdad.org/FAQs for tips on keeping dad healthy";
    // Error
    $msg_error = "That's not a blood pressure";

    // Default to msg_not_tested
    $msg_response = $msg_not_tested;

    $state = $this->getState();

    $tested_val = $state->getContext('ask_tested:message');
    $tested_val = strtolower($tested_val);
    $success_vals = array(
      'y',
      'yes',
      'yea',
      'ya'
    );
    
    $bTested = FALSE;
    foreach ($success_vals as $success_val) {
      // Only matching against the beginning of the string
      $pos = strpos($tested_val, $success_val);
      if ($pos === 0) {
        $bTested = TRUE;
      }
    }

    // Blood pressure did get tested
    if ($bTested) {
      $zip_msg = $state->getContext('ask_zipcode:message');
      $bp_msg = $state->getContext('ask_pressure:message');

      $bp_words = explode(' ', $bp_msg);
      $bp_first_word = array_shift($bp_words);

      $bp_args = explode('/', $bp_first_word);
      $systolic_num = $bp_args[0];
      $diastolic_num = $bp_args[1];

      // Get response for the blood pressure values submitted
      if (empty($systolic_num) || empty($diastolic_num)) {
        $msg_response = $msg_error;
      }
      else {
        // Hypertension
        if ($systolic_num >= 140 || $diastolic_num >= 90) {
          $msg_response = $msg_hypertension;
        }
        // Pre Hypertension
        elseif (($systolic_num >= 120 && $systolic_num < 140) || ($diastolic_num >= 80 && $diastolic_num < 90)) {
          $msg_response = $msg_pre_hypertension;
        }
        // Normal blood pressure
        else {
          $msg_response = $msg_normal;
        }
      }

      // If we have a user with this mobile #, use their existing account
      $mobile = $state->getContext('sms_number');
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

        try {
          profile2_save($profile);
        }
        catch (Exception $e) {
        }
      }

      // Submit zipcode and blood pressure responses to a webform
      $submission = new stdClass;
      $submission->nid = self::ZIPCODE_WEBFORM_NID;
      $submission->data = array();
      $submission->uid = $account->uid;
      $submission->submitted = REQUEST_TIME;
      $submission->remote_addr = ip_address();
      $submission->is_draft = FALSE;
      $submission->sid = NULL;

      $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);
      $wrapper->value()->data[1]['value'][0] = $zip_msg;
      $wrapper->value()->data[2]['value'][0] = $bp_msg;

      $wrapper->save();
    }
    // Blood pressure did NOT get tested
    else {
      $msg_response = $msg_not_tested;
    }

    // Set response message
    $state->setContext('sms_response', $msg_response);

    // End activity
    $state->markCompeted();
  }
}