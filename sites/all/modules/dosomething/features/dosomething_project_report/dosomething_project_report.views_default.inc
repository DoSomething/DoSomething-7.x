<?php
/**
 * @file
 * dosomething_project_report.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_project_report_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'project';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'project';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Field: Field: Facebook like count */
  $handler->display->display_options['fields']['field_fb_like_count']['id'] = 'field_fb_like_count';
  $handler->display->display_options['fields']['field_fb_like_count']['table'] = 'field_data_field_fb_like_count';
  $handler->display->display_options['fields']['field_fb_like_count']['field'] = 'field_fb_like_count';
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_like_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_like_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_like_count']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_fb_like_count']['field_api_classes'] = 0;
  /* Field: Field: How many people are directly involved in your project? */
  $handler->display->display_options['fields']['field_update_people_involved']['id'] = 'field_update_people_involved';
  $handler->display->display_options['fields']['field_update_people_involved']['table'] = 'field_data_field_update_people_involved';
  $handler->display->display_options['fields']['field_update_people_involved']['field'] = 'field_update_people_involved';
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_update_people_involved']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_update_people_involved']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_update_people_involved']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_update_people_involved']['field_api_classes'] = 0;
  /* Field: Field: How many people has your project helped?   */
  $handler->display->display_options['fields']['field_num_people_impacted']['id'] = 'field_num_people_impacted';
  $handler->display->display_options['fields']['field_num_people_impacted']['table'] = 'field_data_field_num_people_impacted';
  $handler->display->display_options['fields']['field_num_people_impacted']['field'] = 'field_num_people_impacted';
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_num_people_impacted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_num_people_impacted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_num_people_impacted']['field_api_classes'] = 0;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['id'] = 'taxonomy_vocabulary_5';
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['table'] = 'field_data_taxonomy_vocabulary_5';
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['field'] = 'taxonomy_vocabulary_5';
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['group_rows'] = 1;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['delta_offset'] = '0';
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['taxonomy_vocabulary_5']['field_api_classes'] = 0;
  /* Field: Field: Essay 1: See It */
  $handler->display->display_options['fields']['field_essay_see_it']['id'] = 'field_essay_see_it';
  $handler->display->display_options['fields']['field_essay_see_it']['table'] = 'field_data_field_essay_see_it';
  $handler->display->display_options['fields']['field_essay_see_it']['field'] = 'field_essay_see_it';
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_essay_see_it']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_essay_see_it']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['field_api_classes'] = 0;
  /* Field: Field: Essay 3: Build It */
  $handler->display->display_options['fields']['field_essay_build_it']['id'] = 'field_essay_build_it';
  $handler->display->display_options['fields']['field_essay_build_it']['table'] = 'field_data_field_essay_build_it';
  $handler->display->display_options['fields']['field_essay_build_it']['field'] = 'field_essay_build_it';
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_essay_build_it']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_essay_build_it']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['field_api_classes'] = 0;
  /* Field: Field: Essay 2: Believe It */
  $handler->display->display_options['fields']['field_essay_believe_it']['id'] = 'field_essay_believe_it';
  $handler->display->display_options['fields']['field_essay_believe_it']['table'] = 'field_data_field_essay_believe_it';
  $handler->display->display_options['fields']['field_essay_believe_it']['field'] = 'field_essay_believe_it';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project_report' => 'project_report',
  );
  $export['project'] = $view;

  return $export;
}
