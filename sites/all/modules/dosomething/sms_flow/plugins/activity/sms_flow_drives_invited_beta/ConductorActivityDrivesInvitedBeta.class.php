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

  // Message returned upon successful join into a club
  public $success_message = '';

  public function option_definition() {
    $options = parent::option_definition();
    $options['alpha_campaign_id'] = array('default' => '');
    $options['success_message'] = array('default' => '');
    return $options;
  }

  public function run($workflow) {
    $state = $this->getState();

    if ($state->getContext($this->name . ':message') === FALSE) {

      $name = $state->getContext('ask_name:message');

      // Only search based on final 10 numbers in mobile #. Ignores international code added by Mobile Commons.
      $mobile = $state->getContext('sms_number');

      // If we have a user with this mobile, update their info.
      // NOTE: find_user_by_cell() doesn't handle international codes when searching by profile's
      // field_user_mobile value. Only handles international code with an @mobile email address
      $account = dosomething_general_find_user_by_cell($mobile);
      if (!$account && strlen($mobile) > 10) {
        $mobile = substr($mobile, -10);
        $account = dosomething_general_find_user_by_cell($mobile);
      }

      // Create account for this user if none is found
      if (!$account) {
        $account = new stdClass;

        $suffix = 0;
        $account->name = $name;
        while (user_load_by_name($account->name)) {
          $suffix++;
          $account->name = $name . '-' . $suffix;
        }

        $pass = user_password(6);
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

        try {
          profile2_save($profile);
        }
        catch( Exception $e ) {
        }

        $this->success_message .= t('Ur password to login and view your drive at DoSomething.org/mytfjdrive is @pass. ', array('@pass' => $pass));
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

      $drives_invite_nid = 0;
      $pattern = '#\<custom_column name\="drives_invite_nid"\>(.*?)\<\/custom_column\>#is';
      preg_match($pattern, $xml, $patternMatches);
      if (count($patternMatches) >= 2) {
        $drives_invite_nid = trim($patternMatches[1]);

        // Get group id based on the nid and join user into that drive
        $gid = og_get_group('node', $drives_invite_nid)->gid;
        if ($gid > 0) {
          dosomething_drives_join($gid, $profile->uid);
        }
      }

      // Send feedback message to Alpha
      // TODO: safe to assume number put into sms_flow_records database doesn't have the international code?
      $alphaMobile = sms_flow_find_alpha(substr($mobile, -10), $drives_invite_nid);
      if ($alphaMobile) {
        $alphaMsg = "Good news! You invited $mobile and he/she joined your drive.";
        $alphaOptions = array('campaign_id' => $this->alpha_campaign_id);
        $return = sms_mobile_commons_send($alphaMobile, $alphaMsg, $alphaOptions);
      }

      $this->success_message .= t('Want to invite more friends? Reply back w/ their cell #s separated by commas and we\'ll send them an invite for u!');
      $state->setContext('sms_response', $this->success_message);
      $state->setContext('drives_invite_nid', $drives_invite_nid);

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
