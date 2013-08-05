<?php

// Because this can also be called from Behat we need to Bootstrap
// Drupal if we haven't done so already.
if (!defined('DRUPAL_ROOT')) {
  chdir('../');
  define('DRUPAL_ROOT', getcwd());
  include_once DRUPAL_ROOT . '/includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
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

  public function schema() {
    return $this->schema;
  }

  public function __construct() {
    // Construction business
  }

  public function construct() {
    if (!empty($overrides)) {
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
  private $default = array(
    'name' => 'Test user',
    'first_name' => 'Test',
    'last_name' => 'User',
    'mail' => 'testing@dosomething.org',
    'mobile' => '345-555-1234',
  );

  public function create() {
    echo "YOU MADE IT!"; exit;
  }

  public function build() {
    echo "YOU'RE BUILDING!"; exit;
  }

  public function build_factory() {
  	$user = $this->drupalCreateUser(array('access content'));

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
  private $default = array(
    'type' => 'blog',
    'title' => 'Blog title',
    'body' => 'dogs',
  );

  public function __construct($overrides = array()) {
    $this->construct();
  }

  public function create() {
    $this->build_factory();
  }

  public function build() {
  }

  public function build_factory() {
    return $this->drupalCreateNode($this->default);
  }
}