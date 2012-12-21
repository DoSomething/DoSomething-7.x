<?php

/**
 * Determine if account exists for this mobile number. Adjust output depending 
 * on existence or absence of account.
 */
class ConductorActivityCreateDrive extends ConductorActivity {
  
    // nid of the webform node to associate report backs with
  const REPORT_BACK_NID = 725896;

  public function run($workflow) {
    
    $state = $this->getState();
    $school_id = $state->getContext('school_sid');
    $mobile = $state->getContext('sms_number');

    $account = _sms_flow_find_user_by_cell($mobile);
    
        // Build report-back submission
    $submission = new stdClass;
    
    // Ask Chris what the bundle should be?
    $submission->bundle = 'campaign_report_back';
    
    $submission->nid = self::REPORT_BACK_NID;
    $submission->data = array();
    $submission->uid = $account->uid;
    $submission->submitted = REQUEST_TIME;
    $submission->remote_addr = ip_address();
    $submission->is_draft = FALSE;
    $submission->sid = NULL;

    $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);

    // Add value based on user response
    $wrapper->field_webform_school_reference->set($school_id);
    
    $wrapper->save();

    $state->markCompleted();
  }

}