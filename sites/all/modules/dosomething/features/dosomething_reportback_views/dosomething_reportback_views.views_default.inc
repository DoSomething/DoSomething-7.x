<?php
/**
 * @file
 * dosomething_reportback_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_reportback_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'reportback_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dosomething_reportbacks';
  $view->human_name = 'Reportback Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_galleriffic';
  $handler->display->display_options['style_options']['css'] = '';
  $handler->display->display_options['style_options']['preload'] = '1';
  $handler->display->display_options['style_options']['transition'] = '500';
  $handler->display->display_options['style_options']['renderss'] = '';
  $handler->display->display_options['style_options']['history'] = 'true';
  $handler->display->display_options['row_plugin'] = 'gallerifficfields';
  $handler->display->display_options['row_options']['slide_field'] = 'rendered_entity';
  $handler->display->display_options['row_options']['thumbnail_field'] = 'rendered_entity_1';
  /* Relationship: Reportbacks: Reportback Node Nid */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'dosomething_reportbacks';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Reportbacks: Reportback Image file id */
  $handler->display->display_options['relationships']['fid']['id'] = 'fid';
  $handler->display->display_options['relationships']['fid']['table'] = 'dosomething_reportback_files';
  $handler->display->display_options['relationships']['fid']['field'] = 'fid';
  $handler->display->display_options['relationships']['fid']['required'] = TRUE;
  /* Field: File: Rendered File */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['relationship'] = 'fid';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'media_original';
  /* Field: File: Rendered File */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['relationship'] = 'fid';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'media_preview';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['reportback_gallery'] = $view;

  return $export;
}
