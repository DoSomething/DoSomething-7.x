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
    elseif ($name == 'speed') {
      $settings[$name] = (int) $setting;
    }
  }

  $base_field = NULL;
  if (!empty($variables['options']['settings']['link'])) {
    $base_field = $variables['view']->base_field;
  }
  if (!empty($settings)) {
    drupal_add_js(array('rotoslider' => $settings), 'setting');
  }

  // Add a slide for each row.
  $items = _rotoslider_process($variables['options']['fields'], $variables['rows'], $variables['view']->field, $base_field);

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
    $key = drupal_html_class($item['title']['#markup'] . '-' . $count);
    // An individual item to be passed to theme_links().
    $links[$key] = array(
      'title' => $item['title']['#markup'],
      'href' => "#",
      'external' => TRUE,
      'attributes' => array(
        'data-key' => $key,
      ),
    );
    $images[$key] = array(
      '#alt' => $item['title']['#markup'],
      '#attributes' => array(
        'data-key' => $key,
      ),
    ) + $item['image'];
    // A container with heading (possibly a link) and text as children.
    if (!empty($item['uri'])) {
      $heading_text = array(
        '#theme' => 'link',
        '#text' => $item['title']['#markup'],
        '#path' => $item['uri']['path'],
        '#options' => $item['uri']['options'] + array(
          'attributes' => array(),
          'html' => FALSE,
        ),
      );
    }
    else {
      $heading_text = $item['title'];
    }
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
        'heading' => $heading_text,
      ),
      'text' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'text',
          ),
        ),
        'text' => $item['text'],
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
      '#alt' => $heading['title']['#markup'],
      '#attributes' => array(
        'class' => array(
          'rotoslider-image',
        ),
      ),
    ) + $heading['image'],
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
      '#pre_render' => array('rotoslider_container_pre_render'),
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'rotoslider-description',
        ),
      ),
      'description' => $heading['text'],
    ),
    'descriptions' => array(
      '#pre_render' => array('rotoslider_container_pre_render'),
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
          'text' => $heading['title']['#markup'],
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
 * #pre_render callback: Prevents empty containers from printing.
 */
function rotoslider_container_pre_render($element) {
  $children_keys = element_children($element);
  $children = drupal_render_children($element, $children_keys);
  if (empty($children)) {
    $element = array('#markup');
  }
  else {
    foreach ($children_keys as $key) {
      show($element[$key]);
    }
  }
  return $element;
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
function _rotoslider_process($options, $rows, $fields, $base_field = NULL) {
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
    $values = array();

    // Find the URI of the original content.
    // @todo Make this a proper field.
    if (!empty($base_field) && !empty($row->_field_data[$base_field])) {
      $values['uri'] = entity_uri($row->_field_data[$base_field]['entity_type'], $row->_field_data[$base_field]['entity']);
    }

    foreach (array('title', 'image', 'text') as $type) {
      $value = '';
      // The field contains a Views field alias.
      if (isset($row->$info[$type])) {
        $value = $row->$info[$type];
      }
      // The field contains the actual value.
      elseif (isset($info[$type])) {
        $value = $info[$type];
      }
      // Do not add items without a title.
      elseif ($type == 'title') {
        continue;
      }

      // Use the rendered value of a field.
      if (is_array($value) && isset($value[0]['rendered'])) {
        $value = $value[0]['rendered'];
      }

      // Rewrite the image to use either theme_image() or theme_image_style().
      if ($type == 'image') {
        // Views gives us an array for theme_image_formatter(), rewrite it.
        if (is_array($value) && isset($value['#theme']) && $value['#theme'] == 'image_formatter') {
          $value['#style_name'] = $value['#image_style'];
          $value['#theme'] = 'image_style';
          $value['#path'] = $value['#item']['uri'];
        }
        else {
          // If a placeholder is set and the image is missing, use it.
          if (empty($value) && !empty($placeholder)) {
            $path = $placeholder;
          }
          // If the image is present, use it.
          elseif (!empty($value) && !is_array($value)) {
            $path = $value;
          }
          if (!empty($path)) {
            $value = array(
              '#theme' => 'image',
              '#path' => $path,
              '#attributes' => array(),
            );
          }
        }
      }

      // Wrap plain text as a render array.
      if (!is_array($value)) {
        $value = array('#markup' => $value);
      }

      $values[$type] = $value;
    }

    $items[$delta] = $values;
  }

  return $items;
}
