<?php

/**
 * @file
 * Project Factory -- creates a Project
 */

class Project extends Factory {
  // Values that can be overridden:
  protected $default = array(
    'type' => 'project',
    'revision_id' => 0,
    'title' => 'Test Project',
    'status' => 1,
    'uid' => 1,
    'field_action_kit_copy' => 'Test Project Action Kit Copy',
    'field_action_items_headline' => 'Test Project Action Items Headline',
    'field_contact_email' => 'developers@dosomething.org',
    'field_cta_copy' => 'Test Project CTA Copy',
    'field_faq_headline' => 'Test Project FAQ Headline',
    'field_gallery_copy' => 'Test Project Gallery Copy',
    'field_gallery_headline' => 'Test Project Gallery Headline',
    'field_gate_description' => 'Test Project Gate Description',
    'field_gate_headline' => 'Test Project Gate Headline',
    'field_gate_subheadline' => 'Test Project Gate Subheadline',
    'field_headline' => 'Test Project Headline',
    'field_has_gate' => 0,
    'field_is_gate_login_signup' => 0,
    'field_organization_code' => 'test-project',
    'field_prizes_copy' => 'Test Project Prizes Copy',
    'field_prizes_headline' => 'Test Project Prizes Headline',
    'field_project_dates' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => '2013-07-02 13:00:00',
          'value2' => '2013-07-26 13:00:00',
        ),
      ),
    ),
    'field_project_info_copy' => 'Test Project Project Info Copy',
    'field_project_info_headline' => 'Test Project Project Info Headline',
    'field_project_profiles_headline' => 'Test Project Project Profiles Headline',
    // Display all sections by default:
    'field_project_section_display' => array(
      LANGUAGE_NONE => array(
        0 => array('value' => 'sms_referral'),
        1 => array('value' => 'sms_example'),
        2 => array('value' => 'reportback'),
        3 => array('value' => 'cta'),
        4 => array('value' => 'action_items'),
        5 => array('value' => 'prizes'),
        6 => array('value' => 'info'),
        7 => array('value' => 'profiles'),
        8 => array('value' => 'gallery'),
        9 => array('value' => 'faq'),
      ),
    ),
    'field_reportback_copy' => 'Test Project Reportback Copy',
    'field_reportback_image_copy' => 'Test Project Reportback Image Copy',
    'field_signup_success_msg' => 'Test Project Signup Success Msg',
    'field_sms_example_headline' => 'Test Project SMS Example Headline',
    'field_sms_example_message' => 'Test Project SMS Example Message',
    'field_sms_referral_info_copy' => 'Test Project SMS Referral Info Copy',
    'field_subheadline' => 'Test Project Subheadline',
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
    // Create first instance of Reportback Fields Field Collection:
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_reportback_fields'));
    $field_collection_item->setHostEntity('node', $node);
    $field_collection_item->field_reportback_fld_label[LANGUAGE_NONE][]['value'] = 'Test Project Reportback Field Label 1';
    $field_collection_item->field_reportback_fld_name[LANGUAGE_NONE][]['value'] = 'test_field1';
    $field_collection_item->field_reportback_fld_desc[LANGUAGE_NONE][]['value'] = 'Test Project Reportback Field Desc 1';
    $field_collection_item->save();
    // Create second instance of Reportback Fields Field Collection:
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_reportback_fields'));
    $field_collection_item->setHostEntity('node', $node);
    $field_collection_item->field_reportback_fld_label[LANGUAGE_NONE][]['value'] = 'Test Project Reportback Field Label 2';
    $field_collection_item->field_reportback_fld_name[LANGUAGE_NONE][]['value'] = 'test_field2';
    $field_collection_item->field_reportback_fld_desc[LANGUAGE_NONE][]['value'] = 'Test Project Reportback Field Desc 2';
    $field_collection_item->save();
    // Set Project node to be deleted after test execution:
    $this->throwOut($node->uid, 'node');
    return $node;
  }
}
