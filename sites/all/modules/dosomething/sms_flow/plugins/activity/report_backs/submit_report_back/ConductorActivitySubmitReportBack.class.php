<?php

/**
 * Takes data received during workflow and submits it to the specified webform.
 */
class ConductorActivitySubmitReportBack extends ConductorActivity {

  // Associative array of data inputs to submit in the report back
  public $submission_fields = array();

  // NID of the webform to submit to
  public $webform_nid;

  // Array of campaign IDs to opt the user out of
  public $campaign_opt_outs;

  // (Optional) Response to send to the user upon successful submission.
  // Use @submission_count to include the number of submissions from this user in the msg.
  public $success_response;

  // (Optional) Identifier to use different method of submittin a report back.
  // ex: 'hunt2013' does not submit to a webform
  public $use_special_submitter;

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $num_submissions = 0;
    $picture = $state->getContext($this->submission_fields['picture']);

    $user = sms_flow_get_or_create_user_by_cell($mobile);
    if ($user) {
      if ($this->use_special_submitter == 'hunt2013') {
        // TODO: Should consider changing the Hunt Report Back module since the
        // method we're calling here is implied to be private. Also might want
        // to consider making this sms_flow module dependent on the Hunt Report
        // Back module.
        $challenge = array(
          'day' => intval($this->submission_fields['challenge_day']),
          'people' => intval($state->getContext('ask_question1:message')),
          'response' => $state->getContext('ask_question2:message'),
          'uri' => $picture,
        );
        
        // Module still in dev. Catch should stop the user from seeing any fatal errors.
        try {
          _hunt_report_back_save_challenge($user->uid, $challenge);
        }
        catch (Exception $e) {
          watchdog('sms_flow', t('Caught exception in Hunt2013 report back submission for user %mobile - %exception', array('%mobile' => $mobile, '%exception' => $e->getMessage())));
        }
      }
      else {
        $submission = new stdClass;
        $submission->bundle = 'campaign_report_back';
        $submission->nid = $this->webform_nid;
        $submission->data = array();
        $submission->uid = $user->uid;
        $submission->submitted = REQUEST_TIME;
        $submission->remote_addr = ip_address();
        $submission->is_draft = FALSE;
        $submission->sid = NULL;

        $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);
        foreach($this->submission_fields as $key => $value) {
          // Handle any default values
          if ($key == 'defaults' && is_array($value)) {
            foreach($value as $default) {
              $defaultValue = $default[0];
              $defaultIndex = intval($default[1]);

              // Special handling for specific keywords
              if ($defaultValue == 'FIRST_NAME') {
                $defaultValue = NULL;
                if ($user->uid > 0) {
                  $profile = profile2_load_by_user($user, 'main');
                  $defaultValue = $profile->field_user_first_name[LANGUAGE_NONE][0]['value'];
                }
              }
              elseif ($defaultValue == 'LAST_NAME') {
                $defaultValue = NULL;
                if ($user->uid > 0) {
                  $profile = profile2_load_by_user($user, 'main');
                  $defaultValue = $profile->field_user_last_name[LANGUAGE_NONE][0]['value'];
                }
              }

              // Set data index to the given default value
              if ($defaultValue) {
                $wrapper->value()->data[$defaultIndex]['value'][0] = $defaultValue;
              }
            }
          }
          // Special handling needed for picture submission fields
          elseif ($key == 'picture') {
            if (!empty($picture)) {
              $f_name = 'public://' . basename($picture);
              $attach_contents = file_get_contents($picture);

              if ($attach_contents !== FALSE) {
                $attach_data = file_save_data($attach_contents, $f_name);

                if ($attach_data !== FALSE) {
                  $attach_array = get_object_vars($attach_data);
                  $wrapper->value()->field_webform_pictures[LANGUAGE_NONE][] = $attach_array;
                }
                else {
                  watchdog('sms_flow', t('Unable to save file data for %url and user %mobile', array('%url' => $picture, '%mobile' => $mobile)));
                }
              }
              else {
                watchdog('sms_flow', t('Unable to get contents from %url for user %mobile', array('%url' => $picture, '%mobile' => $mobile)));
              }
            }
          }
          // Get values to submit from the state's saved context values
          else {
            $data_index = intval($value);
            $wrapper->value()->data[$data_index]['value'][0] = $state->getContext($key . ':message');
          }
        }

        $wrapper->save();

        module_load_include('inc', 'webform', 'includes/webform.submissions');
        $num_submissions = webform_get_submission_count($this->webform_nid, $user->uid);
      }
    }

    // Send response to user about successful submission, if set. @submission_count returns the number of submissions this user has made.
    if (!empty($this->success_response)) {
      if (is_numeric($this->success_response)) {
        dosomething_general_mobile_commons_subscribe($mobile, $this->success_response);
        $state->setContext('ignore_no_response_error', TRUE);
      }
      else {
        $state->setContext('sms_response', t($this->success_response, array('@submission_count' => $num_submissions)));
      }
    }

    //  Opt users out of Mobile Commons campaigns, if set.
    if (!empty($this->campaign_opt_outs)) {
      sms_mobile_commons_campaign_opt_out($mobile, $this->campaign_opt_outs);
    }
    
    $state->markCompleted();
  }

}
