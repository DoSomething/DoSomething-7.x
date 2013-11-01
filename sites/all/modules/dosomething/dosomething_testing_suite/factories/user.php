<?php

/**
 * @file
 * User Factory -- creates a new user on DoSomething.org.
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

  public function get_new() {
    return $this->build_factory();
  }

  public function get_struct() {
    return $this->default;
  }

  private function build_factory() {
    $user = dosomething_api_user_create(array(
      'name' => $this->default['name'], 
      'password' => $this->default['pass'], 
      'email' => $this->default['mail'], 
      'mobile' => $this->default['mobile'], 
      'roles' => $this->default['roles'])
    );
    $this->throwOut($user->uid, 'user');
    return $user;
  }
}
