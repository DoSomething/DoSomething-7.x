<?php

/**
 * This is the first activity in any workflow.
 */
class ConductorActivityDSCreateUser extends ConductorActivity {

  public function option_definition() {
    $options = parent::option_definition();
    // The attribute to set in context.
    $options['attribute_map'] = array('default' => array());
    return $options;
  }

  /**
   * Create a user object from the context built up during this workflow run.
   */
  public function run() {
    $state = $this->getState();

    $account = new stdClass;

    $firstName = $state->getContext('first_name:message');
    $lastName = $state->getContext('last_name:message');
    $birthDate = $state->getContext('birthday:message');
    $mobile = $state->getContext('sms_number');

    $pass = user_password(6);
    require_once('includes/password.inc');
    $hashed_pass = user_hash_password($pass);

    $name = $account->name = substr($firstName, 0, 1) . $lastName;
    $account->pass = $hashed_pass;
    $account->mail = $mobile . '@mobile';
    $account->status = 1;

    $suffix = 0;
    while (user_load_by_name($account->name)) {
      $suffix++;
      $account->name = $account->name . '-' . $suffix;
    }

    user_save($account);

    $reset_link = user_pass_reset_url($account);
    $message = "Thanks for registering!  Your DS password is now " . $pass . " or you can log in with: " . $reset_link;
    $state->setContext('sms_response', $message);
    $state->markCompeted();
  }

}
