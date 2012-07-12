<?php
/**
 * @file
 * dosomething_picsforpets_shelters.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_picsforpets_shelters_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_picsforpets_shelters_node_info() {
  $items = array(
    'shelter' => array(
      'name' => t('Shelter'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Shelter Name'),
      'help' => '',
    ),
  );
  return $items;
}
