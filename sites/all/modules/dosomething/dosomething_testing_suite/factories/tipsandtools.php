<?php

/**
 * @file
 * Tips & Tools Factory -- Creates a Tips & Tools post
 */

class TipsAndTools extends Factory {
  protected $default = array(
    'type' => 'tips_and_tools',
    'title' => 'Test Tips and Tools',
    'field_description' => 'Description',
    'field_editorial_feature_type' => 0,
    'body' => 'Hello world!',
  );

  public function __construct($overrides = array()) {
    $this->construct($overrides);
  }

  public function create() {
    return $this->build_factory();
  }

  public function build() {
    return $this->default;
  }

  private function build_factory() {
    $node =  $this->drupalCreateNode($this->default);
    return $node;
  }
}
