<?php
/**
 * @file
 * dosomething_campaign_sign_up.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_campaign_sign_up_node_info() {
  $items = array(
    'campaign_sign_up' => array(
      'name' => t('campaign sign up'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
