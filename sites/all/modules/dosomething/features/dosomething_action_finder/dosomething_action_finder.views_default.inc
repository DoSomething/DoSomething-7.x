<?php
/**
 * @file
 * dosomething_action_finder.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_action_finder_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'action_finder';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Action Finder';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Action Finder';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Short Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_description']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_description']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action_guide' => 'action_guide',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Field: Issues (taxonomy_vocabulary_5) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['id'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['table'] = 'field_data_taxonomy_vocabulary_5';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['field'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['group'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['expose']['operator_id'] = 'taxonomy_vocabulary_5_tid_op';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['expose']['label'] = 'What Cause?';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['expose']['operator'] = 'taxonomy_vocabulary_5_tid_op';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['expose']['identifier'] = 'issues';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['type'] = 'select';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['vocabulary'] = 'vocabulary_5';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5_tid']['error_message'] = 1;
  /* Filter criterion: Content: Who (taxonomy_vocabulary_3) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['id'] = 'taxonomy_vocabulary_3_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['table'] = 'field_data_taxonomy_vocabulary_3';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['field'] = 'taxonomy_vocabulary_3_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['group'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['expose']['operator_id'] = 'taxonomy_vocabulary_3_tid_op';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['expose']['label'] = 'Who With?';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['expose']['operator'] = 'taxonomy_vocabulary_3_tid_op';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['expose']['identifier'] = 'who';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['type'] = 'select';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['vocabulary'] = 'vocabulary_3';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid']['error_message'] = 1;
  /* Filter criterion: Content: Where (taxonomy_vocabulary_2) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['id'] = 'taxonomy_vocabulary_2_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['table'] = 'field_data_taxonomy_vocabulary_2';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['field'] = 'taxonomy_vocabulary_2_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['group'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['expose']['operator_id'] = 'taxonomy_vocabulary_2_tid_op';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['expose']['label'] = 'Where?';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['expose']['operator'] = 'taxonomy_vocabulary_2_tid_op';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['expose']['identifier'] = 'where';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['type'] = 'select';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['vocabulary'] = 'vocabulary_2';
  $handler->display->display_options['filters']['taxonomy_vocabulary_2_tid']['error_message'] = 1;
  /* Filter criterion: Content: Time (taxonomy_vocabulary_4) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['id'] = 'taxonomy_vocabulary_4_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['table'] = 'field_data_taxonomy_vocabulary_4';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['field'] = 'taxonomy_vocabulary_4_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['group'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['expose']['operator_id'] = 'taxonomy_vocabulary_4_tid_op';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['expose']['label'] = 'How Long?';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['expose']['operator'] = 'taxonomy_vocabulary_4_tid_op';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['expose']['identifier'] = 'time';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['type'] = 'select';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['vocabulary'] = 'vocabulary_4';
  $handler->display->display_options['filters']['taxonomy_vocabulary_4_tid']['error_message'] = 1;

  /* Display: Action Finder Landing Page */
  $handler = $view->new_display('page', 'Action Finder Landing Page', 'page');
  $handler->display->display_options['path'] = 'action-finder';
  $export['action_finder'] = $view;

  return $export;
}
