<?php
/**
 * @file
 * dosomething_awesome_things.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_awesome_things_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'awesome_things_landing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Awesome-Things Landing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Awesome-Things';
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
  $handler->display->display_options['style_plugin'] = 'dosomething_apps_grid';
  $handler->display->display_options['style_options']['fields']['image'] = 'field_athings_landing_image';
  $handler->display->display_options['style_options']['fields']['title'] = 'name';
  $handler->display->display_options['style_options']['fields']['text'] = 'description';
  $handler->display->display_options['style_options']['fields']['link'] = 'field_athings_turl_2';
  $handler->display->display_options['style_options']['settings']['last_adjust'] = TRUE;
  $handler->display->display_options['style_options']['settings']['last_every_nth'] = '3';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'Check out the stories and programs from DoSomething.org.';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Field: Taxonomy term: URL */
  $handler->display->display_options['fields']['field_athings_url']['id'] = 'field_athings_url';
  $handler->display->display_options['fields']['field_athings_url']['table'] = 'field_data_field_athings_url';
  $handler->display->display_options['fields']['field_athings_url']['field'] = 'field_athings_url';
  $handler->display->display_options['fields']['field_athings_url']['label'] = '';
  $handler->display->display_options['fields']['field_athings_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_athings_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_athings_url']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_athings_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_athings_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_athings_url']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_athings_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_athings_url']['type'] = 'plain';
  $handler->display->display_options['fields']['field_athings_url']['field_api_classes'] = 0;
  /* Field: Taxonomy term: tURL */
  $handler->display->display_options['fields']['field_athings_turl_2']['id'] = 'field_athings_turl_2';
  $handler->display->display_options['fields']['field_athings_turl_2']['table'] = 'field_data_field_athings_turl';
  $handler->display->display_options['fields']['field_athings_turl_2']['field'] = 'field_athings_turl';
  $handler->display->display_options['fields']['field_athings_turl_2']['label'] = '';
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_athings_turl_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_athings_turl_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_athings_turl_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_athings_turl_2']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name']['alter']['path'] = '[field_athings_turl_2]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
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
  $handler->display->display_options['fields']['name']['convert_spaces'] = 0;
  /* Field: Taxonomy term: Landing image */
  $handler->display->display_options['fields']['field_athings_landing_image']['id'] = 'field_athings_landing_image';
  $handler->display->display_options['fields']['field_athings_landing_image']['table'] = 'field_data_field_athings_landing_image';
  $handler->display->display_options['fields']['field_athings_landing_image']['field'] = 'field_athings_landing_image';
  $handler->display->display_options['fields']['field_athings_landing_image']['label'] = '';
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_athings_landing_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_athings_landing_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_athings_landing_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_athings_landing_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_athings_landing_image']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_athings_landing_image']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['empty'] = 'No description for this item';
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 1;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'awesome_things' => 'awesome_things',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'awesome-things';
  $export['awesome_things_landing'] = $view;

  return $export;
}
