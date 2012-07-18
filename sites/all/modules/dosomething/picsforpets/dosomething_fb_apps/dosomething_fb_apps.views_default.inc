<?php
/**
 * @file
 * dosomething_fb_apps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_fb_apps_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'pics_for_pets_gallery';
  $view->description = 'This gallery shows animal submissions which are webform submissions.';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Pics for Pets Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'sorry';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<span class="sorry"> Sorry!</span>
We can\'t find what you are looking for.
Please try a new combo.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['id'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['table'] = 'field_data_field_fb_app_shelter_reference';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['field'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['required'] = 0;
  /* Field: Webform Submission: Image */
  $handler->display->display_options['fields']['field_fb_app_image']['id'] = 'field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['table'] = 'field_data_field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['field'] = 'field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fb_app_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_fb_app_image']['field_api_classes'] = 0;
  /* Field: Webform Submission: Animal Name */
  $handler->display->display_options['fields']['field_fb_app_animal_name']['id'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['table'] = 'field_data_field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field_api_classes'] = 0;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_pfp_address']['id'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['table'] = 'field_data_field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['field'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_address']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['text'] = '[field_pfp_address-locality], [field_pfp_address-administrative_area]';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_pfp_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_pfp_address']['field_api_classes'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );
  /* Filter criterion: Webform Submission: Animal Type (field_fb_app_animal_type) */
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['id'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['table'] = 'field_data_field_fb_app_animal_type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['field'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator_id'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['label'] = 'Animal Type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['identifier'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['reduce'] = 0;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['pics_for_pets_gallery'] = $view;

  $view = new view;
  $view->name = 'shelter_per_pet';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Shelter per pet';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'You can find me at:';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['id'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['table'] = 'field_data_field_fb_app_shelter_reference';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['field'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['required'] = 1;
  /* Field: Content: Shelter Website */
  $handler->display->display_options['fields']['field_pfp_shelter_website']['id'] = 'field_pfp_shelter_website';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['table'] = 'field_data_field_pfp_shelter_website';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['field'] = 'field_pfp_shelter_website';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['type'] = 'plain';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_pfp_shelter_website]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_pfp_address']['id'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['table'] = 'field_data_field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['field'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_address']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_pfp_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_pfp_address']['field_api_classes'] = 0;
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_pfp_hours']['id'] = 'field_pfp_hours';
  $handler->display->display_options['fields']['field_pfp_hours']['table'] = 'field_data_field_pfp_hours';
  $handler->display->display_options['fields']['field_pfp_hours']['field'] = 'field_pfp_hours';
  $handler->display->display_options['fields']['field_pfp_hours']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_hours']['label'] = 'Hours:';
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['field_api_classes'] = 0;
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_pfp_contact_name']['id'] = 'field_pfp_contact_name';
  $handler->display->display_options['fields']['field_pfp_contact_name']['table'] = 'field_data_field_pfp_contact_name';
  $handler->display->display_options['fields']['field_pfp_contact_name']['field'] = 'field_pfp_contact_name';
  $handler->display->display_options['fields']['field_pfp_contact_name']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_contact_name']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_contact_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['text'] = '[field_pfp_contact_name]<br />';
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_contact_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_name']['field_api_classes'] = 0;
  /* Field: Content: Phone Number */
  $handler->display->display_options['fields']['field_pfp_phone_number']['id'] = 'field_pfp_phone_number';
  $handler->display->display_options['fields']['field_pfp_phone_number']['table'] = 'field_data_field_pfp_phone_number';
  $handler->display->display_options['fields']['field_pfp_phone_number']['field'] = 'field_pfp_phone_number';
  $handler->display->display_options['fields']['field_pfp_phone_number']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_phone_number']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_phone_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['text'] = '[field_pfp_phone_number]<br />';
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_phone_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['field_api_classes'] = 0;
  /* Field: Content: Contact Email Address */
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['id'] = 'field_pfp_contact_email_address';
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['table'] = 'field_data_field_pfp_contact_email_address';
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['field'] = 'field_pfp_contact_email_address';
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['text'] = '[field_pfp_contact_email_address]<br />';
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_contact_email_address']['field_api_classes'] = 0;
  /* Field: Contact info */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Contact info';
  $handler->display->display_options['fields']['nothing']['label'] = 'Contact';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br />
[field_pfp_contact_name]
[field_pfp_phone_number]
[field_pfp_contact_email_address]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Contextual filter: Webform submissions: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['sid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['sid']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'sid' => array(
      'type' => 'context',
      'context' => 'entity:webform_submission_entity.sid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform submissions: Sid',
    ),
  );
  $export['shelter_per_pet'] = $view;

  $view = new view;
  $view->name = 'webform_submissions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Webform Submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Webform submission */
  $handler->display->display_options['relationships']['webform_submission']['id'] = 'webform_submission';
  $handler->display->display_options['relationships']['webform_submission']['table'] = 'node';
  $handler->display->display_options['relationships']['webform_submission']['field'] = 'webform_submission';
  $handler->display->display_options['relationships']['webform_submission']['required'] = 0;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'webform_submission';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Field: Webform Submission: Image */
  $handler->display->display_options['fields']['field_fb_app_image']['id'] = 'field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['table'] = 'field_data_field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['field'] = 'field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_fb_app_image']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fb_app_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_fb_app_image']['field_api_classes'] = 0;
  /* Field: Webform Submission: Animal Name */
  $handler->display->display_options['fields']['field_fb_app_animal_name']['id'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['table'] = 'field_data_field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: Shelter */
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['id'] = 'field_fb_app_shelter_reference';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['table'] = 'field_data_field_fb_app_shelter_reference';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['field'] = 'field_fb_app_shelter_reference';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['settings'] = array(
    'view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'webform_submission';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );
  /* Filter criterion: Webform Submission: Animal Type (field_fb_app_animal_type) */
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['id'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['table'] = 'field_data_field_fb_app_animal_type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['field'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['relationship'] = 'webform_submission';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator_id'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['label'] = 'Animal Type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['identifier'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['reduce'] = 0;

  /* Display: Gallery Content Pane */
  $handler = $view->new_display('panel_pane', 'Gallery Content Pane', 'panel_pane_1');
  $export['webform_submissions'] = $view;

  return $export;
}
