<?php
/**
 * @file
 * dosomething_campaign_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_campaign_blog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_campaign_blog_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dosomething_campaign_blog_node_info() {
  $items = array(
    'campaign_blog_post' => array(
      'name' => t('Campaign Blog Post'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
