<?php
/**
 * @file
 * dosomething_clubs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_clubs_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_leader_info|node|club|default';
  $field_group->group_name = 'group_club_leader_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Club Leader',
    'weight' => '20',
    'children' => array(
      0 => 'field_club_leader_birthdate',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_club_leader_info|node|club|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_leader_info|node|club|form';
  $field_group->group_name = 'group_club_leader_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Club Leader',
    'weight' => '1',
    'children' => array(
      0 => 'field_club_leader_birthdate',
      1 => 'field_email',
      2 => 'field_name_last',
      3 => 'field_phone_required',
      4 => 'field_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Club Leader',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_club_leader_info|node|club|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_leader_info|node|club|teaser';
  $field_group->group_name = 'group_club_leader_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Club Leader',
    'weight' => '0',
    'children' => array(
      0 => 'field_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_club_leader_info|node|club|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_location|node|club|default';
  $field_group->group_name = 'group_club_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_club_city',
      1 => 'field_club_state',
      2 => 'field_club_zip',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_club_location|node|club|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_members|node|club|default';
  $field_group->group_name = 'group_club_members';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Club Members',
    'weight' => '26',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_club_members|node|club|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_members|node|club|teaser';
  $field_group->group_name = 'group_club_members';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Club Members',
    'weight' => '6',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_club_members|node|club|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_photos_and_albums|node|club|default';
  $field_group->group_name = 'group_club_photos_and_albums';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Club Media',
    'weight' => '5',
    'children' => array(
      0 => 'field_club_picture',
      1 => 'field_club_video',
      2 => 'field_project_photo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_club_photos_and_albums|node|club|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_photos_and_albums|node|club|form';
  $field_group->group_name = 'group_club_photos_and_albums';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Club Media',
    'weight' => '12',
    'children' => array(
      0 => 'field_club_picture',
      1 => 'field_club_video',
      2 => 'field_project_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Club Media',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_club_photos_and_albums|node|club|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_club_photos_and_albums|node|club|teaser';
  $field_group->group_name = 'group_club_photos_and_albums';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'club';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Club Media',
    'weight' => '7',
    'children' => array(
      0 => 'field_club_picture',
      1 => 'field_club_video',
      2 => 'field_project_photo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_club_photos_and_albums|node|club|teaser'] = $field_group;

  return $export;
}
