<?php
/**
 * @file
 * dosomething_member_opportunity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_member_opportunity_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_member_opportunity_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_member_opportunity_node_info() {
  $items = array(
    'grant_judge' => array(
      'name' => t('Grant Judging Form'),
      'base' => 'node_content',
      'description' => t('for judging grant applications'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('<b>Thanks for judging!</b>
'),
    ),
    'member_opportunity' => array(
      'name' => t('Member Opportunity'),
      'base' => 'node_content',
      'description' => t('Entries of ALL DS and non DS grants teens can apply for. Users can add.'),
      'has_title' => '1',
      'title_label' => t('Organization Name'),
      'help' => '',
    ),
  );
  return $items;
}
