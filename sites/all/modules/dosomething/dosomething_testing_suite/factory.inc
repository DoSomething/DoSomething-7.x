<?php

// Because this can also be called from Behat we need to Bootstrap
// Drupal if we haven't done so already.
if (!defined('DRUPAL_ROOT')) {
  chdir('../');
  define('DRUPAL_ROOT', getcwd());
  include_once DRUPAL_ROOT . '/includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
}

// Tests fail on your local because there's no defined REMOTE_ADDR
// while working on the command line.  This fixes that.
if (!isset($_SERVER['REMOTE_ADDR'])) {
  ini_set('error_reporting', 0);
  error_reporting(0);
}

/**
 * Testing Factories
 *
 * With the sheer amount of information passed back and forth
 * through Drupal and DoSomething, we find that creating data can
 * be a cumbursome and overly-complicated experience.  Factories
 * hope to solve this issue by offering a simple class that makes
 * it easy to create new content.
 *
 * Factories can be instiated like so:
 *
 * $this->factory->create('Blog') # Creates a blog post with default data
 * or
 * $this->factory->build('Blog')  # Builds the content array for a blog post, but does NOT create it.
 *
 * You can also override the default data in a factory's create() or build() method,
 * with an optional second parameter.  Like so:
 *
 * $this->factory->create('Blog', array(
 *   'title' => 'My Blog Post',
 *   'body' => 'This is a blog post from me.',
 * ));
 */
class Factory extends WebTestSuite {
  static $factories = array();
  private static $instance;

  public static function instance() {
    if (!self::$instance instanceof Factory) {
      self::$instance = new Factory;
    }

    return self::$instance;
  }

  public function create($factory, $overrides = array()) {
    if (class_exists($factory)) {
      if (!isset($factories[$factory])) {
        $factories[$factory] = new $factory($overrides);
      }

      return $factories[$factory]->create();
    }
  }

  public function build($factory, $overrides = array()) {
    if (class_exists($factory)) {
      if (!isset($factories[$factory])) {
        $factories[$factory] = new $factory($overrides);
      }

      return $factories[$factory]->build();
    }
  }

  public function construct($overrides) {
    $overrides = ($this->default + $overrides);
    if (!empty($overrides)) {
      array_walk($overrides, function(&$value, $key) {
        if (strpos($key, 'field_') !== FALSE && !is_array($value)) {
          $value = array(
            LANGUAGE_NONE => array(
              0 => array(
                'value' => $value,
              ),
            ),
          );
        }
      });


      if (isset($overrides['body'])) {
        // Make the proper body array structure
        $overrides['body'] = array(LANGUAGE_NONE => array(array(
          'value' => $overrides['body'],
        )));
      }

      $this->default = array_replace_recursive($this->default, $overrides);
    }
  }
}

class User extends Factory {
  protected $default = array(
    'name' => 'Test user',
    'mail' => 'testing@dosomething.org',
    'pass' => 'testing+abc',
    'first_name' => 'Test',
    'last_name' => 'User',
    'mobile' => '345-555-1234',
  );

  public function __construct($overrides = array()) {
    $this->construct($overrides);
  }

  public function create() {
    $this->build_factory();
  }

  public function build() {
    return $this->default;
  }

  public function build_factory() {
  	$user = dosomething_api_user_create(array('name' => 'TestUser', 'password' => 'testing+123', 'email' => 'testing@test.org', 'roles' => array(3 => 'administrator')));
    #print_R($user); exit;

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

class Blog extends Factory {
  protected $default = array(
    'type' => 'blog',
    'title' => 'Blog title',
    'body' => 'dogs',
  );

  public function __construct($overrides = array()) {
    $this->construct($overrides);
  }

  public function create() {
    $this->build_factory();
  }

  public function build() {
    return $this->default;
  }

  public function build_factory() {
    return $this->drupalCreateNode($this->default);
  }
}

class Campaign extends Factory {
  protected $default = array(
    'type' => 'campaign',
    'title' => 'Blog title',
    'body' => 'dogs',
    'field_campaign_teaser' => 'Test campaign teaser',
    'group_group' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => 1
        ),
      ),
    ),
    'field_campaign_date' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => '2013-07-02 13:00:00',
          'value2' => '2013-07-26 13:00:00',
        ),
      ),
    ),
    'field_mailchimp_group_id' => '',
    'field_counter_aggregation' => '#count',
    'field_organization_code' => 'The Hunt 2013',
    'field_campaign_status' => 1,
    'field_campaign_sms_game_example' => 73,
    'field_gate_description' => "This is the description of my campaign",
    'field_gate_headline' => 'The campaign gate',
    'field_gate_image' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'fid' => '484415',
          'alt' => 'The Hunt',
          'title' => '',
          'width' => '900',
          'height' => '600',
          'uid' => '1176550',
          'filename' => 'hunt-gate.png',
          'uri' => 'public://gate/hunt-gate.png',
          'filemime' => 'image/png',
          'filesize' => '36075',
          'status' => '1',
          'timestamp' => '1374612164',
          'type' => 'image',
          'rdf_mapping' => array(),
        ),
      ),
    ),
    'field_gate_page_title' => '',
    'field_gate_subheadline' => 'Sub headline',
    'field_has_gate' => 1,
    'field_is_gate_login_signup' => 1,
    'field_mandrill_key' => '',
    'field_mc_optin' => 0,
    'field_gate_color' => '',
  );

  public function __construct($overrides = array()) {
    $this->construct($overrides);
  }

  public function create() {
    $this->build_factory();
  }

  public function build() {
    return $this->default;
  }

  public function build_factory() {
    return $this->drupalCreateNode($this->default);
  }
}
