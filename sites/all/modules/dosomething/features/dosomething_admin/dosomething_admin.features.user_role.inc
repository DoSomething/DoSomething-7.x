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

  // Exported role: ds staff.
  $roles['ds staff'] = array(
    'name' => 'ds staff',
    'weight' => '24',
  );

  // Exported role: optimizely admin.
  $roles['optimizely admin'] = array(
    'name' => 'optimizely admin',
    'weight' => '23',
  );

  return $roles;
}
