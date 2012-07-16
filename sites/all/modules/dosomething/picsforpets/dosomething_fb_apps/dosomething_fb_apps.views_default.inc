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
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Webform submission */
  $handler->display->display_options['relationships']['webform_submission']['id'] = 'webform_submission';
  $handler->display->display_options['relationships']['webform_submission']['table'] = 'node';
  $handler->display->display_options['relationships']['webform_submission']['field'] = 'webform_submission';
  $handler->display->display_options['relationships']['webform_submission']['required'] = 1;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'webform_submission';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Field: Webform Submission: Image */
  $handler->display->display_options['fields']['field_pfp_webform_image']['id'] = 'field_pfp_webform_image';
  $handler->display->display_options['fields']['field_pfp_webform_image']['table'] = 'field_data_field_pfp_webform_image';
  $handler->display->display_options['fields']['field_pfp_webform_image']['field'] = 'field_pfp_webform_image';
  $handler->display->display_options['fields']['field_pfp_webform_image']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_pfp_webform_image']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_webform_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_webform_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_webform_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_webform_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pfp_webform_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_pfp_webform_image']['field_api_classes'] = 0;
  /* Field: Webform Submission: Shelter */
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['id'] = 'field_pfp_shelter_reference';
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['table'] = 'field_data_field_pfp_shelter_reference';
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['field'] = 'field_pfp_shelter_reference';
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_pfp_shelter_reference']['field_api_classes'] = 0;
  /* Field: Webform Submission: Animal Name */
  $handler->display->display_options['fields']['field_pfp_animal_name']['id'] = 'field_pfp_animal_name';
  $handler->display->display_options['fields']['field_pfp_animal_name']['table'] = 'field_data_field_pfp_animal_name';
  $handler->display->display_options['fields']['field_pfp_animal_name']['field'] = 'field_pfp_animal_name';
  $handler->display->display_options['fields']['field_pfp_animal_name']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_pfp_animal_name']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_animal_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_animal_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_animal_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: Animal Type */
  $handler->display->display_options['fields']['field_pfp_animal_types']['id'] = 'field_pfp_animal_types';
  $handler->display->display_options['fields']['field_pfp_animal_types']['table'] = 'field_data_field_pfp_animal_types';
  $handler->display->display_options['fields']['field_pfp_animal_types']['field'] = 'field_pfp_animal_types';
  $handler->display->display_options['fields']['field_pfp_animal_types']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_pfp_animal_types']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_animal_types']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_animal_types']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_animal_types']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_animal_types']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_animal_types']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );

  /* Display: Gallery Content Pane */
  $handler = $view->new_display('panel_pane', 'Gallery Content Pane', 'panel_pane_1');
  $export['webform_submissions'] = $view;

  return $export;
}
