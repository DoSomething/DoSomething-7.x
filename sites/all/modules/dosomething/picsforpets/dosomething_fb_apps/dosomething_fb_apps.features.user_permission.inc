<?php
/**
 * @file
 * dosomething_fb_apps.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_fb_apps_user_default_permissions() {
  $permissions = array();

  // Exported permission: view any fb_app_data_gathering_form webform submissions
  $permissions['view any fb_app_data_gathering_form webform submissions'] = array(
    'name' => 'view any fb_app_data_gathering_form webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'webform_entity_pages',
  );

  return $permissions;
}
