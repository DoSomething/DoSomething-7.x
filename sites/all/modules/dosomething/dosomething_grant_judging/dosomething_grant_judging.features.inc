<?php
/**
 * @file
 * dosomething_grant_judging.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_grant_judging_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_grant_judging_views_api() {
  return array("version" => "3.0");
}
