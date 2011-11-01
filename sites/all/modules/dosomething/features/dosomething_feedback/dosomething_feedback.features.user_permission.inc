<?php
/**
 * @file
 * dosomething_feedback.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_feedback_user_default_permissions() {
  $permissions = array();

  // Exported permission: access feedback form
  $permissions['access feedback form'] = array(
    'name' => 'access feedback form',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'feedback',
  );

  return $permissions;
}
