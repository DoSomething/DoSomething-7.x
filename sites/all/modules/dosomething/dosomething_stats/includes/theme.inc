<?php

/**
 * @file
 * @todo.
 */

/**
 * @todo.
 */
function template_preprocess_dosomething_stats_counter(&$variables) {
  // Compute the longest number.
  $max_count = 1;
  foreach ($variables['items'] as $key => $item) {
    $count = strlen($item['value']);
    if ($count > $max_count) {
      $max_count = $count;
    }
  }
  $variables['max_count'] = $max_count;
  $variables['element'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'vital-stats',
      ),
    ),
  );

  $variables['element']['counter'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'counter',
      ),
    ),
  );
}

/**
 * @todo.
 */
function theme_dosomething_stats_counter($variables) {
  $items = $variables['items'];

  foreach ($items as $key => $item) {
    // Pad the numbers to be as long as the longest.
    $item['value'] = sprintf('% ' . $variables['max_count'] . 's', (int) $item['value']);
    $items[$key] = '<span class="counter-labels">' . $item['title'] . '</span>';
    $items[$key] .= '<span class="digits">' . $item['value'] . '</span>';
  }

  $variables['element']['counter']['list'] = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#type' => 'ul',
    '#title' => '',
  );

  return drupal_render($variables['element']);
}
