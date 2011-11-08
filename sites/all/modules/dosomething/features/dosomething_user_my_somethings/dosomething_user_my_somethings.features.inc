<?php
/**
 * @file
 * dosomething_user_my_somethings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_user_my_somethings_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_user_my_somethings_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
