<?php

/**
 * @file
 * Project Factory -- creates a Project
 */

class Project extends Factory {
  protected $default = array(
    'type' => 'project',
    'revision_id' => 0,
    'title' => 'Test Project',
    'org_code' => 'test-project',
    'field_headline' => 'Test Project Headline',
    'field_subheadline' => 'Test Project Subheadline',
    'field_project_dates' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => '2013-07-02 13:00:00',
          'value2' => '2013-07-26 13:00:00',
        ),
      ),
    ),
    'field_contact_email' => 'developers@dosomething.org',
    'field_signup_success_msg' => 'Thanks for signing up for Test Project!',
    'field_project_section_display' => array(),
    'status' => 1,
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
    return $node;
  }
}
