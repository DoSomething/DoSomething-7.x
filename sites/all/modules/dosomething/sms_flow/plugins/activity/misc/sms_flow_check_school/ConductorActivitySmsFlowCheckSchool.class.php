<?php

/**
 * Activity will check either the user's profile or search through webform submissions to find
 * the school associated for this user. Will update profile with school if it's found in the
 * webform submissions.
 *
 * @output no_school_found
 *    Next activity to go to if school wasn't found
 * @output school_found
 *    Next activity to go to if school is found
 * @context school_sid
 *    Set with the school's ID value if one is found
 */
class ConductorActivitySmsFlowCheckSchool extends ConductorActivity {

  // NID of the webform to check for user's school there. Used as backup if school's not found in profile.
  public $webform_nid_check = 0;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $school_found = FALSE;

    $account = dosomething_api_user_lookup($mobile);
    $profile = profile2_load_by_user($account, 'main');
    if (isset($profile->field_school_reference[LANGUAGE_NONE][0]['target_id'])) {
      // Use school set in profile if it exists.
      $school_sid = $profile->field_school_reference[LANGUAGE_NONE][0]['target_id'];
      $state->setContext('school_sid', $school_sid);
      $school_found = TRUE;
    }
    elseif ($account->uid > 0 && $this->webform_nid_check > 0) {
      // Otherwise, search webform submissions for user's school
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $submissions = webform_get_submissions(array('uid' => $account->uid, 'nid' => $this->webform_nid_check));

      if (count($submissions) > 0) {
        $sub = array_shift($submissions);
        $school_sid = $sub->field_webform_school_reference[LANGUAGE_NONE][0]['target_id'];
        if (intval($school_sid) > 0) {
          // Update user's profile with the school found in this submission
          if ($profile) {
            $profile->field_school_reference[LANGUAGE_NONE][0]['target_id'] = $school_sid;
            profile2_save($profile);
          }

          $state->setContext('school_sid', $school_sid);
          $school_found = TRUE;
        }
      }
    }
    
    if ($school_found) {
      $this->removeOutput('no_school_found');
    }
    else {
      $this->removeOutput('school_found');
    }

    $state->markCompleted();
  }

}

