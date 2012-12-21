<?php

/**
 * Activity to process persons invited to a drive. Joins person into the
 * drive, and then sends a positive feedback sms to the person who invited them.
 * Also acts like an sms_prompt activity, suspending and waiting for a response before
 * before continuing on to the next activity.
 */
class ConductorActivityDrivesInvitedBeta extends ConductorActivity {

  // Mobile Commons campaign id to place alpha user in when sending feedback message
  public $alpha_campaign_id = 0;

  public function option_definition() {
    $options = parent::option_definition();
    $options['alpha_campaign_id'] = array('default' => '');
    return $options;
  }

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $jeans_goal = $state->getContext($this->name . ':message');
    if ($jeans_goal === FALSE) {
      $success_message = '';

      $profileUrl = 'https://secure.mcommons.com/api/profile?phone_number=' . $mobile;

      $ch = curl_init();
      curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
      curl_setopt($ch, CURLOPT_URL, $profileUrl);
      $xml = curl_exec($ch);
      curl_close();

      $account = _sms_flow_find_user_by_cell($mobile);

      $drives_invite_gid = 0;
      $pattern = '#\<custom_column name\="drives_invite_gid"\>(.*?)\<\/custom_column\>#is';
      preg_match($pattern, $xml, $patternMatches);
      if (count($patternMatches) >= 2) {
        $drives_invite_gid = trim($patternMatches[1]);

        // Join user into the drive
        if ($drives_invite_gid > 0) {
          // Set $redirect param to FALSE so it doesn't try to redirect to a webpage
          dosomething_drives_join($drives_invite_gid, $account->uid, FALSE);
        }
      }

      // Send feedback message to Alpha
      $alphaMobile = sms_flow_find_alpha(substr($mobile, -10), $drives_invite_gid);
      if ($alphaMobile) {
        $profile = profile2_load_by_user($account, 'main');
        $first_name = $profile->field_user_first_name[LANGUAGE_NONE][0]['value'];

        $alphaMsg = "Ur friend $first_name accepted your invite to join ur DoSomething Teens for Jeans team! Who else should be involved? Text back TFJINVITE and we'll invite them too.";
        $alphaOptions = array('campaign_id' => $this->alpha_campaign_id);
        $return = sms_mobile_commons_send($alphaMobile, $alphaMsg, $alphaOptions);
      }

      $password = $state->getContext('new_account_password');

      // The new_account_password value is set by sms_flow_create_account activity. If none
      // found, assume that no new account was created.
      if (empty($password)) {
        $link_message = t('View ur drive at http://doso.me/2');
      }
      else {
        $link_message = t('Ur pword to login at http://doso.me/2 is @pass ', array('@pass' => $password));
      }

      $success_message = "You\'ve joined the largest youth led clothing drive in the US! $link_message- What's ur goal for how many jeans you'll collect?";

      $state->setContext('sms_response', $success_message);
      $state->setContext('drives_invite_gid', $drives_invite_gid);

      $state->markSuspended();
    }
    else {
      // Update Mobile Commons profile with TFJ goals
      $url = "https://secure.mcommons.com/api/profile_update";

      $fields = array(
        'phone_number' => urlencode($mobile),
        'TeensforJeans2013_Goals' => urlencode($jeans_goal),
      );

      $fields_query = http_build_query($fields);

      $ch = curl_init();
      curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
      curl_setopt($ch, CURLOPT_URL, $url);
      curl_setopt($ch, CURLOPT_POST, count($fields));
      curl_setopt($ch, CURLOPT_POSTFIELDS, $fields_query);
      $updateResult = curl_exec($ch);

      curl_close($ch);

      $state->markCompleted();
    }
  }

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers() {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }

}
