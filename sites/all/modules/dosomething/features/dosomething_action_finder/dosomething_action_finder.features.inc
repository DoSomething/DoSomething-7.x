<?php
/**
 * @file
 * dosomething_action_finder.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dosomething_action_finder_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
