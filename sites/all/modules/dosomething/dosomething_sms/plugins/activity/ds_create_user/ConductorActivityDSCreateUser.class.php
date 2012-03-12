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

    $account = new stdClass;

    $firstName = $state->getContext('first_name:message');
    $lastName = $state->getContext('last_name:message');
    $birthDate = $state->getContext('birthday:message');
    $mobile = $state->getContext('sms_number');

    $birthday = strtotime($birthDate);
    // If the user is younger than 13 (give or take a day), reject the
    // application (that's (60 * 60 * 24 * 365 * 13) - (60 * 60 * 24)).
    if ($birthday !== FALSE && $birthday > (REQUEST_TIME - 409881600)) {
      $state->setContext('sms_response', t('Sorry if you\'re under 13 you must register through DoSomething.org.'));
      $state->markCompeted();
      return;
    }

    $pass = user_password(6);
    require_once('includes/password.inc');
    $hashed_pass = user_hash_password($pass);

    $name = $account->name = $firstName . ' ' . $lastName;
    $account->pass = $hashed_pass;
    $account->mail = $mobile . '@mobile';
    $account->status = 1;

    $suffix = 0;
    $base_name = $account->name;
    while (user_load_by_name($account->name)) {
      $suffix++;
      $account->name = $base_name . '-' . $suffix;
    }

    // If the user is older than 26 add the old person role.
    // application (that's (60 * 60 * 24 * 365 * 26)).
    if ($birthday !== FALSE && $birthday < (REQUEST_TIME - 819936000)) {
      $account->roles[self::OLD_PERSON_RID] = self::OLD_PERSON_ROLE;
    }

    user_save($account);

    // If birthday is is a timestampe (and they didn't send garbage) add it to
    // the profile.
    $profile_values = array();
    if ($birthday) {
      $field_value = array(
        LANGUAGE_NONE => array(
          array(
            'value' => date(DATE_FORMAT_DATETIME, $birthday),
            'timezone' => 'America/New_York',
            'timezone_db' => 'America/New_York',
            'date_type' => 'datetime',
          ),
        ),
      );
      $field_name = 'field_user_birthday';
      $type_name = 'main';
      $profile_values = array(
        'type' => $type_name,
        $field_name => $field_value,
      );
    }

    $profile = profile2_create($profile_values);
    $profile->uid = $account->uid;

    $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $firstName;
    $profile->field_user_last_name[LANGUAGE_NONE][0]['value'] = $lastName;
    $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;

    profile2_save($profile);

    $reset_link = user_pass_reset_url($account);
    $message = t('You\'re registered! Your password is @pass or click: !link', array('!link' => $reset_link, '@pass' => $pass));
    $state->setContext('sms_response', $message);
    $state->markCompeted();
  }

}
