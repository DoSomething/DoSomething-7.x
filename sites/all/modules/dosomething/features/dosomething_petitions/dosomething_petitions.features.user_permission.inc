<?php
/**
 * @file
 * dosomething_petitions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_petitions_user_default_permissions() {
  $permissions = array();

  // Exported permission: create petition content.
  $permissions['create petition content'] = array(
    'name' => 'create petition content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any petition content.
  $permissions['delete any petition content'] = array(
    'name' => 'delete any petition content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own petition content.
  $permissions['delete own petition content'] = array(
    'name' => 'delete own petition content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any petition content.
  $permissions['edit any petition content'] = array(
    'name' => 'edit any petition content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own petition content.
  $permissions['edit own petition content'] = array(
    'name' => 'edit own petition content',
    'roles' => array(
      0 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: view any petition webform submissions.
  $permissions['view any petition webform submissions'] = array(
    'name' => 'view any petition webform submissions',
    'roles' => array(),
    'module' => 'webform_entity_pages',
  );

  return $permissions;
}
