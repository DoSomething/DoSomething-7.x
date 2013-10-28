<?php

/**
 * @file
 * Campaign Factory -- creates a Campaign
 */

class Campaign extends Factory {
  protected $default = array(
    'type' => 'campaign',
    'revision_id' => 0,
    'title' => 'Testing Campaign',
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
    'field_has_gate' => 0,
    'field_is_gate_login_signup' => 0,
    'field_mandrill_key' => '',
    'field_mc_optin' => 0,
    'field_gate_color' => '',
  );

  public function __construct($overrides = array()) {
    $this->construct($overrides);
  }

  public function get_new() {
    return $this->build_factory();
  }

  public function get_struct() {
    return $this->default;
  }

  private function build_factory() {
    $node = $this->drupalCreateNode($this->default);
    return $node;
  }
}
