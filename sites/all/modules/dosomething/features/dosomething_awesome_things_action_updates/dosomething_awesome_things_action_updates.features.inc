<?php
/**
 * @file
 * dosomething_awesome_things_action_updates.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_awesome_things_action_updates_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_awesome_things_action_updates_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function dosomething_awesome_things_action_updates_image_default_styles() {
  $styles = array();

  // Exported image style: action_results_thumbnail
  $styles['campaign_report_back_style'] = array(
    'name' => 'campaign_report_back_style',
    'effects' => array(
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '225',
          'height' => '105',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
