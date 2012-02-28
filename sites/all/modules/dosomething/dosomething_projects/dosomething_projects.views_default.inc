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
  $view->name = 'dosomething_api';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_project_api_index';
  $view->human_name = 'dosomething_api';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Webform submissions: Rendered Webform Submission */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_webform_submission_entity';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Entity ID';
  $handler->display->display_options['fields']['rendered_entity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'id';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  /* Filter criterion: Geocode Data: LatLong Pair (indexed) */
  $handler->display->display_options['filters']['field_geocode_data_latlon']['id'] = 'field_geocode_data_latlon';
  $handler->display->display_options['filters']['field_geocode_data_latlon']['table'] = 'search_api_index_project_api_index';
  $handler->display->display_options['filters']['field_geocode_data_latlon']['field'] = 'field_geocode_data_latlon';
  $handler->display->display_options['filters']['field_geocode_data_latlon']['group'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_project_api_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 0;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  /* Filter criterion: Indexed Webform Submission: Issues */
  $handler->display->display_options['filters']['taxonomy_vocabulary_5']['id'] = 'taxonomy_vocabulary_5';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5']['table'] = 'search_api_index_project_api_index';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5']['field'] = 'taxonomy_vocabulary_5';
  $handler->display->display_options['filters']['taxonomy_vocabulary_5']['value'] = array();
  $handler->display->display_options['filters']['taxonomy_vocabulary_5']['group'] = 0;
  /* Filter criterion: Address: Administrative area (i.e. State / Province) (indexed) */
  $handler->display->display_options['filters']['field_webform_address_administrative_area']['id'] = 'field_webform_address_administrative_area';
  $handler->display->display_options['filters']['field_webform_address_administrative_area']['table'] = 'search_api_index_project_api_index';
  $handler->display->display_options['filters']['field_webform_address_administrative_area']['field'] = 'field_webform_address_administrative_area';
  $handler->display->display_options['filters']['field_webform_address_administrative_area']['group'] = 0;
  $handler->display->display_options['filters']['field_webform_address_administrative_area']['expose']['operator_id'] = 'field_webform_address_administrative_area_op';
  $handler->display->display_options['filters']['field_webform_address_administrative_area']['expose']['label'] = 'Administrative area (i.e. State / Province) (indexed)';
  $handler->display->display_options['filters']['field_webform_address_administrative_area']['expose']['operator'] = 'field_webform_address_administrative_area_op';
  $handler->display->display_options['filters']['field_webform_address_administrative_area']['expose']['identifier'] = 'field_webform_address_administrative_area';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dosomething_api';
  $export['dosomething_api'] = $view;

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
