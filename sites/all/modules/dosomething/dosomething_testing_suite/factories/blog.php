<?php

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