<?php
/**
 * @file
 * robocalls.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function robocalls_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels" && $api == "layouts") {
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
function robocalls_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function robocalls_image_default_styles() {
  $styles = array();

  // Exported image style: robocall_celeb_photo
  $styles['robocall_celeb_photo'] = array(
    'name' => 'robocall_celeb_photo',
    'effects' => array(
      9 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => '225',
          'height' => '335',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: robocall_celeb_thumbnail_205x115
  $styles['robocall_celeb_thumbnail_205x115'] = array(
    'name' => 'robocall_celeb_thumbnail_205x115',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '205',
          'height' => '115',
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
function robocalls_node_info() {
  $items = array(
    'robo_calls' => array(
      'name' => t('Robo Calls'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
