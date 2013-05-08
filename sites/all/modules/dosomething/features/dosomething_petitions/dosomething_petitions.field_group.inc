<?php
/**
 * @file
 * dosomething_petitions.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_petitions_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_petition_about|node|petition|default';
  $field_group->group_name = 'group_petition_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_petition';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '6',
    'children' => array(
      0 => 'field_petition_about',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_petition_about|node|petition|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_petition_contact|node|petition|form';
  $field_group->group_name = 'group_petition_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Petition Contact',
    'weight' => '8',
    'children' => array(
      0 => 'field_petition_contact_email',
      1 => 'field_petition_contact_name',
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
  $export['group_petition_contact|node|petition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_petition_letter|node|petition|default';
  $field_group->group_name = 'group_petition_letter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_petition';
  $field_group->data = array(
    'label' => 'Letter',
    'weight' => '7',
    'children' => array(
      0 => 'field_petition_letter',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_petition_letter|node|petition|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_petition_updates|node|petition|default';
  $field_group->group_name = 'group_petition_updates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_petition';
  $field_group->data = array(
    'label' => 'Updates',
    'weight' => '8',
    'children' => array(
      0 => 'field_petition_updates',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_petition_updates|node|petition|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_petition|node|petition|default';
  $field_group->group_name = 'group_petition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Petition',
    'weight' => '0',
    'children' => array(
      0 => 'group_petition_about',
      1 => 'group_petition_letter',
      2 => 'group_petition_updates',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_petition|node|petition|default'] = $field_group;

  return $export;
}
