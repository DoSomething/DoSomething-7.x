<?php
/**
 * @file
 * robocalls.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function robocalls_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cause_its_your_birthday';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Cause Call / Robo Call';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cause it\'s your birthday';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_celeb_call' => 0,
    'field_celeb_photo' => 0,
    'name' => 0,
    'description' => 0,
    'name_1' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_celeb_call' => 0,
    'field_celeb_photo' => 0,
    'name' => 0,
    'description' => 0,
    'name_1' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_1' => 'name_1',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['required'] = 0;
  /* Field: Taxonomy term: Photo */
  $handler->display->display_options['fields']['field_celeb_photo']['id'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['table'] = 'field_data_field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['field'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_celeb_photo']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_class'] = '[name]-token-tag';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['name']['convert_spaces'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['name_1']['convert_spaces'] = 0;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 1;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'parent';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'vocabulary_99' => 'vocabulary_99',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Photo (field_celeb_photo:fid) */
  $handler->display->display_options['filters']['field_celeb_photo_fid']['id'] = 'field_celeb_photo_fid';
  $handler->display->display_options['filters']['field_celeb_photo_fid']['table'] = 'field_data_field_celeb_photo';
  $handler->display->display_options['filters']['field_celeb_photo_fid']['field'] = 'field_celeb_photo_fid';
  $handler->display->display_options['filters']['field_celeb_photo_fid']['operator'] = 'not empty';

  /* Display: Cause Call Landing Page */
  $handler = $view->new_display('block', 'Cause Call Landing Page', 'block_robocall_celebs');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_1' => 'name_1',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Photo */
  $handler->display->display_options['fields']['field_celeb_photo']['id'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['table'] = 'field_data_field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['field'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_photo']['settings'] = array(
    'image_style' => 'robocall_celeb_thumbnail_205x115',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_celeb_photo']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_class'] = '[name]-token-tag';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['name']['convert_spaces'] = 0;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 1;
  /* Field: Taxonomy term: Sound File */
  $handler->display->display_options['fields']['field_celeb_call']['id'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['table'] = 'field_data_field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['field'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_call']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_celeb_call']['element_class'] = 'robocalls-celeb-play-audio';
  $handler->display->display_options['fields']['field_celeb_call']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_call']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_celeb_call']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_celeb_call']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_call']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_celeb_call']['settings'] = array(
    'file_view_mode' => 'media_link',
  );
  $handler->display->display_options['fields']['field_celeb_call']['field_api_classes'] = 0;
  /* Field: Send a Call Link */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['ui_name'] = 'Send a Call Link';
  $handler->display->display_options['fields']['name_2']['label'] = '';
  $handler->display->display_options['fields']['name_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name_2']['alter']['text'] = 'Send a Call';
  $handler->display->display_options['fields']['name_2']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_2']['alter']['link_class'] = 'go-button';
  $handler->display->display_options['fields']['name_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_2']['element_type'] = 'div';
  $handler->display->display_options['fields']['name_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name_2']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['name_2']['convert_spaces'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_celeb_photo]
<h3>[name]</h3>
[description]
[field_celeb_call]
[name_2]';
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
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_class'] = 'robocalls-group-title';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['name_1']['convert_spaces'] = 0;

  /* Display: Choose Another Celebrity */
  $handler = $view->new_display('block', 'Choose Another Celebrity', 'block_robocalls_choose_another_celeb');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = 'both';
  $handler->display->display_options['style_options']['visible'] = '3';
  $handler->display->display_options['style_options']['scroll'] = '3';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['animation'] = 'fast';
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_1' => 'name_1',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Sound File */
  $handler->display->display_options['fields']['field_celeb_call']['id'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['table'] = 'field_data_field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['field'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_call']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_celeb_call']['element_class'] = 'robocalls-celeb-play-audio';
  $handler->display->display_options['fields']['field_celeb_call']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_call']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_celeb_call']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_celeb_call']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_celeb_call']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_call']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_celeb_call']['settings'] = array(
    'file_view_mode' => 'media_link',
  );
  $handler->display->display_options['fields']['field_celeb_call']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Photo */
  $handler->display->display_options['fields']['field_celeb_photo']['id'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['table'] = 'field_data_field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['field'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_celeb_photo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_celeb_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_photo']['settings'] = array(
    'image_style' => 'robocall_celeb_thumbnail_205x115',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_celeb_photo']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_class'] = '[name]-token-tag';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['name']['convert_spaces'] = 0;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 1;
  /* Field: Send a Call Button */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['ui_name'] = 'Send a Call Button';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = 'Send a Call';
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['link_class'] = 'go-button';
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['name_1']['convert_spaces'] = 0;
  /* Field: Audio source URL */
  $handler->display->display_options['fields']['field_celeb_call_1']['id'] = 'field_celeb_call_1';
  $handler->display->display_options['fields']['field_celeb_call_1']['table'] = 'field_data_field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call_1']['field'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call_1']['ui_name'] = 'Audio source URL';
  $handler->display->display_options['fields']['field_celeb_call_1']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_call_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_call_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_celeb_call_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_celeb_call_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_celeb_call_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_call_1']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_celeb_call_1']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_celeb_photo]
<h3>[name]</h3>
[description]
[field_celeb_call]
[name_1]
<audio src="/files/Memo.mp3"></audio>';
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
  $export['cause_its_your_birthday'] = $view;

  return $export;
}
