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

  $view = new view();
  $view->name = 'campaign_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Campaign Photo Galleries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_galleriffic';
  $handler->display->display_options['style_options']['css'] = '';
  $handler->display->display_options['style_options']['preload'] = '1';
  $handler->display->display_options['style_options']['transition'] = '500';
  $handler->display->display_options['style_options']['renderss'] = '';
  $handler->display->display_options['style_options']['history'] = 'true';
  $handler->display->display_options['row_plugin'] = 'gallerifficfields';
  $handler->display->display_options['row_options']['slide_field'] = 'field_webform_pictures';
  $handler->display->display_options['row_options']['thumbnail_field'] = 'field_webform_pictures_1';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['label'] = 'campagn group';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: OG membership: OG group gid */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['group']['label'] = 'campaign group';
  $handler->display->display_options['relationships']['group']['required'] = TRUE;
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures']['id'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_webform_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_offset'] = '0';
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures_1']['id'] = 'field_webform_pictures_1';
  $handler->display->display_options['fields']['field_webform_pictures_1']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['label'] = '';
  $handler->display->display_options['fields']['field_webform_pictures_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_webform_pictures_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures_1']['delta_offset'] = '0';
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  /* Contextual filter: OG group: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'group';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campaign_report_back' => 'campaign_report_back',
  );
  /* Filter criterion: Webform Submission: Pictures (field_webform_pictures:fid) */
  $handler->display->display_options['filters']['field_webform_pictures_fid']['id'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['field'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['operator'] = 'not empty';
  /* Filter criterion: Webform submissions: Submitted */
  $handler->display->display_options['filters']['submitted']['id'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['submitted']['field'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['operator'] = '<=';
  $handler->display->display_options['filters']['submitted']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['submitted']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['submitted']['default_date'] = '-2 days';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'test-gallery';

  /* Display: Main Campaign Gallery */
  $handler = $view->new_display('panel_pane', 'Main Campaign Gallery', 'panel_pane_1');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 'offset';
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG group: Entity id',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Webform Gallery */
  $handler = $view->new_display('panel_pane', 'Webform Gallery', 'panel_pane_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Webform Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Webform Nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'numeric';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'webform' => 'webform',
  );
  /* Filter criterion: Webform Submission: Pictures (field_webform_pictures:fid) */
  $handler->display->display_options['filters']['field_webform_pictures_fid']['id'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['field'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['operator'] = 'not empty';
  /* Filter criterion: Webform submissions: Submitted */
  $handler->display->display_options['filters']['submitted']['id'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['submitted']['field'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['operator'] = '<=';
  $handler->display->display_options['filters']['submitted']['value']['value'] = '-2 days';
  $handler->display->display_options['filters']['submitted']['value']['type'] = 'offset';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:entityqueue.eq_og_membership',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Mini Scroller Gallery */
  $handler = $view->new_display('panel_pane', 'Mini Scroller Gallery', 'panel_pane_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['skin'] = '';
  $handler->display->display_options['style_options']['visible'] = '';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures']['id'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_webform_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures']['settings'] = array(
    'image_style' => 'member_photo_gallery',
    'image_link' => 'file',
  );
  $handler->display->display_options['fields']['field_webform_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_offset'] = '0';
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures_1']['id'] = 'field_webform_pictures_1';
  $handler->display->display_options['fields']['field_webform_pictures_1']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_webform_pictures_1']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG group: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'group';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Webform Nid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['ui_name'] = 'Webform Nid';
  $handler->display->display_options['arguments']['sid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Webform Submission: Pictures (field_webform_pictures:fid) */
  $handler->display->display_options['filters']['field_webform_pictures_fid']['id'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['field'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'webform' => 'webform',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Webform submissions: Submitted */
  $handler->display->display_options['filters']['submitted']['id'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['submitted']['field'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['operator'] = '<=';
  $handler->display->display_options['filters']['submitted']['value']['value'] = '-2 days';
  $handler->display->display_options['filters']['submitted']['value']['type'] = 'offset';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG group: Entity id',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Mobile Gallery Feed */
  $handler = $view->new_display('page', 'Mobile Gallery Feed', 'page_2');
  $handler->display->display_options['display_description'] = 'Campaign photos filter by campaign NID';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '6, 12, 15, 30, 45, 60';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'image_items';
  $handler->display->display_options['style_options']['top_child_object'] = 'image_item';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['label'] = 'campagn group';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: OG membership: OG group gid */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['group']['label'] = 'campaign group';
  $handler->display->display_options['relationships']['group']['required'] = TRUE;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures']['id'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['label'] = 'image';
  $handler->display->display_options['fields']['field_webform_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_webform_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_offset'] = '0';
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures_1']['id'] = 'field_webform_pictures_1';
  $handler->display->display_options['fields']['field_webform_pictures_1']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['label'] = 'thumbnail';
  $handler->display->display_options['fields']['field_webform_pictures_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_webform_pictures_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures_1']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'author';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'feed/campaign_photos/%';

  /* Display: Mobile Webform Gallery Feed */
  $handler = $view->new_display('page', 'Mobile Webform Gallery Feed', 'page_3');
  $handler->display->display_options['display_description'] = 'Campaign webform photos filter by webform NID';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '6, 12, 15, 30, 45, 60';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'image_items';
  $handler->display->display_options['style_options']['top_child_object'] = 'image_item';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures']['id'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['label'] = 'image';
  $handler->display->display_options['fields']['field_webform_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_webform_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_offset'] = '0';
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures_1']['id'] = 'field_webform_pictures_1';
  $handler->display->display_options['fields']['field_webform_pictures_1']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['label'] = 'thumbnail';
  $handler->display->display_options['fields']['field_webform_pictures_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_webform_pictures_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures_1']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'webform' => 'webform',
  );
  /* Filter criterion: Webform Submission: Pictures (field_webform_pictures:fid) */
  $handler->display->display_options['filters']['field_webform_pictures_fid']['id'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['field'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'feed/campaign_webform_photos/%';

  /* Display: Campaign Mini Scroller */
  $handler = $view->new_display('panel_pane', 'Campaign Mini Scroller', 'panel_pane_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['skin'] = '';
  $handler->display->display_options['style_options']['visible'] = '';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures']['id'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_webform_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures']['settings'] = array(
    'image_style' => 'member_photo_gallery',
    'image_link' => 'file',
  );
  $handler->display->display_options['fields']['field_webform_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_offset'] = '0';
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures_1']['id'] = 'field_webform_pictures_1';
  $handler->display->display_options['fields']['field_webform_pictures_1']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_webform_pictures_1']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG group: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'group';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Webform Submission: Pictures (field_webform_pictures:fid) */
  $handler->display->display_options['filters']['field_webform_pictures_fid']['id'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['field'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'campaign_report_back' => 'campaign_report_back',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Webform submissions: Submitted */
  $handler->display->display_options['filters']['submitted']['id'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['submitted']['field'] = 'submitted';
  $handler->display->display_options['filters']['submitted']['operator'] = '<=';
  $handler->display->display_options['filters']['submitted']['value']['value'] = '-2 days';
  $handler->display->display_options['filters']['submitted']['value']['type'] = 'offset';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG group: Entity id',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Multiple Webform Gallery */
  $handler = $view->new_display('panel_pane', 'Multiple Webform Gallery', 'panel_pane_5');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures']['id'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_webform_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures']['delta_offset'] = '0';
  /* Field: Webform Submission: Pictures */
  $handler->display->display_options['fields']['field_webform_pictures_1']['id'] = 'field_webform_pictures_1';
  $handler->display->display_options['fields']['field_webform_pictures_1']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['field'] = 'field_webform_pictures';
  $handler->display->display_options['fields']['field_webform_pictures_1']['label'] = '';
  $handler->display->display_options['fields']['field_webform_pictures_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_webform_pictures_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_webform_pictures_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webform_pictures_1']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team_challenge' => 'team_challenge',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Webform Submission: Pictures (field_webform_pictures:fid) */
  $handler->display->display_options['filters']['field_webform_pictures_fid']['id'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['table'] = 'field_data_field_webform_pictures';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['field'] = 'field_webform_pictures_fid';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_webform_pictures_fid']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:entityqueue.eq_og_membership',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['campaign_gallery'] = $view;

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'More >>';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'dosomething_apps_grid';
  $handler->display->display_options['style_options']['fields']['banner'] = 'field_campaign_call_to_action';
  $handler->display->display_options['style_options']['fields']['image'] = 'field_campaign_main_image';
  $handler->display->display_options['style_options']['fields']['title'] = 'title';
  $handler->display->display_options['style_options']['fields']['text'] = 'field_campaign_teaser_1';
  $handler->display->display_options['style_options']['fields']['footer'] = 'field_campain_date';
  $handler->display->display_options['style_options']['fields']['link'] = 'path';
  $handler->display->display_options['style_options']['settings']['last_adjust'] = TRUE;
  $handler->display->display_options['style_options']['settings']['last_every_nth'] = '3';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Relationship: Content: Campaign Sign Up (field_campaign) - reverse */
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['id'] = 'reverse_field_campaign_node';
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['field'] = 'reverse_field_campaign_node';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_campaign_background_color']['id'] = 'field_campaign_background_color';
  $handler->display->display_options['fields']['field_campaign_background_color']['table'] = 'field_data_field_campaign_background_color';
  $handler->display->display_options['fields']['field_campaign_background_color']['field'] = 'field_campaign_background_color';
  $handler->display->display_options['fields']['field_campaign_background_color']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_background_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_background_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_background_color']['hide_alter_empty'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_campaign_foreground_color']['id'] = 'field_campaign_foreground_color';
  $handler->display->display_options['fields']['field_campaign_foreground_color']['table'] = 'field_data_field_campaign_foreground_color';
  $handler->display->display_options['fields']['field_campaign_foreground_color']['field'] = 'field_campaign_foreground_color';
  $handler->display->display_options['fields']['field_campaign_foreground_color']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_foreground_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_foreground_color']['hide_alter_empty'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_campaign_logo']['id'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['table'] = 'field_data_field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['field'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_logo']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_logo']['settings'] = array(
    'image_style' => 'campaigns_logo',
    'image_link' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_type'] = 'span';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'ds-button';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'GET MORE INFO';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['text'] = 'MORE INFO';
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['path'] = 'node/[nid_1]';
  $handler->display->display_options['fields']['nid_1']['alter']['link_class'] = 'ds-button';
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_report_back_reference_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'TELL US WHAT YOU DID';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'ds-button';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_empty'] = TRUE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_campaign_teaser']['id'] = 'field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['table'] = 'field_data_field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['field'] = 'field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['text'] = '<div class="campaign-teaser">[field_campaign_teaser]</div>

[nid_1] [nid] ';
  $handler->display->display_options['fields']['field_campaign_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_teaser']['hide_alter_empty'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_campaign_main_image']['id'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['field'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_main_image']['settings'] = array(
    'image_style' => 'campaigns_image',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="views-field-field-campaign-logo">[field_campaign_logo]</div>
<div class="views-field-field-campaign-teaser">[field_campaign_teaser]</div>
<div class="views-field-field-campaign-main-image">[field_campaign_main_image]</div>
';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'campaigns-container';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
  $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node_1']['label'] = '';
  $handler->display->display_options['fields']['view_node_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['view_node_1']['text'] = 'Join This';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_campaign_headline']['id'] = 'field_campaign_headline';
  $handler->display->display_options['fields']['field_campaign_headline']['table'] = 'field_data_field_campaign_headline';
  $handler->display->display_options['fields']['field_campaign_headline']['field'] = 'field_campaign_headline';
  $handler->display->display_options['fields']['field_campaign_headline']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_headline']['alter']['text'] = '<div class="campaign-join-this">[view_node_1]</div> <div class="campaign-headline">[field_campaign_headline]</div>';
  $handler->display->display_options['fields']['field_campaign_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_headline']['hide_alter_empty'] = FALSE;
  /* Field: Global: Facebook Social Plugin */
  $handler->display->display_options['fields']['fb_social']['id'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['table'] = 'views';
  $handler->display->display_options['fields']['fb_social']['field'] = 'fb_social';
  $handler->display->display_options['fields']['fb_social']['label'] = '';
  $handler->display->display_options['fields']['fb_social']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fb_social']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['fb_social']['fb_social_plugins'] = 'FB Like';
  /* Field: Content: Call to action */
  $handler->display->display_options['fields']['field_campaign_call_to_action']['id'] = 'field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['table'] = 'field_data_field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['field'] = 'field_campaign_call_to_action';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
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
  /* Filter criterion: Content: Main Image (field_campaign_main_image:fid) */
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['id'] = 'field_campaign_main_image_fid';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['field'] = 'field_campaign_main_image_fid';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['group'] = 1;

  /* Display: Current Campaigns Page */
  $handler = $view->new_display('page', 'Current Campaigns Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Join A Campaign';
  $handler->display->display_options['display_description'] = 'Displays a list of current campaigns';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>DoSomething.org spearheads national campaigns so young people can take action on things they care about.  Now, it\'s YOUR turn.  Choose a campaign and make a difference.  Because, let\'s be honest: apathy sucks.</p>
<h2>Current Campaigns</h2>
<p>These campaigns are LIVE.  Don\'t wait: pick one and get started today.  As in, now.  At this very moment.  Immediately.  Pronto.  Stat.  ASAP.  Or even sooner.</p>';
  $handler->display->display_options['header']['area']['format'] = '3';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/past-campaigns" title="Past Campaigns">Past campaigns &raquo;</a>';
  $handler->display->display_options['footer']['area']['format'] = '3';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There are no current campaigns at the moment.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Campaign Sign Up (field_campaign) - reverse */
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['id'] = 'reverse_field_campaign_node';
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['field'] = 'reverse_field_campaign_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_campaign_main_image']['id'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['field'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['path'] = 'http://www.dosomething.org/[path]';
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_main_image']['settings'] = array(
    'image_style' => 'campaigns_image',
    'image_link' => '',
  );
  /* Field: Content: Call to action */
  $handler->display->display_options['fields']['field_campaign_call_to_action']['id'] = 'field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['table'] = 'field_data_field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['field'] = 'field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['element_label_colon'] = FALSE;
  /* Field: Webform: Webform submission count */
  $handler->display->display_options['fields']['webform_submission_count_node']['id'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['table'] = 'node';
  $handler->display->display_options['fields']['webform_submission_count_node']['field'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['relationship'] = 'reverse_field_campaign_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['label'] = '';
  $handler->display->display_options['fields']['webform_submission_count_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['element_label_colon'] = FALSE;
  /* Field: Content: Campaign Date */
  $handler->display->display_options['fields']['field_campain_date']['id'] = 'field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['field'] = 'field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['label'] = '';
  $handler->display->display_options['fields']['field_campain_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_campain_date']['alter']['text'] = '<div>Ends [field_campain_date]</div>
<!--<div><div class="doingit-icon">i</div><span> [webform_submission_count_node] doing it</span></div>-->';
  $handler->display->display_options['fields']['field_campain_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campain_date']['settings'] = array(
    'format_type' => 'campaign',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_campaign_teaser_1']['id'] = 'field_campaign_teaser_1';
  $handler->display->display_options['fields']['field_campaign_teaser_1']['table'] = 'field_data_field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser_1']['field'] = 'field_campaign_teaser';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'element-invisible';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  /* Sort criterion: Content: Campaign Date - end date (field_campain_date:value2) */
  $handler->display->display_options['sorts']['field_campain_date_value2']['id'] = 'field_campain_date_value2';
  $handler->display->display_options['sorts']['field_campain_date_value2']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['sorts']['field_campain_date_value2']['field'] = 'field_campain_date_value2';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
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
    'campaign' => 'campaign',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter']['group'] = 0;
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'minute';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_campain_date.field_campain_date_value' => 'field_data_field_campain_date.field_campain_date_value',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 0;
  $handler->display->display_options['filters']['date_filter_1']['granularity'] = 'minute';
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_campain_date.field_campain_date_value2' => 'field_data_field_campain_date.field_campain_date_value2',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Filter criterion: Content: Main Image (field_campaign_main_image:fid) */
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['id'] = 'field_campaign_main_image_fid';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['field'] = 'field_campaign_main_image_fid';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['group'] = 0;
  $handler->display->display_options['path'] = 'campaigns';
  $handler->display->display_options['menu']['title'] = 'Current Campaigns';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Related Campaigns Content pane */
  $handler = $view->new_display('panel_pane', 'Related Campaigns Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Act Now';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'related-campaign';
  $handler->display->display_options['display_description'] = 'Related campaigns pane - pulled into Causes term page.';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'cause/!1/act-now';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_campaign_logo' => 'field_campaign_logo',
    'title' => 'title',
    'field_campaign_teaser' => 'field_campaign_teaser',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_campaign_logo']['id'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['table'] = 'field_data_field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['field'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_logo']['element_class'] = 'project-related-thumb';
  $handler->display->display_options['fields']['field_campaign_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_logo']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_logo']['settings'] = array(
    'image_style' => 'project_related_thumb',
    'image_link' => 'content',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['element_class'] = 'project-related-thumb';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'project_related_thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'campaign-headline';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'campaign-headline-label';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Is content general? (field_is_content_general) */
  $handler->display->display_options['sorts']['field_is_content_general_value']['id'] = 'field_is_content_general_value';
  $handler->display->display_options['sorts']['field_is_content_general_value']['table'] = 'field_data_field_is_content_general';
  $handler->display->display_options['sorts']['field_is_content_general_value']['field'] = 'field_is_content_general_value';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
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
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'action_guide' => 'action_guide',
    'campaign' => 'campaign',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Picture (field_picture:fid) */
  $handler->display->display_options['filters']['field_picture_fid']['id'] = 'field_picture_fid';
  $handler->display->display_options['filters']['field_picture_fid']['table'] = 'field_data_field_picture';
  $handler->display->display_options['filters']['field_picture_fid']['field'] = 'field_picture_fid';
  $handler->display->display_options['filters']['field_picture_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_picture_fid']['group'] = 2;
  /* Filter criterion: Content: Logo (field_campaign_logo:fid) */
  $handler->display->display_options['filters']['field_campaign_logo_fid']['id'] = 'field_campaign_logo_fid';
  $handler->display->display_options['filters']['field_campaign_logo_fid']['table'] = 'field_data_field_campaign_logo';
  $handler->display->display_options['filters']['field_campaign_logo_fid']['field'] = 'field_campaign_logo_fid';
  $handler->display->display_options['filters']['field_campaign_logo_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_campaign_logo_fid']['group'] = 2;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 3;
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_campain_date.field_campain_date_value2' => 'field_data_field_campain_date.field_campain_date_value2',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: Content: Campaign Date - end date (field_campain_date:value2) */
  $handler->display->display_options['filters']['field_campain_date_value2']['id'] = 'field_campain_date_value2';
  $handler->display->display_options['filters']['field_campain_date_value2']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['filters']['field_campain_date_value2']['field'] = 'field_campain_date_value2';
  $handler->display->display_options['filters']['field_campain_date_value2']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_campain_date_value2']['group'] = 3;

  /* Display: Related Campaigns Content All pane */
  $handler = $view->new_display('panel_pane', 'Related Campaigns Content All pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Act Now';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'related-campaign';
  $handler->display->display_options['display_description'] = 'Related campaigns pane - pulled into Causes term page.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_campaign_logo' => 'field_campaign_logo',
    'title' => 'title',
    'field_campaign_teaser' => 'field_campaign_teaser',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_campaign_logo']['id'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['table'] = 'field_data_field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['field'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_logo']['element_class'] = 'project-related-thumb';
  $handler->display->display_options['fields']['field_campaign_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_logo']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_logo']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['element_class'] = 'project-related-thumb';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['empty'] = '[field_campaign_logo]';
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'campaign-headline';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'campaign-headline-label';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Short Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="unimage-wrapper"><h2>[title]</h2>[field_description]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Is content general? (field_is_content_general) */
  $handler->display->display_options['sorts']['field_is_content_general_value']['id'] = 'field_is_content_general_value';
  $handler->display->display_options['sorts']['field_is_content_general_value']['table'] = 'field_data_field_is_content_general';
  $handler->display->display_options['sorts']['field_is_content_general_value']['field'] = 'field_is_content_general_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
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
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'action_guide' => 'action_guide',
    'campaign' => 'campaign',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Picture (field_picture:fid) */
  $handler->display->display_options['filters']['field_picture_fid']['id'] = 'field_picture_fid';
  $handler->display->display_options['filters']['field_picture_fid']['table'] = 'field_data_field_picture';
  $handler->display->display_options['filters']['field_picture_fid']['field'] = 'field_picture_fid';
  $handler->display->display_options['filters']['field_picture_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_picture_fid']['group'] = 2;
  /* Filter criterion: Content: Logo (field_campaign_logo:fid) */
  $handler->display->display_options['filters']['field_campaign_logo_fid']['id'] = 'field_campaign_logo_fid';
  $handler->display->display_options['filters']['field_campaign_logo_fid']['table'] = 'field_data_field_campaign_logo';
  $handler->display->display_options['filters']['field_campaign_logo_fid']['field'] = 'field_campaign_logo_fid';
  $handler->display->display_options['filters']['field_campaign_logo_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_campaign_logo_fid']['group'] = 2;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'term_node_tid_depth' => array(
      'type' => 'user',
      'context' => 'entity:entityqueue.eq_og_membership',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID (with depth)',
    ),
  );

  /* Display: Future Campaigns Attachment */
  $handler = $view->new_display('attachment', 'Future Campaigns Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Future Campaigns';
  $handler->display->display_options['display_description'] = 'Displays a list of future campaigns';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'dosomething_apps_grid';
  $handler->display->display_options['style_options']['fields']['banner'] = 'field_campaign_call_to_action';
  $handler->display->display_options['style_options']['fields']['image'] = 'field_campaign_main_image';
  $handler->display->display_options['style_options']['fields']['title'] = 'title';
  $handler->display->display_options['style_options']['fields']['text'] = 'field_campaign_teaser';
  $handler->display->display_options['style_options']['fields']['footer'] = 'field_campain_date';
  $handler->display->display_options['style_options']['fields']['link'] = 'field_campaign_link';
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
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Future Campaigns</h2>';
  $handler->display->display_options['header']['area']['format'] = '3';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'Check back soon for our upcoming campaigns.  They\'ll be up shortly, we promise.  Until then, we\'re just playing hard to get.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Campaign Sign Up (field_campaign) - reverse */
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['id'] = 'reverse_field_campaign_node';
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_campaign_node']['field'] = 'reverse_field_campaign_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_campaign_link']['id'] = 'field_campaign_link';
  $handler->display->display_options['fields']['field_campaign_link']['table'] = 'field_data_field_campaign_link';
  $handler->display->display_options['fields']['field_campaign_link']['field'] = 'field_campaign_link';
  $handler->display->display_options['fields']['field_campaign_link']['hide_empty'] = TRUE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_campaign_main_image']['id'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['field'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['path'] = '[field_campaign_link]';
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_main_image']['settings'] = array(
    'image_style' => 'campaigns_image',
    'image_link' => '',
  );
  /* Field: Content: Call to action */
  $handler->display->display_options['fields']['field_campaign_call_to_action']['id'] = 'field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['table'] = 'field_data_field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['field'] = 'field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['element_label_colon'] = FALSE;
  /* Field: Webform: Webform submission count */
  $handler->display->display_options['fields']['webform_submission_count_node']['id'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['table'] = 'node';
  $handler->display->display_options['fields']['webform_submission_count_node']['field'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['relationship'] = 'reverse_field_campaign_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['label'] = '';
  $handler->display->display_options['fields']['webform_submission_count_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_campaign_teaser']['id'] = 'field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['table'] = 'field_data_field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['field'] = 'field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['text'] = '<div class="campaign-teaser">[field_campaign_teaser]</div>';
  $handler->display->display_options['fields']['field_campaign_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_teaser']['hide_alter_empty'] = FALSE;
  /* Field: Content: Campaign Date */
  $handler->display->display_options['fields']['field_campain_date']['id'] = 'field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['field'] = 'field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['label'] = '';
  $handler->display->display_options['fields']['field_campain_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_campain_date']['alter']['text'] = '<div>Starts [field_campain_date]</div>
<!--<div><div class="doingit-icon">i</div><span> [webform_submission_count_node] signed up</span></div>-->';
  $handler->display->display_options['fields']['field_campain_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campain_date']['settings'] = array(
    'format_type' => 'campaign',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'element-invisible';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  /* Sort criterion: Content: Campaign Date -  start date (field_campain_date) */
  $handler->display->display_options['sorts']['field_campain_date_value']['id'] = 'field_campain_date_value';
  $handler->display->display_options['sorts']['field_campain_date_value']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['sorts']['field_campain_date_value']['field'] = 'field_campain_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['granularity'] = 'minute';
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_campain_date.field_campain_date_value' => 'field_data_field_campain_date.field_campain_date_value',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Filter criterion: Content: Main Image (field_campaign_main_image:fid) */
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['id'] = 'field_campaign_main_image_fid';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['field'] = 'field_campaign_main_image_fid';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['group'] = 1;
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'panel_pane_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_pager'] = TRUE;
  $handler->display->display_options['render_pager'] = TRUE;

  /* Display: Past Campaigns Page */
  $handler = $view->new_display('page', 'Past Campaigns Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past Campaigns';
  $handler->display->display_options['display_description'] = 'Displays a list of past campaigns.';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'dosomething_apps_grid';
  $handler->display->display_options['style_options']['fields']['banner'] = 'field_campaign_call_to_action';
  $handler->display->display_options['style_options']['fields']['image'] = 'field_campaign_main_image';
  $handler->display->display_options['style_options']['fields']['title'] = 'title';
  $handler->display->display_options['style_options']['fields']['text'] = 'field_campaign_teaser';
  $handler->display->display_options['style_options']['fields']['footer'] = 'field_campain_date';
  $handler->display->display_options['style_options']['fields']['link'] = 'path';
  $handler->display->display_options['style_options']['settings']['last_adjust'] = TRUE;
  $handler->display->display_options['style_options']['settings']['last_every_nth'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_campaign_main_image']['id'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['field'] = 'field_campaign_main_image';
  $handler->display->display_options['fields']['field_campaign_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['path'] = 'http://www.dosomething.org/[path]';
  $handler->display->display_options['fields']['field_campaign_main_image']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_campaign_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_main_image']['settings'] = array(
    'image_style' => 'campaigns_image',
    'image_link' => '',
  );
  /* Field: Content: Call to action */
  $handler->display->display_options['fields']['field_campaign_call_to_action']['id'] = 'field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['table'] = 'field_data_field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['field'] = 'field_campaign_call_to_action';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_call_to_action']['element_label_colon'] = FALSE;
  /* Field: Webform: Webform submission count */
  $handler->display->display_options['fields']['webform_submission_count_node']['id'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['table'] = 'node';
  $handler->display->display_options['fields']['webform_submission_count_node']['field'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['relationship'] = 'reverse_field_campaign_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['label'] = '';
  $handler->display->display_options['fields']['webform_submission_count_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['element_label_colon'] = FALSE;
  /* Field: Content: Campaign Date */
  $handler->display->display_options['fields']['field_campain_date']['id'] = 'field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['field'] = 'field_campain_date';
  $handler->display->display_options['fields']['field_campain_date']['label'] = '';
  $handler->display->display_options['fields']['field_campain_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_campain_date']['alter']['text'] = '<div>Ended [field_campain_date]</div>
<!--<div><div class="doingit-icon">i</div><span> [webform_submission_count_node] did it</span></div>-->';
  $handler->display->display_options['fields']['field_campain_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campain_date']['settings'] = array(
    'format_type' => 'campaign',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_campaign_teaser']['id'] = 'field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['table'] = 'field_data_field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['field'] = 'field_campaign_teaser';
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_teaser']['alter']['text'] = '<div class="campaign-teaser">[field_campaign_teaser]</div>';
  $handler->display->display_options['fields']['field_campaign_teaser']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'element-invisible';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  /* Sort criterion: Content: Campaign Date - end date (field_campain_date:value2) */
  $handler->display->display_options['sorts']['field_campain_date_value2']['id'] = 'field_campain_date_value2';
  $handler->display->display_options['sorts']['field_campain_date_value2']['table'] = 'field_data_field_campain_date';
  $handler->display->display_options['sorts']['field_campain_date_value2']['field'] = 'field_campain_date_value2';
  $handler->display->display_options['sorts']['field_campain_date_value2']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
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
    'campaign' => 'campaign',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter']['group'] = 0;
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'minute';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_campain_date.field_campain_date_value2' => 'field_data_field_campain_date.field_campain_date_value2',
  );
  /* Filter criterion: Content: Main Image (field_campaign_main_image:fid) */
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['id'] = 'field_campaign_main_image_fid';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['table'] = 'field_data_field_campaign_main_image';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['field'] = 'field_campaign_main_image_fid';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_campaign_main_image_fid']['group'] = 0;
  $handler->display->display_options['path'] = 'past-campaigns';
  $export['current_campaigns'] = $view;

  return $export;
}
