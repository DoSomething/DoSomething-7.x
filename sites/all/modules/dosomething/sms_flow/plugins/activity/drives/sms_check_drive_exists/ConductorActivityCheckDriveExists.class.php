<?php

/**
 * Determine if drive exists for this school. Adjust output depending 
 * on existence or absence of drive.
 */
class ConductorActivityCheckDriveExists extends ConductorActivity {

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $school = $state->getContext('school_sid');

    $account = _sms_flow_find_campaign_by_school($school);
    
    

    // No account found. Only output should be 'no_account_exists'
    if (!$account) {
      $this->removeOutput('create_drive');
    }
    // Drive found. Only output should be 'account_exists'
    else {
      $this->removeOutput('no_drive_exists');
    }

    $state->markCompleted();
  }

}