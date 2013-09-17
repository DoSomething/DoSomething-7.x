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

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '22',
  );

  // Exported role: editorial admin.
  $roles['editorial admin'] = array(
    'name' => 'editorial admin',
    'weight' => '25',
  );

  // Exported role: product team.
  $roles['product team'] = array(
    'name' => 'product team',
    'weight' => '23',
  );

  // Exported role: staff.
  $roles['staff'] = array(
    'name' => 'staff',
    'weight' => '24',
  );

  return $roles;
}
