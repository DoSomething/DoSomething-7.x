<?php

/**
 * @file
 * Petition Factory -- Creates a petition.
 */

class Petition extends Factory {
  protected $default = array(
    'type' => 'petition',
    'title' => 'Testing petition: Let us pass tests so we can deploy code',
    'field_petition_about' => 'I think that we should have a lot of tests so the site does not die.',
    'field_petition_letter' => 'Dear DoSomething, please test things.',
    'field_petition_goal' => '10000',
    'field_petition_contact_name' => 'Tester',
    'field_petition_contact_email' => 'test@dosomething.org',
    'field_petition_target' => 'Everyone at DoSomething',
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
    $node = $this->drupalCreateNode($this->default);
    $this->throwOut($node->nid);
    return $node;
  }
}
