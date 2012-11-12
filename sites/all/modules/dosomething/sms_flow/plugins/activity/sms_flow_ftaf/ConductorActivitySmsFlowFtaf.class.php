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
    
    $drives_invite_gid = $state->getContext('drives_invite_gid');
    if (empty($drives_invite_gid)) {
      // If no drives_invite_gid has been set, get the value from Mobile Commons profile
      $profileUrl = 'https://secure.mcommons.com/api/profile?phone_number=' . $mobile;

      $ch = curl_init();
      curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
      curl_setopt($ch, CURLOPT_URL, $profileUrl);
      $xml = curl_exec($ch);
      curl_close();

      $pattern = '#\<custom_column name\="drives_invite_gid"\>(.*?)\<\/custom_column\>#is';
      preg_match($pattern, $xml, $patternMatches);
      if (count($patternMatches) >= 2) {
        $drives_invite_gid = trim($patternMatches[1]);
      }
    }

    // NOTE: This feels hacky. Depending on what workflow this sms_flow_ftaf
    // activity is in, we look for the numbers from different activities.
    $message = $state->getContext('process_beta:message');
    if (empty($message)) {
      $message = $state->getContext('ftaf_prompt:message');
    }

    $numbers = explode(',', $message);

    $vetted_numbers = array();
    foreach ($numbers as $number) {
      // TODO: may also want to explode by spaces if people separated numbers by spaces instead of commas
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

      $account = _sms_flow_find_user_by_cell($mobile);

      if ($account) {
        $profile = profile2_load_by_user($account);
        if (isset($profile['main'])) {
          $inviter_name = $profile['main']->field_user_first_name[LANGUAGE_NONE][0]['value'];

          if (empty($inviter_name)) {
            $inviter_name = $mobile;
          }
        }
      }

      $args = array(
        'tfj2013_inviter' => $inviter_name,
        'drives_invite_gid' => $drives_invite_gid,
      );

      $f['details']['nid'] = $drives_invite_gid;
      sms_flow_start($mobile, $this->alpha_optin, $this->beta_optin, $vetted_numbers, $f, $args, FALSE);
      
      $response = $this->response_success;
    }

    $state->setContext('sms_response', $response);
    $state->markCompleted();
  }
}

