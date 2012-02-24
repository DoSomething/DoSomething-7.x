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
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Action Finder';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See all Action Guides »';
  $handler->display->display_options['link_display'] = 'custom_url';
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
  /* Contextual filter: Field: Issues (taxonomy_vocabulary_5) */
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['id'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['table'] = 'field_data_taxonomy_vocabulary_5';
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['field'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['taxonomy_vocabulary_5_tid']['not'] = 0;
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

  /* Display: Action of the Week */
  $handler = $view->new_display('panel_pane', 'Action of the Week', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['link_url'] = 'action-finder';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'action_of_the_week' => 'action_of_the_week',
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
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
    'image_style' => 'explore_action_guides',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Action of the Week';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['view_node']['element_type'] = '0';
  $handler->display->display_options['fields']['view_node']['element_label_type'] = '0';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'do-this-link';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Action Finder Landing Context */
  $handler = $view->new_display('ctools_context', 'Action Finder Landing Context', 'ctools_context_1');
  $handler->display->display_options['display_description'] = 'The main Action Finder landing page content';
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '27';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Short Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="unimage-wrapper">
  <h2>[title]</h2>
  [field_description]
</div>
  ';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $handler->display->display_options['argument_input'] = array(
    'taxonomy_vocabulary_5_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
    ),
  );
  $export['action_finder'] = $view;

  return $export;
}
