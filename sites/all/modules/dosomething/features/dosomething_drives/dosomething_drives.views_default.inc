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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sid' => 'sid',
    'etid' => 'etid',
    'field_drive_location' => 'field_drive_location',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'etid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_drive_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Join this drive';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'team/spit-12/[etid]';
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
    'distance' => '50',
    'distance2' => 200,
    'unit' => '3959',
    'origin' => '',
  );
  $handler->display->display_options['filters']['field_geofield_distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator_id'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['label'] = 'Zip Code';
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
  $export['drive_search'] = $view;

  return $export;
}
