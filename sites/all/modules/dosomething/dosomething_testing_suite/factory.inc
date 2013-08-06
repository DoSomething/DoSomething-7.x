<?php

/**
 * @file
 * Factory functionality.
 *
 * @author Michael Chittenden <mchittenden@dosomething.org>
 */

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
 * hope to solve this issue by offering a wrapper for your code,
 * thereby reducing code reuse and making it easy to create new
 * data objects.
 *
 * Factories can be run like so:
 *
 * @code
 *  $this->factory->create('Blog') # Creates a blog post with default data
 *  $this->factory->create('Blog', array('title' => 'Behat is cool')) # Creates a blog post, but replaces the title with "Behat is cool"
 * @endcode
 *
 * Notice the first line here creates a blog post but doesn't specify an array
 * as the second parameter.  Without that array, the factory builder assumes
 * that you want all of the default information used.  The default informations
 * is defined, per factory, in the factory class's $default protected property.
 *
 * The second line does use an array as the second parameter.  Whatever is passed
 * through the array overwrites a key/value pair of the same name in the class's
 * $default protected property.  So for example, the default title for the Blog
 * factory is 'Blog title'.  Passing array('title' => 'Behat is cool') replaces
 * that default title with "Behat is cool" for this instance ONLY.  Factory
 * assumes that everything else should be the default values.
 *
 * You can also "Build" a factory -- which populates the array as though it were
 * going to be created, but doesn't actually create the object.  Like so:
 *
 * @code
 *  $data = $this->factory->build('Blog')  # Builds the content array for a blog post, but does NOT create it.
 *  $data = $this->factory->build('Blog', array('title' => 'My blog post')) # Builds the content  array for a blog post with the title "My blog post", but does NOT create it.
 * @endcode
 *
 * The first call returns an array with all of the default data specified in the
 * $default array in the Blog class.  The second call returns the same data, with
 * the title replaced with 'My blog post' -- again for this instance ONLY.
 *
 */
class Factory extends WebTestSuite {
  // Stores instances of factories
  private $factories = array();

  // Stores instance of the Factory class itself.
  private static $instance;

  // Singleton
  public static function instance() {
    if (!self::$instance instanceof Factory) {
      self::$instance = new Factory;
    }

    return self::$instance;
  }

  /**
   * Runs the create() method on a particular factory.  This will
   * populate the data and actually create the object in the database.
   *
   * @param string $factory
   *   A valid, case-sensitive, name of a factory class.
   *
   * @param array $overrides
   *   An optional key/value array of fields to override in the specified
   *   factory.  Anything that is not overridden will remain default.
   *
   * @return mixed
   *   The output of the factory's create() method -- generally the newly
   *   created object.
   */
  public function create($factory, $overrides = array()) {
    // Make sure that the factory exists.
    if (class_exists($factory)) {
      // We need to re-instatiate every time because overrides change.
      $this->factories[$factory] = new $factory($overrides);

      // Run the create method.
      return $this->factories[$factory]->create();
    }
  }

  /**
   * Runs the build() method on a particular factory.  This populate
   * the data, but NOT create the object in the database.
   *
   * @param string $factory
   *   A valid, case-sensitive, name of a factory class.
   *
   * @param array $overrides
   *   An optional key/value array of fields to override in the specified
   *   factory.  Anything that is not overridden will remain default.
   *
   * @return array
   *   The output of the factory's build() method -- generally ONLY the
   *   populated array.
   */
  public function build($factory, $overrides = array()) {
    // Make sure that the factory exists.
    if (class_exists($factory)) {
      // We need to re-instatiate every time because overrides change.
      $this->factories[$factory] = new $factory($overrides);

      // Run the build method.
      return $this->factories[$factory]->build();
    }
  }

  /**
   * Gets the default value of a specific column in a factory's $default array.
   *
   * @param string $factory
   *   A valid, case-sensitive, name of a factory class.
   *
   * @param string $column
   *   The column that you would like to get the default value for.
   *
   * @return mixed
   *   The default value of the specified column.
   */
  public function getDefault($factory, $column) {
    if (class_exists($factory)) {
      // We need to re-instatiate to get the default values.
      $this->factories[$factory] = new $factory();

      // Return the default value.
      return $this->factories[$factory]->default[$column];
    }
  }

  /**
   * Abstracted construct method, to be used in child class's __construct() method.
   *
   * Walks through each of the fields and sets them up with the appropriate array
   * structure for insertion into the database.
   *
   * @param array $overrides
   *   An array of optional overrides for the $default parameter array.  Anything
   *   that is in the $default array, but not in the $overrides array, will remain
   *   default.
   */
  protected function construct($overrides) {
    // Make sure that we're looking at the entire array, overrides and
    // everything else.
    $overrides = ($this->default + $overrides);

    if (!empty($overrides)) {
      // Walk through all "field_*" fields and set them up in the
      // required field[LANGUAGE_NONE][0]['value'] structure
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

      // Do the same thing for the body.
      if (isset($overrides['body'])) {
        // Make the proper body array structure
        $overrides['body'] = array(LANGUAGE_NONE => array(array(
          'value' => $overrides['body'],
        )));
      }

      // Override the default array to include the overrides.
      $this->default = array_replace_recursive($this->default, $overrides);
    }
  }
}

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
