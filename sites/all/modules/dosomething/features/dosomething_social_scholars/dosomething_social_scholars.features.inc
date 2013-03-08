<?php
/**
 * @file
 * dosomething_social_scholars.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_social_scholars_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
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
function dosomething_social_scholars_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function dosomething_social_scholars_image_default_styles() {
  $styles = array();

  // Exported image style: social_scholarship_images_petition_735x150.
  $styles['social_scholarship_images_petition_735x150'] = array(
    'name' => 'social_scholarship_images_petition_735x150',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '735',
          'height' => '150',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: social_scholarship_stat_image_190x190.
  $styles['social_scholarship_stat_image_190x190'] = array(
    'name' => 'social_scholarship_stat_image_190x190',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '190',
          'height' => '190',
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
function dosomething_social_scholars_node_info() {
  $items = array(
    'social_scholarship' => array(
      'name' => t('Social Scholarship'),
      'base' => 'node_content',
      'description' => '',
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
function dosomething_social_scholars_default_webform_submission_entity_type() {
  $items = array();
  $items['social_scholarship'] = entity_import('webform_submission_entity_type', '{ "type" : "social_scholarship", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
