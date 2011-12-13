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
  $view->name = 'project_updates';
  $view->description = 'User submitted updates to a project.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Project Updates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Updates';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Video (optional) */
  $handler->display->display_options['fields']['field_embedded_video']['id'] = 'field_embedded_video';
  $handler->display->display_options['fields']['field_embedded_video']['table'] = 'field_data_field_embedded_video';
  $handler->display->display_options['fields']['field_embedded_video']['field'] = 'field_embedded_video';
  $handler->display->display_options['fields']['field_embedded_video']['label'] = '';
  $handler->display->display_options['fields']['field_embedded_video']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_embedded_video']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_embedded_video']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_embedded_video']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_embedded_video']['type'] = 'styles_media_medium';
  $handler->display->display_options['fields']['field_embedded_video']['settings'] = array(
    'file_view_mode' => 'media_original',
  );
  $handler->display->display_options['fields']['field_embedded_video']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_embedded_video']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_embedded_video']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_embedded_video']['field_api_classes'] = 0;
  /* Field: Content: Project Photo */
  $handler->display->display_options['fields']['field_project_photo']['id'] = 'field_project_photo';
  $handler->display->display_options['fields']['field_project_photo']['table'] = 'field_data_field_project_photo';
  $handler->display->display_options['fields']['field_project_photo']['field'] = 'field_project_photo';
  $handler->display->display_options['fields']['field_project_photo']['label'] = '';
  $handler->display->display_options['fields']['field_project_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_project_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_project_photo']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_project_photo']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Project (field_project:target_id) */
  $handler->display->display_options['arguments']['field_project_target_id']['id'] = 'field_project_target_id';
  $handler->display->display_options['arguments']['field_project_target_id']['table'] = 'field_data_field_project';
  $handler->display->display_options['arguments']['field_project_target_id']['field'] = 'field_project_target_id';
  $handler->display->display_options['arguments']['field_project_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_project_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_project_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_project_target_id']['not'] = 0;
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
    'project_update' => 'project_update',
    'project_updates' => 'project_updates',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'field_project_target_id' => array(
      'type' => 'context',
      'context' => 'entity:webform_submission_entity.sid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project:target_id)',
    ),
  );
  $export['project_updates'] = $view;

  $view = new view;
  $view->name = 'related_resources';
  $view->description = 'Used in sidebars to show related resources content.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Resources';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See all »';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field: Issues (taxonomy_vocabulary_5) */
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['id'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['table'] = 'field_data_taxonomy_vocabulary_5';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['field'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['required'] = 0;
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
  /* Contextual filter: Taxonomy term: Has taxonomy term ID, parent, child, or sibling term ID  */
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['id'] = 'dosomething_causes_term_node_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['field'] = 'dosomething_causes_term_node_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['relationship'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['use_taxonomy_term_path'] = 0;
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
    'tips_and_tools' => 'tips_and_tools',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 1;

  /* Display: Action Related Resources */
  $handler = $view->new_display('panel_pane', 'Action Related Resources', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 'link_to_view';
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'dosomething_causes_term_node_tid' => array(
      'type' => 'context',
      'context' => 'entity:webform_submission_entity.taxonomy_vocabulary_5',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Causes or issues',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['related_resources'] = $view;

  return $export;
}
