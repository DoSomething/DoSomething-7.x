<?php
/**
 * @file
 * dosomething_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_projects_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'dosomething_projects';
  $view->description = 'API Projects';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = '<query-meta><num_pages>0</num_pages><num_items>0</num_items></query-meta>';
  $handler->display->display_options['empty']['text']['format'] = '2';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Field: What's the problem you are trying to solve? */
  $handler->display->display_options['fields']['field_essay_see_it']['id'] = 'field_essay_see_it';
  $handler->display->display_options['fields']['field_essay_see_it']['table'] = 'field_data_field_essay_see_it';
  $handler->display->display_options['fields']['field_essay_see_it']['field'] = 'field_essay_see_it';
  $handler->display->display_options['fields']['field_essay_see_it']['label'] = 'essay_see_it';
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_essay_see_it']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_see_it']['field_api_classes'] = 0;
  /* Field: Field: What's your plan of action? */
  $handler->display->display_options['fields']['field_essay_build_it']['id'] = 'field_essay_build_it';
  $handler->display->display_options['fields']['field_essay_build_it']['table'] = 'field_data_field_essay_build_it';
  $handler->display->display_options['fields']['field_essay_build_it']['field'] = 'field_essay_build_it';
  $handler->display->display_options['fields']['field_essay_build_it']['label'] = 'essay_build_it';
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_essay_build_it']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_build_it']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'date_created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'date_updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['path']['alter']['text'] = 'http://www.dosomething.org[path]';
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['taxletter']['id'] = 'taxletter';
  $handler->display->display_options['arguments']['taxletter']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['taxletter']['field'] = 'name';
  $handler->display->display_options['arguments']['taxletter']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['taxletter']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['taxletter']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['taxletter']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['taxletter']['default_argument_options']['code'] = 'if (isset($_GET[\'cause\']) {
    return urldecode($_GET[\'cause\']);
  } else {
    return \'all\';
  }';
  $handler->display->display_options['arguments']['taxletter']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['taxletter']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['taxletter']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['taxletter']['glossary'] = 0;
  $handler->display->display_options['arguments']['taxletter']['limit'] = '0';
  $handler->display->display_options['arguments']['taxletter']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['taxletter']['add_table'] = 0;
  $handler->display->display_options['arguments']['taxletter']['require_value'] = 0;
  /* Contextual filter: Search: Search Terms */
  $handler->display->display_options['arguments']['keys']['id'] = 'keys';
  $handler->display->display_options['arguments']['keys']['table'] = 'search_index';
  $handler->display->display_options['arguments']['keys']['field'] = 'keys';
  $handler->display->display_options['arguments']['keys']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['keys']['exception']['value'] = '*';
  $handler->display->display_options['arguments']['keys']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['keys']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['keys']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['keys']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['keys']['validate']['fail'] = 'ignore';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    0 => 'project',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['value'] = '2001-10-01 00:00:00';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['path'] = 'dosomething-projects';
  $handler->display->display_options['use_batch'] = '0';
  $export['dosomething_projects'] = $view;

  return $export;
}
