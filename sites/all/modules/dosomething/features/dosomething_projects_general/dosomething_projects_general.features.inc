<?php
/**
 * @file
 * dosomething_projects_general.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dosomething_projects_general_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
