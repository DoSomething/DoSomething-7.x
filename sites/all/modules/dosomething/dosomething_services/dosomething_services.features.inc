<?php
/**
 * @file
 * dosomething_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_services_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
