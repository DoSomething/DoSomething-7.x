<?php
/**
 * @file
 * dosomething_program_short_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_program_short_form_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_program_short_form_node_info() {
  $items = array(
    'program_short_form' => array(
      'name' => t('Program Short Form'),
      'base' => 'node_content',
      'description' => t('Short contact form for pages like Scholarships, Grants, Boot Camp, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
