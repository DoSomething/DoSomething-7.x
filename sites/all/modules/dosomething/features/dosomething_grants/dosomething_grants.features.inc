<?php
/**
 * @file
 * dosomething_grants.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_grants_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_grants_node_info() {
  $items = array(
    'grants_database' => array(
      'name' => t('Grants'),
      'base' => 'node_content',
      'description' => t('Entries of ALL DS and non DS grants teens can apply for.  Users can add. '),
      'has_title' => '1',
      'title_label' => t('Organization Name'),
      'help' => '',
    ),
  );
  return $items;
}
