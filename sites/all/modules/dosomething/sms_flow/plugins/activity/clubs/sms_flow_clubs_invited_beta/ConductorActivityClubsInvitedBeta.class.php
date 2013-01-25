<?php

/**
 * Activity to process persons invited to a drive. Joins person into the
 * drive, and then sends a positive feedback sms to the person who invited them.
 * Also acts like an sms_prompt activity, suspending and waiting for a response before
 * before continuing on to the next activity.
 */
class ConductorActivityClubsInvitedBeta extends ConductorActivity {

  // Mobile Commons campaign id to place alpha user in when sending feedback message
  protected $alpha_campaign_id = 0;

  public function run($workflow) {
    $state = $this->getState();
    if ($state->getContext($this->name . ':message') === FALSE) {
      $success_message = '';
      $first_name = '';

      $name = $state->getContext('ask_name:message');

      // Only search based on final 10 numbers in mobile #. Ignores international code added by Mobile Commons.
      $mobile = $state->getContext('sms_number');

      // If we have a user with this mobile, update their info.
      $account = _sms_flow_find_user_by_cell($mobile);

      // Create account for this user if none is found
      if (!$account) {
        $account = new stdClass;

        $suffix = 0;
        $account->name = $name;
        while (user_load_by_name($account->name)) {
          $suffix++;
          $account->name = $name . '-' . $suffix;
        }

        $pass = strtoupper(user_password(6));
        require_once('includes/password.inc');
        $hashed_pass = user_hash_password($pass);
        $account->pass = $hashed_pass;
        $account->mail = $mobile . '@mobile';
        $account->status = 1;

        $account = user_save($account);

        $profile_values = array('type' => 'main');
        $profile = profile2_create($profile_values);
        $profile->uid = $account->uid;
        
        $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;
        $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $name;
        $first_name = $name;

        try {
          profile2_save($profile);
        }
        catch( Exception $e ) {
          $success_message .= t('Sorry, there was a problem creating your account.  To try again, text CJOIN.');
        }

        $success_message .= t('Login with this phone # & this password (@pass) at dosomething.org/myclub. ', array('@pass' => $pass));
      }
      else {
        $success_message .= t('Awesome! You\'ve been added to your friend\'s club at dosomething.org/myclub. ');
      }

      $profileUrl = 'https://secure.mcommons.com/api/profile?phone_number=' . $mobile;

      $ch = curl_init();
      curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
      curl_setopt($ch, CURLOPT_URL, $profileUrl);
      $xml = curl_exec($ch);
      curl_close();

      $pattern = '#\<custom_column name\="clubs_invite_gid"\>(.*?)\<\/custom_column\>#is';
      preg_match($pattern, $xml, $patternMatches);
      if (count($patternMatches) >= 2) {
        $clubs_invite_gid = trim($patternMatches[1]);

        // Join user into the drive
        if ($clubs_invite_gid > 0) {
          dosomething_clubs_add_user_by_email_or_cell($mobile, $clubs_invite_gid);
        }
      }

      // Send feedback message to Alpha
      $alphaMobile = sms_flow_find_alpha(substr($mobile, -10), $clubs_invite_gid);
      if ($alphaMobile) {
        if (empty($first_name)) {
          $profile = profile2_load_by_user($account, 'main');
          $first_name = $profile->field_user_first_name[LANGUAGE_NONE][0]['value'];
        }

        $alphaMsg = "Ur friend $first_name accepted your invite to join ur DoSomething club! Who else should be involved? Text back CINVITE and we'll invite them too.";
        $alphaOptions = array('campaign_id' => $this->alpha_campaign_id);
        $return = sms_mobile_commons_send($alphaMobile, $alphaMsg, $alphaOptions);
      }

      $success_message .= t('Who else should be involved? Respond with more phone #s and we\'ll invite them too');
      $state->setContext('sms_response', $success_message);
      $state->setContext('clubs_invite_gid', $clubs_invite_gid);

      $state->markSuspended();
    }
    else {
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
