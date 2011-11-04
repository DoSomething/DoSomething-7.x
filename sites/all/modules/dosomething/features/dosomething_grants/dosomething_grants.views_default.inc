<?php
/**
 * @file
 * dosomething_grants.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_grants_views_default_views() {
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
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
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

  return $export;
}
