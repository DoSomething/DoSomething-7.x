<?php
/**
 * @file
 * dosomething_start_something.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_start_something_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_start_something_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function dosomething_start_something_image_default_styles() {
  $styles = array();

  // Exported image style: explore_action_guides
  $styles['explore_action_guides'] = array(
    'name' => 'explore_action_guides',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '345',
          'height' => '125',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: upcoming_somethings_thumb
  $styles['upcoming_somethings_thumb'] = array(
    'name' => 'upcoming_somethings_thumb',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '85',
          'height' => '55',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function dosomething_start_something_node_info() {
  $items = array(
    'dsu_guides' => array(
      'name' => t('Social Action How-To'),
      'base' => 'node_content',
      'description' => t('DoSomethingU: How to, tips, video, 11 Things to know about...
'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('11 Things to know about should be tagged as "information"'),
    ),
  );
  return $items;
}
