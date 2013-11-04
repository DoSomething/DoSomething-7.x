<?php

/**
 * Submits a campaign sign up.
 */
class ConductorActivitySmsFlowSignupSubmit extends ConductorActivity {

  /**
   * Node ID of the campaign being signed up for.
   * @var int
   */
  public $nid;

  /**
   * Key/Value pair defining where data retrieved through the workflow should get 
   * submitted. Key is a field name in the sign up form, and Value is a context
   * name to get the corresponding data from.
   * @var array
   */
  public $submission_fields;

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $user = sms_flow_get_or_create_user_by_cell($mobile);
    if ($user && isset($this->nid)) {

      // Build the array of data to submit with this sign up
      $signup_data = array();
      foreach ($this->submission_fields as $fieldName => $contextKey) {
        $signup_data[$fieldName] = $state->getContext($contextKey);
      }

      // Submit the sign up
      dosomething_signups_insert_signup($user->uid, $this->nid, $signup_data);
    }

    $state->markCompleted();
  }

}