<?php

/**
 * @file
 * Action Guide Factory -- Creates an Action Guide post
 */

class ActionGuide extends Factory {
  protected $default = array(
    'type' => 'action_guide',
    'title' => 'Test Action Guide',
    'field_description' => 'Description',
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
