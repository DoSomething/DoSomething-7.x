<?php
/**
 * @file
 * dosomething_share_of_day.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_share_of_day_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'share_of_day';
  $view->description = 'Share of the Day for home';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Share of the Day';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Share of the Day';
  $handler->display->display_options['css_class'] = 'share-of-day';
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
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_share_of_day_link']['id'] = 'field_share_of_day_link';
  $handler->display->display_options['fields']['field_share_of_day_link']['table'] = 'field_data_field_share_of_day_link';
  $handler->display->display_options['fields']['field_share_of_day_link']['field'] = 'field_share_of_day_link';
  $handler->display->display_options['fields']['field_share_of_day_link']['label'] = '';
  $handler->display->display_options['fields']['field_share_of_day_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_share_of_day_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_link']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_share_of_day_link']['field_api_classes'] = 0;
  /* Field: Content: Picture */
  $handler->display->display_options['fields']['field_share_of_day_pic']['id'] = 'field_share_of_day_pic';
  $handler->display->display_options['fields']['field_share_of_day_pic']['table'] = 'field_data_field_share_of_day_pic';
  $handler->display->display_options['fields']['field_share_of_day_pic']['field'] = 'field_share_of_day_pic';
  $handler->display->display_options['fields']['field_share_of_day_pic']['label'] = '';
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['path'] = '[field_share_of_day_link]';
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['element_class'] = 'picture';
  $handler->display->display_options['fields']['field_share_of_day_pic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_share_of_day_pic']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_pic']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_pic']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_pic']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_share_of_day_pic']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_share_of_day_pic']['settings'] = array(
    'file_view_mode' => 'media_preview',
  );
  $handler->display->display_options['fields']['field_share_of_day_pic']['field_api_classes'] = 0;
  /* Field: Content: Attribution */
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['id'] = 'field_share_of_day_attr_pic';
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['table'] = 'field_data_field_share_of_day_attr_pic';
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['field'] = 'field_share_of_day_attr_pic';
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['label'] = '';
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['element_class'] = 'attribution';
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_share_of_day_attr_pic']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['body']['alter']['path'] = '[field_share_of_day_link]';
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
  $handler->display->display_options['fields']['body']['element_class'] = 'quote';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 1;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Attribution */
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['id'] = 'field_share_of_day_attr_quote';
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['table'] = 'field_data_field_share_of_day_attr_quote';
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['field'] = 'field_share_of_day_attr_quote';
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['label'] = '';
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['element_class'] = 'attribution';
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_quote']['field_api_classes'] = 0;
  /* Field: Content: Fact / Stat */
  $handler->display->display_options['fields']['field_share_of_day_fact']['id'] = 'field_share_of_day_fact';
  $handler->display->display_options['fields']['field_share_of_day_fact']['table'] = 'field_data_field_share_of_day_fact';
  $handler->display->display_options['fields']['field_share_of_day_fact']['field'] = 'field_share_of_day_fact';
  $handler->display->display_options['fields']['field_share_of_day_fact']['label'] = '';
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['path'] = '[field_share_of_day_link]';
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['element_class'] = 'fact';
  $handler->display->display_options['fields']['field_share_of_day_fact']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_share_of_day_fact']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_fact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_fact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_fact']['field_api_classes'] = 0;
  /* Field: Content: Attribution */
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['id'] = 'field_share_of_day_attr_fact';
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['table'] = 'field_data_field_share_of_day_attr_fact';
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['field'] = 'field_share_of_day_attr_fact';
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['label'] = '';
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['element_class'] = 'attribution';
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_share_of_day_attr_fact']['field_api_classes'] = 0;
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
    'share_of_day' => 'share_of_day',
  );
  $export['share_of_day'] = $view;

  return $export;
}
