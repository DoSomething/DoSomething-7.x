<?php

/**
 * Determine if account exists for this mobile number. Adjust output depending 
 * on existence or absence of account.
 */
class ConductorActivityJoinUserToDrive extends ConductorActivity {

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $account = dosomething_api_user_lookup($mobile);

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