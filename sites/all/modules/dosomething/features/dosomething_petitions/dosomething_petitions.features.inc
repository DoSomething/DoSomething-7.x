<?php
/**
 * @file
 * dosomething_petitions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_petitions_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "js_injector" && $api == "js_injector_rules") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_petitions_node_info() {
  $items = array(
    'petition' => array(
      'name' => t('Petition'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Call to Action'),
      'help' => '',
    ),
  );
  return $items;
}
