<?php
/**
 * @file
 * crazyshit.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crazyshit_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crazy_shit_landing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Crazy Shit landing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crazy Shit landing page';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<p class="no-results">No posts yet -- <a href="/crazy/submit">submit yours!</a></p>';
  $handler->display->display_options['empty']['area']['format'] = '3';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 0;
  $handler->display->display_options['fields']['picture']['image_style'] = 'crazy_facebook_picture';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 0;
  /* Field: Webform submissions: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = '';
  $handler->display->display_options['fields']['sid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['more_link'] = 0;
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
  /* Field: Webform Submission: A Crazy Image */
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['id'] = 'field_crazy_crazy_picture';
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['table'] = 'field_data_field_crazy_crazy_picture';
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['field'] = 'field_crazy_crazy_picture';
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['label'] = '';
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['settings'] = array(
    'image_style' => 'crazy_image_dimensions',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_crazy_crazy_picture']['field_api_classes'] = 0;
  /* Field: Webform Submission: Crazy Count */
  $handler->display->display_options['fields']['field_crazy_count']['id'] = 'field_crazy_count';
  $handler->display->display_options['fields']['field_crazy_count']['table'] = 'field_data_field_crazy_count';
  $handler->display->display_options['fields']['field_crazy_count']['field'] = 'field_crazy_count';
  $handler->display->display_options['fields']['field_crazy_count']['label'] = '';
  $handler->display->display_options['fields']['field_crazy_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crazy_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_crazy_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_crazy_count']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_crazy_count']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_crazy_count']['field_api_classes'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_conditional']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_conditional']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_conditional']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_crazy_count';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '5';
  $handler->display->display_options['fields']['views_conditional']['then'] = '0';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_crazy_count]';
  /* Field: Webform Submission: Bullshit count */
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['id'] = 'field_crazy_bullshit_count';
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['table'] = 'field_data_field_crazy_bullshit_count';
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['field'] = 'field_crazy_bullshit_count';
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['label'] = '';
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_crazy_bullshit_count']['field_api_classes'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_2']['id'] = 'views_conditional_2';
  $handler->display->display_options['fields']['views_conditional_2']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_conditional_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_conditional_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_conditional_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_conditional_2']['if'] = 'field_crazy_bullshit_count';
  $handler->display->display_options['fields']['views_conditional_2']['condition'] = '5';
  $handler->display->display_options['fields']['views_conditional_2']['then'] = '0';
  $handler->display->display_options['fields']['views_conditional_2']['or'] = '[field_crazy_bullshit_count]';
  /* Field: Webform Submission: Vouch Count */
  $handler->display->display_options['fields']['field_crazy_vouch_count']['id'] = 'field_crazy_vouch_count';
  $handler->display->display_options['fields']['field_crazy_vouch_count']['table'] = 'field_data_field_crazy_vouch_count';
  $handler->display->display_options['fields']['field_crazy_vouch_count']['field'] = 'field_crazy_vouch_count';
  $handler->display->display_options['fields']['field_crazy_vouch_count']['label'] = '';
  $handler->display->display_options['fields']['field_crazy_vouch_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_crazy_vouch_count']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_crazy_vouch_count']['field_api_classes'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_conditional_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_conditional_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_conditional_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_crazy_vouch_count';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '5';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '0';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[field_crazy_vouch_count]';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['field_api_classes'] = 0;
  /* Field: Webform submissions: Submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['label'] = '';
  $handler->display->display_options['fields']['submitted']['exclude'] = TRUE;
  $handler->display->display_options['fields']['submitted']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['external'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['submitted']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['submitted']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['submitted']['alter']['html'] = 0;
  $handler->display->display_options['fields']['submitted']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['submitted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['submitted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['submitted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['submitted']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['submitted']['date_format'] = 'field_recipient_birthdate_medium';
  /* Field: Buttons */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Buttons';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="vouch-button">
<a href="#" class="button-submit" rel="[sid]">I Believe It</a>
<span>[views_conditional_1]</span>
</div>
<div class="bs-button">
<a href="#" class="button-submit" rel="[sid]">Call BS</a>
<span>[views_conditional_2]</span>
</div>
<div class="fb-share">
<a href="#" rel="[sid]">Share on Facebook</a>
</div>';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_alter_empty'] = 0;
  /* Field: Template */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Template';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="crazy-submission s-[sid] a-[uid]">
<div class="fb-and-pic">
<div class="fb-picture">[picture]</div>
<div class="s-[sid]-picture simg">[field_crazy_crazy_picture]</div>
</div>
<p class="buttons">
[nothing_1]
</p>
<p class="author">[field_user_first_name]</p>
<div class="dateline">[submitted]</div>
</div>
';
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
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Sort criterion: Webform Submission: All Time Count (field_crazy_total_count) */
  $handler->display->display_options['sorts']['field_crazy_total_count_value']['id'] = 'field_crazy_total_count_value';
  $handler->display->display_options['sorts']['field_crazy_total_count_value']['table'] = 'field_data_field_crazy_total_count';
  $handler->display->display_options['sorts']['field_crazy_total_count_value']['field'] = 'field_crazy_total_count_value';
  $handler->display->display_options['sorts']['field_crazy_total_count_value']['order'] = 'DESC';
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'crazy_shit' => 'crazy_shit',
  );

  /* Display: Gallery View */
  $handler = $view->new_display('block', 'Gallery View', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'crazy_shit' => 'crazy_shit',
  );

  /* Display: Friends View */
  $handler = $view->new_display('block', 'Friends View', 'friends_view');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<p>None of your friends have told their story yet.  Click invite friends to get them to tell their tale.</p>';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'crazy_shit' => 'crazy_shit',
  );
  /* Filter criterion: Webform submissions: UID */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '1';
  $export['crazy_shit_landing'] = $view;

  return $export;
}
