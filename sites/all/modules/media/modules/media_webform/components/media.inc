<?php

/**
 * @file
 * Media: Webform module media component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_media() {
  return array(
    'name' => '',
    'form_key' => NULL,
    'mandatory' => 0,
    'pid' => 0,
    'weight' => 0,
    'extra' => array(
      'allowed_types' => array(),
      'allowed_schemes' => array(),
    ),
  );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_media($component) {
  $instance = array('widget' => array('settings' => $component['extra']));
  $form['extra'] = media_field_widget_settings_form(NULL, $instance);
  return $form;
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_media($component, $value = NULL, $filter = TRUE) {
  $form = array();
  $form_state = array();
  $instance = array('widget' => array('settings' => $component['extra']));

  $element = array(
    'media' => media_field_widget_form($form, $form_state, NULL, $instance, NULL, NULL, NULL, array()),
    '#webform_component' => $component,
    '#weight' => $component['weight'],
    '#title' => $filter ? _webform_filter_xss($component['name']) : $component['name'],
    '#title_display' => $component['extra']['title_display'] ? $component['extra']['title_display'] : 'before',
    '#description' => $filter ? _webform_filter_descriptions($component['extra']['description']) : $component['extra']['description'],
    '#theme_wrappers' => array('webform_element'),
  );

  if ($component['mandatory']) {
    $element['#required'] = TRUE;
  }

  return $element;
}

/**
 * Implements _webform_submit_component().
 */
function _webform_submit_media($component, $value) {
  return isset($value['media']) ? $value['media'] : NULL;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_media($component, $value, $format = 'html') {
  $fid = isset($value['fid']) ? $value['fid'] : NULL;
  return file_view(file_load($fid));
}
