<?php
/**
 * @file
 * dosomething_editorial_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_editorial_content_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_editorial_content_node_info() {
  $items = array(
    'editorial_content_' => array(
      'name' => t('Editorial Content'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
