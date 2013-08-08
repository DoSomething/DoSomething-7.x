<?php

/**
 * @file
 * Petition Factory -- Creates a petition.
 */

class ShareAStat extends Factory {
  protected $default = array(
    'type' => 'social_scholarship',
    'title' => 'Testing Share a Stat',
    'body' => 'Oh hey! This is a Share a Stat.',
    'field_sas_is_scholarship' => 1,
    'field_tip_to_show_on_form' => 'Caterpillars must spend a lot on shoes',
    'field_redirect_message' => 'Winter is cold',
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
    return $this->drupalCreateNode($this->default);
  }
}
