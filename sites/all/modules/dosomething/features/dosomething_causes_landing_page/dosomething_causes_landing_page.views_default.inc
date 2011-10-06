<?php
/**
 * @file
 * dosomething_causes_landing_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_causes_landing_page_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'causes';
  $view->description = 'Causes related displays';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Causes';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Causes';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['required'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_causes_image']['id'] = 'field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['table'] = 'field_data_field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['field'] = 'field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['label'] = '';
  $handler->display->display_options['fields']['field_causes_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_causes_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_causes_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_causes_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_causes_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_causes_image']['settings'] = array(
    'image_style' => 'find_your_cause',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_causes_image']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['operator'] = 'empty';
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['name']['expose']['multiple'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '11 Great Causes for You to Rock';
  $export['causes'] = $view;

  return $export;
}
