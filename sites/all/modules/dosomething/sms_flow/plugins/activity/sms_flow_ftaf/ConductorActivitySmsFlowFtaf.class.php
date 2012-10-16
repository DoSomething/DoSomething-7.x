<?php

/**
 * Process phone numbers and forward invites on to users using sms_flow_start()
 */
class ConductorActivitySmsFlowFtaf extends ConductorActivity {

  // Mobile Commons optin path for inviter to be joined into
  public $alpha_optin = 0;

  // Mobile Commons optin path for the invitee to be joined into
  public $beta_optin = 0;

  // Response sent to inviter if process succeeds
  public $response_success = '';

  // Response sent to inviter if process fails
  public $response_fail = '';

  public function option_definition() {
    $options = parent::option_definition();
    $options['alpha_optin'] = array('default' => 0);
    $options['beta_optin'] = array('default' => 0);
    $options['response_success'] = array('default' => '');
    $options['response_fail'] = array('default' => '');

    return $options;
  }
  
  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $message = $state->getContext('process_beta:message');

    $numbers = explode(',', $message);

    $vetted_numbers = array();
    foreach ($numbers as $number) {
      $number = trim($number);
      $number = preg_replace("/[^0-9]/", "", $number);

      if (dosomething_general_valid_cell($number)) {
        $vetted_numbers[] = $number;
      }
      else {
        continue;
      }
    }

    $response = $this->response_fail;
    if (count($vetted_numbers) > 0) {
      
      $inviter_name = '';
      $account = dosomething_general_find_user_by_cell($mobile);
      if ($account) {
        $profile = profile2_load_by_user($account);
        if (isset($profile['main'])) {
          $inviter_name = $profile['main']->field_user_first_name[LANGUAGE_NONE][0]['value'];
        }
      }

      if (!empty($inviter_name)) {
        $args = array(
          'tfj2013_inviter' => $inviter_name,
        );
        // TODO: are there other form values and args that need to be passed in?
        sms_flow_start($mobile, $this->alpha_optin, $this->beta_optin, $vetted_numbers, FALSE, $args, FALSE);
      }
      
      $response = $this->response_success;
    }

    $state->setContext('sms_response', $response);
    $state->markCompleted();
  }
}

