<?php
/**
 * @file
 * dosomething_drives.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_drives_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_drives_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dosomething_drives_node_info() {
  $items = array(
    'drive_form' => array(
      'name' => t('Drive Form'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name of the Drive'),
      'help' => '',
    ),
  );
  return $items;
}
