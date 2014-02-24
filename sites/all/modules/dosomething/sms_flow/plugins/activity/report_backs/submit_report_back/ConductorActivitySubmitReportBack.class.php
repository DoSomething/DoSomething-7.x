<?php

/**
 * Takes data received during workflow and submits it to the specified webform.
 */
class ConductorActivitySubmitReportBack extends ConductorActivity {

  /**
   * Associative array of data inputs to submit in the report back.
   *
   * @var array
   */
  public $submission_fields = array();

  /**
   * NID of the webform to submit to.
   *
   * @var int
   */
  public $webform_nid;

  /**
   * Campaign IDs to opt the user out of.
   *
   * @var array
   */
  public $campaign_opt_outs;

  /**
   * (optional) Response to send to the user upon successful submission.
   * Use @submission_count to include the number of submissions from this user
   * in the msg.
   *
   * @var string
   */
  public $success_response;

  /**
   * The Mobile Commons campaign ID of the $success_response opt-in path. This
   * needs to be set in order to update the user's MCommons profile that helps
   * indicate whether or not this is the first campaign a user's finished or not.
   *
   * @var int
   */
  public $success_response_mcommons_campaign_id;

  /**
   * (optional) Åctivity name to pull value from and insert into $success_response.
   * Use @field_value to include this value into the success message.
   *
   * @var string
   */
  public $field_value_in_response;

  /**
   * (optional) Identifier to use different method of submitting a report back.
   * ex: 'hunt2013' does not submit to a webform
   *
   * @var string
   */
  public $use_special_submitter;

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $num_submissions = 0;
    $picture = $state->getContext($this->submission_fields['picture']);

    $user = sms_flow_get_or_create_user_by_cell($mobile);
    if ($user) {
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

      // Handling for special case - Mind on My Money 2013.
      // This should be removed once it's no longer relevant.
      if ($this->use_special_submitter == 'momm2013') {
        $mdataId = intval($_REQUEST['mdata_id']);

        // Submit which session the attendee went to, and get the index to submit
        // the MoMM session-specific question to based on the mData ID.
        $cidSession = 29;
        $cidMommQuestion = 0;
        if ($mdataId == 201) {
          $wrapper->value()->data[$cidSession]['value'][0] = "Life In Plastic: Credit";

          // Component ID for the field to the credit-specific question
          $cidMommQuestion = 33;
        }
        elseif ($mdataId == 311) {
          $wrapper->value()->data[$cidSession]['value'][0] = "99 Payments: College Loans";

          // Component ID for the field to the loans-specific question
          $cidMommQuestion = 32;
        }
        elseif ($mdataId == 9241) {
          $wrapper->value()->data[$cidSession]['value'][0] = "Check Yourself: Budgeting";

          // Component ID for the field to the savings-specific question
          $cidMommQuestion = 31;
        }

        // Save answer to MoMM session-specific question
        $mommAnswer = $state->getContext('ask_momm2013_question:message');
        $wrapper->value()->data[$cidMommQuestion]['value'][0] = $mommAnswer;
      }

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
                if (!empty($profile->field_user_first_name)) {
                  $defaultValue = $profile->field_user_first_name[LANGUAGE_NONE][0]['value'];
                }
              }
            }
            elseif ($defaultValue == 'LAST_NAME') {
              $defaultValue = NULL;
              if ($user->uid > 0) {
                $profile = profile2_load_by_user($user, 'main');
                if (!empty($profile->field_user_last_name)) {
                  $defaultValue = $profile->field_user_last_name[LANGUAGE_NONE][0]['value'];
                }
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
            $file_contents = file_get_contents($picture);

            if ($file_contents !== FALSE) {
              $file_data = file_save_data($file_contents, $f_name);

              if ($file_data !== FALSE) {
                $file_data->uid = $user->uid;
                file_save($file_data);
                $attach_array = get_object_vars($file_data);
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

      // Only attempt to save the submission if webform node id is valid.
      if ($this->webform_nid > 0) {
        $wrapper->save();

        module_load_include('inc', 'webform', 'includes/webform.submissions');
        $num_submissions = webform_get_submission_count($this->webform_nid, $user->uid);
      }
    }

    // Send response to user about successful submission, if set. @submission_count returns the number of submissions this user has made.
    if (!empty($this->success_response)) {
      if (is_numeric($this->success_response)) {
        // Set the first_completed_campaign_id field with this campaign if there is none set yet.
        $args = array();
        if (empty($_REQUEST['profile_first_completed_campaign_id'])) {
          $args = array('first_completed_campaign_id' => $this->success_response_mcommons_campaign_id);
        }

        // Update user's profile and send a response via subscribing to an opt-in path.
        dosomething_general_mobile_commons_subscribe($mobile, $this->success_response, $args);

        $state->setContext('ignore_no_response_error', TRUE);
      }
      else {
        $fieldValue = $state->getContext($this->field_value_in_response . ':message');
        $state->setContext('sms_response', t($this->success_response, array('@submission_count' => $num_submissions, '@field_value' => $fieldValue)));
      }
    }

    // Opt users out of Mobile Commons campaigns, if set.
    if (!empty($this->campaign_opt_outs)) {
      sms_mobile_commons_campaign_opt_out($mobile, $this->campaign_opt_outs);
    }

    $state->markCompleted();
  }

}
