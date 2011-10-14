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
  $view->api_version = '3.0-alpha1';
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
  /* Field: Field: What's the problem you are trying to solve? */
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
  /* Field: Field: What's your plan of action? */
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
  /* Field: Field: Why is it important to you? */
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

  /* Display: Project Block - Details */
  $handler = $view->new_display('block', 'Project Block - Details', 'block_1');

  /* Display: Project Block - Gallery */
  $handler = $view->new_display('block', 'Project Block - Gallery', 'block_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_galleriffic';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'gallerifficfields';
  $handler->display->display_options['row_options']['slide_field'] = 'field_picture';
  $handler->display->display_options['row_options']['thumbnail_field'] = 'field_picture_1';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: large picture */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['ui_name'] = 'large picture';
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
    'image_style' => 'medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: small image */
  $handler->display->display_options['fields']['field_picture_1']['id'] = 'field_picture_1';
  $handler->display->display_options['fields']['field_picture_1']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture_1']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture_1']['ui_name'] = 'small image';
  $handler->display->display_options['fields']['field_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_picture_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_picture_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_picture_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_picture_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_picture_1']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture_1']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture_1']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project_report' => 'project_report',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'projects';

  /* Display: Project Block - Title */
  $handler = $view->new_display('block', 'Project Block - Title', 'block_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
