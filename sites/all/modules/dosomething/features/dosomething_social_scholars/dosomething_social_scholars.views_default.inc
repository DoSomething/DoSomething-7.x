<?php
/**
 * @file
 * dosomething_social_scholars.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_social_scholars_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'campaign_list_for_sas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campaign List for SaS';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campaign List for Clubs';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Campaign Sign Up (field_campaign) */
  $handler->display->display_options['relationships']['field_campaign_nid']['id'] = 'field_campaign_nid';
  $handler->display->display_options['relationships']['field_campaign_nid']['table'] = 'field_data_field_campaign';
  $handler->display->display_options['relationships']['field_campaign_nid']['field'] = 'field_campaign_nid';
  $handler->display->display_options['relationships']['field_campaign_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_campaign_nid']['delta'] = '0';
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
  /* Field: Content: Campaign Date */
  $handler->display->display_options['fields']['field_campain_date']['id'] = 'field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['field'] = 'field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['label'] = '';
  $handler->display->display_options['fields']['field_campain_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campain_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campain_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campain_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_campain_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campain_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campain_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campain_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_campain_date']['settings'] = array(
    'format_type' => 'timestamp',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_campain_date']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
    'campaign' => 'campaign',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Campaign Date - end date (field_campain_date:value2) */
  $handler->display->display_options['filters']['field_campain_date_value2']['id'] = 'field_campain_date_value2';
  $handler->display->display_options['filters']['field_campain_date_value2']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['filters']['field_campain_date_value2']['field'] = 'field_campain_date_value2';
  $handler->display->display_options['filters']['field_campain_date_value2']['operator'] = '>';
  $handler->display->display_options['filters']['field_campain_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_campain_date_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_campain_date_value2']['year_range'] = '-1:+1';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_campaign_nid';
  $handler->display->display_options['filters']['nid']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Webform Options */
  $handler = $view->new_display('webform_select', 'Webform Options', 'webform_select_1');

  /* Display: Clubs Campaign List */
  $handler = $view->new_display('references', 'Clubs Campaign List', 'references_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'List of current running campaigns for clubs add page';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'references_fields';
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['campaign_list_for_sas'] = $view;

  $view = new view;
  $view->name = 'share_a_stat_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Share a Stat Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Share a Stat Gallery';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'views_galleriffic';
  $handler->display->display_options['style_options']['css'] = '';
  $handler->display->display_options['style_options']['preload'] = '1';
  $handler->display->display_options['style_options']['renderss'] = '';
  $handler->display->display_options['style_options']['history'] = 'true';
  $handler->display->display_options['row_plugin'] = 'gallerifficfields';
  $handler->display->display_options['row_options']['slide_field'] = 'field_share_your_own_image_1';
  $handler->display->display_options['row_options']['thumbnail_field'] = 'field_share_your_own_image';
  /* Field: Webform submissions: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  /* Field: Thumbnail */
  $handler->display->display_options['fields']['field_share_your_own_image']['id'] = 'field_share_your_own_image';
  $handler->display->display_options['fields']['field_share_your_own_image']['table'] = 'field_data_field_share_your_own_image';
  $handler->display->display_options['fields']['field_share_your_own_image']['field'] = 'field_share_your_own_image';
  $handler->display->display_options['fields']['field_share_your_own_image']['ui_name'] = 'Thumbnail';
  $handler->display->display_options['fields']['field_share_your_own_image']['label'] = '';
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_share_your_own_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_share_your_own_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_share_your_own_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_share_your_own_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_share_your_own_image']['field_api_classes'] = 0;
  /* Field: Large */
  $handler->display->display_options['fields']['field_share_your_own_image_1']['id'] = 'field_share_your_own_image_1';
  $handler->display->display_options['fields']['field_share_your_own_image_1']['table'] = 'field_data_field_share_your_own_image';
  $handler->display->display_options['fields']['field_share_your_own_image_1']['field'] = 'field_share_your_own_image';
  $handler->display->display_options['fields']['field_share_your_own_image_1']['ui_name'] = 'Large';
  $handler->display->display_options['fields']['field_share_your_own_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_share_your_own_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_share_your_own_image_1']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_share_your_own_image_1']['field_api_classes'] = 0;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
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
    'social_scholarship' => 'social_scholarship',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'aoisdjfasdf';
  $export['share_a_stat_gallery'] = $view;

  return $export;
}
