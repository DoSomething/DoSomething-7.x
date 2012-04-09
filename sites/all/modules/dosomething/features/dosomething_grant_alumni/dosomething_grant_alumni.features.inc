<?php
/**
 * @file
 * dosomething_grant_alumni.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_grant_alumni_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_grant_alumni_node_info() {
  $items = array(
    'grant_alumni' => array(
      'name' => t('Grant Alumni Listing'),
      'base' => 'node_content',
      'description' => t('descriptions of winners of Do Something Grants, created by staff'),
      'has_title' => '1',
      'title_label' => t('Alumni Name'),
      'help' => '',
    ),
  );
  return $items;
}
