<?php
/**
 * @file
 * dosomething_about.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dosomething_about_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
