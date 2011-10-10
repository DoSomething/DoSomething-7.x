<?php
/**
 * @file
 * dosomething_awesome_things_landing_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_awesome_things_landing_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
