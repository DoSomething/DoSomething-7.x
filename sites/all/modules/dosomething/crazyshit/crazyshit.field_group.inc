<?php
/**
 * @file
 * crazyshit.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crazyshit_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_crazy_page1|node|crazy_shit|form';
  $field_group->group_name = 'group_crazy_page1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'crazy_shit';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page 1 Crazyiness',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'title',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Page 1 Crazyiness',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'start',
    ),
  );
  $export['group_crazy_page1|node|crazy_shit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_crazy_page1|webform_submission_entity|crazy_shit|form';
  $field_group->group_name = 'group_crazy_page1';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'crazy_shit';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page 1',
    'weight' => '2',
    'children' => array(
      0 => 'field_crazy_crazy_picture',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_crazy_page1|webform_submission_entity|crazy_shit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_crazy_page2|node|crazy_shit|form';
  $field_group->group_name = 'group_crazy_page2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'crazy_shit';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page 2 crazyness',
    'weight' => '1',
    'children' => array(
      0 => 'field_crazy_image',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Page 2 crazyness',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'start',
    ),
  );
  $export['group_crazy_page2|node|crazy_shit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_crazy_page2|webform_submission_entity|crazy_shit|form';
  $field_group->group_name = 'group_crazy_page2';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'crazy_shit';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page 2 crazyness',
    'weight' => '3',
    'children' => array(
      0 => 'field_crazy_top_text',
      1 => 'field_crazy_bottom_text',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_crazy_page2|webform_submission_entity|crazy_shit|form'] = $field_group;

  return $export;
}
