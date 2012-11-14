<?php
/**
 * @file
 * dosomething_scholarship_rec.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_scholarship_rec_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'application_page_info';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Application Page Info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recommendations';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_rec_request_target_id']['id'] = 'field_rec_request_target_id';
  $handler->display->display_options['relationships']['field_rec_request_target_id']['table'] = 'field_data_field_rec_request';
  $handler->display->display_options['relationships']['field_rec_request_target_id']['field'] = 'field_rec_request_target_id';
  $handler->display->display_options['relationships']['field_rec_request_target_id']['label'] = 'Recommendation Request';
  $handler->display->display_options['relationships']['field_rec_request_target_id']['required'] = 1;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_application_target_id']['id'] = 'field_application_target_id';
  $handler->display->display_options['relationships']['field_application_target_id']['table'] = 'field_data_field_application';
  $handler->display->display_options['relationships']['field_application_target_id']['field'] = 'field_application_target_id';
  $handler->display->display_options['relationships']['field_application_target_id']['relationship'] = 'field_rec_request_target_id';
  $handler->display->display_options['relationships']['field_application_target_id']['label'] = 'Application';
  $handler->display->display_options['relationships']['field_application_target_id']['required'] = 1;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Recommendation Node';
  $handler->display->display_options['relationships']['nid']['required'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[title]</h2>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
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
  /* Field: Webform submissions: Rendered Webform Submission */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_webform_submission_entity';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  /* Contextual filter: Webform submissions: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['relationship'] = 'field_application_target_id';
  $handler->display->display_options['arguments']['sid']['default_action'] = 'empty';
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
    'scholarship_recommendation' => 'scholarship_recommendation',
  );

  /* Display: Recommendations */
  $handler = $view->new_display('panel_pane', 'Recommendations', 'panel_pane_1');
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

  /* Display: Queue Management */
  $handler = $view->new_display('panel_pane', 'Queue Management', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Queue Management';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<h2>Current Queue</h2>
None

<h2>Manage</h2>
<a href="/entityqueue/add/!2_yes/!1?destination=application/!1">Yes</a> | 
<a href="/entityqueue/add/!2_no/!1?destination=application/!1">No</a> |
<a href="/entityqueue/add/!2_maybe/!1?destination=application/!1">Maybe</a> |
<a href="/entityqueue/add/!2_too_soon/!1?destination=application/!1">Too Soon</a>';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['id'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['field'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['label'] = 'Entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: EQ ID */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_entityqueue';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['fields']['rendered_entity_1']['ui_name'] = 'EQ ID';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['display'] = 'id';
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'full';
  /* Field: Entityqueue: Rendered Entityqueue */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_entityqueue';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['text'] = '<h2>Current Queue</h2>
[rendered_entity]

<h2>Manage</h2>
<a href="/entityqueue/swap/[rendered_entity_1]/!2_yes/!1?destination=application/!1">Yes</a> | 
<a href="/entityqueue/swap/[rendered_entity_1]/!2_no/!1?destination=application/!1">No</a> |
<a href="/entityqueue/swap/[rendered_entity_1]/!2_maybe/!1?destination=application/!1">Maybe</a> |
<a href="/entityqueue/swap/[rendered_entity_1]/!2_maybe/!1?destination=application/!1">Too Soon</a>';
  $handler->display->display_options['fields']['rendered_entity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['empty'] = '<h2>Current Queue</h2>
None

<h2>Manage</h2>
<a href="/entityqueue/add/!2_yes/!1?destination=application/!1">Yes</a> | 
<a href="/entityqueue/add/!2_no/!1?destination=application/!1">No</a> |
<a href="/entityqueue/add/!2_maybe/!1?destination=application/!1">Maybe</a> |
<a href="/entityqueue/add/!2_too_soon/!1?destination=application/!1">Too Soon</a>';
  $handler->display->display_options['fields']['rendered_entity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Webform submissions: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['sid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['sid']['not'] = 0;
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['must_not_be'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name']['id'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['value'] = array(
    'foot_locker_maybe' => 'foot_locker_maybe',
    'foot_locker_no' => 'foot_locker_no',
    'foot_locker_too_soon' => 'foot_locker_too_soon',
    'foot_locker_yes' => 'foot_locker_yes',
  );
  $handler->display->display_options['argument_input'] = array(
    'sid' => array(
      'type' => 'context',
      'context' => 'entity:webform_submission_entity.sid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform submissions: Sid',
    ),
    'null' => array(
      'type' => 'user',
      'context' => 'entity:entityqueue.eq_profile2_type',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Queue Prefix',
    ),
  );

  /* Display: Low Income */
  $handler = $view->new_display('panel_pane', 'Low Income', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Low Income Queue';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<a href="/entityqueue/add/low_income/!1?destination=application/!1">Flag low income</a>';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['id'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['field'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['label'] = 'Entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: EQ ID */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_entityqueue';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['fields']['rendered_entity_1']['ui_name'] = 'EQ ID';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['display'] = 'id';
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'full';
  /* Field: Entityqueue: Rendered Entityqueue */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_entityqueue';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['text'] = '<a href="/entityqueue/remove/low_income/!1?destination=application/!1">Unflag low income</a>';
  $handler->display->display_options['fields']['rendered_entity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Webform submissions: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['sid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['sid']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name']['id'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['value'] = array(
    'low_income' => 'low_income',
  );
  $handler->display->display_options['filters']['entityqueue_name']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'sid' => array(
      'type' => 'context',
      'context' => 'entity:webform_submission_entity.sid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Webform submissions: Sid',
    ),
    'null' => array(
      'type' => 'user',
      'context' => 'entity:entityqueue.eq_profile2_type',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Queue Prefix',
    ),
  );
  $export['application_page_info'] = $view;

  $view = new view;
  $view->name = 'application_queues';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Application Queues';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Application Queues';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access all webform results';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'sid' => 'sid',
    'field_webform_last_name' => 'field_webform_last_name',
    'field_webform_first_name' => 'field_webform_first_name',
    'submitted' => 'submitted',
    'title' => 'title',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_webform_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_webform_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'submitted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Primary Queue */
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['id'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['field'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['ui_name'] = 'Primary Queue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue']['required'] = 0;
  /* Relationship: Recommendation Request */
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['id'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['field'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['ui_name'] = 'Recommendation Request';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['label'] = 'Recommendation Request';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['required'] = 0;
  /* Relationship: Recommendation */
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['id'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['field'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['ui_name'] = 'Recommendation';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['label'] = 'Recommendation';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['required'] = 0;
  /* Relationship: Recommendation Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['relationships']['nid']['ui_name'] = 'Recommendation Node';
  $handler->display->display_options['relationships']['nid']['label'] = 'Recommendation Node';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Relationship: Secondary Queue */
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue_1']['id'] = 'reverse_eq_webform_submission_entity_entityqueue_1';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue_1']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue_1']['field'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue_1']['ui_name'] = 'Secondary Queue';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue_1']['label'] = 'Secondary Entityqueue referencing Webform Submission from eq_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_eq_webform_submission_entity_entityqueue_1']['required'] = 0;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'uid';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Email';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::system_block_ip_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::user_block_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'use_queue' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
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
  /* Field: Webform Submission: Last Name */
  $handler->display->display_options['fields']['field_webform_last_name']['id'] = 'field_webform_last_name';
  $handler->display->display_options['fields']['field_webform_last_name']['table'] = 'field_data_field_webform_last_name';
  $handler->display->display_options['fields']['field_webform_last_name']['field'] = 'field_webform_last_name';
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['path'] = 'application/[sid]';
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: First Name */
  $handler->display->display_options['fields']['field_webform_first_name']['id'] = 'field_webform_first_name';
  $handler->display->display_options['fields']['field_webform_first_name']['table'] = 'field_data_field_webform_first_name';
  $handler->display->display_options['fields']['field_webform_first_name']['field'] = 'field_webform_first_name';
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['field_api_classes'] = 0;
  /* Field: Webform submissions: Submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
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
  $handler->display->display_options['fields']['submitted']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['submitted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['submitted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['submitted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['submitted']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['submitted']['date_format'] = 'short';
  /* Field: COUNT(DISTINCT Content: Title) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['title']['label'] = 'Received Recommendations';
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
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['separator'] = '';
  $handler->display->display_options['fields']['title']['format_plural'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'application/[sid]';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
  );

  /* Display: Ready */
  $handler = $view->new_display('page', 'Ready', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name']['id'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['operator'] = 'empty';
  $handler->display->display_options['filters']['entityqueue_name']['value'] = array(
    'foot_locker_maybe' => 'foot_locker_maybe',
    'foot_locker_no' => 'foot_locker_no',
    'foot_locker_yes' => 'foot_locker_yes',
  );
  $handler->display->display_options['path'] = 'applications/ready';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Ready to be Read';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Application Reading';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Yes */
  $handler = $view->new_display('page', 'Yes', 'page_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name']['id'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['value'] = array(
    'foot_locker_yes' => 'foot_locker_yes',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name_1']['id'] = 'entityqueue_name_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name_1']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name_1']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['value'] = array(
    'low_income' => 'low_income',
  );
  $handler->display->display_options['filters']['entityqueue_name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['operator_id'] = 'entityqueue_name_1_op';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['label'] = 'Secondary Queue';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['operator'] = 'entityqueue_name_1_op';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['identifier'] = 'entityqueue_name_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['reduce'] = 1;
  $handler->display->display_options['path'] = 'applications/yes';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Yes';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: No */
  $handler = $view->new_display('page', 'No', 'page_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name']['id'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['value'] = array(
    'foot_locker_no' => 'foot_locker_no',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name_1']['id'] = 'entityqueue_name_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name_1']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name_1']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['value'] = array(
    'low_income' => 'low_income',
  );
  $handler->display->display_options['filters']['entityqueue_name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['operator_id'] = 'entityqueue_name_1_op';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['label'] = 'queue machine name';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['operator'] = 'entityqueue_name_1_op';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['identifier'] = 'entityqueue_name_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['reduce'] = 1;
  $handler->display->display_options['path'] = 'applications/no';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'No';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Maybe */
  $handler = $view->new_display('page', 'Maybe', 'page_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name']['id'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['value'] = array(
    'foot_locker_maybe' => 'foot_locker_maybe',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name_1']['id'] = 'entityqueue_name_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name_1']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name_1']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['value'] = array(
    'low_income' => 'low_income',
  );
  $handler->display->display_options['filters']['entityqueue_name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['operator_id'] = 'entityqueue_name_1_op';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['label'] = 'queue machine name';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['operator'] = 'entityqueue_name_1_op';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['identifier'] = 'entityqueue_name_1';
  $handler->display->display_options['filters']['entityqueue_name_1']['expose']['reduce'] = 1;
  $handler->display->display_options['path'] = 'applications/maybe';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Maybe';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Drafts */
  $handler = $view->new_display('page', 'Drafts', 'page_4');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  /* Field: Webform Submission: Last Name */
  $handler->display->display_options['fields']['field_webform_last_name']['id'] = 'field_webform_last_name';
  $handler->display->display_options['fields']['field_webform_last_name']['table'] = 'field_data_field_webform_last_name';
  $handler->display->display_options['fields']['field_webform_last_name']['field'] = 'field_webform_last_name';
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['path'] = 'application/[sid]';
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_webform_last_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_webform_last_name']['field_api_classes'] = 0;
  /* Field: Webform Submission: First Name */
  $handler->display->display_options['fields']['field_webform_first_name']['id'] = 'field_webform_first_name';
  $handler->display->display_options['fields']['field_webform_first_name']['table'] = 'field_data_field_webform_first_name';
  $handler->display->display_options['fields']['field_webform_first_name']['field'] = 'field_webform_first_name';
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_webform_first_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_webform_first_name']['field_api_classes'] = 0;
  /* Field: Webform submissions: Submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
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
  $handler->display->display_options['fields']['submitted']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['submitted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['submitted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['submitted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['submitted']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['submitted']['date_format'] = 'short';
  /* Field: COUNT(DISTINCT Content: Title) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['title']['label'] = 'Received Recommendations';
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
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['separator'] = '';
  $handler->display->display_options['fields']['title']['format_plural'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'application/[sid]';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['is_draft']['group'] = 1;
  $handler->display->display_options['path'] = 'applications/drafts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Drafts';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Too Soon */
  $handler = $view->new_display('page', 'Too Soon', 'page_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Entityqueue: queue machine name */
  $handler->display->display_options['filters']['entityqueue_name']['id'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['table'] = 'entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['field'] = 'entityqueue_name';
  $handler->display->display_options['filters']['entityqueue_name']['relationship'] = 'reverse_eq_webform_submission_entity_entityqueue';
  $handler->display->display_options['filters']['entityqueue_name']['value'] = array(
    'foot_locker_too_soon' => 'foot_locker_too_soon',
  );
  $handler->display->display_options['path'] = 'applications/too_soon';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Too Soon';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['application_queues'] = $view;

  $view = new view;
  $view->name = 'foot_locker_pulls';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Foot Locker Pulls';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access all webform results';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Rec Request */
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['id'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['field'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['ui_name'] = 'Rec Request';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['label'] = 'Rec Request';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['required'] = 1;
  /* Relationship: Rec */
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['id'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['field'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['ui_name'] = 'Rec';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['label'] = 'Rec';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['required'] = 0;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: Webform submissions: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
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
  $handler->display->display_options['fields']['sid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['sid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sid']['separator'] = '';
  $handler->display->display_options['fields']['sid']['format_plural'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['fields']['title']['label'] = 'Type';
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
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Webform submissions: Submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['fields']['submitted']['label'] = 'Rec Submitted';
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
  $handler->display->display_options['fields']['submitted']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['submitted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['submitted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['submitted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['submitted']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['submitted']['date_format'] = 'short';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'User E-mail';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['mail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Webform Submission: Email */
  $handler->display->display_options['fields']['field_webform_email']['id'] = 'field_webform_email';
  $handler->display->display_options['fields']['field_webform_email']['table'] = 'field_data_field_webform_email';
  $handler->display->display_options['fields']['field_webform_email']['field'] = 'field_webform_email';
  $handler->display->display_options['fields']['field_webform_email']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['fields']['field_webform_email']['label'] = 'Recommender\'s Email';
  $handler->display->display_options['fields']['field_webform_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_webform_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_webform_email']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_webform_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_webform_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_webform_email']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_webform_email']['field_api_classes'] = 0;
  /* Sort criterion: Webform submissions: Sid */
  $handler->display->display_options['sorts']['sid']['id'] = 'sid';
  $handler->display->display_options['sorts']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['sid']['field'] = 'sid';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_application_with_rec' => 'scholarship_application_with_rec',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['filters']['nid_1']['table'] = 'node';
  $handler->display->display_options['filters']['nid_1']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_1']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['filters']['nid_1']['value']['value'] = '724597';
  $handler->display->display_options['filters']['nid_1']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['filters']['nid']['value']['value'] = '724596';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  /* Filter criterion: Webform submissions: Sid */
  $handler->display->display_options['filters']['sid']['id'] = 'sid';
  $handler->display->display_options['filters']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['sid']['field'] = 'sid';
  $handler->display->display_options['filters']['sid']['relationship'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['filters']['sid']['operator'] = 'empty';
  $handler->display->display_options['filters']['sid']['group'] = 2;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/footlocker/missing-recommendations';
  $export['foot_locker_pulls'] = $view;

  return $export;
}
