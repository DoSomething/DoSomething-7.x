<?php
/**
 * @file
 * dosomething_grants.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_grants_node_info() {
  $items = array(
    'grants_database' => array(
      'name' => t('Grants'),
      'base' => 'node_content',
      'description' => t('Entries of ALL DS and non DS grants teens can apply for.  Users can add. '),
      'has_title' => '1',
      'title_label' => t('Organization Name'),
      'help' => '',
    ),
  );
  return $items;
}
