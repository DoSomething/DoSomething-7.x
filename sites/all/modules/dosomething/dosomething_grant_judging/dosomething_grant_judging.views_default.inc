<?php
/**
 * @file
 * dosomething_grant_judging.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dosomething_grant_judging_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'grant_judging';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Grant Judging';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Seed Grant Judging';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    7 => '7',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_grant_judge_application_webform_submission_entity']['id'] = 'reverse_field_grant_judge_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_grant_judge_application_webform_submission_entity']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['reverse_field_grant_judge_application_webform_submission_entity']['field'] = 'reverse_field_grant_judge_application_webform_submission_entity';
  $handler->display->display_options['relationships']['reverse_field_grant_judge_application_webform_submission_entity']['label'] = 'Grant Judgment';
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'reverse_field_grant_judge_application_webform_submission_entity';
  $handler->display->display_options['relationships']['uid']['label'] = 'Grant Judgment User';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_webform_project_submission_target_id']['id'] = 'field_webform_project_submission_target_id';
  $handler->display->display_options['relationships']['field_webform_project_submission_target_id']['table'] = 'field_data_field_webform_project_submission';
  $handler->display->display_options['relationships']['field_webform_project_submission_target_id']['field'] = 'field_webform_project_submission_target_id';
  $handler->display->display_options['relationships']['field_webform_project_submission_target_id']['required'] = TRUE;
  /* Relationship: Entityqueue: dosomething_grant_application Queue */
  $handler->display->display_options['relationships']['dosomething_grant_application']['id'] = 'dosomething_grant_application';
  $handler->display->display_options['relationships']['dosomething_grant_application']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['dosomething_grant_application']['field'] = 'dosomething_grant_application';
  $handler->display->display_options['relationships']['dosomething_grant_application']['required'] = TRUE;
  $handler->display->display_options['relationships']['dosomething_grant_application']['limit'] = 1;
  $handler->display->display_options['relationships']['dosomething_grant_application']['queues'] = array(
    'grants_judging' => 'grants_judging',
    'grants_rejected' => 0,
    'grants_toosoon' => 0,
  );
  /* Field: Webform submissions: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = '';
  $handler->display->display_options['fields']['sid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sid']['alter']['text'] = 'Judge now!';
  $handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sid']['separator'] = '';
  /* Field: Webform Submission: Title of your project */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['relationship'] = 'field_webform_project_submission_target_id';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  /* Field: Webform Submission: Name */
  $handler->display->display_options['fields']['field_webform_name']['id'] = 'field_webform_name';
  $handler->display->display_options['fields']['field_webform_name']['table'] = 'field_data_field_webform_name';
  $handler->display->display_options['fields']['field_webform_name']['field'] = 'field_webform_name';
  $handler->display->display_options['fields']['field_webform_name']['label'] = '';
  $handler->display->display_options['fields']['field_webform_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_webform_name']['alter']['text'] = '[field_webform_name-value] ([field_project_title])';
  $handler->display->display_options['fields']['field_webform_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_webform_name']['alter']['path'] = 'grants/judge/[sid]?destination=grants/judge';
  $handler->display->display_options['fields']['field_webform_name']['element_label_colon'] = FALSE;
  /* Filter criterion: Global: View */
  $handler->display->display_options['filters']['view']['id'] = 'view';
  $handler->display->display_options['filters']['view']['table'] = 'views';
  $handler->display->display_options['filters']['view']['field'] = 'view';
  $handler->display->display_options['filters']['view']['operator'] = 'NOT IN';
  $handler->display->display_options['filters']['view']['view'] = 'grant_judging:attachment_1';

  /* Display: Grant Judging Landing Unjudged */
  $handler = $view->new_display('page', 'Grant Judging Landing Unjudged', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Welcome to Seed Grant Judging! Do Something.org Seed Grants powered by American Express aim to support young social entrepreneurs in community projects with lasting impact. Please review the judging criteria below before beginning.

<strong>NOVEMBER JUDGING IS OPEN NOW THROUGH OCTOBER 23RD </strong>

<h2>Judging Criteria</h2>
Each application will be judged on a a scale of 1-10 (1 = absolutely do not agree, 5 = neutral, 10 = totally agree) for the following criteria:
<ul>
<li><strong>Youth led and driven.</strong> The applicant is in charge of, or plays a very active role in designing, leading, and implementing the project.</li>
<li><strong>Measurable change.</strong> The applicant’s project strives toward tangible results and measurable impact. There are clear goals and a focused plan of action for reaching those goals.</li>
<li><strong>Community focus.</strong> The applicant’s project focuses on improving community problems and engaging and involving the community in their project.</li>
<li><strong>Lasting change.</strong> The applicant’s project can be a one-time event or ongoing program, however it should strive to make a lasting change in his or her community.</li>
<li><strong>Creativity.</strong> The applicant’s project is creative and demonstrates an original idea for solving a problem and creating change in the local community.</li>
<li><strong>Diversity.</strong> The applicant’s project promotes diversity and brings different kinds of people together.</li>
<li><strong>Grant winner material?</strong> The applicant has met the above criteria and provides a unique and detailed plan to measure impact effectively.</li>
</ul>

<h2>To be judged:</h2>';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/grants/judge-confirm" class="go-button">Submit all</a>';
  $handler->display->display_options['footer']['area']['format'] = '3';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'Looks like you\'ve already started judging all of the available applications. See below if you haven\'t finished.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'grants/judge';

  /* Display: Draft Judgments */
  $handler = $view->new_display('attachment', 'Draft Judgments', 'attachment_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Incomplete Judging Forms</h2>';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['relationship'] = 'reverse_field_grant_judge_application_webform_submission_entity';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['is_draft']['group'] = 1;
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Judged Apps */
  $handler = $view->new_display('attachment', 'Judged Apps', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'What you\'ve judged so far';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Already judged:</h2>';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['grant_judging'] = $view;

  return $export;
}
