<?php
/**
 * @file
 * dosomething_home.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_home_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_home_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function dosomething_home_image_default_styles() {
  $styles = array();

  // Exported image style: rotoslider_homepage_main
  $styles['rotoslider_homepage_main'] = array(
    'name' => 'rotoslider_homepage_main',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '540',
          'height' => '390',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: rotoslider_nav
  $styles['rotoslider_nav'] = array(
    'name' => 'rotoslider_nav',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '175',
          'height' => '65',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: rotoslider_start_something_main
  $styles['rotoslider_start_something_main'] = array(
    'name' => 'rotoslider_start_something_main',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '515',
          'height' => '325',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
