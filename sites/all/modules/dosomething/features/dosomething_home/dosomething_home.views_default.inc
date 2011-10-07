<?php
/**
 * @file
 * dosomething_home.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_home_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'news_stuff';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'news-stuff';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News & Stuff';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_blog_image']['id'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['table'] = 'field_data_field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['field'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['label'] = '';
  $handler->display->display_options['fields']['field_blog_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blog_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blog_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['element_class'] = 'news-image';
  $handler->display->display_options['fields']['field_blog_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blog_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_blog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blog_image']['settings'] = array(
    'image_style' => 'news_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_blog_image']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['element_class'] = 'news-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Subtitle */
  $handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_subtitle']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_subtitle']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_subtitle']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['element_class'] = 'news-subtitle';
  $handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subtitle']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_subtitle']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_subtitle']['field_api_classes'] = 0;
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
    'blog' => 'blog',
  );
  $export['news_stuff'] = $view;

  return $export;
}
