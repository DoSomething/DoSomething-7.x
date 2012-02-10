<?php

/**
 * @file
 * Preprocess functions for Dosomething Apps Grid.
 */

/**
 * Builds the Dosomething Apps Grid structure as a render array.
 */
function template_preprocess_dosomething_apps_grid(&$variables) {
  $variables['element'] = array();
  $view = $variables['view'];
  $options = $variables['options'];
  foreach ($variables['rows'] as $delta => $row) {
    $fields = array();
    foreach ($view->field as $field_name => $field) {
      $fields[$field_name] = $view->style_plugin->dosomething_apps_grid_fields_value($field, $field_name, $row, $delta);
    }

    if (!empty($fields[$options['banner']])) {
      $element['banner'] = $fields[$options['banner']]['rendered'];
    }

    if (!empty($fields[$options['image']])) {
      $element['image'] = $fields[$options['image']]['rendered'];
    }

    if (!empty($fields[$options['text']])) {
      $element['text'] = $fields[$options['text']]['rendered'];
    }

    if (!empty($fields[$options['footer']])) {
      $element['footer'] = $fields[$options['footer']]['rendered'];
    }

    if (!empty($fields[$options['link']])) {
      $element['link'] = $fields[$options['link']]['rendered'];
    }
    
    if (!empty($element)) {
      $variables['element'][$delta] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'apps-grid',
          ),
        ),
      ) + $element;
    }
  }

  if (!empty($variables['element'])) {
    $variables['element']['#attached']['css'][] = drupal_get_path('module', 'dosomething_apps_grid') . '/css/dosomething_apps_grid.css';
  }
}

/**
 * Render the event.
 */
function theme_dosomething_apps_grid($variables) {
  return drupal_render($variables['element']);
}
