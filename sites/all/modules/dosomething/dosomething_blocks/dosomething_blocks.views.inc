<?php

/**
 * @file
 * Provide views handlers and plugins that allow display of .
 */

/**
 * Implements hook_views_data().
 */
function dosomething_blocks_views_data() {
  $data['views']['ds_social_plugins'] = array(
    'title' => t('DoSomething Social Plugins'),
    'help' => t('Display a DoSomething social plugins block.'),
    'field' => array(
      'handler' => 'ds_social_plugins_handler_field',
    ),
  );
  return $data;
}
