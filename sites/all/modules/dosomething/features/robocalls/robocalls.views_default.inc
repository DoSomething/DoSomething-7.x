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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
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
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Photo */
  $handler->display->display_options['fields']['field_celeb_photo']['id'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['table'] = 'field_data_field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['field'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_class'] = '[name]-token-tag';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  /* Field: Taxonomy term: Photo thumbnail */
  $handler->display->display_options['fields']['field_photo_thumbnail']['id'] = 'field_photo_thumbnail';
  $handler->display->display_options['fields']['field_photo_thumbnail']['table'] = 'field_data_field_photo_thumbnail';
  $handler->display->display_options['fields']['field_photo_thumbnail']['field'] = 'field_photo_thumbnail';
  /* Field: Taxonomy term: Photo thumbnail */
  $handler->display->display_options['fields']['field_photo_thumbnail_1']['id'] = 'field_photo_thumbnail_1';
  $handler->display->display_options['fields']['field_photo_thumbnail_1']['table'] = 'field_data_field_photo_thumbnail';
  $handler->display->display_options['fields']['field_photo_thumbnail_1']['field'] = 'field_photo_thumbnail';
  /* Field: Taxonomy term: Photo thumbnail */
  $handler->display->display_options['fields']['field_photo_thumbnail_2']['id'] = 'field_photo_thumbnail_2';
  $handler->display->display_options['fields']['field_photo_thumbnail_2']['table'] = 'field_data_field_photo_thumbnail';
  $handler->display->display_options['fields']['field_photo_thumbnail_2']['field'] = 'field_photo_thumbnail';
  $handler->display->display_options['fields']['field_photo_thumbnail_2']['label'] = '';
  $handler->display->display_options['fields']['field_photo_thumbnail_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_photo_thumbnail_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_thumbnail_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_thumbnail_2']['settings'] = array(
    'image_style' => 'robocall_celeb_thumbnail_205x115',
    'image_link' => 'content',
  );
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_1' => 'name_1',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Photo */
  $handler->display->display_options['fields']['field_celeb_photo']['id'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['table'] = 'field_data_field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['field'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_photo']['settings'] = array(
    'image_style' => 'robocall_celeb_thumbnail_205x115',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Photo thumbnail */
  $handler->display->display_options['fields']['field_photo_thumbnail']['id'] = 'field_photo_thumbnail';
  $handler->display->display_options['fields']['field_photo_thumbnail']['table'] = 'field_data_field_photo_thumbnail';
  $handler->display->display_options['fields']['field_photo_thumbnail']['field'] = 'field_photo_thumbnail';
  $handler->display->display_options['fields']['field_photo_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_photo_thumbnail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_photo_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_thumbnail']['settings'] = array(
    'image_style' => 'robocall_celeb_thumbnail_205x115',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_class'] = '[name]-token-tag';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Sound File */
  $handler->display->display_options['fields']['field_celeb_call']['id'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['table'] = 'field_data_field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['field'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_call']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_call']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_celeb_call']['element_class'] = 'robocalls-celeb-play-audio';
  $handler->display->display_options['fields']['field_celeb_call']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_call']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_call']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_celeb_call']['settings'] = array(
    'file_view_mode' => 'media_link',
  );
  /* Field: Send a Call Button */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['ui_name'] = 'Send a Call Button';
  $handler->display->display_options['fields']['name_2']['label'] = '';
  $handler->display->display_options['fields']['name_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['text'] = 'Send a Call';
  $handler->display->display_options['fields']['name_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['link_class'] = 'go-button';
  $handler->display->display_options['fields']['name_2']['element_type'] = 'div';
  $handler->display->display_options['fields']['name_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_2']['link_to_taxonomy'] = TRUE;
  /* Field: Tell Us About It button */
  $handler->display->display_options['fields']['name_3']['id'] = 'name_3';
  $handler->display->display_options['fields']['name_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_3']['field'] = 'name';
  $handler->display->display_options['fields']['name_3']['ui_name'] = 'Tell Us About It button';
  $handler->display->display_options['fields']['name_3']['label'] = '';
  $handler->display->display_options['fields']['name_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_3']['alter']['text'] = 'Tell Us';
  $handler->display->display_options['fields']['name_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_3']['alter']['path'] = '/calloffame/new-celeb';
  $handler->display->display_options['fields']['name_3']['alter']['link_class'] = 'go-button';
  $handler->display->display_options['fields']['name_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_3']['link_to_taxonomy'] = TRUE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'name';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '???';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[name_3]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[name_2]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_photo_thumbnail]
<h4>[name]</h4>
[description]
[field_celeb_call]
[views_conditional]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_class'] = 'robocalls-group-title';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;

  /* Display: Choose Another Celebrity */
  $handler = $view->new_display('block', 'Choose Another Celebrity', 'block_robocalls_choose_another_celeb');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Sound File */
  $handler->display->display_options['fields']['field_celeb_call']['id'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['table'] = 'field_data_field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['field'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_call']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_call']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_celeb_call']['element_class'] = 'robocalls-celeb-play-audio';
  $handler->display->display_options['fields']['field_celeb_call']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_call']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_call']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_celeb_call']['settings'] = array(
    'file_view_mode' => 'media_link',
  );
  /* Field: Taxonomy term: Photo */
  $handler->display->display_options['fields']['field_celeb_photo']['id'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['table'] = 'field_data_field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['field'] = 'field_celeb_photo';
  $handler->display->display_options['fields']['field_celeb_photo']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_photo']['settings'] = array(
    'image_style' => 'robocall_celeb_thumbnail_205x115',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_class'] = '[name]-token-tag';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Send a Call Button */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['ui_name'] = 'Send a Call Button';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = 'Send a Call';
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['link_class'] = 'go-button';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = TRUE;
  /* Field: Tell us next celeb */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['ui_name'] = 'Tell us next celeb';
  $handler->display->display_options['fields']['name_2']['label'] = '';
  $handler->display->display_options['fields']['name_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['text'] = 'Tell Us';
  $handler->display->display_options['fields']['name_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['link_class'] = 'go-button';
  $handler->display->display_options['fields']['name_2']['element_type'] = 'div';
  $handler->display->display_options['fields']['name_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_2']['link_to_taxonomy'] = TRUE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'name';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '???';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[name_2]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[name_1]';
  /* Field: Audio source URL */
  $handler->display->display_options['fields']['field_celeb_call_1']['id'] = 'field_celeb_call_1';
  $handler->display->display_options['fields']['field_celeb_call_1']['table'] = 'field_data_field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call_1']['field'] = 'field_celeb_call';
  $handler->display->display_options['fields']['field_celeb_call_1']['ui_name'] = 'Audio source URL';
  $handler->display->display_options['fields']['field_celeb_call_1']['label'] = '';
  $handler->display->display_options['fields']['field_celeb_call_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celeb_call_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celeb_call_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_celeb_call_1']['type'] = 'file_url_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_celeb_photo]
<h4>[name]</h4>
[description]
[field_celeb_call]
[views_conditional]
<audio src="/files/Memo.mp3"></audio>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $export['cause_its_your_birthday'] = $view;

  return $export;
}
