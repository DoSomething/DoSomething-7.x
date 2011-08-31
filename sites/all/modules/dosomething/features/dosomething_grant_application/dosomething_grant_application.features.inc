<?php
/**
 * @file
 * dosomething_grant_application.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_grant_application_node_info() {
  $items = array(
    'grant_application' => array(
      'name' => t('grant application'),
      'base' => 'node_content',
      'description' => t('Applications for grants'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
