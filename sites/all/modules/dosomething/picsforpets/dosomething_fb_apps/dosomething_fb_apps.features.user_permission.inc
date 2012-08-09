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

  // Exported permission: administer adopted status
  $permissions['administer adopted status'] = array(
    'name' => 'administer adopted status',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'dosomething_fb_apps',
  );

  return $permissions;
}
