<?php
/**
 * @file
 * dosomething_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dosomething_project_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_action_items|node|project|form';
  $field_group->group_name = 'group_project_action_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Action Items',
    'weight' => '18',
    'children' => array(
      0 => 'field_action_items',
      1 => 'field_action_items_headline',
      2 => 'field_action_kit_copy',
      3 => 'field_action_kit_file',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-project-action-items field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_project_action_items|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_assets|node|project|form';
  $field_group->group_name = 'group_project_assets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Assets',
    'weight' => '10',
    'children' => array(
      0 => 'field_banner_logo',
      1 => 'field_rules_regs_file',
      2 => 'field_sponsors',
      3 => 'field_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Assets',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-assets field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_assets|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_cta|node|project|form';
  $field_group->group_name = 'group_project_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call to Action',
    'weight' => '17',
    'children' => array(
      0 => 'field_cta_button_label',
      1 => 'field_cta_copy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Call to Action',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-cta field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_cta|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_faq|node|project|form';
  $field_group->group_name = 'group_project_faq';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FAQ',
    'weight' => '23',
    'children' => array(
      0 => 'field_faq',
      1 => 'field_faq_headline',
      2 => 'field_faq_button_label',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'FAQ',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-faq field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_faq|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_gallery|node|project|form';
  $field_group->group_name = 'group_project_gallery';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Gallery',
    'weight' => '22',
    'children' => array(
      0 => 'field_gallery_button_label',
      1 => 'field_gallery_copy',
      2 => 'field_gallery_headline',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Gallery',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-gallery field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_gallery|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_gate|node|project|form';
  $field_group->group_name = 'group_project_gate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Gate',
    'weight' => '12',
    'children' => array(
      0 => 'field_gate_color',
      1 => 'field_gate_description',
      2 => 'field_gate_headline',
      3 => 'field_gate_image',
      4 => 'field_gate_page_title',
      5 => 'field_gate_subheadline',
      6 => 'field_has_gate',
      7 => 'field_is_gate_login_signup',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Gate',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-gate field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_gate|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_info|node|project|form';
  $field_group->group_name = 'group_project_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Info',
    'weight' => '20',
    'children' => array(
      0 => 'field_project_info_copy',
      1 => 'field_project_info_headline',
      2 => 'field_project_info_items',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Project Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-info field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_info|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_prizes|node|project|form';
  $field_group->group_name = 'group_project_prizes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prizes',
    'weight' => '19',
    'children' => array(
      0 => 'field_prizes',
      1 => 'field_prizes_button_label',
      2 => 'field_prizes_copy',
      3 => 'field_prizes_headline',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Prizes',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-prizes field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_prizes|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_profiles|node|project|form';
  $field_group->group_name = 'group_project_profiles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Profiles',
    'weight' => '21',
    'children' => array(
      0 => 'field_project_profiles',
      1 => 'field_project_profiles_copy',
      2 => 'field_project_profiles_headline',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Project Profiles',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-profiles field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_profiles|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_reportback|node|project|form';
  $field_group->group_name = 'group_project_reportback';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Report Back',
    'weight' => '16',
    'children' => array(
      0 => 'field_max_num_reportbacks',
      1 => 'field_reportback_copy',
      2 => 'field_reportback_success_msg',
      3 => 'field_reportback_fields',
      4 => 'field_reportback_image_copy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Report Back',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-reportback field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_reportback|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_sms_example|node|project|form';
  $field_group->group_name = 'group_project_sms_example';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'SMS Example',
    'weight' => '15',
    'children' => array(
      0 => 'field_sms_example_button_label',
      1 => 'field_sms_example_headline',
      2 => 'field_sms_example_message',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'SMS Example',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-sms-example field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_sms_example|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_sms_referral|node|project|form';
  $field_group->group_name = 'group_project_sms_referral';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'SMS Referral',
    'weight' => '14',
    'children' => array(
      0 => 'field_mobilecommons_opt_in_alpha',
      1 => 'field_mobilecommons_opt_in_beta',
      2 => 'field_sms_referral_has_email',
      3 => 'field_sms_referral_info_copy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'SMS Referral',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-sms-referral field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_sms_referral|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_social|node|project|form';
  $field_group->group_name = 'group_project_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '11',
    'children' => array(
      0 => 'field_facebook_share_msg',
      1 => 'field_twitter_share_msg',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Media',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-social field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_social|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_subscribe|node|project|form';
  $field_group->group_name = 'group_project_subscribe';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Subscribe',
    'weight' => '13',
    'children' => array(
      0 => 'field_mailchimp_group',
      1 => 'field_mandrill_key',
      2 => 'field_mobilecommons_opt_in',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Subscribe',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-subscribe field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_project_subscribe|node|project|form'] = $field_group;

  return $export;
}
