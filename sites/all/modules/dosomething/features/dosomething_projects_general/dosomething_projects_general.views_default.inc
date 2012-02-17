<?php
/**
 * @file
 * dosomething_projects_general.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_projects_general_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'project_related_displays';
  $view->description = 'Displays related the projects';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Project related displays';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
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
    'action_guide' => 'action_guide',
  );

  /* Display: Get Inspired Block */
  $handler = $view->new_display('block', 'Get Inspired Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Actions You Can Do';
  $handler->display->display_options['display_description'] = 'Displays a list of action guides';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/action-finder" title="" class="projects-see-all">See all &raquo;</a>';
  $handler->display->display_options['footer']['area']['format'] = '3';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Issues (taxonomy_vocabulary_5) */
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['id'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['table'] = 'field_data_taxonomy_vocabulary_5';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['field'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['id'] = 'dosomething_causes_term_node_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['field'] = 'dosomething_causes_term_node_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['relationship'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Get Inspired Block';

  /* Display: Get The Facts Block */
  $handler = $view->new_display('block', 'Get The Facts Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Resources';
  $handler->display->display_options['display_description'] = 'Displays a list of Tips and Tools, 11 Facts content.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/find-your-cause" title="" class="projects-see-all">See all &raquo;</a>';
  $handler->display->display_options['footer']['area']['format'] = '3';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 1;
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
    'tips_and_tools' => 'tips_and_tools',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['block_description'] = 'Get The Facts Block';

  /* Display: Related Projects Content Pane */
  $handler = $view->new_display('panel_pane', 'Related Projects Content Pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Projects';
  $handler->display->display_options['display_description'] = 'Displays a list of related Projects';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/projects/%1" title="" class="projects-see-all">See all &raquo;</a>';
  $handler->display->display_options['footer']['area']['format'] = '3';
  $handler->display->display_options['footer']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'term_node_tid_depth' => array(
      'type' => 'none',
      'context' => 'entity:file.extension',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID (with depth)',
    ),
    'nid' => array(
      'type' => 'wildcard',
      'context' => 'entity:file.extension',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Actions Content Pane */
  $handler = $view->new_display('panel_pane', 'Actions Content Pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Actions You Can Do';
  $handler->display->display_options['display_description'] = 'Displays a list of action guides';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/action-finder?issues=!1" title="" class="projects-see-all">See all &raquo;</a>';
  $handler->display->display_options['footer']['area']['format'] = '3';
  $handler->display->display_options['footer']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;

  /* Display: Resources Content Pane */
  $handler = $view->new_display('panel_pane', 'Resources Content Pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related  Stuff';
  $handler->display->display_options['display_description'] = 'Displays a list of resources.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/resources/?cause=!1" title="" class="projects-see-all">See all &raquo;</a>';
  $handler->display->display_options['footer']['area']['format'] = '3';
  $handler->display->display_options['footer']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
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
    'tips_and_tools' => 'tips_and_tools',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  $export['project_related_displays'] = $view;

  $view = new view;
  $view->name = 'related_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Related Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['use_more_text'] = 'See all »';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No related projects yet.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Field: Issues (taxonomy_vocabulary_5) */
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['id'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['table'] = 'field_data_taxonomy_vocabulary_5';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['field'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['label'] = 'issues_and_causes';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['required'] = 0;
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
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['separator'] = '';
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Webform Submission: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_title']['field_api_classes'] = 0;
  /* Field: Global: Facebook Social Plugin */
  $handler->display->display_options['fields']['fb_social']['id'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['table'] = 'views';
  $handler->display->display_options['fields']['fb_social']['field'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['label'] = '';
  $handler->display->display_options['fields']['fb_social']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['fb_social']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fb_social']['fb_social_plugins'] = 'small_like';
  /* Field: Webform submissions: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = '';
  $handler->display->display_options['fields']['sid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['text'] = 'Learn more »';
  $handler->display->display_options['fields']['sid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['sid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sid']['separator'] = '';
  $handler->display->display_options['fields']['sid']['format_plural'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="unimage-wrapper">
<h2>[field_project_title]</h2>
[sid]
[fb_social]
</div>';
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
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['id'] = 'dosomething_causes_term_node_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['field'] = 'dosomething_causes_term_node_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['relationship'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Field: Picture (field_picture:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_picture';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';

  /* Display: Landing pane */
  $handler = $view->new_display('panel_pane', 'Landing pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'taxonomy_vocabulary_5_tid' => array(
      'type' => 'panel',
      'context' => 'entity:feedback.field_image',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field: Issues (taxonomy_vocabulary_5)',
    ),
  );

  /* Display: Action Related Projects Sidebar */
  $handler = $view->new_display('panel_pane', 'Action Related Projects Sidebar', 'action_sidebar_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Stuff';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'projects/%1';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_picture' => 'field_picture',
    'sid' => 'sid',
    'field_project_title' => 'field_project_title',
    'field_webform_project_summary' => 'field_webform_project_summary',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_picture']['element_class'] = 'project-related-thumb';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'project_related_thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Webform submissions: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = '';
  $handler->display->display_options['fields']['sid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['text'] = 'Learn more »';
  $handler->display->display_options['fields']['sid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sid']['separator'] = '';
  $handler->display->display_options['fields']['sid']['format_plural'] = 0;
  /* Field: Webform Submission: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['field_project_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_title']['element_class'] = 'views-field-title';
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_title']['field_api_classes'] = 0;
  /* Field: Webform Submission: Project Summary */
  $handler->display->display_options['fields']['field_webform_project_summary']['id'] = 'field_webform_project_summary';
  $handler->display->display_options['fields']['field_webform_project_summary']['table'] = 'field_data_field_webform_project_summary';
  $handler->display->display_options['fields']['field_webform_project_summary']['field'] = 'field_webform_project_summary';
  $handler->display->display_options['fields']['field_webform_project_summary']['label'] = '';
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['max_length'] = '35';
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_webform_project_summary']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_project_summary']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_webform_project_summary']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_webform_project_summary']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_webform_project_summary']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['id'] = 'dosomething_causes_term_node_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['field'] = 'dosomething_causes_term_node_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['relationship'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dosomething_causes_term_node_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Webform submissions: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['sid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['sid']['not'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Webform Submission: Title (field_project_title) */
  $handler->display->display_options['filters']['field_project_title_value']['id'] = 'field_project_title_value';
  $handler->display->display_options['filters']['field_project_title_value']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['filters']['field_project_title_value']['field'] = 'field_project_title_value';
  $handler->display->display_options['filters']['field_project_title_value']['operator'] = 'not empty';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'dosomething_causes_term_node_tid' => array(
      'type' => 'context',
      'context' => 'entity:webform_submission_entity.taxonomy_vocabulary_5',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Related taxonomy term:',
    ),
    'sid' => array(
      'type' => 'context',
      'context' => 'entity:webform_submission_entity.sid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform submissions: Sid',
    ),
  );
  $export['related_projects'] = $view;

  return $export;
}
