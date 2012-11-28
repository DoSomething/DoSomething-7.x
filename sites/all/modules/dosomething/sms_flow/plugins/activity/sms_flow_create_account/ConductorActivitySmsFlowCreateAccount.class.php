<?php

/**
 * Create or update the Drupal account for this user given phone number,
 * first name, and (optional) their email address.
 */
class ConductorActivitySmsFlowCreateAccount extends ConductorActivity {

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $email = $state->getContext('ask_email:message');
    $first_name = $state->getContext('ask_first_name:message');

    if (!empty($email)) {
      $account = user_load_by_mail($email);

      if ($account) {
        $profile = profile2_load_by_user($account, 'main');
        $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $first_name;
        $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;

        try {
          profile2_save($profile);
        }
        catch( Exception $e ) {}
      }

      $message = t('Your account for @mail has been updated with your new info. ', array('@mail' => $email));
    }

    // Already checked for mobile account before, so if there's still no account at
    // this point, it's safe to assume one doesn't exist and a new one should be created
    if (!$account) {
      $account = new stdClass;

      $suffix = 0;
      $account->name = $first_name;
      while (user_load_by_name($account->name)) {
        $suffix++;
        $account->name = $name . '-' . $suffix;
      }

      $pass = strtoupper(user_password(6));
      require_once('includes/password.inc');
      $hashed_pass = user_hash_password($pass);
      $account->pass = $hashed_pass;
      if (!empty($email)) {
        $account->mail = $email;
      }
      else {
        $account->mail = $mobile . '@mobile';
      }
      $account->status = 1;

      $account = user_save($account);

      $profile_values = array('type' => 'main');
      $profile = profile2_create($profile_values);
      $profile->uid = $account->uid;
      
      $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;
      $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $first_name;

      try {
        profile2_save($profile);
      }
      catch( Exception $e ) {}

      $message = t('Your password to login with your new account at http://www.dosomething.org is @pass. ', array('@pass' => $pass));
    }

    $state->setContext('pending_message', $message);
    $state->markCompleted();
  }

}