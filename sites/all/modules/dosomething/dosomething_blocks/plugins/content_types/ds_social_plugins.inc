<?php

/**
 * @file
 * Plugin to get node id for social media icons.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('DoSomething Social Media Plugins'),

  'description' => t('Displays social media plugins.'),

  'single' => TRUE,

  'content_types' => array('ds_social_plugins'),

  'render callback' => 'dosomething_blocks_social_plugins_content_type_render',

  'defaults' => array(),

  'icon' => 'icon_example.png',

  'category' => array(t('DoSometing'), 1),
);

/**
 * Run-time rendering of the body of the block (content type)
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time
 * @param $args
 * @param $context
 *   Context - in this case we don't have any
 *
 * @return
 *   An object with at least title and content members
 */
function dosomething_blocks_social_plugins_content_type_render($subtype, $conf, $args, $context) {
  dpm($args);
  $block = new stdClass();
  $block->title = "";
  $block->content = dosomething_blocks_social_node_plugins($url = NULL); 
  dpm($block);
  return $block;
}


