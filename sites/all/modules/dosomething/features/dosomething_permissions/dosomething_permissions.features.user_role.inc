<?php
/**
 * @file
 * dosomething_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dosomething_permissions_user_default_roles() {
  $roles = array();

  // Exported role: ds staff.
  $roles['ds staff'] = array(
    'name' => 'ds staff',
    'weight' => '24',
  );

  return $roles;
}
