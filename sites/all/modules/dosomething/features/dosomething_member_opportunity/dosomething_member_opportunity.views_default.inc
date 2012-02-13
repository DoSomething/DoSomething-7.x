<?php
/**
 * @file
 * dosomething_member_opportunity.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_member_opportunity_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'editorial_content_per_grant';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Editorial content per grant';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_editorial_reference_target_id']['id'] = 'field_editorial_reference_target_id';
  $handler->display->display_options['relationships']['field_editorial_reference_target_id']['table'] = 'field_data_field_editorial_reference';
  $handler->display->display_options['relationships']['field_editorial_reference_target_id']['field'] = 'field_editorial_reference_target_id';
  $handler->display->display_options['relationships']['field_editorial_reference_target_id']['required'] = 1;
  /* Relationship: Webform Submission: Grant Reference (field_webform_grant_ref) */
  $handler->display->display_options['relationships']['field_webform_grant_ref_nid']['id'] = 'field_webform_grant_ref_nid';
  $handler->display->display_options['relationships']['field_webform_grant_ref_nid']['table'] = 'field_data_field_webform_grant_ref';
  $handler->display->display_options['relationships']['field_webform_grant_ref_nid']['field'] = 'field_webform_grant_ref_nid';
  $handler->display->display_options['relationships']['field_webform_grant_ref_nid']['relationship'] = 'field_editorial_reference_target_id';
  $handler->display->display_options['relationships']['field_webform_grant_ref_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_webform_grant_ref_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['field_editorial_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_editorial_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_editorial_image']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_editorial_image']['field_api_classes'] = 0;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_editorial_teaser']['id'] = 'field_editorial_teaser';
  $handler->display->display_options['fields']['field_editorial_teaser']['table'] = 'field_data_field_editorial_teaser';
  $handler->display->display_options['fields']['field_editorial_teaser']['field'] = 'field_editorial_teaser';
  $handler->display->display_options['fields']['field_editorial_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_editorial_teaser']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_editorial_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_editorial_teaser']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Global: Facebook Social Plugin */
  $handler->display->display_options['fields']['fb_social']['id'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['table'] = 'views';
  $handler->display->display_options['fields']['fb_social']['field'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['label'] = '';
  $handler->display->display_options['fields']['fb_social']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fb_social']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fb_social']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fb_social']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fb_social']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fb_social']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fb_social']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fb_social']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fb_social']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['fb_social']['fb_social_plugins'] = 'small_like';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_webform_grant_ref_nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['editorial_content_per_grant'] = $view;

  $view = new view;
  $view->name = 'grants';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Grants';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Current Grants';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'image_style' => '',
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
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Learn more >>';
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
    'member_opportunity' => 'member_opportunity',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '718330';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['grants'] = $view;

  $view = new view;
  $view->name = 'member_opportunity';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Grants Database';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Grants Database';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_type_of_award' => 'field_type_of_award',
    'field_award_focus' => 'field_award_focus',
    'field_application_deadline_2' => 'field_application_deadline_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_type_of_award' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_focus' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_application_deadline_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Type of Award */
  $handler->display->display_options['fields']['field_type_of_award']['id'] = 'field_type_of_award';
  $handler->display->display_options['fields']['field_type_of_award']['table'] = 'field_data_field_type_of_award';
  $handler->display->display_options['fields']['field_type_of_award']['field'] = 'field_type_of_award';
  $handler->display->display_options['fields']['field_type_of_award']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_type_of_award']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_type_of_award']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_type_of_award']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_type_of_award']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_type_of_award']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_type_of_award']['field_api_classes'] = 0;
  /* Field: Content: Award Focus */
  $handler->display->display_options['fields']['field_award_focus']['id'] = 'field_award_focus';
  $handler->display->display_options['fields']['field_award_focus']['table'] = 'field_data_field_award_focus';
  $handler->display->display_options['fields']['field_award_focus']['field'] = 'field_award_focus';
  $handler->display->display_options['fields']['field_award_focus']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_award_focus']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_award_focus']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_award_focus']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_award_focus']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_award_focus']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_award_focus']['field_api_classes'] = 0;
  /* Field: Content: Grant status */
  $handler->display->display_options['fields']['field_rolling']['id'] = 'field_rolling';
  $handler->display->display_options['fields']['field_rolling']['table'] = 'field_data_field_rolling';
  $handler->display->display_options['fields']['field_rolling']['field'] = 'field_rolling';
  $handler->display->display_options['fields']['field_rolling']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_rolling']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_rolling']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_rolling']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_rolling']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_rolling']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_rolling']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_rolling']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_rolling']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_rolling']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_rolling']['field_api_classes'] = 0;
  /* Field: Content: Application Deadline */
  $handler->display->display_options['fields']['field_application_deadline_2']['id'] = 'field_application_deadline_2';
  $handler->display->display_options['fields']['field_application_deadline_2']['table'] = 'field_data_field_application_deadline_2';
  $handler->display->display_options['fields']['field_application_deadline_2']['field'] = 'field_application_deadline_2';
  $handler->display->display_options['fields']['field_application_deadline_2']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_deadline_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_deadline_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_application_deadline_2']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_application_deadline_2']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_application_deadline_2']['field_api_classes'] = 0;
  /* Sort criterion: Content: Application Deadline (field_application_deadline_2) */
  $handler->display->display_options['sorts']['field_application_deadline_2_value']['id'] = 'field_application_deadline_2_value';
  $handler->display->display_options['sorts']['field_application_deadline_2_value']['table'] = 'field_data_field_application_deadline_2';
  $handler->display->display_options['sorts']['field_application_deadline_2_value']['field'] = 'field_application_deadline_2_value';
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
    'member_opportunity' => 'member_opportunity',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 0;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Award Focus (field_award_focus) */
  $handler->display->display_options['filters']['field_award_focus_value']['id'] = 'field_award_focus_value';
  $handler->display->display_options['filters']['field_award_focus_value']['table'] = 'field_data_field_award_focus';
  $handler->display->display_options['filters']['field_award_focus_value']['field'] = 'field_award_focus_value';
  $handler->display->display_options['filters']['field_award_focus_value']['group'] = 0;
  $handler->display->display_options['filters']['field_award_focus_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['operator_id'] = 'field_award_focus_value_op';
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['label'] = 'Award Focus';
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['operator'] = 'field_award_focus_value_op';
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['identifier'] = 'field_award_focus_value';
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Type of Award (field_type_of_award) */
  $handler->display->display_options['filters']['field_type_of_award_value']['id'] = 'field_type_of_award_value';
  $handler->display->display_options['filters']['field_type_of_award_value']['table'] = 'field_data_field_type_of_award';
  $handler->display->display_options['filters']['field_type_of_award_value']['field'] = 'field_type_of_award_value';
  $handler->display->display_options['filters']['field_type_of_award_value']['group'] = 0;
  $handler->display->display_options['filters']['field_type_of_award_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_of_award_value']['expose']['operator_id'] = 'field_type_of_award_value_op';
  $handler->display->display_options['filters']['field_type_of_award_value']['expose']['label'] = 'Award Type';
  $handler->display->display_options['filters']['field_type_of_award_value']['expose']['operator'] = 'field_type_of_award_value_op';
  $handler->display->display_options['filters']['field_type_of_award_value']['expose']['identifier'] = 'field_type_of_award_value';
  $handler->display->display_options['filters']['field_type_of_award_value']['expose']['reduce'] = 0;

  /* Display: Grants Database Page */
  $handler = $view->new_display('page', 'Grants Database Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'Here is a database of available resources for entrepreneurs. We now allow YOU to add resources! <a href="/node/add/member-opportunity">Submit an award or grant listing</a>.';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['path'] = 'grants/database';

  /* Display: Scholarships Database Page */
  $handler = $view->new_display('page', 'Scholarships Database Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scholarships Database';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'Here is a collection of scholarships that support young people that take action in their community.';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
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
    'member_opportunity' => 'member_opportunity',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Type of Award (field_type_of_award) */
  $handler->display->display_options['filters']['field_type_of_award_value']['id'] = 'field_type_of_award_value';
  $handler->display->display_options['filters']['field_type_of_award_value']['table'] = 'field_data_field_type_of_award';
  $handler->display->display_options['filters']['field_type_of_award_value']['field'] = 'field_type_of_award_value';
  $handler->display->display_options['filters']['field_type_of_award_value']['value'] = array(
    'Scholarship' => 'Scholarship',
  );
  $handler->display->display_options['filters']['field_type_of_award_value']['group'] = 0;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 0;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Award Focus (field_award_focus) */
  $handler->display->display_options['filters']['field_award_focus_value']['id'] = 'field_award_focus_value';
  $handler->display->display_options['filters']['field_award_focus_value']['table'] = 'field_data_field_award_focus';
  $handler->display->display_options['filters']['field_award_focus_value']['field'] = 'field_award_focus_value';
  $handler->display->display_options['filters']['field_award_focus_value']['group'] = 0;
  $handler->display->display_options['filters']['field_award_focus_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['operator_id'] = 'field_award_focus_value_op';
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['label'] = 'Award Focus';
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['operator'] = 'field_award_focus_value_op';
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['identifier'] = 'field_award_focus_value';
  $handler->display->display_options['filters']['field_award_focus_value']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'scholarships/database';
  $export['member_opportunity'] = $view;

  return $export;
}
