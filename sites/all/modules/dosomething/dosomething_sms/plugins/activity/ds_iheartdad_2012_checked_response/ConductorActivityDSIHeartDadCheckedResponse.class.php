<?php

/**
 *
 */
class ConductorActivityDSIHeartDadCheckedResponse extends ConductorActivity {
  // nid of the webform to submit the zipcodes to
  // TODO: create webform and get actual NID
  const ZIPCODE_WEBFORM_NID = 123456;

  public function run() {
    $msg_not_tested = t('You still have time to take pressure off dad! Check dad\'s pressure at your local drug store. Txt CHECKED w/ a pic & his blood pressure #s. You could win a $4k scholarship!');
    // TODO: do we care about Hypotension? (90/60 or less)
    // Normal blood pressure (less than 120/80)
    $msg_normal = "Awesome, looks like his health is in tip top shape. Keep it that way! Check out our site for more tips on keeping dad healthy at iheartdad.org/FAQs";
    // Pre Hypertension (120-139/80-89)
    $msg_pre_hypertension = "Dad's pressure is a little high but no worries! Check out our guide on our website at iheartdad.org to find out what you can do iheartdad.org/FAQs";
    // Hypertension (140/90 and higher)
    $msg_hypertension = "Dad's pressure is on the rise but no worries! Have him schedule an appt with a trusted doc and check out our website with more tips on keeping dad healthy iheartdad.org/FAQs";
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

      // TODO: Submit zipcode and blood pressure responses to a webform
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