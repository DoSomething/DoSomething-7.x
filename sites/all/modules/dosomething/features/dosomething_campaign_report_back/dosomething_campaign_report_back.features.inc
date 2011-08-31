<?php
/**
 * @file
 * dosomething_campaign_report_back.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_campaign_report_back_node_info() {
  $items = array(
    'campaign_report_back' => array(
      'name' => t('campaign report back'),
      'base' => 'node_content',
      'description' => t('A way for users to report back on the things they have done.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
