<?php

/**
 * @file
 * contains views module hooks
 */

/**
 * Implementation of hook_views_data().
 */
function dosomething_projects_general_views_data() {
  return array(
    'dosomething_projects_general' => array(
      'table' => array(
        'group' => t('DoSomething'),
        'join' => array('#global' => array()),
      ),
      'area' => array(
        'title' => t('More link'),
        'help' => t('Adds a link to this issues Cause page (parent taxonomy term).'),
        'area' => array(
          'handler' => 'dosomething_projects_general_handler_area_more_link',
        ),
      ),
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function dosomething_projects_general_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'dosomething_projects_general'),
    ),
    'handlers' => array(
      'dosomething_projects_general_handler_area_more_link' => array(
        'parent' => 'views_handler_area_text',
      ),
    ),
  );
}
