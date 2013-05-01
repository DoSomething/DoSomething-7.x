<?php

/**
 * Create or update the Drupal account for this user given phone number,
 * first name, and (optional) their email address.
 */
class ConductorActivitySmsFlowCreateAccount extends ConductorActivity {

  // Mailchimp bucket emails should get added into
  public $mailchimp_group_name;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $email = $state->getContext('ask_email:message');
    $first_name = $state->getContext('ask_first_name:message');

    // Attempt to find existing account associated with the email
    if (!empty($email)) {
      $account = dosomething_api_user_lookup($email);
    }

    // If not found yet, attempt to find existing account with the mobile number
    if (!$account) {
      $account = dosomething_api_user_lookup($mobile);
    }

    // Update info in found account
    if ($account) {
      if (!empty($email) && $account->mail != $email) {
        $account->mail = $email;
        $account = user_save($account);
      }

      $profile = profile2_load_by_user($account, 'main');
      $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $first_name;
      $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;

      try {
        profile2_save($profile);
      }
      catch(Exception $e) {}

      $message = t('Your account for @mail has been updated with your new info. ', array('@mail' => $email));
    }
    // No accounts were found. Create a new one.
    else {
      $pass = strtoupper(user_password(6));
      $account = dosomething_api_user_create(array('name' => $first_name, 'email' => $email, 'mobile' => $mobile, 'password' => $pass));

      if (!empty($email)) {
        $account->mail = $email;
        if (!empty($this->mailchimp_group_name)) {
          dosomething_general_mailchimp_subscribe($email, $this->mailchimp_group_name);
        }
      }

      $message = t('Ur password to login at http://www.dosomething.org is @pass. ', array('@pass' => $pass));
    }

    // No message is sent from this activity. Messages that should be sent as a result of it
    // though are placed in pending_message. Responsibility is on subsequent activities to 
    // process and display these messages.
    $state->setContext('pending_message', $message);
    $state->setContext('new_account_password', $pass);
    $state->markCompleted();
  }

}