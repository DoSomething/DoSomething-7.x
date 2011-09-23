<?php
/**
 * @file
 * dosomething_projects.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function dosomething_projects_views_default_views() {
  $export = array();

  $view = new view;
  $view = new view;
  $view->name = 'dosomething_projects';
  $view->description = 'API Projects';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
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
  /* Field: Content: What's the problem you are trying to solve? */
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
  /* Field: Content: Why is it important to you? */
  $handler->display->display_options['fields']['field_essay_believe_it']['id'] = 'field_essay_believe_it';
  $handler->display->display_options['fields']['field_essay_believe_it']['table'] = 'field_data_field_essay_believe_it';
  $handler->display->display_options['fields']['field_essay_believe_it']['field'] = 'field_essay_believe_it';
  $handler->display->display_options['fields']['field_essay_believe_it']['label'] = 'essay_believe_it';
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_essay_believe_it']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_essay_believe_it']['field_api_classes'] = 0;
  /* Field: Content: What's your plan of action? */
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
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['label'] = 'location_postal';
  /* Field: Location: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'location';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['label'] = 'location_lat';
  $handler->display->display_options['fields']['latitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['latitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['latitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['latitude']['style'] = 'dd';
  /* Field: Location: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'location';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['label'] = 'location_long';
  $handler->display->display_options['fields']['longitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['longitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['longitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['longitude']['style'] = 'dd';
  /* Field: Content: How many people has your project helped?   */
  $handler->display->display_options['fields']['field_num_people_impacted']['id'] = 'field_num_people_impacted';
  $handler->display->display_options['fields']['field_num_people_impacted']['table'] = 'field_data_field_num_people_impacted';
  $handler->display->display_options['fields']['field_num_people_impacted']['field'] = 'field_num_people_impacted';
  $handler->display->display_options['fields']['field_num_people_impacted']['label'] = 'num_people_impacted';
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_num_people_impacted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_num_people_impacted']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_num_people_impacted']['field_api_classes'] = 0;
  /* Field: Content: How many people have you inspired to take action? */
  $handler->display->display_options['fields']['field_num_people_inspired']['id'] = 'field_num_people_inspired';
  $handler->display->display_options['fields']['field_num_people_inspired']['table'] = 'field_data_field_num_people_inspired';
  $handler->display->display_options['fields']['field_num_people_inspired']['field'] = 'field_num_people_inspired';
  $handler->display->display_options['fields']['field_num_people_inspired']['label'] = 'num_people_involved';
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_num_people_inspired']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_num_people_inspired']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_num_people_inspired']['field_api_classes'] = 0;
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
  /* Field: Content: Taxonomy upgrade extras */
  $handler->display->display_options['fields']['taxonomyextra']['id'] = 'taxonomyextra';
  $handler->display->display_options['fields']['taxonomyextra']['table'] = 'field_data_taxonomyextra';
  $handler->display->display_options['fields']['taxonomyextra']['field'] = 'taxonomyextra';
  $handler->display->display_options['fields']['taxonomyextra']['label'] = 'allterms';
  $handler->display->display_options['fields']['taxonomyextra']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['external'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['alter']['html'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['taxonomyextra']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['taxonomyextra']['hide_empty'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['empty_zero'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['group_rows'] = 1;
  $handler->display->display_options['fields']['taxonomyextra']['delta_offset'] = '0';
  $handler->display->display_options['fields']['taxonomyextra']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['taxonomyextra']['field_api_classes'] = 0;
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
  /* Contextual filter: Location: Province */
  $handler->display->display_options['arguments']['province']['id'] = 'province';
  $handler->display->display_options['arguments']['province']['table'] = 'location';
  $handler->display->display_options['arguments']['province']['field'] = 'province';
  $handler->display->display_options['arguments']['province']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['province']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['province']['default_argument_options']['code'] = 'if (isset($_GET[\'province\'])) {
    return urldecode($_GET[\'province\']);
  } else {
    return \'all\';
  }';
  $handler->display->display_options['arguments']['province']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['province']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['province']['validate']['fail'] = 'ignore';
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
  /* Filter criterion: Location: Distance / Proximity */
  $handler->display->display_options['filters']['distance']['id'] = 'distance';
  $handler->display->display_options['filters']['distance']['table'] = 'location';
  $handler->display->display_options['filters']['distance']['field'] = 'distance';
  $handler->display->display_options['filters']['distance']['value'] = array(
    'latitude' => '',
    'longitude' => '',
    'postal_code' => '',
    'country' => '',
    'php_code' => '',
    'nid_arg' => '',
    'nid_loc_field' => 'node',
    'uid_arg' => '',
    'search_distance' => '10',
    'search_units' => 'mile',
  );
  $handler->display->display_options['filters']['distance']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['distance']['origin'] = 'postal_default';
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
