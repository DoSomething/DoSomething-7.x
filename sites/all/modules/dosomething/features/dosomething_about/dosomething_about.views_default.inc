<?php
/**
 * @file
 * dosomething_about.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_about_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'about_us';
  $view->description = 'Displays content on the About Us page';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'About Us';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'About Us';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'dosomething_apps_grid';
  $handler->display->display_options['style_options']['fields']['image'] = 'field_about_image';
  $handler->display->display_options['style_options']['fields']['title'] = 'name';
  $handler->display->display_options['style_options']['fields']['text'] = 'nothing';
  $handler->display->display_options['style_options']['fields']['link'] = 'field_about_link';
  $handler->display->display_options['style_options']['settings']['last_adjust'] = TRUE;
  $handler->display->display_options['style_options']['settings']['last_every_nth'] = '3';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'Locavore farm-to-table bicycle rights, artisan 8-bit four loko wes anderson. Tumblr brunch aesthetic twee farm-to-table. High life locavore +1, messenger bag terry richardson butcher salvia.';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_about_image']['id'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['table'] = 'field_data_field_about_image';
  $handler->display->display_options['fields']['field_about_image']['field'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['label'] = '';
  $handler->display->display_options['fields']['field_about_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_about_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_about_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_about_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_about_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_about_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_about_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_about_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_about_image']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_about_image']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Path */
  $handler->display->display_options['fields']['field_about_link']['id'] = 'field_about_link';
  $handler->display->display_options['fields']['field_about_link']['table'] = 'field_data_field_about_link';
  $handler->display->display_options['fields']['field_about_link']['field'] = 'field_about_link';
  $handler->display->display_options['fields']['field_about_link']['label'] = '';
  $handler->display->display_options['fields']['field_about_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_about_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_about_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_about_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_about_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_about_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_about_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_about_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_about_link']['type'] = 'default';
  $handler->display->display_options['fields']['field_about_link']['group_column'] = '';
  $handler->display->display_options['fields']['field_about_link']['field_api_classes'] = 0;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'about_us' => 'about_us',
  );

  /* Display: About Us Page */
  $handler = $view->new_display('page', 'About Us Page', 'page');
  $handler->display->display_options['display_description'] = 'The main About Us page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_about_image']['id'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['table'] = 'field_data_field_about_image';
  $handler->display->display_options['fields']['field_about_image']['field'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['label'] = '';
  $handler->display->display_options['fields']['field_about_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_about_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_about_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_about_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_about_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_about_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_about_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_about_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_about_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_about_image']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_about_image']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Path */
  $handler->display->display_options['fields']['field_about_link']['id'] = 'field_about_link';
  $handler->display->display_options['fields']['field_about_link']['table'] = 'field_data_field_about_link';
  $handler->display->display_options['fields']['field_about_link']['field'] = 'field_about_link';
  $handler->display->display_options['fields']['field_about_link']['label'] = '';
  $handler->display->display_options['fields']['field_about_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_about_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_about_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_about_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_about_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_about_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_about_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_about_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_about_link']['group_column'] = '';
  $handler->display->display_options['fields']['field_about_link']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name']['alter']['path'] = '[field_about_link]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
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
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 1;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['path'] = 'about';
  $export['about_us'] = $view;

  return $export;
}
