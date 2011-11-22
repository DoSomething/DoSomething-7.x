<?php
/**
 * @file
 * dosomething_awesome_things_action_update.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_awesome_things_action_update_views_default_views() {
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
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
    'image_link' => '',
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
  $export['campaign_report_back'] = $view;

  return $export;
}
