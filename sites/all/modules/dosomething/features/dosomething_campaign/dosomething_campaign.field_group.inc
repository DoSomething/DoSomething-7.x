<?php
/**
 * @file
 * dosomething_campaign.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_campaign_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_campaign_gate|node|campaign|form';
  $field_group->group_name = 'group_campaign_gate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Campaign Gate',
    'weight' => '23',
    'children' => array(
      0 => 'field_gate_description',
      1 => 'field_gate_headline',
      2 => 'field_gate_image',
      3 => 'field_gate_page_title',
      4 => 'field_gate_subheadline',
      5 => 'field_has_gate',
      6 => 'field_is_gate_login_signup',
      7 => 'field_gate_color',
      8 => 'field_signup_data_form_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Campaign Gate',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-campaign-gate field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_campaign_gate|node|campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_campaign_list|node|campaign|form';
  $field_group->group_name = 'group_campaign_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Campaign List',
    'weight' => '4',
    'children' => array(
      0 => 'field_campaign_main_image',
      1 => 'field_campaign_teaser',
      2 => 'field_campain_date',
      3 => 'field_campaign_call_to_action',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => ' group-campaign-list field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_campaign_list|node|campaign|form'] = $field_group;

  return $export;
}
