<?php
/**
 * @file
 * dosomething_campaign_report_back.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_campaign_report_back_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'campaign_report_back';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Campaign Report Back';
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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
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
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'campaign_report_back_style',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_webform_pictures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures']['settings'] = array(
    'image_style' => 'campaign_report_back_style',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_webform_pictures']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_webform_pictures']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_webform_pictures']['field_api_classes'] = 0;
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_submission']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_submission']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_submission']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_submission']['text'] = 'Campaign Report Back';
  /* Field: Webform Submission: Photos */
  $handler->display->display_options['fields']['field_project_report_images']['id'] = 'field_project_report_images';
  $handler->display->display_options['fields']['field_project_report_images']['table'] = 'field_data_field_project_report_images';
  $handler->display->display_options['fields']['field_project_report_images']['field'] = 'field_project_report_images';
  /* Field: Webform Submission: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campaign_report_back' => 'campaign_report_back',
    'project_report' => 'project_report',
  );
  /* Filter criterion: Webform Submission: Issues (field_webform_issues) */
  $handler->display->display_options['filters']['field_webform_issues_tid']['id'] = 'field_webform_issues_tid';
  $handler->display->display_options['filters']['field_webform_issues_tid']['table'] = 'field_data_field_webform_issues';
  $handler->display->display_options['filters']['field_webform_issues_tid']['field'] = 'field_webform_issues_tid';
  $handler->display->display_options['filters']['field_webform_issues_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['operator_id'] = 'field_webform_issues_tid_op';
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['label'] = 'Causes';
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['operator'] = 'field_webform_issues_tid_op';
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['identifier'] = 'field_webform_issues_tid';
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_webform_issues_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_webform_issues_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_webform_issues_tid']['vocabulary'] = 'vocabulary_5';
  $handler->display->display_options['filters']['field_webform_issues_tid']['error_message'] = 1;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Awesome-things landing gallery */
  $handler = $view->new_display('panel_pane', 'Awesome-things landing gallery', 'panel_pane_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_galleriffic';
  $handler->display->display_options['style_options']['preload'] = '5';
  $handler->display->display_options['style_options']['numbthumbs'] = '5';
  $handler->display->display_options['style_options']['pager_bottom'] = '';
  $handler->display->display_options['style_options']['renderss'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'gallerifficfields';
  $handler->display->display_options['row_options']['slide_field'] = 'field_project_report_images';
  $handler->display->display_options['row_options']['thumbnail_field'] = 'field_project_report_images_1';
  $handler->display->display_options['row_options']['title_field'] = 'field_project_title';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Photos */
  $handler->display->display_options['fields']['field_project_report_images']['id'] = 'field_project_report_images';
  $handler->display->display_options['fields']['field_project_report_images']['table'] = 'field_data_field_project_report_images';
  $handler->display->display_options['fields']['field_project_report_images']['field'] = 'field_project_report_images';
  $handler->display->display_options['fields']['field_project_report_images']['label'] = 'slide';
  $handler->display->display_options['fields']['field_project_report_images']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_report_images']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_report_images']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_report_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_project_report_images']['settings'] = array(
    'image_style' => 'awesome_things_slide',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_project_report_images']['field_api_classes'] = 0;
  /* Field: Webform Submission: Photos */
  $handler->display->display_options['fields']['field_project_report_images_1']['id'] = 'field_project_report_images_1';
  $handler->display->display_options['fields']['field_project_report_images_1']['table'] = 'field_data_field_project_report_images';
  $handler->display->display_options['fields']['field_project_report_images_1']['field'] = 'field_project_report_images';
  $handler->display->display_options['fields']['field_project_report_images_1']['label'] = 'thumbnail';
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_report_images_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_report_images_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_report_images_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_project_report_images_1']['settings'] = array(
    'image_style' => 'awesome_things_thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_project_report_images_1']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_project_title']['element_class'] = 'galleriffic-title';
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_title']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campaign_report_back' => 'campaign_report_back',
    'project_report' => 'project_report',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Webform Submission: Photos (field_project_report_images:fid) */
  $handler->display->display_options['filters']['field_project_report_images_fid']['id'] = 'field_project_report_images_fid';
  $handler->display->display_options['filters']['field_project_report_images_fid']['table'] = 'field_data_field_project_report_images';
  $handler->display->display_options['filters']['field_project_report_images_fid']['field'] = 'field_project_report_images_fid';
  $handler->display->display_options['filters']['field_project_report_images_fid']['operator'] = 'not empty';
  $export['campaign_report_back'] = $view;

  return $export;
}

