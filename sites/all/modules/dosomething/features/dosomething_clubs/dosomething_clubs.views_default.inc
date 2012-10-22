<?php
/**
 * @file
 * dosomething_clubs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_clubs_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'campaign_list_for_clubs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campaign List for Clubs';
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
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_conditional']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_conditional']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_conditional']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_campain_date';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = ' (Sign Up has not yet started -- check back soon.)';
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
  $export['campaign_list_for_clubs'] = $view;

  $view = new view;
  $view->name = 'club_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Club Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Club Members';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'More >>';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Club members pictures coming soon!';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Group membership: User group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 0;
  /* Relationship: OG membership: Group gid */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['group']['required'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 1;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
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
  $handler->display->display_options['fields']['picture']['image_style'] = 'project_related_thumb';
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Joined [created] ';
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/Y';
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
  $handler->display->display_options['sorts']['created_1']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created_1']['field'] = 'created';
  $handler->display->display_options['sorts']['created_1']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['sorts']['created_1']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Club Members */
  $handler = $view->new_display('panel_pane', 'Club Members', 'panel_pane_1');
  $handler->display->display_options['link_url'] = 'club/!1/members';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Club Members All */
  $handler = $view->new_display('panel_pane', 'Club Members All', 'panel_pane_2');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['group']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'group' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group gid',
    ),
  );
  $export['club_members'] = $view;

  $view = new view;
  $view->name = 'club_photo_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Club Photo Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Gallery';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['skin'] = '';
  $handler->display->display_options['style_options']['visible'] = '5';
  $handler->display->display_options['style_options']['scroll'] = '1';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Do you have any new photos to add? */
  $handler->display->display_options['fields']['field_project_photo']['id'] = 'field_project_photo';
  $handler->display->display_options['fields']['field_project_photo']['table'] = 'field_data_field_project_photo';
  $handler->display->display_options['fields']['field_project_photo']['field'] = 'field_project_photo';
  $handler->display->display_options['fields']['field_project_photo']['label'] = '';
  $handler->display->display_options['fields']['field_project_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_project_photo']['settings'] = array(
    'image_style' => 'club_gallery_photos_120x120',
    'image_link' => 'file',
  );
  $handler->display->display_options['fields']['field_project_photo']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_project_photo']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_project_photo']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
    'club' => 'club',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'node_edit_form.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['club_photo_gallery'] = $view;

  $view = new view;
  $view->name = 'club_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Club Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Doing It';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'More >>';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<a href="/campaigns">Join a Campaign</a> or <a href="/projects/submit">Start a project</a>';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Group membership: User group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 0;
  /* Relationship: OG membership: Group gid */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['group']['required'] = 0;
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
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_picture']['empty'] = '<a href="/webform-submission/[sid]"><img src="/sites/all/modules/dosomething/features/dosomething_projects_general/project-nopic-60x60.png" alt="Official Dosomething.org Project" /></a>
';
  $handler->display->display_options['fields']['field_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'project_related_thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['separator'] = '';
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Webform Submission: Title of your project */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['field_project_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_title']['field_api_classes'] = 0;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project_report' => 'project_report',
  );
  /* Filter criterion: Webform Submission: What&#039;s the status of your project? (field_project_type) */
  $handler->display->display_options['filters']['field_project_type_value']['id'] = 'field_project_type_value';
  $handler->display->display_options['filters']['field_project_type_value']['table'] = 'field_data_field_project_type';
  $handler->display->display_options['filters']['field_project_type_value']['field'] = 'field_project_type_value';
  $handler->display->display_options['filters']['field_project_type_value']['value'] = array(
    2 => '2',
    3 => '3',
  );

  /* Display: Doing It pane */
  $handler = $view->new_display('panel_pane', 'Doing It pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Doing It pane - All */
  $handler = $view->new_display('panel_pane', 'Doing It pane - All', 'panel_pane_3');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
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
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_picture']['empty'] = '<a href="/webform-submission/[sid]"><img src="/sites/all/modules/dosomething/features/dosomething_projects_general/project-nopic-120x120.png" alt="Official Dosomething.org Project" /></a>
';
  $handler->display->display_options['fields']['field_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['separator'] = '';
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Webform Submission: Title of your project */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['field_project_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_title']['field_api_classes'] = 0;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Done It pane */
  $handler = $view->new_display('panel_pane', 'Done It pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Done It';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project_report' => 'project_report',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Webform Submission: What&#039;s the status of your project? (field_project_type) */
  $handler->display->display_options['filters']['field_project_type_value']['id'] = 'field_project_type_value';
  $handler->display->display_options['filters']['field_project_type_value']['table'] = 'field_data_field_project_type';
  $handler->display->display_options['filters']['field_project_type_value']['field'] = 'field_project_type_value';
  $handler->display->display_options['filters']['field_project_type_value']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_project_type_value']['group'] = 0;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Done It pane - All */
  $handler = $view->new_display('panel_pane', 'Done It pane - All', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Done It';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
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
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_picture']['empty'] = '<a href="/webform-submission/[sid]"><img src="/sites/all/modules/dosomething/features/dosomething_projects_general/project-nopic-120x120.png" alt="Official Dosomething.org Project" /></a>
';
  $handler->display->display_options['fields']['field_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['separator'] = '';
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Webform Submission: Title of your project */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['path'] = 'webform-submission/[sid]';
  $handler->display->display_options['fields']['field_project_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_title']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project_report' => 'project_report',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Webform Submission: What&#039;s the status of your project? (field_project_type) */
  $handler->display->display_options['filters']['field_project_type_value']['id'] = 'field_project_type_value';
  $handler->display->display_options['filters']['field_project_type_value']['table'] = 'field_data_field_project_type';
  $handler->display->display_options['filters']['field_project_type_value']['field'] = 'field_project_type_value';
  $handler->display->display_options['filters']['field_project_type_value']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_project_type_value']['group'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['club_projects'] = $view;

  $view = new view;
  $view->name = 'club_school_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Club School Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Club Name / School Name';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
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
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_club_address']['id'] = 'field_club_address';
  $handler->display->display_options['fields']['field_club_address']['table'] = 'field_data_field_club_address';
  $handler->display->display_options['fields']['field_club_address']['field'] = 'field_club_address';
  $handler->display->display_options['fields']['field_club_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_club_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_club_address']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_club_city']['id'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['table'] = 'field_data_field_club_city';
  $handler->display->display_options['fields']['field_club_city']['field'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_club_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_city']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_club_city']['field_api_classes'] = 0;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_club_state']['id'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['fields']['field_club_state']['field'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_club_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_state']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_club_state']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_club_state']['field_api_classes'] = 0;
  /* Field: Content: ZIP/Postal Code */
  $handler->display->display_options['fields']['field_club_zip']['id'] = 'field_club_zip';
  $handler->display->display_options['fields']['field_club_zip']['table'] = 'field_data_field_club_zip';
  $handler->display->display_options['fields']['field_club_zip']['field'] = 'field_club_zip';
  $handler->display->display_options['fields']['field_club_zip']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['field_api_classes'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'club' => 'club',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'club-data-export.csv';
  $export['club_school_data'] = $view;

  $view = new view;
  $view->name = 'clubs';
  $view->description = 'Club related displays.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clubs';
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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search!';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Start over';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<p>Browse these clubs to find one near you. If there are none nearby, <a href="http://www.dosomething.org/node/add/club" target="_blank">start your own</a>.</p>';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
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
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_club_state']['id'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['fields']['field_club_state']['field'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['label'] = '';
  $handler->display->display_options['fields']['field_club_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_club_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_state']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_club_city']['id'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['table'] = 'field_data_field_club_city';
  $handler->display->display_options['fields']['field_club_city']['field'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['label'] = '';
  $handler->display->display_options['fields']['field_club_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_club_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_city']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['field_api_classes'] = 0;
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'club' => 'club',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: State (field_club_state) */
  $handler->display->display_options['filters']['field_club_state_value']['id'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['filters']['field_club_state_value']['field'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['group'] = 1;
  $handler->display->display_options['filters']['field_club_state_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['operator_id'] = 'field_club_state_value_op';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['label'] = 'State/Province (field_club_state)';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['operator'] = 'field_club_state_value_op';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['identifier'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Location: Distance / Proximity */
  $handler->display->display_options['filters']['distance']['id'] = 'distance';
  $handler->display->display_options['filters']['distance']['table'] = 'location';
  $handler->display->display_options['filters']['distance']['field'] = 'distance';
  $handler->display->display_options['filters']['distance']['operator'] = 'dist';
  $handler->display->display_options['filters']['distance']['value'] = array(
    'latitude' => '',
    'longitude' => '',
    'postal_code' => '',
    'country' => '',
    'php_code' => '',
    'nid_arg' => '',
    'nid_loc_field' => 'node',
    'uid_arg' => '',
    'search_distance' => '10',
    'search_units' => 'mile',
  );
  $handler->display->display_options['filters']['distance']['group'] = 1;
  $handler->display->display_options['filters']['distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['distance']['expose']['operator_id'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['label'] = 'Distance / Proximity';
  $handler->display->display_options['filters']['distance']['expose']['operator'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['identifier'] = 'distance';
  $handler->display->display_options['filters']['distance']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['distance']['expose']['gmap_macro'] = array(
    'default' => '[gmap ]',
  );
  $handler->display->display_options['filters']['distance']['expose']['user_location_choose'] = array(
    'default' => FALSE,
  );
  $handler->display->display_options['filters']['distance']['origin'] = 'postal_default';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;

  /* Display: Club Results Content Pane */
  $handler = $view->new_display('panel_pane', 'Club Results Content Pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Displays search results for a state or zip club search.';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'og_description' => 'og_description',
    'field_club_state' => 'field_club_state',
    'field_club_city' => 'field_club_city',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Club';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_club_state']['id'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['fields']['field_club_state']['field'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['label'] = 'State/Province';
  $handler->display->display_options['fields']['field_club_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_state']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_club_city']['id'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['table'] = 'field_data_field_club_city';
  $handler->display->display_options['fields']['field_club_city']['field'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_city']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'club' => 'club',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: State (field_club_state) */
  $handler->display->display_options['filters']['field_club_state_value']['id'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['filters']['field_club_state_value']['field'] = 'field_club_state_value';
  $handler->display->display_options['filters']['field_club_state_value']['group'] = 0;
  $handler->display->display_options['filters']['field_club_state_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_club_state_value']['expose']['operator_id'] = 'field_club_state_value_op';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['label'] = 'Browse Clubs by State';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['operator'] = 'field_club_state_value_op';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['field_club_state_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: ZIP/Postal Code (field_club_zip) */
  $handler->display->display_options['filters']['field_club_zip_value']['id'] = 'field_club_zip_value';
  $handler->display->display_options['filters']['field_club_zip_value']['table'] = 'field_data_field_club_zip';
  $handler->display->display_options['filters']['field_club_zip_value']['field'] = 'field_club_zip_value';
  $handler->display->display_options['filters']['field_club_zip_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['operator_id'] = 'field_club_zip_value_op';
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['label'] = 'Browse Clubs by Zip';
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['operator'] = 'field_club_zip_value_op';
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['identifier'] = 'zip';
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_club_zip_value']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_club_state' => 'field_club_state',
    'field_club_city' => 'field_club_city',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Club';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_club_state']['id'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['fields']['field_club_state']['field'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['label'] = 'State/Province';
  $handler->display->display_options['fields']['field_club_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_state']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_club_city']['id'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['table'] = 'field_data_field_club_city';
  $handler->display->display_options['fields']['field_club_city']['field'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_city']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'clubs/directory';
  $export['clubs'] = $view;

  $view = new view;
  $view->name = 'clubs_admin';
  $view->description = 'Club related displays.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clubs Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Clubs Admin';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    7 => '7',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'GO';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'User';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['required'] = 1;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_eq_profile2_entityqueue']['id'] = 'reverse_eq_profile2_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_profile2_entityqueue']['table'] = 'profile';
  $handler->display->display_options['relationships']['reverse_eq_profile2_entityqueue']['field'] = 'reverse_eq_profile2_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_profile2_entityqueue']['relationship'] = 'profile';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_reference_target_id']['id'] = 'field_school_reference_target_id';
  $handler->display->display_options['relationships']['field_school_reference_target_id']['table'] = 'field_data_field_school_reference';
  $handler->display->display_options['relationships']['field_school_reference_target_id']['field'] = 'field_school_reference_target_id';
  $handler->display->display_options['relationships']['field_school_reference_target_id']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Club Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date Created';
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
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'campaign';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Profile: Cell Phone */
  $handler->display->display_options['fields']['field_user_mobile']['id'] = 'field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['table'] = 'field_data_field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['field'] = 'field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['relationship'] = 'profile';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'profile';
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
  $handler->display->display_options['fields']['field_user_first_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['field_api_classes'] = 0;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'profile';
  /* Field: Profile: Birthdate */
  $handler->display->display_options['fields']['field_user_birthday']['id'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['field'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_birthday']['label'] = 'Birth Date';
  $handler->display->display_options['fields']['field_user_birthday']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_birthday']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_birthday']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_birthday']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_user_birthday']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_club_city']['id'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['table'] = 'field_data_field_club_city';
  $handler->display->display_options['fields']['field_club_city']['field'] = 'field_club_city';
  $handler->display->display_options['fields']['field_club_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_city']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_club_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_city']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_city']['field_api_classes'] = 0;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_club_state']['id'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['table'] = 'field_data_field_club_state';
  $handler->display->display_options['fields']['field_club_state']['field'] = 'field_club_state';
  $handler->display->display_options['fields']['field_club_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_state']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_club_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_state']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_state']['field_api_classes'] = 0;
  /* Field: Content: ZIP/Postal Code */
  $handler->display->display_options['fields']['field_club_zip']['id'] = 'field_club_zip';
  $handler->display->display_options['fields']['field_club_zip']['table'] = 'field_data_field_club_zip';
  $handler->display->display_options['fields']['field_club_zip']['field'] = 'field_club_zip';
  $handler->display->display_options['fields']['field_club_zip']['label'] = 'Zip';
  $handler->display->display_options['fields']['field_club_zip']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_zip']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_club_zip']['field_api_classes'] = 0;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  /* Field: Profile: Location */
  $handler->display->display_options['fields']['field_user_address']['id'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address']['field'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_address']['label'] = 'Address';
  $handler->display->display_options['fields']['field_user_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_user_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_user_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_user_address']['field_api_classes'] = 0;
  /* Field: Content: My Do Something Club is going to work on */
  $handler->display->display_options['fields']['field_camp']['id'] = 'field_camp';
  $handler->display->display_options['fields']['field_camp']['table'] = 'field_data_field_camp';
  $handler->display->display_options['fields']['field_camp']['field'] = 'field_camp';
  $handler->display->display_options['fields']['field_camp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_camp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_camp']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_camp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_camp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_camp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_camp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_camp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_camp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_camp']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_camp']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_camp']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_camp']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_camp']['field_api_classes'] = 0;
  /* Field: School: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'ds_school';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_school_reference_target_id';
  $handler->display->display_options['fields']['name_1']['label'] = 'School Name';
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
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 1;
  /* Field: School: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'ds_school';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_school_reference_target_id';
  $handler->display->display_options['fields']['type']['label'] = 'School Type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  /* Field: School: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'ds_school';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['relationship'] = 'field_school_reference_target_id';
  $handler->display->display_options['fields']['state']['label'] = 'State of School';
  $handler->display->display_options['fields']['state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['state']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['state']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['state']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['state']['hide_alter_empty'] = 1;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'club' => 'club',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'name' => 'name',
    'mail' => 'mail',
    'field_phone_required' => 'field_phone_required',
    'field_user_mobile' => 'field_user_mobile',
    'field_user_first_name' => 'field_user_first_name',
    'field_user_last_name' => 'field_user_last_name',
    'field_club_city' => 'field_club_city',
    'field_club_state' => 'field_club_state',
    'field_club_zip' => 'field_club_zip',
    'uid' => 'uid',
    'field_user_address' => 'field_user_address',
    'field_camp' => 'field_camp',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone_required' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_mobile' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_club_zip' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_camp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'admin/clubs';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/clubs/xls';
  $export['clubs_admin'] = $view;

  $view = new view;
  $view->name = 'clubs_to_do_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Clubs To Do List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Clubs To Do List';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_todo_image']['id'] = 'field_todo_image';
  $handler->display->display_options['fields']['field_todo_image']['table'] = 'field_data_field_todo_image';
  $handler->display->display_options['fields']['field_todo_image']['field'] = 'field_todo_image';
  $handler->display->display_options['fields']['field_todo_image']['label'] = '';
  $handler->display->display_options['fields']['field_todo_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_todo_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_todo_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_todo_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_todo_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_todo_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_todo_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_todo_image']['settings'] = array(
    'file_view_mode' => 'media_preview',
  );
  $handler->display->display_options['fields']['field_todo_image']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['name']['convert_spaces'] = 0;
  /* Field: Taxonomy term: Link to */
  $handler->display->display_options['fields']['field_todo_link']['id'] = 'field_todo_link';
  $handler->display->display_options['fields']['field_todo_link']['table'] = 'field_data_field_todo_link';
  $handler->display->display_options['fields']['field_todo_link']['field'] = 'field_todo_link';
  $handler->display->display_options['fields']['field_todo_link']['label'] = '';
  $handler->display->display_options['fields']['field_todo_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_todo_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_todo_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_todo_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_todo_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_todo_link']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_todo_link']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<img src="[field_todo_image]" width="60" style="float: left" alt="" />
<a href="[field_todo_link]">[name]</a>';
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
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'clubs_todo_list' => 'clubs_todo_list',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['clubs_to_do_list'] = $view;

  return $export;
}
