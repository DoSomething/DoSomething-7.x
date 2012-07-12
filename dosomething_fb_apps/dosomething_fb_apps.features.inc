<?php
/**
 * @file
 * dosomething_fb_apps.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_fb_apps_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_fb_apps_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dosomething_fb_apps_node_info() {
  $items = array(
    'fb_app_data_gathering_form' => array(
      'name' => t('FB App Data Gathering Form'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
