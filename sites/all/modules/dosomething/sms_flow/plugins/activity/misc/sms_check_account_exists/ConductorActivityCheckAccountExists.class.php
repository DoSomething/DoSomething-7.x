<?php

/**
 * Determine if account exists for this mobile number. Adjust output depending 
 * on existence or absence of account.
 */
class ConductorActivityCheckAccountExists extends ConductorActivity {

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $account = _sms_flow_find_user_by_cell($mobile);
    
    if ($bla) {
      $bla = TRUE;
    }

    // No account found. Only output should be 'no_account_exists'
    if (!$account) {
      $this->removeOutput('account_exists');
    }
    // Account found. Only output should be 'account_exists'
    else {
      $this->removeOutput('no_account_exists');
    }

    $state->markCompleted();
  }

}