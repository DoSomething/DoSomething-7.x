<?php
/**
 * @file
 * teams.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function teams_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "conductor") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function teams_node_info() {
  $items = array(
    'team_challenge' => array(
      'name' => t('Team Challenge'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
