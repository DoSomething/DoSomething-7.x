<?php
/**
 * @file
 * dosomething_action_finder.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_action_finder_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_action_finder_views_api() {
  return array("version" => "3.0");
}
