<?php
/**
 * @file
 * dosomething_campaign.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_campaign_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
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
function dosomething_campaign_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dosomething_campaign_node_info() {
  $items = array(
    'campaign' => array(
      'name' => t('Campaign'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'campaign_content_page' => array(
      'name' => t('Campaign Content Page'),
      'base' => 'node_content',
      'description' => t('simple sub page for any campaign - IE facts, faq, action pages, maps etc. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
