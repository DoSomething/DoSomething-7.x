<?php
/**
 * @file
 * dosomething_campaign_schools.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_campaign_schools_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'campaign_school_pages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Campaign School Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'rendered_entity' => 'rendered_entity',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'submitted user';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['required'] = 1;
  /* Relationship: Group membership: Node group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['label'] = 'webform group membership';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 1;
  /* Relationship: OG membership: Group gid */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['group']['label'] = 'campaign';
  $handler->display->display_options['relationships']['group']['required'] = 1;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_webform_school_reference_target_id']['id'] = 'field_webform_school_reference_target_id';
  $handler->display->display_options['relationships']['field_webform_school_reference_target_id']['table'] = 'field_data_field_webform_school_reference';
  $handler->display->display_options['relationships']['field_webform_school_reference_target_id']['field'] = 'field_webform_school_reference_target_id';
  $handler->display->display_options['relationships']['field_webform_school_reference_target_id']['label'] = 'school';
  $handler->display->display_options['relationships']['field_webform_school_reference_target_id']['required'] = 0;
  /* Field: OG group: Entity id */
  $handler->display->display_options['fields']['etid']['id'] = 'etid';
  $handler->display->display_options['fields']['etid']['table'] = 'og';
  $handler->display->display_options['fields']['etid']['field'] = 'etid';
  $handler->display->display_options['fields']['etid']['relationship'] = 'group';
  $handler->display->display_options['fields']['etid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['etid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['etid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['etid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['etid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['etid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['etid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['etid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['etid']['separator'] = '';
  $handler->display->display_options['fields']['etid']['format_plural'] = 0;
  /* Contextual filter: Webform Submission: School (field_webform_school_reference) */
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['id'] = 'field_webform_school_reference_target_id';
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['table'] = 'field_data_field_webform_school_reference';
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['field'] = 'field_webform_school_reference_target_id';
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_webform_school_reference_target_id']['not'] = 0;
  /* Contextual filter: OG group: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'group';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['etid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['etid']['not'] = 0;

  /* Display: Members List */
  $handler = $view->new_display('panel_pane', 'Members List', 'member_list');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_user_first_name' => 'field_user_first_name',
    'field_user_last_name' => 'field_user_last_name',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['field_api_classes'] = 0;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_last_name']['field_api_classes'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_webform_school_reference_target_id' => array(
      'type' => 'context',
      'context' => 'entity:ds_school.sid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform Submission: School (field_webform_school_reference)',
    ),
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG group: Entity id',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Photo Gallery */
  $handler = $view->new_display('panel_pane', 'Photo Gallery', 'photo_gallery');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['visible'] = '';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'rendered_entity' => 'rendered_entity',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures']['id'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_webform_pictures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_webform_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures']['settings'] = array(
    'image_style' => 'member_photo_gallery',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_webform_pictures']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_webform_pictures']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Webform Submission: Pictures (field_webform_pictures:fid) */
  $handler->display->display_options['filters']['field_webform_pictures_fid']['id'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['field'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['operator'] = 'not empty';
  $handler->display->display_options['argument_input'] = array(
    'field_webform_school_reference_target_id' => array(
      'type' => 'context',
      'context' => 'entity:ds_school.sid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform Submission: School (field_webform_school_reference)',
    ),
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG group: Entity id',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Schools List */
  $handler = $view->new_display('panel_pane', 'Schools List', 'school_list');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'rendered_entity' => 'rendered_entity',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: School: ID */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'ds_school';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['relationship'] = 'field_webform_school_reference_target_id';
  $handler->display->display_options['fields']['sid']['label'] = '';
  $handler->display->display_options['fields']['sid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sid']['hide_alter_empty'] = 1;
  /* Field: School: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ds_school';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_webform_school_reference_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'school/[sid]/!1';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG group: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'group';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['etid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['etid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: School: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'ds_school';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'field_webform_school_reference_target_id';
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['reduce'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG group: Entity id',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['campaign_school_pages'] = $view;

  return $export;
}
