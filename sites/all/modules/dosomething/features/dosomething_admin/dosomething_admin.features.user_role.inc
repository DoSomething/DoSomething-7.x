<?php
/**
 * @file
 * dosomething_admin.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dosomething_admin_user_default_roles() {
  $roles = array();

  // Exported role: ds product team.
  $roles['ds product team'] = array(
    'name' => 'ds product team',
    'weight' => '23',
  );

  // Exported role: ds staff.
  $roles['ds staff'] = array(
    'name' => 'ds staff',
    'weight' => '24',
  );

  return $roles;
}
