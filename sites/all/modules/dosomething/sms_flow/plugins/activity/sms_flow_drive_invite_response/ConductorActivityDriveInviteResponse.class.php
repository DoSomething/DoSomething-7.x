<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityDriveInviteResponse extends ConductorActivity {

  // Array of responses indicating an acceptance of the invite
  public $accept_responses = array();

  // Message returned to the users if they reject the invite
  public $invite_rejected_message = '';

  // Message returned to the user if no numbers are found
  public $no_numbers_message = '';

  // Message returned to the users if they are already in a drive.
  public $already_in_drive_messsage = '';

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Invite accepted
    if (self::hasAcceptResponse($_REQUEST['args'])) {
      $this->removeOutput('end');
    }
    // Invite rejected. Output should be 'end'
    else {
      $this->removeOutput('check_account_exists');

      // Defense against cases where people should've gone from process_beta to sms_flow_ftaf, but didn't.
      preg_match_all('#(?:1)?(?<numbers>\d{3}\d{3}\d{4})#i', preg_replace('#[^0-9]#', '', $_REQUEST['args']), $numbers);
      if (!empty($numbers['numbers'])) {
        $state->setContext('sms_response', $this->no_numbers_message);
      }
      else {
        $already_in_drive = FALSE;
        $account = _sms_flow_find_user_by_cell($mobile);
        if ($account && $account->uid) {
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

          $drives_invite_gid = 0;
          if (count($patternMatches) >= 2) {
            $drives_invite_gid = trim($patternMatches[1]);
          }

          if ($drives_invite_gid > 0) {
            $team_uids = teams_get_member_uids($drives_invite_gid);
            foreach ($team_uids as $uid) {
              if ($uid == $account->uid) {
                $already_in_drive = TRUE;
                break;
              }
            }
          }
        }

        if ($already_in_drive) {
          $state->setContext('sms_response', $this->already_in_drive_messsage);
        }
        else {
          $state->setContext('sms_response', $this->invite_rejected_message);
        }
      }
    }

    $state->markCompleted();
  }

  private function hasAcceptResponse($response) {
    $response = strtolower($response);
    foreach($this->accept_responses as $val) {
      if (stripos($response, $val) === 0) {
        return TRUE;
      }
    }

    return FALSE;
  }

}