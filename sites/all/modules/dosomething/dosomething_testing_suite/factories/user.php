<?php

/**
 * User class -- creates a new user.
 */
class User extends Factory {
  protected $default = array(
    'name' => 'TestUser',
    'mail' => 'testing-abc123@dosomething.org',
    'pass' => 'testing-abc',
    'first_name' => 'Test',
    'last_name' => 'User',
    'mobile' => '345-555-1234',
    'roles' => array(),
  );

  public function __construct($overrides = array()) {
    $this->default['mail'] = 'testing-' . time() . '@test.org';
    $this->default['name'] = 'TestUser-' . time();
    $this->construct($overrides);
  }

  public function create() {
    $this->build_factory();
  }

  public function build() {
    return $this->default;
  }

  public function build_factory() {
    $user = dosomething_api_user_create(array('name' => $this->default['name'], 'password' => $this->default['pass'], 'email' => $this->default['mail'], 'mobile' => $this->default['mobile'], 'roles' => $this->default['roles']));

    // Load a profile object for the user.
    $profile_values = array('type' => 'main');
    $profile = profile2_create($profile_values);
    $profile->uid = $user->uid;

    // If we have the user's phone number, set that.
    if (!empty($this->schema['mobile'])) {
      $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $this->schema['mobile'];
    }
    // If they have a real first name, set that.
    if ($this->schema['name'] != 'Guest user' && $this->schema['name'] != $this->schema['mobile']) {
      $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $this->schema['first_name'];
      $profile->field_user_last_name[LANGUAGE_NONE][0]['value'] = $this->schema['last_name'];
    }

    // Try and save the profile and set a message that we did so...
    try {
      profile2_save($profile);
    }
    // ...or throw an exception saying we failed.
    catch (Exception $e) {
      throw new Exception(t('Sorry, there was a problem creating the account.'));
    }

    // Set the profile object as a sub-object of user.
    $user->profile = $profile;

    return $user;
  }
}