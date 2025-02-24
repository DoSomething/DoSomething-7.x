<?php
/**
 * @file
 * dosomething_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_other|profile2|main|form';
  $field_group->group_name = 'group_profile_other';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '3',
    'children' => array(
      0 => 'field_user_anniversary',
      1 => 'field_user_hearabout',
      2 => 'field_registration_page',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Other',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_profile_other|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_personal|profile2|main|form';
  $field_group->group_name = 'group_profile_personal';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_birthday',
      1 => 'field_user_first_name',
      2 => 'field_user_gender',
      3 => 'field_user_is_over13',
      4 => 'field_user_last_name',
      5 => 'field_user_mobile',
      6 => 'taxonomy_vocabulary_5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_profile_personal|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_subscriptions|profile2|main|form';
  $field_group->group_name = 'group_profile_subscriptions';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Subscriptions',
    'weight' => '2',
    'children' => array(
      0 => 'field_user_mobile_optin',
      1 => 'field_user_newsletter_optin',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Subscriptions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_profile_subscriptions|profile2|main|form'] = $field_group;

  return $export;
}
