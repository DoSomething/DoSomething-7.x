<?php
/**
 * @file
 * dosomething_school.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_school_node_info() {
  $items = array(
    'school' => array(
      'name' => t('School'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('School Name'),
      'help' => '',
    ),
  );
  return $items;
}
