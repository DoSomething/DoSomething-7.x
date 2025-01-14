<?php

/**
 * This is the first activity in any workflow.
 */
class ConductorActivityDSCreateUser extends ConductorActivity {

  const OLD_PERSON_ROLE = 'old person';
  const OLD_PERSON_RID = 20;

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

    $firstName = $state->getContext('first_name:message');
    $lastName = $state->getContext('last_name:message');
    $birthDate = $state->getContext('birthday:message');
    $mobile = $state->getContext('sms_number');

    // If we have a user with this mobile, lets update their info.
    $account = dosomething_general_find_user_by_cell($mobile);

    $newAccount = FALSE;
    if (!$account) {
      $account = new stdClass;
      $newAccount = TRUE;
    }

    $birthday = strtotime($birthDate);
    if ($birthday !== FALSE && !dosomething_login_person_is_over_age($birthday, 13)) {
      $state->setContext('sms_response', t('Sorry if you\'re under 13 you must register through DoSomething.org.'));
      $state->markCompleted();
      return;
    }

    $pass = user_password(6);
    require_once('includes/password.inc');
    $hashed_pass = user_hash_password($pass);

    $name = $account->name = $firstName . ' ' . $lastName;
    $account->pass = $hashed_pass;
    if ($newAccount) {
      $account->mail = $mobile . '@mobile';
      $account->status = 1;
    }

    if ($newAccount || $account->name == $mobile) {
      $suffix = 0;
      $base_name = $account->name;
      while (user_load_by_name($account->name)) {
        $suffix++;
        $account->name = $base_name . '-' . $suffix;
      }
    }

    if ($birthday !== FALSE && dosomething_login_person_is_over_age($birthday, 26)) {
      $account->roles[self::OLD_PERSON_RID] = self::OLD_PERSON_ROLE;
    }
    user_save($account);

    $profile_values = array(
      'type' => 'main',
    );

    if (!$newAccount) {
      $profile = profile2_load_by_user($account, 'main');
    }
    if (!isset($profile) || is_object($profile)) {
      $profile = profile2_create(array('type' => 'main'));
      $profile->uid = $account->uid;
    }

    // If birthday is is a timestamp (and they didn't send garbage) add it to
    // the profile.
    if ($birthday) {
      $profile->field_user_birthday[LANGUAGE_NONE][0] = array(
        'value' => date(DATE_FORMAT_DATETIME, $birthday),
        'timezone' => 'America/New_York',
        'timezone_db' => 'America/New_York',
        'date_type' => 'datetime',
      );
    }

    $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $firstName;
    $profile->field_user_last_name[LANGUAGE_NONE][0]['value'] = $lastName;
    $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;

    profile2_save($profile);

    $reset_link = user_pass_reset_url($account);
    $message = t('You\'re registered! Your password for DoSomething.org is @pass or click: !link', array('!link' => $reset_link, '@pass' => $pass));
    $state->setContext('sms_response', $message);
    $state->markCompleted();
  }

}
