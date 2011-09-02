<?php
/**
 * @file
 * dosomething_editorial_content.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_editorial_content_node_info() {
  $items = array(
    'editorial_content_' => array(
      'name' => t('Editorial Content'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
