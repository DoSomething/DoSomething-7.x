<?php

/**
 * @file
 * Theme functions for the Rotoslider.
 */

/**
 * Style plugin to render each item in a Rotoslider.
 */
function template_preprocess_rotoslider_view_slider(&$variables) {
  // Prepare settings to be passed to JS.
  $settings = array();
  foreach (array_filter($variables['options']['settings']) as $name => $setting) {
    if ($name == 'percentage') {
      $settings[$name] = $setting / 100;
    }
    else {
      $settings[$name] = (int) $setting;
    }
  }
  if (!empty($settings)) {
    drupal_add_js(array('rotoslider' => $settings), 'setting');
  }

  // Add a slide for each row.
  $items = _rotoslider_process($variables['options']['fields'], $variables['rows'], $variables['view']->field);

  // Either create an initial slide from the settings, or use the first slide.
  if (!empty($variables['options']['initial']['default'])) {
    unset($variables['options']['initial']['default']);
    $heading = _rotoslider_process($variables['options']['initial'], array($variables['rows'][0]), $variables['view']->field);
    $heading = reset($heading);
  }
  else {
    $heading = array_shift($items);
  }

  // Build the element for theme_rotoslider_slider().
  $variables['element'] = array(
    '#theme' => 'rotoslider_slider',
    '#items' => $items,
    '#heading' => $heading,
  );
}

/**
 * Skip the usage of a tpl.php file.
 */
function theme_rotoslider_view_slider($variables) {
  return drupal_render($variables['element']);
}

/**
 * Builds a renderable array of a Rotoslider.
 *
 * @param $variables
 *   An associative array containing:
 *   - items: An associative array of items to be displayed in the slider. Each
 *     item should be itself an array, with the following elements:
 *     - title: The slider item text.
 *     - image: The image URL.
 *     - text: The description associated with this item.
 *   - header: A single item to be displayed as the initial state of the slider.
 *     The array must contain the following elements:
 *     - title: The title of the slider set.
 *     - image: The image URL to be used in the default state.
 *     - text: The description of the slider set.
 */
function template_preprocess_rotoslider_slider(&$variables) {
  $items = $variables['items'];
  $heading = $variables['heading'];

  static $count;
  $count++;

  // Build three arrays, each with its fields.
  $links = array();
  $images = array();
  $text = array();
  foreach ($items as $item) {
    // Append an integer to each set of data to keep them unique.
    $key = drupal_html_class($item['title'] . '-' . $count);
    // An individual item to be passed to theme_links().
    $links[$key] = array(
      'title' => $item['title'],
      'href' => "#",
      'external' => TRUE,
      'attributes' => array(
        'data-key' => $key,
      ),
    );
    // Each image is passed to theme_image().
    $images[$key] = array(
      '#theme' => 'image',
      '#path' => $item['image'],
      '#alt' => $item['title'],
      '#attributes' => array(
        'data-key' => $key,
      ),
    );
    // A container with heading and text as children.
    $text[$key] = array(
      '#type' => 'container',
      '#attributes' => array(
        'data-key' => $key,
        'class' => array(
          'rotoslider-text',
        ),
      ),
      'heading' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'heading',
          ),
        ),
        '#children' => $item['title'],
      ),
      'text' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'text',
          ),
        ),
        '#children' => $item['text'],
      ),
    );
  }

  $path = drupal_get_path('module', 'rotoslider');
  $element = array(
    '#attached' => array(
      'css' => array(
        $path . '/css/rotoslider.base.css',
        $path . '/css/rotoslider.theme.css',
      ),
      'js' => array(
        $path . '/js/rotoslider.js',
      ),
    ),
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'rotoslider',
      ),
    ),
    'image' => array(
      '#theme' => 'image',
      '#path' => $heading['image'],
      '#alt' => $heading['title'],
      '#attributes' => array(
        'class' => array(
          'rotoslider-image',
        ),
      ),
    ),
    'images' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'rotoslider-images',
        ),
      ),
      'images' => $images,
    ),
    'description' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'rotoslider-description',
        ),
      ),
      '#children' => $heading['text'],
    ),
    'descriptions' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'rotoslider-descriptions',
        ),
      ),
      'text' => $text,
    ),
    'menu' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'rotoslider-menu',
        ),
      ),
      'links' => array(
        '#theme' => 'links',
        '#attributes' => array(
          'class' => array(
            'rotoslider-nav',
          ),
        ),
        '#links' => $links,
        '#heading' => array(
          'text' => $heading['title'],
          'level' => 'div',
          'class' => array(
            'heading',
          ),
        ),
      ),
    ),
  );

  $variables['element'] = $element;
}

/**
 * Returns HTML for a Rotoslider.
 */
function theme_rotoslider_slider($variables) {
  return drupal_render($variables['element']);
}

/**
 * Helper function: Turns raw Views data into santized values.
 *
 * @param $options
 *   Array of either Views field names or hardcoded values, keyed by field type.
 * @param $rows
 *   Array of objects containing raw Views data, keyed by Views field aliases.
 * @param $fields
 *   Array of Views field handler objects, keyed by Views field names.
 *
 * @return
 *   Array of numerically indexed items. Each item should itself be an array,
 *   with the following elements:
 *   - title: The item's plain text title.
 *   - image: The item's image absolute URL.
 *   - text: The item's decription, which may contain markup.
 */
function _rotoslider_process($options, $rows, $fields) {
  $items = array();

  $info = array();
  foreach (array_filter($options) as $type => $field_name) {
    if (empty($fields[$field_name])) {
      $info[$type] = $field_name;
    }
    else {
      $info[$type] = isset($fields[$field_name]->field_info) ? "field_$field_name" : $fields[$field_name]->field_alias;
    }
  }

  // Get the placeholder image.
  $placeholder = variable_get('rotoslider_placeholder');
  foreach ($rows as $delta => $row) {
    foreach (array('title', 'image', 'text') as $type) {
      if (isset($row->$info[$type])) {
        $value = $row->$info[$type];
      }
      elseif (isset($info[$type])) {
        $value = $info[$type];
      }
      elseif ($type == 'title') {
        continue;
      }
      else {
        $value = '';
      }

      // If a placeholder is set and the image is missing, use it.
      if (empty($value)) {
        $value = ($type == 'image' && !empty($placeholder)) ? $placeholder : '';
      }

      $column = $type == 'image' ? 'uri' : 'value';
      $values[$type] = is_array($value) ? $value[0]['raw'][$column] : $value;
    }

    $items[$delta] = array(
      'title' => check_plain($values['title']),
      'image' => file_create_url(check_plain($values['image'])),
      'text' => check_markup($values['text']),
    );
  }

  return $items;
}
