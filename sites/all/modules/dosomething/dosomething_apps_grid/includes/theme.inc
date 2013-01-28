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
  $rows = $variables['rows'];

  $row_count = count($rows) - 1;
  $count = 0;
  $order = array_flip(array('banner', 'image', 'title', 'text', 'footer', 'link'));
  foreach ($rows as $delta => $row) {
    $element = array();
    foreach ($options['fields'] as $type => $field_name) {
      // If the selected field is not in the results, return.
      if (empty($view->field[$field_name])) {
        continue;
      }

      $field = $view->style_plugin->get_field($delta, $field_name);
      // If the field is empty, return.
      if (empty($field)) {
        continue;
      }

      // If the results are a string, create a render array.
      if (!is_array($field)) {
        $field = array('#markup' => $field);
      }

      // Respect the field element and class settings.
      $element_type = $view->field[$field_name]->element_type();
      $element_class = $view->field[$field_name]->element_classes($delta);
      $field['#prefix'] = '<' . $element_type . ' class="apps-' . $type;
      if ($element_class) {
        $field['#prefix'] .= ' ' . $element_class;
      }
      $field['#prefix'] .= '">';
      $field['#suffix'] = '</' . $element_type . '>';

      // Add the rendered fields for everything except links.
      if ($type != 'link') {
        $element[$type] = $field;
      }
      // Add the link with the text 'Go'.
      else {
        // The URL might have been prepared for HTML rendering, parse it.
        $markup = str_replace('&amp;', '&', $field['#markup']);

        // Remove leading forward slash if present
        $markup = ltrim($markup, '/');

        $url_options = drupal_parse_url($markup);
      
        $element['link'] = array(
          '#prefix' => $field['#prefix'],
          '#suffix' => $field['#suffix'],
          '#type' => 'link',
          '#href' => $url_options['path'],
          '#title' => t('Go'),
          '#options' => $url_options + array(
            'attributes' => array(
            ),
            'html' => FALSE,
            'absolute' => TRUE,
          ),
        );
      }
      // Ensure the elements are in the correct order.
      $element[$type]['#weight'] = $order[$type];
    }

    // Assign 'first' and 'last' classes.
    $last = $options['settings']['last_every_nth'];
    $classes = array('apps-box');
    if (($last && $count % $last == 0) || (!$last && $count == 0)) {
      $classes[] = 'first';
    }
    elseif (($last && ($count + 1) % $last == 0) || (!$last && $count == $row_count)) {
      $classes[] = 'last';
    }

    // Add the element.
    if (!empty($element)) {
      $elements[$delta] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => $classes,
        ),
      ) + $element;
    }
    $count++;
  }

  if (!empty($elements)) {
    $variables['element'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'apps-grid',
        ),
      ),
      '#attached' => array(
        'css' => array(
          ctools_attach_css('dosomething_apps_grid', 'dosomething_apps_grid'),
        ),
      ),
    );

    // If the view is grouped, give each group a title.
    if (!empty($variables['title'])) {
      $variables['element']['title'] = array(
        '#prefix' => '<h3 class="apps-title">',
        '#suffix' => '</h3>',
        '#markup' => $variables['title'],
      );
    }

    // Add in the elements.
    $variables['element'] += $elements;
  }
}

/**
 * Render the element.
 */
function theme_dosomething_apps_grid($variables) {
  return drupal_render($variables['element']);
}
