<?php
/**
 * @file
 * dosomething_fb_apps.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_fb_apps_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fb_app_animal_info_group|webform_submission_entity|fb_app_data_gathering_form|form';
  $field_group->group_name = 'group_fb_app_animal_info_group';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'fb_app_data_gathering_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '1| Enter Animal Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_fb_app_age',
      1 => 'field_fb_app_animal_name',
      2 => 'field_fb_app_animal_type',
      3 => 'field_fb_app_other',
      4 => 'field_fb_app_three_words',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '1| Enter Animal Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_fb_app_animal_info_group|webform_submission_entity|fb_app_data_gathering_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fb_app_find_shelter_group|webform_submission_entity|fb_app_data_gathering_form|form';
  $field_group->group_name = 'group_fb_app_find_shelter_group';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'fb_app_data_gathering_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '2| Find Your Shelter',
    'weight' => '1',
    'children' => array(
      0 => 'field_fb_app_shelter_reference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '2| Find Your Shelter',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_fb_app_find_shelter_group|webform_submission_entity|fb_app_data_gathering_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fb_app_upload_pet_pic|webform_submission_entity|fb_app_data_gathering_form|form';
  $field_group->group_name = 'group_fb_app_upload_pet_pic';
  $field_group->entity_type = 'webform_submission_entity';
  $field_group->bundle = 'fb_app_data_gathering_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3| Upload Your Pet Picture',
    'weight' => '2',
    'children' => array(
      0 => 'field_fb_app_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '3| Upload Your Pet Picture',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_fb_app_upload_pet_pic|webform_submission_entity|fb_app_data_gathering_form|form'] = $field_group;

  return $export;
}
