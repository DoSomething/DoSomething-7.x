<?php
/**
 * @file
 * dosomething_picsforpets_general.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dosomething_picsforpets_general_user_default_roles() {
  $roles = array();

  // Exported role: furtographer.
  $roles['furtographer'] = array(
    'name' => 'furtographer',
    'weight' => '3',
  );

  return $roles;
}
