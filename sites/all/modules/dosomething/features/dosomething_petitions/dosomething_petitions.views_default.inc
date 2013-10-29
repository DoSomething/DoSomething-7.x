<?php
/**
 * @file
 * dosomething_petitions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_petitions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'petitions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Petitions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Current Petitions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Petition Picture */
  $handler->display->display_options['fields']['field_petition_picture']['id'] = 'field_petition_picture';
  $handler->display->display_options['fields']['field_petition_picture']['table'] = 'field_data_field_petition_picture';
  $handler->display->display_options['fields']['field_petition_picture']['field'] = 'field_petition_picture';
  $handler->display->display_options['fields']['field_petition_picture']['label'] = '';
  $handler->display->display_options['fields']['field_petition_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_petition_picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_petition_picture']['alter']['text'] = '<span class="views-field-field-picture">[field_petition_picture]</span>';
  $handler->display->display_options['fields']['field_petition_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_petition_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_petition_picture']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Financial Education Image */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Financial Education Image';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<span class="field-content"><span class="views-field-field-picture"><a href="/petition/financial-education"><img typeof="foaf:Image" src="/files/u/sitewide/fin.jpg" width="120" height="120" alt="" /></a></span></span>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Views If Empty: Views If Empty */
  $handler->display->display_options['fields']['views_ifempty']['id'] = 'views_ifempty';
  $handler->display->display_options['fields']['views_ifempty']['table'] = 'views_ifempty';
  $handler->display->display_options['fields']['views_ifempty']['field'] = 'views_ifempty';
  $handler->display->display_options['fields']['views_ifempty']['label'] = '';
  $handler->display->display_options['fields']['views_ifempty']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_ifempty']['emptyfield'] = 'field_petition_picture';
  $handler->display->display_options['fields']['views_ifempty']['outputfield'] = 'nothing_1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Recipients */
  $handler->display->display_options['fields']['field_petition_target']['id'] = 'field_petition_target';
  $handler->display->display_options['fields']['field_petition_target']['table'] = 'field_data_field_petition_target';
  $handler->display->display_options['fields']['field_petition_target']['field'] = 'field_petition_target';
  $handler->display->display_options['fields']['field_petition_target']['label'] = '';
  $handler->display->display_options['fields']['field_petition_target']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_petition_target']['element_label_colon'] = FALSE;
  /* Field: School Administrators */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'School Administrators';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'School Administrators';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Views If Empty: Views If Empty */
  $handler->display->display_options['fields']['views_ifempty_1']['id'] = 'views_ifempty_1';
  $handler->display->display_options['fields']['views_ifempty_1']['table'] = 'views_ifempty';
  $handler->display->display_options['fields']['views_ifempty_1']['field'] = 'views_ifempty';
  $handler->display->display_options['fields']['views_ifempty_1']['label'] = '';
  $handler->display->display_options['fields']['views_ifempty_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_ifempty_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_ifempty_1']['emptyfield'] = 'field_petition_target';
  $handler->display->display_options['fields']['views_ifempty_1']['outputfield'] = 'nothing_2';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="unimage-wrapper">
<h2>[title]</h2>
Petitioning: [views_ifempty_1]
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'petition' => 'petition',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['petitions'] = $view;

  return $export;
}
