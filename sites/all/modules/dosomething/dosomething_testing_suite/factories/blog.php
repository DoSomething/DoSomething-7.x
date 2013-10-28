<?php

/**
 * @file
 * Blog Factory -- Creates a blog post
 */

class Blog extends Factory {
  /**
   * An key/value array specifying fields for this particular object, and values
   * that those fields should take by default (but are overwriteable).  Don't worry
   * about using the array(LANGUAGE_NONE => etc)...the constructor will automatically
   * set up the appropriate array structure.
   *
   * This *must* be a protected property.
   */
  protected $default = array(
    'type' => 'blog',
    'title' => 'Blog title',
    'body' => 'Hello world!',
  );

  /**
   * Required.
   *
   * @param array $overrides
   *   An optional array of overrides for the $default array.
   */
  public function __construct($overrides = array()) {
    // Runs the global initializer.  Takes any overrides passed into this Factory
    // and replaces the default values with those overrides.  Also sets up the
    // proper array structure.
    $this->construct($overrides);
  }

  /**
   * The get_new() method allows for pre- and post- callbacks around object creation.
   * $this->build_factory() should be called within this method.
   *
   * Required.
   */
  public function get_new() {
    return $this->build_factory();
  }

  /**
   * The get_struct() method should return the $default array as it is after being
   * overwritten by the __construct() method.
   *
   * Required.
   */
  public function get_struct() {
    return $this->default;
  }

  /**
   * The build_factory() method is technically optional, but allows for easier
   * callbacks within the get_new() method above.  This method should actually do
   * the processing required to create the object.
   *
   * This method should be private.
   */
  private function build_factory() {
    return $this->drupalCreateNode($this->default);
  }
}
