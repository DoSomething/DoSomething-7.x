<?php

/**
 * Conductory activity that mimics Forward-to-a-Friend functionality. Property
 * values can either be set by a previous activity, or explicitly when the
 * activity is created.
 */
class ConductorActivitySmsFlowGenericFtaf extends ConductorActivity {

  // Mobile Commons opt-in path that Alpha inviters are sent into after the FTAF
  protected $alpha_optin;

  // Mobile Commons opt-in path that the Betas are invited to
  public $beta_optin;

  // Number identifier of an invite sent for a particular campaign, sms game, etc
  public $id_override;

  // Response to send on an error
  public $response_error;

  // Response to send if FTAF is successful
  public $response_success;

  // Type of invite sent - particularly if it's for an sms_game or club
  public $type_override;

  // Nested array of FTAF data. mdata_id or opt_in_path_id are used to determine which FTAF data to use.
  // array(
  //   array(
  //     'opt_in_path_id' => number
  //     'mdata_id' => number,
  //     'alpha_optin',
  //     'beta_optin', etc...
  //   ), ...
  // )
  public $ftaf_sets;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $this->alpha_optin = empty($this->alpha_optin) ? $state->getContext('ftaf_alpha_optin') : $this->alpha_optin;
    $this->beta_optin = empty($this->beta_optin) ? $state->getContext('ftaf_beta_optin') : $this->beta_optin;
    $this->id_override = empty($this->id_override) ? $state->getContext('ftaf_id_override') : $this->id_override;
    $this->response_error = empty($this->response_error) ? $state->getContext('ftaf_response_error') : $this->response_error;
    $this->response_success = empty($this->response_success) ? $state->getContext('ftaf_response_success') : $this->response_success;
    $this->type_override = empty($this->type_override) ? $state->getContext('ftaf_type_override') : $this->type_override;

    // If the workflow was triggered by a known mdata_id or opt_in_path_id, get values from the $ftaf_set array instead
    $opt_in_path_id = intval($_REQUEST['opt_in_path_id']);
    $mdata_id = intval($_REQUEST['mdata_id']);
    if ($opt_in_path_id > 0 || $mdata_id > 0) {
      $selected_set = NULL;
      foreach ($this->ftaf_sets as $ftaf_set) {
        // Use this set if opt_in_path_id matches
        if (isset($ftaf_set['opt_in_path_id']) && $opt_in_path_id > 0 && $ftaf_set['opt_in_path_id'] == $opt_in_path_id) {
          $selected_set = $ftaf_set;
          break;
        }
        // Use the set with a mdata_id match unless an opt_in_path_id is matched later
        else if (isset($ftaf_set['mdata_id']) && $mdata_id > 0 && $ftaf_set['mdata_id'] == $mdata_id) {
          $selected_set = $ftaf_set;
        }
      }

      if ($selected_set) {
        $this->alpha_optin = !empty($selected_set['alpha_optin']) ? $selected_set['alpha_optin'] : 0;
        $this->beta_optin = !empty($selected_set['beta_optin']) ? $selected_set['beta_optin'] : 0;
        $this->id_override = $selected_set['id_override'];
        $this->response_success = $selected_set['response_success'];
        $this->response_error = $selected_set['response_error'];
        $this->type_override = $selected_set['type_override'];
      }
    }

    // If opt-in paths are arrays, randomly select one
    if (is_array($this->beta_optin)) {
      $selected_idx = rand(0, count($this->beta_optin) - 1);
      $this->beta_optin = $this->beta_optin[$selected_idx];
    }

    $ftaf_numbers_unvetted = $state->getContext('ftaf_prompt:message');

    $ftaf_numbers = array();
    // Matches phone numbers regardless of separators and delimiters
    preg_match_all('#(?:1)?(?<numbers>\d{3}\d{3}\d{4})#i', preg_replace('#[^0-9]#', '', $ftaf_numbers_unvetted), $numbers);
    if (!empty($numbers['numbers'])) {
      $ftaf_numbers = $numbers['numbers'];

      // Remove any items where the value equals the user's number
      $userNumKeys = array_keys($ftaf_numbers, $mobile);
      if (count($userNumKeys) > 0) {
        foreach ($userNumKeys as $key) {
          unset($ftaf_numbers[$key]);
        }

        // Re-index the array
        $ftaf_numbers = array_values($ftaf_numbers);
      }
    }

    if (count($ftaf_numbers) > 0) {

      $form['details']['nid'] = $this->id_override;
      $sms_flow_args = $state->getContext('ftaf_sms_flow_args');
      if ($sms_flow_args === FALSE) {
        $sms_flow_args = array();
      }

      sms_flow_start($mobile, $this->alpha_optin, $this->beta_optin, $ftaf_numbers, $form, $sms_flow_args, FALSE, $this->type_override);
      $sms_response = $this->response_success;
    }
    else {
      $sms_response = $this->response_error;
    }

    if (empty($sms_response)) {
      $state->setContext('ignore_no_response_error', TRUE);
    }
    else {
      if (is_numeric($sms_response)) {
        dosomething_general_mobile_commons_subscribe($mobile, $sms_response);
        $state->setContext('ignore_no_response_error', TRUE);
      }
      else {
        $state->setContext('sms_response', $sms_response);
      }
    }
    $state->markCompleted();
  }

}

