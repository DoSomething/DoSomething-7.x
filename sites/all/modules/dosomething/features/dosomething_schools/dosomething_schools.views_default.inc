<?php
/**
 * @file
 * dosomething_schools.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_schools_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'school_proximity';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_school_location_index';
  $view->human_name = 'School proximity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse Schools';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Indexed School: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_school_location_index';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: Indexed School: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'search_api_index_school_location_index';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['label'] = '';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['city']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['city']['link_to_entity'] = 0;
  /* Field: Indexed School: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'search_api_index_school_location_index';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = '';
  $handler->display->display_options['fields']['state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['state']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['state']['link_to_entity'] = 0;
  /* Field: Indexed School: Zip */
  $handler->display->display_options['fields']['zip']['id'] = 'zip';
  $handler->display->display_options['fields']['zip']['table'] = 'search_api_index_school_location_index';
  $handler->display->display_options['fields']['zip']['field'] = 'zip';
  $handler->display->display_options['fields']['zip']['label'] = '';
  $handler->display->display_options['fields']['zip']['exclude'] = TRUE;
  $handler->display->display_options['fields']['zip']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['external'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['zip']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['zip']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['zip']['alter']['html'] = 0;
  $handler->display->display_options['fields']['zip']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['zip']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['zip']['hide_empty'] = 0;
  $handler->display->display_options['fields']['zip']['empty_zero'] = 0;
  $handler->display->display_options['fields']['zip']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['zip']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2>[name]
[city], [state] [zip]</h2>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Filter criterion: Indexed School: Latitude and longitude */
  $handler->display->display_options['filters']['lat_lon']['id'] = 'lat_lon';
  $handler->display->display_options['filters']['lat_lon']['table'] = 'search_api_index_school_location_index';
  $handler->display->display_options['filters']['lat_lon']['field'] = 'lat_lon';
  $handler->display->display_options['filters']['lat_lon']['group'] = '0';
  $handler->display->display_options['filters']['lat_lon']['exposed'] = TRUE;
  $handler->display->display_options['filters']['lat_lon']['expose']['operator_id'] = 'lat_lon_op';
  $handler->display->display_options['filters']['lat_lon']['expose']['label'] = 'Latitude and longitude';
  $handler->display->display_options['filters']['lat_lon']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['lat_lon']['expose']['operator'] = 'lat_lon_op';
  $handler->display->display_options['filters']['lat_lon']['expose']['identifier'] = 'lat_lon';
  $handler->display->display_options['filters']['lat_lon']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['lat_lon']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['lat_lon']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'school-proximity';
  $export['school_proximity'] = $view;

  return $export;
}
