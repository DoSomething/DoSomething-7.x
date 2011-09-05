<?php
/**
 * @file
 * dosomething_fb_social_plugins.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function dosomething_fb_social_plugins_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "fb_social" && $api == "fb_social") {
    return array("version" => "1");
  }
}
