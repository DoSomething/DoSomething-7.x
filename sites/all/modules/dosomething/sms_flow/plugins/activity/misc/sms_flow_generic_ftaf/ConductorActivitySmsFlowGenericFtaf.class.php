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

  // Nested array of FTAF data. mdata_id is used to determine which FTAF data to use.
  // array(
  //   array(
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

    // If the parent workflow was triggered by a known mdata_id, get values from the $fatf_set array instead
    $mdata_id = intval($_REQUEST['mdata_id']);
    if ($mdata_id > 0) {
      foreach ($this->ftaf_sets as $ftaf_set) {
        if ($ftaf_set['mdata_id'] == $mdata_id) {

          $this->alpha_optin = !empty($ftaf_set['alpha_optin']) ? $ftaf_set['alpha_optin'] : 0;
          $this->beta_optin = !empty($ftaf_set['beta_optin']) ? $ftaf_set['beta_optin'] : 0;
          $this->id_override = $ftaf_set['id_override'];
          $this->response_success = $ftaf_set['response_success'];
          $this->response_error = $ftaf_set['response_error'];
          $this->type_override = $ftaf_set['type_override'];
          break;
        }
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
      $state->setContext('sms_response', $sms_response);
    }
    $state->markCompleted();
  }

}

