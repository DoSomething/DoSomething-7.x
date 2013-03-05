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

  // Message sent back to the alpha inviter. If @name is set, will use the beta's first name.
  public $alpha_message = '';

  // URL to the drive page
  public $drive_link = '';

  // Message returned to user on success
  public $success_message = '';

  // Name of the Mobile Commons custom field to update with the user's response to the invitation confirmation
  public $mcommons_update_field = '';

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $user_response = $state->getContext($this->name . ':message');
    if ($user_response === FALSE) {
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

        $alphaMsg = t($this->alpha_message, array('@name' => $first_name));
        $alphaOptions = array('campaign_id' => $this->alpha_campaign_id);
        $return = sms_mobile_commons_send($alphaMobile, $alphaMsg, $alphaOptions);
      }

      $password = $state->getContext('new_account_password');

      // The new_account_password value is set by sms_flow_create_account activity. If none
      // found, assume that no new account was created.
      if (empty($password)) {
        $link_message = t('View ur team at @link.', array('@link' => $this->drive_link));
      }
      else {
        $link_message = t('Ur pword to login at @link is @pass.', array('@link' => $this->drive_link, '@pass' => $password));
      }

      $this->success_message = $link_message . ' ' . $this->success_message;

      $state->setContext('sms_response', $this->success_message);
      $state->setContext('drives_invite_gid', $drives_invite_gid);

      $state->markSuspended();
    }
    else {
      if (!empty($this->mcommons_update_field)) {
        // Update Mobile Commons profile with drive goals
        $url = "https://secure.mcommons.com/api/profile_update";

        $fields = array(
          'phone_number' => urlencode($mobile),
          $this->mcommons_update_field => urlencode($user_response),
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
      }
      // if no mcommons field specified, then expect phone #s for a FTAF
      else {
        $state->setContext('ftaf_prompt:message', $user_response);
      }

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