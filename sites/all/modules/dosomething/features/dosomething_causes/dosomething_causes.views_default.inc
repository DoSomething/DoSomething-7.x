<?php
/**
 * @file
 * dosomething_causes.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_causes_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'causes';
  $view->description = 'Causes and Issues related displays';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Causes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find Your Cause';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rotoslider';
  $handler->display->display_options['style_options']['fields']['title'] = 'name';
  $handler->display->display_options['style_options']['fields']['image'] = 'field_causes_image';
  $handler->display->display_options['style_options']['fields']['text'] = 'description';
  $handler->display->display_options['style_options']['settings']['link'] = 1;
  $handler->display->display_options['style_options']['settings']['image'] = 0;
  $handler->display->display_options['style_options']['initial']['default'] = 1;
  $handler->display->display_options['style_options']['initial']['title'] = 'Explore The Issues';
  $handler->display->display_options['style_options']['initial']['image'] = 'field_causes_image_1';
  $handler->display->display_options['style_options']['initial']['text'] = 'description_1';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Locavore farm-to-table bicycle rights, artisan 8-bit four loko wes anderson. Tumblr brunch aesthetic twee farm-to-table. High life locavore +1, messenger bag terry richardson butcher salvia.';
  $handler->display->display_options['header']['area']['format'] = '1';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_causes_image']['id'] = 'field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['table'] = 'field_data_field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['field'] = 'field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['label'] = '';
  $handler->display->display_options['fields']['field_causes_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_causes_image']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_causes_image_1']['id'] = 'field_causes_image_1';
  $handler->display->display_options['fields']['field_causes_image_1']['table'] = 'field_data_field_causes_image';
  $handler->display->display_options['fields']['field_causes_image_1']['field'] = 'field_causes_image';
  $handler->display->display_options['fields']['field_causes_image_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['field_causes_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_causes_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_causes_image_1']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description_1']['id'] = 'description_1';
  $handler->display->display_options['fields']['description_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description_1']['field'] = 'description';
  $handler->display->display_options['fields']['description_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['description_1']['label'] = '';
  $handler->display->display_options['fields']['description_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description_1']['hide_alter_empty'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: Taxonomy term: Parent term */
  $handler->display->display_options['arguments']['parent']['id'] = 'parent';
  $handler->display->display_options['arguments']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['arguments']['parent']['field'] = 'parent';
  $handler->display->display_options['arguments']['parent']['default_action'] = 'default';
  $handler->display->display_options['arguments']['parent']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['parent']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['parent']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['parent']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );

  /* Display: Issues content pane */
  $handler = $view->new_display('panel_pane', 'Issues content pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'displays child issue terms on a Cause parent page ';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'dosomething_apps_grid';
  $handler->display->display_options['style_options']['fields']['image'] = 'field_causes_image';
  $handler->display->display_options['style_options']['fields']['title'] = 'dosomething_causes_link_1';
  $handler->display->display_options['style_options']['fields']['text'] = 'description';
  $handler->display->display_options['style_options']['fields']['link'] = 'dosomething_causes_link';
  $handler->display->display_options['style_options']['settings']['last_adjust'] = TRUE;
  $handler->display->display_options['style_options']['settings']['last_every_nth'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>We have resources and project ideas for every issue you can think of. Browse below for easy ways to get involved in your community around your favorite cause.</p>';
  $handler->display->display_options['header']['area']['format'] = '3';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  /* Field: Go link */
  $handler->display->display_options['fields']['dosomething_causes_link']['id'] = 'dosomething_causes_link';
  $handler->display->display_options['fields']['dosomething_causes_link']['table'] = 'views';
  $handler->display->display_options['fields']['dosomething_causes_link']['field'] = 'dosomething_causes_link';
  $handler->display->display_options['fields']['dosomething_causes_link']['ui_name'] = 'Go link';
  $handler->display->display_options['fields']['dosomething_causes_link']['label'] = '';
  $handler->display->display_options['fields']['dosomething_causes_link']['alter']['text'] = 'taxonomy/term/[tid]';
  $handler->display->display_options['fields']['dosomething_causes_link']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_causes_image']['id'] = 'field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['table'] = 'field_data_field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['field'] = 'field_causes_image';
  $handler->display->display_options['fields']['field_causes_image']['label'] = '';
  $handler->display->display_options['fields']['field_causes_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_causes_image']['alter']['path'] = '[dosomething_causes_link]';
  $handler->display->display_options['fields']['field_causes_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_causes_image']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_causes_image_1']['id'] = 'field_causes_image_1';
  $handler->display->display_options['fields']['field_causes_image_1']['table'] = 'field_data_field_causes_image';
  $handler->display->display_options['fields']['field_causes_image_1']['field'] = 'field_causes_image';
  $handler->display->display_options['fields']['field_causes_image_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['field_causes_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_causes_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_causes_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_causes_image_1']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description_1']['id'] = 'description_1';
  $handler->display->display_options['fields']['description_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description_1']['field'] = 'description';
  $handler->display->display_options['fields']['description_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['description_1']['label'] = '';
  $handler->display->display_options['fields']['description_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description_1']['hide_alter_empty'] = FALSE;
  /* Field: Title link */
  $handler->display->display_options['fields']['dosomething_causes_link_1']['id'] = 'dosomething_causes_link_1';
  $handler->display->display_options['fields']['dosomething_causes_link_1']['table'] = 'views';
  $handler->display->display_options['fields']['dosomething_causes_link_1']['field'] = 'dosomething_causes_link';
  $handler->display->display_options['fields']['dosomething_causes_link_1']['ui_name'] = 'Title link';
  $handler->display->display_options['fields']['dosomething_causes_link_1']['label'] = '';
  $handler->display->display_options['fields']['dosomething_causes_link_1']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['dosomething_causes_link_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['dosomething_causes_link_1']['alter']['path'] = 'taxonomy/term/[tid]';
  $handler->display->display_options['fields']['dosomething_causes_link_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['dosomething_causes_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dosomething_causes_link_1']['dosomething_causes_link_type'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Parent term */
  $handler->display->display_options['arguments']['parent']['id'] = 'parent';
  $handler->display->display_options['arguments']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['arguments']['parent']['field'] = 'parent';
  $handler->display->display_options['arguments']['parent']['default_action'] = 'default';
  $handler->display->display_options['arguments']['parent']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['parent']['default_argument_options']['argument'] = '0';
  $handler->display->display_options['arguments']['parent']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['parent']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['parent']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'causes';
  $export['causes'] = $view;

  $view = new view();
  $view->name = 'find_your_cause';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Find Your Cause';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find Your Cause';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_campaign_main_image']['id'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['field'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_main_image']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Learn More &raquo;';
  /* Field: Global: Facebook Social Plugin */
  $handler->display->display_options['fields']['fb_social']['id'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['table'] = 'views';
  $handler->display->display_options['fields']['fb_social']['field'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['label'] = '';
  $handler->display->display_options['fields']['fb_social']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fb_social']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['fb_social']['fb_social_plugins'] = 'FB Like';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['tid']['add_table'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['arguments']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid_1']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid_1']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid_1']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['tid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid_1']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid_1']['validate_options']['vocabularies'] = array(
    'vocabulary_5' => 'vocabulary_5',
  );
  $handler->display->display_options['arguments']['tid_1']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid_1']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['tid_1']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['tid_1']['add_table'] = TRUE;
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
    'action_guide' => 'action_guide',
    'campaign' => 'campaign',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'find-your-cause';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Find Your Cause';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Find Your Cause Content Pane */
  $handler = $view->new_display('panel_pane', 'Find Your Cause Content Pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Displays the main content of the Find Your Cause Page.';
  $export['find_your_cause'] = $view;

  $view = new view();
  $view->name = 'polls';
  $view->description = 'Displays Poll related content';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Polls';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Poll';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  /* Relationship: Field: Issues (taxonomy_vocabulary_5) */
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['id'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['table'] = 'field_data_taxonomy_vocabulary_5';
  $handler->display->display_options['relationships']['taxonomy_vocabulary_5_tid']['field'] = 'taxonomy_vocabulary_5_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'taxonomy_vocabulary_5_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'poll' => 'poll',
  );

  /* Display: Poll Content Pane */
  $handler = $view->new_display('panel_pane', 'Poll Content Pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Displays a list of related Poll content.';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: FB Social Attachment */
  $handler = $view->new_display('attachment', 'FB Social Attachment', 'attachment_1');
  $handler->display->display_options['display_description'] = 'Attaches the FB Social Plugin to the Poll Content Pane.';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Global: Facebook Social Plugin */
  $handler->display->display_options['fields']['fb_social']['id'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['table'] = 'views';
  $handler->display->display_options['fields']['fb_social']['field'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['label'] = '';
  $handler->display->display_options['fields']['fb_social']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fb_social']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['fb_social']['fb_social_plugins'] = 'FB Like';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['displays'] = array(
    'panel_pane_1' => 'panel_pane_1',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['polls'] = $view;

  return $export;
}
