<?php
/**
 * @file
 * crazyshit.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crazyshit_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
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
function crazyshit_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function crazyshit_image_default_styles() {
  $styles = array();

  // Exported image style: crazy_facebook_picture.
  $styles['crazy_facebook_picture'] = array(
    'name' => 'crazy_facebook_picture',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '50',
          'height' => '50',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: crazy_image_dimensions.
  $styles['crazy_image_dimensions'] = array(
    'name' => 'crazy_image_dimensions',
    'effects' => array(
      14 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '400',
          'height' => '400',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
      15 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => '400',
          'height' => '400',
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function crazyshit_node_info() {
  $items = array(
    'crazy_shit' => array(
      'name' => t('Crazy #*(@&#$'),
      'base' => 'node_content',
      'description' => t('Craaaazy'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_webform_submission_entity_type().
 */
function crazyshit_default_webform_submission_entity_type() {
  $items = array();
  $items['crazy_shit'] = entity_import('webform_submission_entity_type', '{ "type" : "crazy_shit", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
