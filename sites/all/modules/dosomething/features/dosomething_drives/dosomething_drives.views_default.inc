<?php
/**
 * @file
 * dosomething_drives.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_drives_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'drive_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Drive Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Group membership: Webform Submission group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['label'] = 'drive group';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 1;
  /* Relationship: OG membership: Group gid */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['group']['required'] = 1;
  /* Field: OG group: Entity id */
  $handler->display->display_options['fields']['etid']['id'] = 'etid';
  $handler->display->display_options['fields']['etid']['table'] = 'og';
  $handler->display->display_options['fields']['etid']['field'] = 'etid';
  $handler->display->display_options['fields']['etid']['relationship'] = 'group';
  $handler->display->display_options['fields']['etid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['etid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['etid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['etid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['etid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['etid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['etid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['etid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['etid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['etid']['separator'] = '';
  $handler->display->display_options['fields']['etid']['format_plural'] = 0;
  /* Field: Webform Submission: Team Name */
  $handler->display->display_options['fields']['field_team_name']['id'] = 'field_team_name';
  $handler->display->display_options['fields']['field_team_name']['table'] = 'field_data_field_team_name';
  $handler->display->display_options['fields']['field_team_name']['field'] = 'field_team_name';
  $handler->display->display_options['fields']['field_team_name']['label'] = 'Drive Name';
  $handler->display->display_options['fields']['field_team_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_team_name']['alter']['path'] = 'team/spit/[etid]';
  $handler->display->display_options['fields']['field_team_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_team_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_team_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: Drive Location */
  $handler->display->display_options['fields']['field_drive_location']['id'] = 'field_drive_location';
  $handler->display->display_options['fields']['field_drive_location']['table'] = 'field_data_field_drive_location';
  $handler->display->display_options['fields']['field_drive_location']['field'] = 'field_drive_location';
  $handler->display->display_options['fields']['field_drive_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_drive_location']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_drive_location']['field_api_classes'] = 0;
  /* Field: Webform Submission: Geocode Data - proximity */
  $handler->display->display_options['fields']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['table'] = 'field_data_field_geocode_data';
  $handler->display->display_options['fields']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['label'] = '';
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['text'] = '[field_geofield_distance] miles away';
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geofield_distance']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['precision'] = '1';
  $handler->display->display_options['fields']['field_geofield_distance']['separator'] = '';
  $handler->display->display_options['fields']['field_geofield_distance']['format_plural'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['source'] = 'exposed_filter';
  $handler->display->display_options['fields']['field_geofield_distance']['source_lat'] = '0';
  $handler->display->display_options['fields']['field_geofield_distance']['source_lon'] = '0';
  $handler->display->display_options['fields']['field_geofield_distance']['radius_of_earth'] = '3959';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'team/spit/[etid]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'go-button';
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
  /* Sort criterion: Webform Submission: Geocode Data - proximity */
  $handler->display->display_options['sorts']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['table'] = 'field_data_field_geocode_data';
  $handler->display->display_options['sorts']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['source'] = 'exposed_filter';
  $handler->display->display_options['sorts']['field_geofield_distance']['source_lat'] = '0';
  $handler->display->display_options['sorts']['field_geofield_distance']['source_lon'] = '0';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_skip_url'] = 1;
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['null']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['null']['validate_options']['code'] = 'if (!empty($view->exposed_raw_input[\'field_geofield_distance\'][\'origin\'])) return true;';
  $handler->display->display_options['arguments']['null']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['null']['must_not_be'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'drive_form' => 'drive_form',
  );
  /* Filter criterion: Webform Submission: Geocode Data - proximity */
  $handler->display->display_options['filters']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['table'] = 'field_data_field_geocode_data';
  $handler->display->display_options['filters']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['operator'] = '<=';
  $handler->display->display_options['filters']['field_geofield_distance']['value'] = array(
    'distance' => '100',
    'distance2' => 200,
    'unit' => '3959',
    'origin' => '',
  );
  $handler->display->display_options['filters']['field_geofield_distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator_id'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['label'] = 'Geocode Data - proximity';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['identifier'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['field_geofield_distance']['source'] = 'geocode';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:entityqueue.eq_profile2_type',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Drive Form NID',
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'drives';
  $handler->display->display_options['style_options']['top_child_object'] = 'drive';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: OG group: Entity id */
  $handler->display->display_options['fields']['etid']['id'] = 'etid';
  $handler->display->display_options['fields']['etid']['table'] = 'og';
  $handler->display->display_options['fields']['etid']['field'] = 'etid';
  $handler->display->display_options['fields']['etid']['relationship'] = 'group';
  $handler->display->display_options['fields']['etid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['etid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['etid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['etid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['etid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['etid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['etid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['etid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['etid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['etid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['etid']['separator'] = '';
  $handler->display->display_options['fields']['etid']['format_plural'] = 0;
  /* Field: Webform Submission: Team Name */
  $handler->display->display_options['fields']['field_team_name']['id'] = 'field_team_name';
  $handler->display->display_options['fields']['field_team_name']['table'] = 'field_data_field_team_name';
  $handler->display->display_options['fields']['field_team_name']['field'] = 'field_team_name';
  $handler->display->display_options['fields']['field_team_name']['label'] = 'Drive Name';
  $handler->display->display_options['fields']['field_team_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_team_name']['alter']['path'] = 'team/spit12/[etid]';
  $handler->display->display_options['fields']['field_team_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_team_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_team_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: Drive Location */
  $handler->display->display_options['fields']['field_drive_location']['id'] = 'field_drive_location';
  $handler->display->display_options['fields']['field_drive_location']['table'] = 'field_data_field_drive_location';
  $handler->display->display_options['fields']['field_drive_location']['field'] = 'field_drive_location';
  $handler->display->display_options['fields']['field_drive_location']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['alter']['text'] = '[field_drive_location-name_line]|[field_drive_location-thoroughfare]|[field_drive_location-locality]|[field_drive_location-administrative_area]|[field_drive_location-postal_code]';
  $handler->display->display_options['fields']['field_drive_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_drive_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_drive_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_drive_location']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_drive_location']['field_api_classes'] = 0;
  /* Field: Webform Submission: Geocode Data - proximity */
  $handler->display->display_options['fields']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['table'] = 'field_data_field_geocode_data';
  $handler->display->display_options['fields']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['label'] = '';
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['text'] = '[field_geofield_distance] miles away';
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geofield_distance']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['field_geofield_distance']['precision'] = '1';
  $handler->display->display_options['fields']['field_geofield_distance']['separator'] = '';
  $handler->display->display_options['fields']['field_geofield_distance']['format_plural'] = 0;
  $handler->display->display_options['fields']['field_geofield_distance']['source'] = 'exposed_filter';
  $handler->display->display_options['fields']['field_geofield_distance']['source_lat'] = '0';
  $handler->display->display_options['fields']['field_geofield_distance']['source_lon'] = '0';
  $handler->display->display_options['fields']['field_geofield_distance']['radius_of_earth'] = '3959';
  /* Field: Webform Submission: Drive Date */
  $handler->display->display_options['fields']['field_drive_date']['id'] = 'field_drive_date';
  $handler->display->display_options['fields']['field_drive_date']['table'] = 'field_data_field_drive_date';
  $handler->display->display_options['fields']['field_drive_date']['field'] = 'field_drive_date';
  $handler->display->display_options['fields']['field_drive_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_drive_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_drive_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_drive_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_drive_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_drive_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_drive_date']['field_api_classes'] = 0;
  /* Field: Webform Submission: Drive Goal */
  $handler->display->display_options['fields']['field_drive_goal']['id'] = 'field_drive_goal';
  $handler->display->display_options['fields']['field_drive_goal']['table'] = 'field_data_field_drive_goal';
  $handler->display->display_options['fields']['field_drive_goal']['field'] = 'field_drive_goal';
  $handler->display->display_options['fields']['field_drive_goal']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_drive_goal']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_drive_goal']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_drive_goal']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_drive_goal']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Link';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'http://www.dosomething.org/team/spit/[etid]';
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
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['path'] = 'api/drive-search';
  $export['drive_search'] = $view;

  return $export;
}
