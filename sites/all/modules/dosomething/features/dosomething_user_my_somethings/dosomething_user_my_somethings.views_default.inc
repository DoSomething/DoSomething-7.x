<?php
/**
 * @file
 * dosomething_user_my_somethings.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_user_my_somethings_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'my_somethings';
  $view->description = 'The teams for my somethings display.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'My Teams';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Teams';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'You have not yet joined any clubs.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Group: Node group */
  $handler->display->display_options['relationships']['og_rel']['id'] = 'og_rel';
  $handler->display->display_options['relationships']['og_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_rel']['field'] = 'og_rel';
  $handler->display->display_options['relationships']['og_rel']['required'] = 1;
  /* Relationship: OG group: OG membership */
  $handler->display->display_options['relationships']['og_membership']['id'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership']['table'] = 'og';
  $handler->display->display_options['relationships']['og_membership']['field'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership']['relationship'] = 'og_rel';
  $handler->display->display_options['relationships']['og_membership']['required'] = 1;
  /* Field: Content: Official club photo */
  $handler->display->display_options['fields']['field_club_picture']['id'] = 'field_club_picture';
  $handler->display->display_options['fields']['field_club_picture']['table'] = 'field_data_field_club_picture';
  $handler->display->display_options['fields']['field_club_picture']['field'] = 'field_club_picture';
  $handler->display->display_options['fields']['field_club_picture']['label'] = '';
  $handler->display->display_options['fields']['field_club_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_club_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_club_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_club_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_club_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_club_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_club_picture']['settings'] = array(
    'image_style' => 'my_somethings',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_club_picture']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'club-title-container';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: OG membership: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['etid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['etid']['not'] = 0;
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

  /* Display: My Clubs */
  $handler = $view->new_display('panel_pane', 'My Clubs', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Entity id',
    ),
  );
  $export['my_somethings'] = $view;

  $view = new view;
  $view->name = 'profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Editors Picks for You';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'More »';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
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
  $handler->display->display_options['fields']['field_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 1;
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
  $handler->display->display_options['fields']['field_picture']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
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
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action_guide' => 'action_guide',
    'campaign' => 'campaign',
    'tips_and_tools' => 'tips_and_tools',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';

  /* Display: Editors picks pane */
  $handler = $view->new_display('panel_pane', 'Editors picks pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Editors Picks For You';
  $handler->display->display_options['display_description'] = 'Editors picks content pane on Member Profiles';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'queue1' => 0,
    'queue2' => 0,
    'queue3' => 0,
    'queue4' => 0,
    'queue5' => 0,
    'queue6' => 0,
    'queue7' => 0,
    'queue8' => 0,
    'queue9' => 0,
    'queue10' => 0,
    'queue11' => 0,
    'queue12' => 0,
    'queue13' => 0,
    'queue14' => 0,
    'queue15' => 0,
    'queue16' => 0,
    'queue17' => 0,
    'queue18' => 0,
    'queue19' => 0,
    'queue20' => 0,
    'queue21' => 0,
    'queue22' => 0,
    'queue23' => 0,
    'queue24' => 0,
    'queue25' => 0,
    'queue26' => 0,
    'queue27' => 0,
    'queue28' => 0,
    'queue29' => 0,
    'queue30' => 0,
    'queue31' => 0,
    'queue32' => 0,
    'queue33' => 0,
    'queue34' => 0,
    'queue35' => 0,
    'queue36' => 0,
    'queue37' => 0,
    'queue38' => 0,
    'queue40' => 0,
    'queue41' => 0,
    'queue42' => 0,
    'queue43' => 0,
    'queue44' => 0,
    'queue45' => 0,
    'queue46' => 0,
    'queue47' => 0,
    'queue48' => 0,
    'queue49' => 0,
    'queue50' => 0,
    'queue51' => 0,
    'queue52' => 0,
    'queue53' => 0,
    'queue54' => 0,
    'queue55' => 0,
    'queue56' => 0,
    'queue57' => 0,
    'queue58' => 0,
    'queue59' => 0,
    'queue60' => 0,
    'queue61' => 0,
    'queue62' => 0,
    'queue63' => 0,
    'queue64' => 0,
    'queue65' => 0,
    'queue66' => 0,
    'projects_police_personal_info' => 0,
    'projects_police_solicitation' => 0,
    'projects_police_volunteer_opp' => 0,
    'projects_police_not_a_project' => 0,
    'projects_police_offensive' => 0,
    'projects_police_blank_project' => 0,
    'action_of_the_week' => 0,
    'featured_campaign' => 0,
    'recent_scholarship_winner' => 0,
    'scholarships_past_winners' => 0,
    'action_updates' => 0,
    'featured_blog_posts' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture']['element_class'] = 'pane-narrow-thumb';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 1;
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
  $handler->display->display_options['fields']['field_picture']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
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
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 0;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Editors picks pane all */
  $handler = $view->new_display('panel_pane', 'Editors picks pane all', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Editors Picks For You';
  $handler->display->display_options['display_description'] = 'Editors picks content pane on Member Profiles';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/users/admin" class="back">« Back to profile</a>';
  $handler->display->display_options['footer']['area']['format'] = '4';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture']['element_class'] = 'pane-narrow-thumb';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'my_somethings',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="views-field-title">[title]</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'something-description';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Editors picks pane all - Club */
  $handler = $view->new_display('panel_pane', 'Editors picks pane all - Club', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Editors Picks For You';
  $handler->display->display_options['display_description'] = 'Editors picks content pane on Club';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_picture']['element_class'] = 'pane-narrow-thumb';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'my_somethings',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_picture']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_picture']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_picture']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_picture']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_picture']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_picture']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="views-field-title">[title]</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'something-description';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['profile'] = $view;

  $view = new view;
  $view->name = 'profile_incomplete_fields';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Profile incomplete fields';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stuff You Need To Do';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'All profile fields complete.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_first_name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_user_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_first_name']['empty'] = 'First name';
  $handler->display->display_options['fields']['field_user_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_first_name']['field_api_classes'] = 0;
  /* Field: Profile: Gender */
  $handler->display->display_options['fields']['field_user_gender']['id'] = 'field_user_gender';
  $handler->display->display_options['fields']['field_user_gender']['table'] = 'field_data_field_user_gender';
  $handler->display->display_options['fields']['field_user_gender']['field'] = 'field_user_gender';
  $handler->display->display_options['fields']['field_user_gender']['label'] = '';
  $handler->display->display_options['fields']['field_user_gender']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_user_gender']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_user_gender']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_gender']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_gender']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_gender']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_gender']['empty'] = '<a href="/user/!1/edit/main">Add gender</a>';
  $handler->display->display_options['fields']['field_user_gender']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_gender']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_user_gender']['field_api_classes'] = 0;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_last_name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_user_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_last_name']['empty'] = 'Last name';
  $handler->display->display_options['fields']['field_user_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_last_name']['field_api_classes'] = 0;
  /* Field: Profile: Location */
  $handler->display->display_options['fields']['field_user_address']['id'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address']['field'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['label'] = '';
  $handler->display->display_options['fields']['field_user_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_user_address']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_user_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_address']['empty'] = 'Location';
  $handler->display->display_options['fields']['field_user_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_address']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_user_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_user_address']['field_api_classes'] = 0;
  /* Field: Profile: What's Your Something? */
  $handler->display->display_options['fields']['field_user_preferred_cause']['id'] = 'field_user_preferred_cause';
  $handler->display->display_options['fields']['field_user_preferred_cause']['table'] = 'field_data_field_user_preferred_cause';
  $handler->display->display_options['fields']['field_user_preferred_cause']['field'] = 'field_user_preferred_cause';
  $handler->display->display_options['fields']['field_user_preferred_cause']['label'] = '';
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_preferred_cause']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_preferred_cause']['empty'] = '<a href="/user/!1/edit/main">Add What\'s Your Something?</a>';
  $handler->display->display_options['fields']['field_user_preferred_cause']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_preferred_cause']['click_sort_column'] = array(
    0 => 'nid',
  );
  $handler->display->display_options['fields']['field_user_preferred_cause']['field_api_classes'] = 0;
  /* Field: Profile: Why Do You Do Something? */
  $handler->display->display_options['fields']['field_user_why_do_you']['id'] = 'field_user_why_do_you';
  $handler->display->display_options['fields']['field_user_why_do_you']['table'] = 'field_data_field_user_why_do_you';
  $handler->display->display_options['fields']['field_user_why_do_you']['field'] = 'field_user_why_do_you';
  $handler->display->display_options['fields']['field_user_why_do_you']['label'] = '';
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_why_do_you']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_why_do_you']['empty'] = 'Why Do You Do Something?';
  $handler->display->display_options['fields']['field_user_why_do_you']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_why_do_you']['field_api_classes'] = 0;
  /* Field: Profile: Cell Phone */
  $handler->display->display_options['fields']['field_user_mobile']['id'] = 'field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['table'] = 'field_data_field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['field'] = 'field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['label'] = '';
  $handler->display->display_options['fields']['field_user_mobile']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_user_mobile']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_mobile']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_mobile']['empty'] = '<a href="/user/!1/edit/main">Add cell</a>';
  $handler->display->display_options['fields']['field_user_mobile']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_mobile']['field_api_classes'] = 0;
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_school_reference']['id'] = 'field_school_reference';
  $handler->display->display_options['fields']['field_school_reference']['table'] = 'field_data_field_school_reference';
  $handler->display->display_options['fields']['field_school_reference']['field'] = 'field_school_reference';
  $handler->display->display_options['fields']['field_school_reference']['label'] = '';
  $handler->display->display_options['fields']['field_school_reference']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_school_reference']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_school_reference']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_school_reference']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_school_reference']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_reference']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_school_reference']['empty'] = '<a href="/user/!1/edit/main">Add school</a>';
  $handler->display->display_options['fields']['field_school_reference']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_school_reference']['click_sort_column'] = array(
    0 => 'target_id',
  );
  $handler->display->display_options['fields']['field_school_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_school_reference']['field_api_classes'] = 0;
  /* Contextual filter: Profile: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'profile';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['user']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['user']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['user']['not'] = 0;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'user' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Profile: User uid',
    ),
  );
  $export['profile_incomplete_fields'] = $view;

  return $export;
}
