<?php
/**
 * @file
 * dosomething_share_of_day.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_share_of_day_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_share_of_day_fact|node|share_of_day|form';
  $field_group->group_name = 'group_share_of_day_fact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'share_of_day';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_share_of_day_group';
  $field_group->data = array(
    'label' => 'Fact',
    'weight' => '7',
    'children' => array(
      0 => 'field_share_of_day_fact',
      1 => 'field_share_of_day_attr_fact',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_share_of_day_fact|node|share_of_day|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_share_of_day_group|node|share_of_day|form';
  $field_group->group_name = 'group_share_of_day_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'share_of_day';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Share of the Day',
    'weight' => '4',
    'children' => array(
      0 => 'group_share_of_day_picture',
      1 => 'group_share_of_day_fact',
      2 => 'group_share_of_day_quote',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_share_of_day_group|node|share_of_day|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_share_of_day_picture|node|share_of_day|form';
  $field_group->group_name = 'group_share_of_day_picture';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'share_of_day';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_share_of_day_group';
  $field_group->data = array(
    'label' => 'Picture',
    'weight' => '5',
    'children' => array(
      0 => 'field_share_of_day_pic',
      1 => 'field_share_of_day_attr_pic',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_share_of_day_picture|node|share_of_day|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_share_of_day_quote|node|share_of_day|form';
  $field_group->group_name = 'group_share_of_day_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'share_of_day';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_share_of_day_group';
  $field_group->data = array(
    'label' => 'Quote',
    'weight' => '6',
    'children' => array(
      0 => 'body',
      1 => 'field_share_of_day_attr_quote',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_share_of_day_quote|node|share_of_day|form'] = $field_group;

  return $export;
}
