<?php
/**
 * @file
 * share_a_stat_scholarship.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function share_a_stat_scholarship_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_asdfg|webform_submission_entity|social_scholarship|default';
  $field_group->group_name = 'group_asdfg';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'social_scholarship';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Testing',
    'weight' => '0',
    'children' => array(
      0 => 'field_social_scholars_first_name',
      1 => 'field_social_scholars_cell',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Testing',
      'instance_settings' => array(
        'classes' => 'TESTING',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_asdfg|webform_submission_entity|social_scholarship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_scholars_friends|webform_submission_entity|social_scholarship|form';
  $field_group->group_name = 'group_social_scholars_friends';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'social_scholarship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Friend\'s cells',
    'weight' => '4',
    'children' => array(
      0 => 'field_social_scholars_friend_1',
      1 => 'field_social_scholars_friend_2',
      2 => 'field_social_scholars_friend_3',
      3 => 'field_social_scholars_friend_4',
      4 => 'field_social_scholars_friend_5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social_scholars_friends|webform_submission_entity|social_scholarship|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_yourinfo|webform_submission_entity|social_scholarship|form';
  $field_group->group_name = 'group_yourinfo';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'social_scholarship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Your information',
    'weight' => '1',
    'children' => array(
      0 => 'field_social_scholars_first_name',
      1 => 'field_social_scholars_cell',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_yourinfo|webform_submission_entity|social_scholarship|form'] = $field_group;

  return $export;
}
