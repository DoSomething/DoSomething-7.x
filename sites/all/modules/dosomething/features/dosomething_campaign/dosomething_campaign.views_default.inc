<?php
/**
 * @file
 * dosomething_campaign.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_campaign_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'current_campaigns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Current Campaigns';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Content: Campaign (field_report_back_reference) - reverse */
  $handler->display->display_options['relationships']['reverse_field_report_back_reference_node']['id'] = 'reverse_field_report_back_reference_node';
  $handler->display->display_options['relationships']['reverse_field_report_back_reference_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_report_back_reference_node']['field'] = 'reverse_field_report_back_reference_node';
  $handler->display->display_options['relationships']['reverse_field_report_back_reference_node']['required'] = 0;
  /* Field: Content: Background color */
  $handler->display->display_options['fields']['field_campaign_background_color']['id'] = 'field_campaign_background_color';
  $handler->display->display_options['fields']['field_campaign_background_color']['table'] = 'field_data_field_campaign_background_color';
  $handler->display->display_options['fields']['field_campaign_background_color']['field'] = 'field_campaign_background_color';
  $handler->display->display_options['fields']['field_campaign_background_color']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_background_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_background_color']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_background_color']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_background_color']['field_api_classes'] = 0;
  /* Field: Content: Foreground color */
  $handler->display->display_options['fields']['field_campaign_foreground_color']['id'] = 'field_campaign_foreground_color';
  $handler->display->display_options['fields']['field_campaign_foreground_color']['table'] = 'field_data_field_campaign_foreground_color';
  $handler->display->display_options['fields']['field_campaign_foreground_color']['field'] = 'field_campaign_foreground_color';
  $handler->display->display_options['fields']['field_campaign_foreground_color']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_foreground_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['field_api_classes'] = 0;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_campaign_logo']['id'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['table'] = 'field_data_field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['field'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['empty'] = 'logo';
  $handler->display->display_options['fields']['field_campaign_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_campaign_logo']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Get More Info';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_report_back_reference_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Report back';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_campaign_teaser']['id'] = 'field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['table'] = 'field_data_field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['field'] = 'field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['text'] = '[field_campaign_teaser] 

[view_node] [nid] ';
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_teaser']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_teaser']['field_api_classes'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_campaign_main_image']['id'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['field'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_main_image']['empty'] = 'Main image';
  $handler->display->display_options['fields']['field_campaign_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_main_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_campaign_main_image']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="views-field-field-campaign-logo">[field_campaign_logo]</div>
<div class="views-field-field-campaign-teaser">[field_campaign_teaser]</div>
<div class="views-field-field-campaign-main-image">[field_campaign_main_image]</div>
';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'campaigns-container';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_alter_empty'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
  $handler->display->display_options['fields']['view_node_1']['table'] = 'node';
  $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node_1']['label'] = '';
  $handler->display->display_options['fields']['view_node_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node_1']['text'] = 'Join This';
  /* Field: Content: Headline */
  $handler->display->display_options['fields']['field_campaign_headline']['id'] = 'field_campaign_headline';
  $handler->display->display_options['fields']['field_campaign_headline']['table'] = 'field_data_field_campaign_headline';
  $handler->display->display_options['fields']['field_campaign_headline']['field'] = 'field_campaign_headline';
  $handler->display->display_options['fields']['field_campaign_headline']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['text'] = '<span class="campaign-headline">[field_campaign_headline]</span> <span class="campaign-join-this">[view_node_1]</span>';
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_headline']['field_api_classes'] = 0;
  /* Field: Global: Facebook Social Plugin */
  $handler->display->display_options['fields']['fb_social']['id'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['table'] = 'views';
  $handler->display->display_options['fields']['fb_social']['field'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['label'] = '';
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
  $handler->display->display_options['fields']['fb_social']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['fb_social']['fb_social_plugins'] = 'FB Like';
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
    'campaign' => 'campaign',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'campaigns';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Current Campaigns';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Related Campaigns Content pane */
  $handler = $view->new_display('panel_pane', 'Related Campaigns Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Campaigns';
  $handler->display->display_options['display_description'] = 'Related campaigns pane - pulled into Causes term page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_campaign_logo']['id'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['table'] = 'field_data_field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['field'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_campaign_logo']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_type'] = 'span';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'related-campaign-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Do This';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'vocabulary_1' => 0,
    'vocabulary_9' => 0,
    'vocabulary_5' => 0,
    'blog_type' => 0,
    'vocabulary_6' => 0,
    'vocabulary_11' => 0,
    'vocabulary_18' => 0,
    'vocabulary_17' => 0,
    'vocabulary_15' => 0,
    'vocabulary_19' => 0,
    'vocabulary_4' => 0,
    'vocabulary_16' => 0,
    'vocabulary_2' => 0,
    'vocabulary_3' => 0,
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;
  $export['current_campaigns'] = $view;

  return $export;
}
