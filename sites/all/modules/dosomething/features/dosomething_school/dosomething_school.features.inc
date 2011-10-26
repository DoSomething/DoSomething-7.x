<?php
/**
 * @file
 * dosomething_school.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_school_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_school_node_info() {
  $items = array(
    'school' => array(
      'name' => t('School'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('School Name'),
      'help' => '',
    ),
  );
  return $items;
}
