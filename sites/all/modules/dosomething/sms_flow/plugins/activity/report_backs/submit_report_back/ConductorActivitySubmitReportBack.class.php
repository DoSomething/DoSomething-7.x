<?php

/**
 * Takes data received during workflow and submits it to the specified webform.
 */
class ConductorActivitySubmitReportBack extends ConductorActivity {

  // Associative array of data inputs to submit in the report back
  public $submission_fields = array();

  // NID of the webform to submit to
  public $webform_nid;

  // Response to send to the user upon successful submission.
  // Use @submission_count to include the number of submissions from this user in the msg.
  public $success_response;

  public function run($workflow) {
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
      foreach($this->submission_fields as $key => $value) {
        if ($key == 'picture') {
          if (!empty($picture)) {
            $f_name = 'public://' . basename($picture);
            $attach_contents = file_get_contents($picture);
            $attach_data = file_save_data($attach_contents, $f_name);
            $attach_array = get_object_vars($attach_data);
            $wrapper->value()->field_webform_pictures[LANGUAGE_NONE][] = $attach_array;
          }
        }
        else {
          $data_index = intval($value);
          $wrapper->value()->data[$data_index]['value'][0] = $state->getContext($key . ':message');
        }
      }

      $wrapper->save();

      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $num_submissions = webform_get_submission_count($this->webform_nid, $user->uid);
    }

    $state->setContext('sms_response', t($this->success_response, array('@submission_count' => $num_submissions)));
    $state->markCompleted();
  }

}
