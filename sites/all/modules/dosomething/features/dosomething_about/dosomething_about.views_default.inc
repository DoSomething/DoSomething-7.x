<?php
/**
 * @file
 * dosomething_about.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_about_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'about_us';
  $view->description = 'Displays content on the About Us page';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'About Us';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'About Us';
  $handler->display->display_options['css_class'] = 'about-us-page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'dosomething_apps_grid';
  $handler->display->display_options['style_options']['fields']['image'] = 'field_about_image';
  $handler->display->display_options['style_options']['fields']['title'] = 'name';
  $handler->display->display_options['style_options']['fields']['text'] = 'description';
  $handler->display->display_options['style_options']['fields']['link'] = 'field_about_link';
  $handler->display->display_options['style_options']['settings']['last_adjust'] = TRUE;
  $handler->display->display_options['style_options']['settings']['last_every_nth'] = '3';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'DoSomething.org is the country\'s largest not-for-profit for young people and social change. We have 1,666,208 members (and counting) who kick ass on causes they care about. Bullying. Animal cruelty. Homelessness. Cancer. The list goes on. DoSomething.org spearheads national campaigns so 13- to 25-year-olds can make an impact - without ever needing money, an adult, or a car. Over 2.4 million people took action through DoSomething.org in 2012. You know, because apathy sucks.';
  $handler->display->display_options['header']['area']['format'] = '1';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_about_image']['id'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['table'] = 'field_data_field_about_image';
  $handler->display->display_options['fields']['field_about_image']['field'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['label'] = '';
  $handler->display->display_options['fields']['field_about_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_about_image']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Path */
  $handler->display->display_options['fields']['field_about_link']['id'] = 'field_about_link';
  $handler->display->display_options['fields']['field_about_link']['table'] = 'field_data_field_about_link';
  $handler->display->display_options['fields']['field_about_link']['field'] = 'field_about_link';
  $handler->display->display_options['fields']['field_about_link']['label'] = '';
  $handler->display->display_options['fields']['field_about_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_about_link']['type'] = 'default';
  $handler->display->display_options['fields']['field_about_link']['group_column'] = '';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'about_us' => 'about_us',
  );

  /* Display: About Us Page */
  $handler = $view->new_display('page', 'About Us Page', 'page');
  $handler->display->display_options['display_description'] = 'The main About Us page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Path */
  $handler->display->display_options['fields']['field_about_link']['id'] = 'field_about_link';
  $handler->display->display_options['fields']['field_about_link']['table'] = 'field_data_field_about_link';
  $handler->display->display_options['fields']['field_about_link']['field'] = 'field_about_link';
  $handler->display->display_options['fields']['field_about_link']['label'] = '';
  $handler->display->display_options['fields']['field_about_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_link']['group_column'] = '';
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_about_image']['id'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['table'] = 'field_data_field_about_image';
  $handler->display->display_options['fields']['field_about_image']['field'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['label'] = '';
  $handler->display->display_options['fields']['field_about_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_about_image']['alter']['path'] = '[field_about_link]';
  $handler->display->display_options['fields']['field_about_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_about_image']['settings'] = array(
    'image_style' => 'issue_main',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = '[field_about_link]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'about';
  $export['about_us'] = $view;

  return $export;
}
