<?php
/**
 * @file
 * dosomething_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
      2 => 'content loader',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
      2 => 'content loader',
    ),
    'module' => 'node',
  );

  // Exported permission: add media from remote sources.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'content loader',
      4 => 'unverified user',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: administer files.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
      2 => 'content loader',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: administer imce.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
      2 => 'content loader',
    ),
    'module' => 'imce',
  );

  // Exported permission: edit file.
  $permissions['edit file'] = array(
    'name' => 'edit file',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
      2 => 'content loader',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: use text format 1.
  $permissions['use text format 1'] = array(
    'name' => 'use text format 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'club reviewer',
      4 => 'content editor',
      5 => 'content loader',
      6 => 'developer',
      7 => 'grant reviewer',
      8 => 'moderator',
      9 => 'unverified user',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format 3.
  $permissions['use text format 3'] = array(
    'name' => 'use text format 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
      2 => 'content loader',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format 5.
  $permissions['use text format 5'] = array(
    'name' => 'use text format 5',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format editor_html.
  $permissions['use text format editor_html'] = array(
    'name' => 'use text format editor_html',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
      2 => 'content loader',
      3 => 'developer',
    ),
    'module' => 'filter',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'content editor',
      3 => 'content loader',
      4 => 'unverified user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
