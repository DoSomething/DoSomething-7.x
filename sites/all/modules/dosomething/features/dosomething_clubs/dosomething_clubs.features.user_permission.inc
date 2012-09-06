<?php
/**
 * @file
 * dosomething_clubs.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_clubs_user_default_permissions() {
  $permissions = array();

  // Exported permission: create club content
  $permissions['create club content'] = array(
    'name' => 'create club content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'content loader',
      4 => 'unverified user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
