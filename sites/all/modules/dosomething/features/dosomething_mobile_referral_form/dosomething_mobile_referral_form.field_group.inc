<?php
/**
 * @file
 * dosomething_mobile_referral_form.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_mobile_referral_form_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_friends_cell|webform_submission_entity|mobile_referral_form|default';
  $field_group->group_name = 'group_friends_cell';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'mobile_referral_form';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Friends\' Cell Numbers',
    'weight' => '2',
    'children' => array(
      0 => 'field_cell_friend1',
      1 => 'field_cell_friend2',
      2 => 'field_cell_friend3',
      3 => 'field_cell_friend4',
      4 => 'field_cell_friend5',
      5 => 'field_cell_friend6',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_friends_cell|webform_submission_entity|mobile_referral_form|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_friends_cell|webform_submission_entity|mobile_referral_form|form';
  $field_group->group_name = 'group_friends_cell';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'mobile_referral_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Friends\' Cell Numbers',
    'weight' => '2',
    'children' => array(
      0 => 'field_cell_friend6',
      1 => 'field_cell_friend5',
      2 => 'field_cell_friend4',
      3 => 'field_cell_friend3',
      4 => 'field_cell_friend2',
      5 => 'field_cell_friend1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Friends\' Cell Numbers',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_friends_cell|webform_submission_entity|mobile_referral_form|form'] = $field_group;

  return $export;
}
