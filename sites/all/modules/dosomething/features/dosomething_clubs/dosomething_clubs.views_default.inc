<?php
/**
 * @file
 * dosomething_clubs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_clubs_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'clubs';
  $view->description = 'Club related displays.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clubs';
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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'GO';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Field: Content: Group description */
  $handler->display->display_options['fields']['og_description']['id'] = 'og_description';
  $handler->display->display_options['fields']['og_description']['table'] = 'field_data_og_description';
  $handler->display->display_options['fields']['og_description']['field'] = 'og_description';
  $handler->display->display_options['fields']['og_description']['label'] = '';
  $handler->display->display_options['fields']['og_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['og_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['og_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['og_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['og_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['og_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['og_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['og_description']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['og_description']['field_api_classes'] = 0;
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_club_state']['id'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['fields']['field_club_state']['field'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['label'] = '';
  $handler->display->display_options['fields']['field_club_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_club_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_state']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_club_city']['id'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['table'] = 'field_data_field_club_city';
  $handler->display->display_options['fields']['field_club_city']['field'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['label'] = '';
  $handler->display->display_options['fields']['field_club_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_club_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_city']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['field_api_classes'] = 0;
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
    'club' => 'club',
  );
  /* Filter criterion: Content: State/Province (field_club_state) */
  $handler->display->display_options['filters']['field_club_state_value']['id'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['filters']['field_club_state_value']['field'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['operator_id'] = 'field_club_state_value_op';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['label'] = 'State/Province (field_club_state)';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['operator'] = 'field_club_state_value_op';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['identifier'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['multiple'] = FALSE;

  /* Display: Club Results Content Pane */
  $handler = $view->new_display('panel_pane', 'Club Results Content Pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Displays search results for a state or zip club search.';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'og_description' => 'og_description',
    'field_club_state' => 'field_club_state',
    'field_club_city' => 'field_club_city',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Club';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_club_state']['id'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['fields']['field_club_state']['field'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['label'] = 'State/Province';
  $handler->display->display_options['fields']['field_club_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_state']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_club_city']['id'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['table'] = 'field_data_field_club_city';
  $handler->display->display_options['fields']['field_club_city']['field'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_city']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['field_api_classes'] = 0;
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
    'club' => 'club',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: State/Province (field_club_state) */
  $handler->display->display_options['filters']['field_club_state_value']['id'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['filters']['field_club_state_value']['field'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['group'] = 0;
  $handler->display->display_options['filters']['field_club_state_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['operator_id'] = 'field_club_state_value_op';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['label'] = 'Browse Clubs by State';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['operator'] = 'field_club_state_value_op';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['identifier'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Enter your ZIP code (field_club_zip) */
  $handler->display->display_options['filters']['field_club_zip_value']['id'] = 'field_club_zip_value';
  $handler->display->display_options['filters']['field_club_zip_value']['table'] = 'field_data_field_club_zip';
  $handler->display->display_options['filters']['field_club_zip_value']['field'] = 'field_club_zip_value';
  $handler->display->display_options['filters']['field_club_zip_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['operator_id'] = 'field_club_zip_value_op';
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['label'] = 'Browse Clubs by Zip';
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['operator'] = 'field_club_zip_value_op';
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['identifier'] = 'field_club_zip_value';
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['multiple'] = FALSE;
  $export['clubs'] = $view;

  return $export;
}
