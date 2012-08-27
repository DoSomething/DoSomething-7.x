<?php
/**
 * @file
 * dosomething_fb_apps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_fb_apps_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'animal_shetlter_by_submission';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Animal Shetlter by Submission';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Webform Submission: Shelter Name */
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['id'] = 'field_fb_app_shelter_name';
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['table'] = 'field_data_field_fb_app_shelter_name';
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['field'] = 'field_fb_app_shelter_name';
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: Address */
  $handler->display->display_options['fields']['field_fb_app_address']['id'] = 'field_fb_app_address';
  $handler->display->display_options['fields']['field_fb_app_address']['table'] = 'field_data_field_fb_app_address';
  $handler->display->display_options['fields']['field_fb_app_address']['field'] = 'field_fb_app_address';
  $handler->display->display_options['fields']['field_fb_app_address']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['field_api_classes'] = 0;
  /* Field: Webform Submission: City */
  $handler->display->display_options['fields']['field_fb_app_city']['id'] = 'field_fb_app_city';
  $handler->display->display_options['fields']['field_fb_app_city']['table'] = 'field_data_field_fb_app_city';
  $handler->display->display_options['fields']['field_fb_app_city']['field'] = 'field_fb_app_city';
  $handler->display->display_options['fields']['field_fb_app_city']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['field_api_classes'] = 0;
  /* Field: Webform Submission: State */
  $handler->display->display_options['fields']['field_fb_app_state']['id'] = 'field_fb_app_state';
  $handler->display->display_options['fields']['field_fb_app_state']['table'] = 'field_data_field_fb_app_state';
  $handler->display->display_options['fields']['field_fb_app_state']['field'] = 'field_fb_app_state';
  $handler->display->display_options['fields']['field_fb_app_state']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_fb_app_state']['field_api_classes'] = 0;
  /* Field: CityState */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'CityState';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_fb_app_city], [field_fb_app_state]';
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'This is not a DoSomething approved shelter';
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
  /* Contextual filter: Webform submissions: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['sid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['sid']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'sid' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform submissions: Sid',
    ),
  );
  $export['animal_shetlter_by_submission'] = $view;

  $view = new view;
  $view->name = 'pics_for_pets_gallery';
  $view->description = 'This gallery shows animal submissions which are webform submissions.';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Pics for Pets Gallery';
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
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'sorry';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="no-results">
<span class="sorry"> Sorry!</span>
<div class="sorry-text">
We can\'t find what<br />you are looking for.<br />
Please try a new combo.
</div>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['id'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['table'] = 'field_data_field_fb_app_shelter_reference';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['field'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['required'] = 0;
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
  $handler->display->display_options['fields']['sid']['format_plural'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'click to learn more';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'webform-submission/[sid]';
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
  $handler->display->display_options['fields']['nothing']['element_class'] = 'click-to-learn-more';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Webform Submission: Image */
  $handler->display->display_options['fields']['field_fb_app_image']['id'] = 'field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['table'] = 'field_data_field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['field'] = 'field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['element_class'] = 'gallery-pet-image gallery-submission';
  $handler->display->display_options['fields']['field_fb_app_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fb_app_image']['settings'] = array(
    'image_style' => 'gallery_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_fb_app_image']['field_api_classes'] = 0;
  /* Field: Webform Submission: Animal Name */
  $handler->display->display_options['fields']['field_fb_app_animal_name']['id'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['table'] = 'field_data_field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_class'] = 'gallery-pet-text gallery-submission';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field_api_classes'] = 0;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_pfp_address']['id'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['table'] = 'field_data_field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['field'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_address']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['text'] = '[field_pfp_address-locality], [field_pfp_address-administrative_area]';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['element_class'] = 'gallery-pet-text gallery-submission';
  $handler->display->display_options['fields']['field_pfp_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_pfp_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_pfp_address']['field_api_classes'] = 0;
  /* Field: Webform Submission: Facebook Share Count */
  $handler->display->display_options['fields']['field_fb_app_share_count']['id'] = 'field_fb_app_share_count';
  $handler->display->display_options['fields']['field_fb_app_share_count']['table'] = 'field_data_field_fb_app_share_count';
  $handler->display->display_options['fields']['field_fb_app_share_count']['field'] = 'field_fb_app_share_count';
  $handler->display->display_options['fields']['field_fb_app_share_count']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_share_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_share_count']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_fb_app_share_count']['element_wrapper_class'] = 'sid-[sid]';
  $handler->display->display_options['fields']['field_fb_app_share_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['empty'] = '0';
  $handler->display->display_options['fields']['field_fb_app_share_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['type'] = 'share_button';
  $handler->display->display_options['fields']['field_fb_app_share_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_fb_app_share_count']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="gallery-thumbnail-text">
<div class="click-to-learn">[nothing]</div>
[field_fb_app_animal_name]<br />
[field_pfp_address]<br />
<div id=[sid]>[field_fb_app_share_count]</div>
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
  /* Field: Webform Submission: Zip */
  $handler->display->display_options['fields']['field_fb_app_zip']['id'] = 'field_fb_app_zip';
  $handler->display->display_options['fields']['field_fb_app_zip']['table'] = 'field_data_field_fb_app_zip';
  $handler->display->display_options['fields']['field_fb_app_zip']['field'] = 'field_fb_app_zip';
  $handler->display->display_options['fields']['field_fb_app_zip']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['field_api_classes'] = 0;
  /* Field: Webform Submission: What are three words to best describe your furry friend? */
  $handler->display->display_options['fields']['field_fb_app_three_words']['id'] = 'field_fb_app_three_words';
  $handler->display->display_options['fields']['field_fb_app_three_words']['table'] = 'field_data_field_fb_app_three_words';
  $handler->display->display_options['fields']['field_fb_app_three_words']['field'] = 'field_fb_app_three_words';
  $handler->display->display_options['fields']['field_fb_app_three_words']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_three_words']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_three_words']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_fb_app_three_words']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['field_api_classes'] = 0;
  /* Sort criterion: Webform Submission: Facebook Share Count (field_fb_app_share_count) */
  $handler->display->display_options['sorts']['field_fb_app_share_count_value']['id'] = 'field_fb_app_share_count_value';
  $handler->display->display_options['sorts']['field_fb_app_share_count_value']['table'] = 'field_data_field_fb_app_share_count';
  $handler->display->display_options['sorts']['field_fb_app_share_count_value']['field'] = 'field_fb_app_share_count_value';
  $handler->display->display_options['sorts']['field_fb_app_share_count_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_fb_app_share_count_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_fb_app_share_count_value']['expose']['label'] = 'Most Shared';
  /* Sort criterion: dosomething_fb_app: Least Shared */
  $handler->display->display_options['sorts']['least_shared_1']['id'] = 'least_shared_1';
  $handler->display->display_options['sorts']['least_shared_1']['table'] = 'field_data_field_fb_app_share_count';
  $handler->display->display_options['sorts']['least_shared_1']['field'] = 'least_shared';
  $handler->display->display_options['sorts']['least_shared_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['least_shared_1']['expose']['label'] = 'Least Shared';
  /* Sort criterion: dosomething_fb_app_shelter: Closest to me */
  $handler->display->display_options['sorts']['closest_to_me']['id'] = 'closest_to_me';
  $handler->display->display_options['sorts']['closest_to_me']['table'] = 'field_data_field_fb_app_shelter_reference';
  $handler->display->display_options['sorts']['closest_to_me']['field'] = 'closest_to_me';
  $handler->display->display_options['sorts']['closest_to_me']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['closest_to_me']['expose']['label'] = 'Closest to me';
  /* Sort criterion: Webform submissions: Oldest */
  $handler->display->display_options['sorts']['submitted_asc']['id'] = 'submitted_asc';
  $handler->display->display_options['sorts']['submitted_asc']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted_asc']['field'] = 'submitted_asc';
  $handler->display->display_options['sorts']['submitted_asc']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['submitted_asc']['expose']['label'] = 'Oldest';
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  $handler->display->display_options['sorts']['submitted']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['submitted']['expose']['label'] = 'Newest';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );
  /* Filter criterion: Webform Submission: Animal Type (field_fb_app_animal_type) */
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['id'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['table'] = 'field_data_field_fb_app_animal_type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['field'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator_id'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['label'] = 'Sort by';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['identifier'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['reduce'] = 0;
  /* Filter criterion: Webform Submission: Published (field_fb_app_published) */
  $handler->display->display_options['filters']['field_fb_app_published_value']['id'] = 'field_fb_app_published_value';
  $handler->display->display_options['filters']['field_fb_app_published_value']['table'] = 'field_data_field_fb_app_published';
  $handler->display->display_options['filters']['field_fb_app_published_value']['field'] = 'field_fb_app_published_value';
  $handler->display->display_options['filters']['field_fb_app_published_value']['value'] = array(
    1 => '1',
  );

  /* Display: All pets */
  $handler = $view->new_display('panel_pane', 'All pets', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;

  /* Display: Service */
  $handler = $view->new_display('panel_pane', 'Service', 'service');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'sorry';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'We can\'t find what you are looking for.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['id'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['table'] = 'field_data_field_fb_app_shelter_reference';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['field'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['required'] = 0;
  /* Relationship: Webform Submission: Image (field_fb_app_image:fid) */
  $handler->display->display_options['relationships']['field_fb_app_image_fid']['id'] = 'field_fb_app_image_fid';
  $handler->display->display_options['relationships']['field_fb_app_image_fid']['table'] = 'field_data_field_fb_app_image';
  $handler->display->display_options['relationships']['field_fb_app_image_fid']['field'] = 'field_fb_app_image_fid';
  $handler->display->display_options['relationships']['field_fb_app_image_fid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['sid']['alter']['strip_tags'] = 1;
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
  $handler->display->display_options['fields']['nothing']['label'] = 'submission id';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[sid]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Webform Submission: Animal Name */
  $handler->display->display_options['fields']['field_fb_app_animal_name']['id'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['table'] = 'field_data_field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_class'] = 'gallery-pet-text gallery-submission';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: Age */
  $handler->display->display_options['fields']['field_fb_app_age']['id'] = 'field_fb_app_age';
  $handler->display->display_options['fields']['field_fb_app_age']['table'] = 'field_data_field_fb_app_age';
  $handler->display->display_options['fields']['field_fb_app_age']['field'] = 'field_fb_app_age';
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_age']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_age']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_age']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_age']['field_api_classes'] = 0;
  /* Field: Webform Submission: Animal Type */
  $handler->display->display_options['fields']['field_fb_app_animal_type']['id'] = 'field_fb_app_animal_type';
  $handler->display->display_options['fields']['field_fb_app_animal_type']['table'] = 'field_data_field_fb_app_animal_type';
  $handler->display->display_options['fields']['field_fb_app_animal_type']['field'] = 'field_fb_app_animal_type';
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_type']['field_api_classes'] = 0;
  /* Field: Webform Submission: Other */
  $handler->display->display_options['fields']['field_fb_app_other']['id'] = 'field_fb_app_other';
  $handler->display->display_options['fields']['field_fb_app_other']['table'] = 'field_data_field_fb_app_other';
  $handler->display->display_options['fields']['field_fb_app_other']['field'] = 'field_fb_app_other';
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_other']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_other']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_other']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_other']['field_api_classes'] = 0;
  /* Field: Webform Submission: What are three words to best describe your furry friend? */
  $handler->display->display_options['fields']['field_fb_app_three_words']['id'] = 'field_fb_app_three_words';
  $handler->display->display_options['fields']['field_fb_app_three_words']['table'] = 'field_data_field_fb_app_three_words';
  $handler->display->display_options['fields']['field_fb_app_three_words']['field'] = 'field_fb_app_three_words';
  $handler->display->display_options['fields']['field_fb_app_three_words']['label'] = 'Three Words';
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_fb_app_three_words']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_fb_app_three_words']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_fb_app_three_words']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Existing Shelter';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_pfp_address']['id'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['table'] = 'field_data_field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['field'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_address']['label'] = 'Existing Shelter Address';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['text'] = '[field_pfp_address-thoroughfare]
[field_pfp_address-locality], [field_pfp_address-administrative_area] [field_pfp_address-postal_code]';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['element_class'] = 'gallery-pet-text gallery-submission';
  $handler->display->display_options['fields']['field_pfp_address']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_pfp_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_pfp_address']['field_api_classes'] = 0;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_1']['id'] = 'uri_1';
  $handler->display->display_options['fields']['uri_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_1']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_1']['relationship'] = 'field_fb_app_image_fid';
  $handler->display->display_options['fields']['uri_1']['label'] = 'Image';
  $handler->display->display_options['fields']['uri_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['uri_1']['alter']['text'] = '[uri_1]';
  $handler->display->display_options['fields']['uri_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uri_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uri_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uri_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uri_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['uri_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uri_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uri_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uri_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uri_1']['link_to_file'] = 0;
  $handler->display->display_options['fields']['uri_1']['file_download_path'] = 1;
  /* Field: Webform Submission: Shelter Name */
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['id'] = 'field_fb_app_shelter_name';
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['table'] = 'field_data_field_fb_app_shelter_name';
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['field'] = 'field_fb_app_shelter_name';
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: Address */
  $handler->display->display_options['fields']['field_fb_app_address']['id'] = 'field_fb_app_address';
  $handler->display->display_options['fields']['field_fb_app_address']['table'] = 'field_data_field_fb_app_address';
  $handler->display->display_options['fields']['field_fb_app_address']['field'] = 'field_fb_app_address';
  $handler->display->display_options['fields']['field_fb_app_address']['label'] = 'Street';
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_address']['field_api_classes'] = 0;
  /* Field: Webform Submission: City */
  $handler->display->display_options['fields']['field_fb_app_city']['id'] = 'field_fb_app_city';
  $handler->display->display_options['fields']['field_fb_app_city']['table'] = 'field_data_field_fb_app_city';
  $handler->display->display_options['fields']['field_fb_app_city']['field'] = 'field_fb_app_city';
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_city']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_city']['field_api_classes'] = 0;
  /* Field: Webform Submission: State */
  $handler->display->display_options['fields']['field_fb_app_state']['id'] = 'field_fb_app_state';
  $handler->display->display_options['fields']['field_fb_app_state']['table'] = 'field_data_field_fb_app_state';
  $handler->display->display_options['fields']['field_fb_app_state']['field'] = 'field_fb_app_state';
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_state']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_state']['field_api_classes'] = 0;
  /* Field: Webform Submission: Zip */
  $handler->display->display_options['fields']['field_fb_app_zip']['id'] = 'field_fb_app_zip';
  $handler->display->display_options['fields']['field_fb_app_zip']['table'] = 'field_data_field_fb_app_zip';
  $handler->display->display_options['fields']['field_fb_app_zip']['field'] = 'field_fb_app_zip';
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_zip']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_zip']['field_api_classes'] = 0;
  /* Field: Webform Submission: Facebook Share Count */
  $handler->display->display_options['fields']['field_fb_app_share_count']['id'] = 'field_fb_app_share_count';
  $handler->display->display_options['fields']['field_fb_app_share_count']['table'] = 'field_data_field_fb_app_share_count';
  $handler->display->display_options['fields']['field_fb_app_share_count']['field'] = 'field_fb_app_share_count';
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_share_count']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_share_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_fb_app_share_count']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['expose']['label'] = 'Newest';
  $handler->display->display_options['sorts']['submitted']['granularity'] = 'minute';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['arguments']['sid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );
  /* Filter criterion: Webform Submission: Animal Type (field_fb_app_animal_type) */
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['id'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['table'] = 'field_data_field_fb_app_animal_type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['field'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator_id'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['label'] = 'Sort by';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['identifier'] = 'animal_type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['reduce'] = 0;
  /* Filter criterion: Webform Submission: Published (field_fb_app_published) */
  $handler->display->display_options['filters']['field_fb_app_published_value']['id'] = 'field_fb_app_published_value';
  $handler->display->display_options['filters']['field_fb_app_published_value']['table'] = 'field_data_field_fb_app_published';
  $handler->display->display_options['filters']['field_fb_app_published_value']['field'] = 'field_fb_app_published_value';
  $handler->display->display_options['filters']['field_fb_app_published_value']['value'] = array(
    1 => '1',
  );

  /* Display: My shared pets */
  $handler = $view->new_display('panel_pane', 'My shared pets', 'panel_pane_2');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'sorry';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="no-results">
<span class="sorry"> Sorry!</span>
<div class="sorry-text">
You have not shared any pets yet.<br />
Start sharing now!
</div>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Facebook user shares: Facebook user ID */
  $handler->display->display_options['arguments']['fb_user_id']['id'] = 'fb_user_id';
  $handler->display->display_options['arguments']['fb_user_id']['table'] = 'fb_user_shares';
  $handler->display->display_options['arguments']['fb_user_id']['field'] = 'fb_user_id';
  $handler->display->display_options['arguments']['fb_user_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['fb_user_id']['default_argument_type'] = 'current_user_fbid';
  $handler->display->display_options['arguments']['fb_user_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['fb_user_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['fb_user_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['fb_user_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['fb_user_id']['glossary'] = 0;
  $handler->display->display_options['arguments']['fb_user_id']['limit'] = '0';
  $handler->display->display_options['arguments']['fb_user_id']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['fb_user_id']['break_phrase'] = 0;
  $export['pics_for_pets_gallery'] = $view;

  $view = new view;
  $view->name = 'shelter_per_pet';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Shelter per pet';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'You can find me at:';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['id'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['table'] = 'field_data_field_fb_app_shelter_reference';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['field'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['relationships']['field_fb_app_shelter_reference_target_id']['required'] = 1;
  /* Field: Content: Shelter Website */
  $handler->display->display_options['fields']['field_pfp_shelter_website']['id'] = 'field_pfp_shelter_website';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['table'] = 'field_data_field_pfp_shelter_website';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['field'] = 'field_pfp_shelter_website';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_shelter_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['type'] = 'plain';
  $handler->display->display_options['fields']['field_pfp_shelter_website']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_pfp_shelter_website]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_pfp_address']['id'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['table'] = 'field_data_field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['field'] = 'field_pfp_address';
  $handler->display->display_options['fields']['field_pfp_address']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_address']['label'] = '';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['text'] = '[field_pfp_address-thoroughfare]<br />
[field_pfp_address-locality], [field_pfp_address-administrative_area]
';
  $handler->display->display_options['fields']['field_pfp_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pfp_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_pfp_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_pfp_address']['field_api_classes'] = 0;
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_pfp_hours']['id'] = 'field_pfp_hours';
  $handler->display->display_options['fields']['field_pfp_hours']['table'] = 'field_data_field_pfp_hours';
  $handler->display->display_options['fields']['field_pfp_hours']['field'] = 'field_pfp_hours';
  $handler->display->display_options['fields']['field_pfp_hours']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_hours']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_hours']['field_api_classes'] = 0;
  /* Field: Content: Phone Number */
  $handler->display->display_options['fields']['field_pfp_phone_number']['id'] = 'field_pfp_phone_number';
  $handler->display->display_options['fields']['field_pfp_phone_number']['table'] = 'field_data_field_pfp_phone_number';
  $handler->display->display_options['fields']['field_pfp_phone_number']['field'] = 'field_pfp_phone_number';
  $handler->display->display_options['fields']['field_pfp_phone_number']['relationship'] = 'field_fb_app_shelter_reference_target_id';
  $handler->display->display_options['fields']['field_pfp_phone_number']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pfp_phone_number']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pfp_phone_number']['field_api_classes'] = 0;
  /* Contextual filter: Webform submissions: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['sid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['sid']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'sid' => array(
      'type' => 'context',
      'context' => 'entity:webform_submission_entity.sid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform submissions: Sid',
    ),
  );
  $export['shelter_per_pet'] = $view;

  $view = new view;
  $view->name = 'webform_submissions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Webform Submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Webform submission */
  $handler->display->display_options['relationships']['webform_submission']['id'] = 'webform_submission';
  $handler->display->display_options['relationships']['webform_submission']['table'] = 'node';
  $handler->display->display_options['relationships']['webform_submission']['field'] = 'webform_submission';
  $handler->display->display_options['relationships']['webform_submission']['required'] = 0;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'webform_submission';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Field: Webform Submission: Image */
  $handler->display->display_options['fields']['field_fb_app_image']['id'] = 'field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['table'] = 'field_data_field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['field'] = 'field_fb_app_image';
  $handler->display->display_options['fields']['field_fb_app_image']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_fb_app_image']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fb_app_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_fb_app_image']['field_api_classes'] = 0;
  /* Field: Webform Submission: Animal Name */
  $handler->display->display_options['fields']['field_fb_app_animal_name']['id'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['table'] = 'field_data_field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field'] = 'field_fb_app_animal_name';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_animal_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: Shelter */
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['id'] = 'field_fb_app_shelter_reference';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['table'] = 'field_data_field_fb_app_shelter_reference';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['field'] = 'field_fb_app_shelter_reference';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['label'] = '';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['settings'] = array(
    'view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_fb_app_shelter_reference']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'webform_submission';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fb_app_data_gathering_form' => 'fb_app_data_gathering_form',
  );
  /* Filter criterion: Webform Submission: Animal Type (field_fb_app_animal_type) */
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['id'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['table'] = 'field_data_field_fb_app_animal_type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['field'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['relationship'] = 'webform_submission';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator_id'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['label'] = 'Animal Type';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['operator'] = 'field_fb_app_animal_type_value_op';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['identifier'] = 'field_fb_app_animal_type_value';
  $handler->display->display_options['filters']['field_fb_app_animal_type_value']['expose']['reduce'] = 0;

  /* Display: Gallery Content Pane */
  $handler = $view->new_display('panel_pane', 'Gallery Content Pane', 'panel_pane_1');
  $export['webform_submissions'] = $view;

  return $export;
}
