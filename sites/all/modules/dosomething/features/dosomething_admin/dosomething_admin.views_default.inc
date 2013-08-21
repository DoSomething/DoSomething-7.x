<?php
/**
 * @file
 * dosomething_admin.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_admin_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_lookup_submission';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Admin Lookup: Submission';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Submission Lookup';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access all webform results';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = '1';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sid' => 'sid',
    'nid' => 'nid',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: App Bridge */
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['id'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['field'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_application_webform_submission_entity']['ui_name'] = 'App Bridge';
  /* Relationship: Request Bridge */
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['id'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['field'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_rec_request_webform_submission_entity']['ui_name'] = 'Request Bridge';
  /* Field: Webform submissions: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'UID';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['label'] = 'Submission';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission_2']['id'] = 'view_submission_2';
  $handler->display->display_options['fields']['view_submission_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission_2']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission_2']['relationship'] = 'reverse_field_application_webform_submission_entity';
  $handler->display->display_options['fields']['view_submission_2']['label'] = 'Recommendation Request (if exists)';
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission_3']['id'] = 'view_submission_3';
  $handler->display->display_options['fields']['view_submission_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission_3']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission_3']['relationship'] = 'reverse_field_rec_request_webform_submission_entity';
  $handler->display->display_options['fields']['view_submission_3']['label'] = 'Recommendation (if exists)';
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'uid';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  /* Filter criterion: Webform Submission: First Name (field_webform_first_name) */
  $handler->display->display_options['filters']['field_webform_first_name_value']['id'] = 'field_webform_first_name_value';
  $handler->display->display_options['filters']['field_webform_first_name_value']['table'] = 'field_data_field_webform_first_name';
  $handler->display->display_options['filters']['field_webform_first_name_value']['field'] = 'field_webform_first_name_value';
  $handler->display->display_options['filters']['field_webform_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_webform_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_webform_first_name_value']['expose']['operator_id'] = 'field_webform_first_name_value_op';
  $handler->display->display_options['filters']['field_webform_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_webform_first_name_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_webform_first_name_value']['expose']['operator'] = 'field_webform_first_name_value_op';
  $handler->display->display_options['filters']['field_webform_first_name_value']['expose']['identifier'] = 'field_webform_first_name_value';
  /* Filter criterion: Webform Submission: Last Name (field_webform_last_name) */
  $handler->display->display_options['filters']['field_webform_last_name_value']['id'] = 'field_webform_last_name_value';
  $handler->display->display_options['filters']['field_webform_last_name_value']['table'] = 'field_data_field_webform_last_name';
  $handler->display->display_options['filters']['field_webform_last_name_value']['field'] = 'field_webform_last_name_value';
  $handler->display->display_options['filters']['field_webform_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_webform_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_webform_last_name_value']['expose']['operator_id'] = 'field_webform_last_name_value_op';
  $handler->display->display_options['filters']['field_webform_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_webform_last_name_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_webform_last_name_value']['expose']['operator'] = 'field_webform_last_name_value_op';
  $handler->display->display_options['filters']['field_webform_last_name_value']['expose']['identifier'] = 'field_webform_last_name_value';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scholarship_recommendation' => 'scholarship_recommendation',
    'scholarship_recommendation_reque' => 'scholarship_recommendation_reque',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/lookup/submission';
  $export['admin_lookup_submission'] = $view;

  $view = new view();
  $view->name = 'admin_lookup_user';
  $view->description = 'Allow for searching by username, email address, first & last names.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Admin Lookup: User';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Lookup';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access administration menu';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = '1';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'field_user_first_name' => 'field_user_first_name',
    'field_user_last_name' => 'field_user_last_name',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_user_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
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
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'profile';
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'profile';
  /* Field: Profile: Cell Phone */
  $handler->display->display_options['fields']['field_user_mobile']['id'] = 'field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['table'] = 'field_data_field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['field'] = 'field_user_mobile';
  $handler->display->display_options['fields']['field_user_mobile']['relationship'] = 'profile';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  /* Filter criterion: Profile: First Name (field_user_first_name) */
  $handler->display->display_options['filters']['field_user_first_name_value']['id'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['filters']['field_user_first_name_value']['field'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_first_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_user_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['operator_id'] = 'field_user_first_name_value_op';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['operator'] = 'field_user_first_name_value_op';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['identifier'] = 'field_user_first_name_value';
  /* Filter criterion: Profile: Last Name (field_user_last_name) */
  $handler->display->display_options['filters']['field_user_last_name_value']['id'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['filters']['field_user_last_name_value']['field'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_last_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_user_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['operator_id'] = 'field_user_last_name_value_op';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['operator'] = 'field_user_last_name_value_op';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['identifier'] = 'field_user_last_name_value';
  /* Filter criterion: Profile: Cell Phone (field_user_mobile) */
  $handler->display->display_options['filters']['field_user_mobile_value']['id'] = 'field_user_mobile_value';
  $handler->display->display_options['filters']['field_user_mobile_value']['table'] = 'field_data_field_user_mobile';
  $handler->display->display_options['filters']['field_user_mobile_value']['field'] = 'field_user_mobile_value';
  $handler->display->display_options['filters']['field_user_mobile_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_mobile_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_mobile_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_mobile_value']['expose']['operator_id'] = 'field_user_mobile_value_op';
  $handler->display->display_options['filters']['field_user_mobile_value']['expose']['label'] = 'Cell Phone';
  $handler->display->display_options['filters']['field_user_mobile_value']['expose']['operator'] = 'field_user_mobile_value_op';
  $handler->display->display_options['filters']['field_user_mobile_value']['expose']['identifier'] = 'field_user_mobile_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/lookup/user';
  $export['admin_lookup_user'] = $view;

  return $export;
}
