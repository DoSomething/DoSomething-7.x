<?php
/**
 * @file
 * dosomething_scholarship_application.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_scholarship_application_node_info() {
  $items = array(
    'scholarship_application' => array(
      'name' => t('scholarship application'),
      'base' => 'node_content',
      'description' => t('An application for a scholarship'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
