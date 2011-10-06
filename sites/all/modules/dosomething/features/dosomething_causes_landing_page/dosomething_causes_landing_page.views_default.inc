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

  /* Display: Causes Landing Page Block */
  $handler = $view->new_display('block', 'Causes Landing Page Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '11 Great Causes for You to Rock';
  $handler->display->display_options['display_description'] = 'The main content for the causes landing page';

  /* Display: Causes content pane */
  $handler = $view->new_display('panel_pane', 'Causes content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
    'image_style' => 'cause_main',
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'vocabulary_1' => 0,
    'vocabulary_9' => 0,
    'vocabulary_5' => 0,
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
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['not'] = 0;
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.extension',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Taxonomy term: Term ID',
    ),
  );

  /* Display: Issues content pane */
  $handler = $view->new_display('panel_pane', 'Issues content pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Explore The Issues';
  $handler->display->display_options['display_description'] = 'displays child issue terms on a Cause parent page ';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Parent term */
  $handler->display->display_options['arguments']['parent']['id'] = 'parent';
  $handler->display->display_options['arguments']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['arguments']['parent']['field'] = 'parent';
  $handler->display->display_options['arguments']['parent']['default_action'] = 'default';
  $handler->display->display_options['arguments']['parent']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['parent']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['parent']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['parent']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['parent']['default_argument_options']['vocabularies'] = array(
    'vocabulary_1' => 0,
    'vocabulary_9' => 0,
    'vocabulary_5' => 0,
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
  $handler->display->display_options['arguments']['parent']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['parent']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['parent']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['parent']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['parent']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['parent']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 0;
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'none',
      'context' => 'entity:file.extension',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Taxonomy term: Term ID',
    ),
  );
  $export['causes'] = $view;

  return $export;
}
