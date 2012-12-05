<?php

/**
 * Process phone numbers and forward invites on to users using sms_flow_start()
 */
class ConductorActivitySmsFlowClubsFtaf extends ConductorActivity {

  // Mobile Commons optin path for inviter to be joined into
  public $alpha_optin = 0;

  // Mobile Commons optin path for the invitee to be joined into
  public $beta_optin = 0;

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

    $clubs_invite_gid = $state->getContext('clubs_invite_gid');
    if (empty($clubs_invite_gid)) {
      // TODO: create a generic function to access the profile from the mCommons api. Also
      // will want to use config variables stored in sms_mobile_commons_email and
      // sms_mobile_commons_password instead of hardcoding them into our curl calls.
      // If no clubs_invite_gid has been set, get the value from Mobile Commons profile
      $profileUrl = 'https://secure.mcommons.com/api/profile?phone_number=' . $mobile;

      $ch = curl_init();
      curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
      curl_setopt($ch, CURLOPT_URL, $profileUrl);
      $xml = curl_exec($ch);
      curl_close();

      $clubs_invite_gid = 0;
      $pattern = '#\<custom_column name\="clubs_invite_gid"\>(.*?)\<\/custom_column\>#is';
      preg_match($pattern, $xml, $patternMatches);
      if (count($patternMatches) >= 2) {
        $clubs_invite_gid = trim($patternMatches[1]);
      }
    }

    // NOTE: This feels hacky. Depending on what workflow this sms_flow_ftaf
    // activity is in, we look for the numbers from different activities.
    // TODO: What we could do instead is set a context variable in a previous activity
    // that contains the name of the activity to expect the numbers to come from. Then
    // use that name concatenated with ":message" to get the message.
    $message = $state->getContext('clubs_process_beta:message');
    if (empty($message)) {
      $message = $state->getContext('ftaf_prompt:message');
    }

    $unvetted_numbers = array();
    // Matches phone numbers regardless of separators and delimiters
    preg_match_all('#(?:1)?(?<numbers>\d{3}\d{3}\d{4})#i', preg_replace('#[^0-9]#', '', $message), $numbers);
    if (!empty($numbers['numbers'])) {
       $unvetted_numbers = $numbers['numbers'];
    }

    $vetted_numbers = array();
    foreach ($unvetted_numbers as $number) {
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
        'clubs_inviter_name' => $inviter_name,
        'clubs_invite_gid' => $clubs_invite_gid,
      );

      $f['details']['nid'] = $clubs_invite_gid;

      // Remove any numbers that are already part of the drive
      $teamUIDs = dosomething_clubs_get_club_members($clubs_invite_gid);
      $numbersAlreadyJoined = array();
      $count = count($vetted_numbers);
      for ($i=$count-1; $i >= 0; $i--) {
        $number = $vetted_numbers[$i];

        // Check if this number is in the team already
        $friendAccount = _sms_flow_find_user_by_cell($number);
        if ($friendAccount && $friendAccount->uid) {
          foreach ($teamUIDs as $uid) {
            if ($friendAccount->uid == $uid) {
              $numbersAlreadyJoined[] = $number;
              unset($vetted_numbers[$i]);
              break;
            }
          }
        }
      }

      $response = '';
      if (count($numbersAlreadyJoined) > 0) {
        $response = 'These people are already members of the club:';
        foreach ($numbersAlreadyJoined as $number) {
          $response .= ' ' . $number;
        }
        $response .= '. ';
      }

      if (count($vetted_numbers) > 0) {
        $response .= 'We sent invites to these numbers:';
        foreach ($vetted_numbers as $number) {
          $response .= ' ' . $number;
        }
        $response .= '. ';
      }

      $response .= 'Text CINVITE if you want to invite more.';

      sms_flow_start($mobile, $this->alpha_optin, $this->beta_optin, $vetted_numbers, $f, $args, FALSE);
    }

    $state->setContext('sms_response', $response);
    $state->markCompleted();
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