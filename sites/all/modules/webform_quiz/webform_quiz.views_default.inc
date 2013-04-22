<?php
/**
 * @file
 * webform_quiz.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function webform_quiz_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'quizzes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Quizzes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quizzes';
  $handler->display->display_options['css_class'] = 'action-finder-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Quiz Header */
  $handler->display->display_options['fields']['field_quiz_header']['id'] = 'field_quiz_header';
  $handler->display->display_options['fields']['field_quiz_header']['table'] = 'field_data_field_quiz_header';
  $handler->display->display_options['fields']['field_quiz_header']['field'] = 'field_quiz_header';
  $handler->display->display_options['fields']['field_quiz_header']['label'] = '';
  $handler->display->display_options['fields']['field_quiz_header']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_quiz_header']['alter']['text'] = '<span class="views-field-field-picture">[field_quiz_header]</span>';
  $handler->display->display_options['fields']['field_quiz_header']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_quiz_header']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_quiz_header']['settings'] = array(
    'image_style' => 'action_results_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="unimage-wrapper">
<h2>[title]</h2>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
    'quiz' => 'quiz',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'quizzes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Quizzes';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Quizzes';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_quiz_header' => 'field_quiz_header',
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Quiz Header */
  $handler->display->display_options['fields']['field_quiz_header']['id'] = 'field_quiz_header';
  $handler->display->display_options['fields']['field_quiz_header']['table'] = 'field_data_field_quiz_header';
  $handler->display->display_options['fields']['field_quiz_header']['field'] = 'field_quiz_header';
  $handler->display->display_options['fields']['field_quiz_header']['label'] = '';
  $handler->display->display_options['fields']['field_quiz_header']['element_class'] = 'project-related-thumb';
  $handler->display->display_options['fields']['field_quiz_header']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_quiz_header']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_quiz_header']['settings'] = array(
    'image_style' => 'project_related_thumb',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $export['quizzes'] = $view;

  return $export;
}
