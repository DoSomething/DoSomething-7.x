<?php
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Rotoslider'),
  'description' => t('Sample rotoslider.'),
  'defaults' => array(
    'link' => TRUE,
  ),  
  'category' => t('Rotoslider'),
);

/**
 * Render the custom content type.
 */
function rotoslider_demo_roto_slider_content_type_render($subtype, $conf, $panel_args, $context) {
  // Build the content type block.
  $block = new stdClass();
  $block->module  = 'rotoslider_demo';
  $block->content = drupal_render(rotoslider_demo_page());
  $block->delta   = 1;

  return $block;
}
