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

  $view = new view;
  $view->name = 'action_updates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Action Update';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_editorial_reference_target_id']['id'] = 'field_editorial_reference_target_id';
  $handler->display->display_options['relationships']['field_editorial_reference_target_id']['table'] = 'field_data_field_editorial_reference';
  $handler->display->display_options['relationships']['field_editorial_reference_target_id']['field'] = 'field_editorial_reference_target_id';
  $handler->display->display_options['relationships']['field_editorial_reference_target_id']['required'] = 0;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'field_editorial_reference_target_id';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'action_updates' => 'action_updates',
    'queue1' => 0,
    'queue2' => 0,
    'queue3' => 0,
    'queue4' => 0,
    'queue5' => 0,
    'queue6' => 0,
    'queue7' => 0,
    'queue8' => 0,
    'queue9' => 0,
    'queue10' => 0,
    'queue11' => 0,
    'queue12' => 0,
    'queue13' => 0,
    'queue14' => 0,
    'queue15' => 0,
    'queue16' => 0,
    'queue17' => 0,
    'queue18' => 0,
    'queue19' => 0,
    'queue20' => 0,
    'queue21' => 0,
    'queue22' => 0,
    'queue23' => 0,
    'queue24' => 0,
    'queue25' => 0,
    'queue26' => 0,
    'queue27' => 0,
    'queue28' => 0,
    'queue29' => 0,
    'queue30' => 0,
    'queue31' => 0,
    'queue32' => 0,
    'queue33' => 0,
    'queue34' => 0,
    'queue35' => 0,
    'queue36' => 0,
    'queue37' => 0,
    'queue38' => 0,
    'queue40' => 0,
    'queue41' => 0,
    'queue42' => 0,
    'queue43' => 0,
    'queue44' => 0,
    'queue45' => 0,
    'queue46' => 0,
    'queue47' => 0,
    'queue48' => 0,
    'queue49' => 0,
    'queue50' => 0,
    'queue51' => 0,
    'queue52' => 0,
    'queue53' => 0,
    'queue54' => 0,
    'queue55' => 0,
    'queue56' => 0,
    'queue57' => 0,
    'queue58' => 0,
    'queue59' => 0,
    'queue60' => 0,
    'queue61' => 0,
    'queue62' => 0,
    'queue63' => 0,
    'queue64' => 0,
    'queue65' => 0,
    'queue66' => 0,
    'projects_police_personal_info' => 0,
    'projects_police_solicitation' => 0,
    'projects_police_volunteer_opp' => 0,
    'projects_police_not_a_project' => 0,
    'projects_police_offensive' => 0,
    'projects_police_blank_project' => 0,
    'action_of_the_week' => 0,
    'featured_campaign' => 0,
    'recent_scholarship_winner' => 0,
    'scholarships_past_winners' => 0,
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_editorial_image']['id'] = 'field_editorial_image';
  $handler->display->display_options['fields']['field_editorial_image']['table'] = 'field_data_field_editorial_image';
  $handler->display->display_options['fields']['field_editorial_image']['field'] = 'field_editorial_image';
  $handler->display->display_options['fields']['field_editorial_image']['label'] = '';
  $handler->display->display_options['fields']['field_editorial_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_editorial_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_editorial_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_editorial_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_editorial_image']['settings'] = array(
    'image_style' => 'campaign_report_back_style',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_editorial_image']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'Campaign Report Back';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
    'editorial_content_' => 'editorial_content_',
  );
  /* Filter criterion: Webform Submission: Issues (field_webform_issues) */
  $handler->display->display_options['filters']['field_webform_issues_tid']['id'] = 'field_webform_issues_tid';
  $handler->display->display_options['filters']['field_webform_issues_tid']['table'] = 'field_data_field_webform_issues';
  $handler->display->display_options['filters']['field_webform_issues_tid']['field'] = 'field_webform_issues_tid';
  $handler->display->display_options['filters']['field_webform_issues_tid']['relationship'] = 'field_editorial_reference_target_id';
  $handler->display->display_options['filters']['field_webform_issues_tid']['value'] = array(
    6983 => '6983',
    9377 => '9377',
    65 => '65',
    6817 => '6817',
    32 => '32',
    89 => '89',
    81 => '81',
    120 => '120',
    9379 => '9379',
    22 => '22',
  );
  $handler->display->display_options['filters']['field_webform_issues_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['operator_id'] = 'field_webform_issues_tid_op';
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['label'] = 'Issues';
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['operator'] = 'field_webform_issues_tid_op';
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['identifier'] = 'field_webform_issues_tid';
  $handler->display->display_options['filters']['field_webform_issues_tid']['expose']['reduce'] = 1;
  $handler->display->display_options['filters']['field_webform_issues_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_webform_issues_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_webform_issues_tid']['vocabulary'] = 'vocabulary_5';
  $handler->display->display_options['filters']['field_webform_issues_tid']['error_message'] = 1;
  /* Filter criterion: Content: Campaign (field_report_back_reference) */
  $handler->display->display_options['filters']['field_report_back_reference_nid']['id'] = 'field_report_back_reference_nid';
  $handler->display->display_options['filters']['field_report_back_reference_nid']['table'] = 'field_data_field_report_back_reference';
  $handler->display->display_options['filters']['field_report_back_reference_nid']['field'] = 'field_report_back_reference_nid';
  $handler->display->display_options['filters']['field_report_back_reference_nid']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_report_back_reference_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_report_back_reference_nid']['expose']['operator_id'] = 'field_report_back_reference_nid_op';
  $handler->display->display_options['filters']['field_report_back_reference_nid']['expose']['label'] = 'Campaign';
  $handler->display->display_options['filters']['field_report_back_reference_nid']['expose']['operator'] = 'field_report_back_reference_nid_op';
  $handler->display->display_options['filters']['field_report_back_reference_nid']['expose']['identifier'] = 'field_report_back_reference_nid';
  $handler->display->display_options['filters']['field_report_back_reference_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'campaign_report_back' => 'campaign_report_back',
    'awards_archive' => 'awards_archive',
    'grant_application' => 'grant_application',
    'scholarship' => 'scholarship',
  );
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = 1;
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  /* Filter criterion: Webform submissions: Submitted */
  $handler->display->display_options['filters']['submitted']['id'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['submitted']['field'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['relationship'] = 'field_editorial_reference_target_id';
  $handler->display->display_options['filters']['submitted']['operator'] = 'between';
  $handler->display->display_options['filters']['submitted']['exposed'] = TRUE;
  $handler->display->display_options['filters']['submitted']['expose']['operator_id'] = 'submitted_op';
  $handler->display->display_options['filters']['submitted']['expose']['label'] = 'Submitted';
  $handler->display->display_options['filters']['submitted']['expose']['operator'] = 'submitted_op';
  $handler->display->display_options['filters']['submitted']['expose']['identifier'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['expose']['multiple'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');

  $export['action_updates'] = $view;

  return $export;
}
