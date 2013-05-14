<?php
/**
 * @file
 * Administration pages for the 'Flush page cache' module.
 */


/**
 * Form builder; Administration page for the 'Flush page cache' module.
 *
 * @ingroup forms
 */
function flush_page_cache_admin_settings($form, $form_state = NULL) {
  // Link settings
  $form['link'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link settings'),
  );
  $form['link']['flush_page_cache_footer_link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add flush page cache link to footer'),
    '#default_value' => variable_get('flush_page_cache_footer_link', (module_exists('admin_menu')) ? '0' : '1'),
  );

  // Custom settings
  $form['flush_page_cache_custom'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Custom settings'),
    '#description' => t('Enter custom cache objects to be purged when a page\'s cache is flushed, using the <a href="@href">cache_clear_all()</a> function.', array('@href' => 'http://api.drupal.org/api/drupal/includes!cache.inc/function/cache_clear_all/6')) .
      '<ul>' .
        '<li>' . t("<b>Path</b>: The path on which this cache entry should be cleared. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')) . '</li>' .
        '<li>' . t('<b>Cache ID ($cid)</b>: The cache ID to delete. If left blank, all cache entries that can expire are deleted.') . '</li>' .
        '<li>' . t('<b>Table ($table)</b>: The table $table to delete from.') . '</li>' .
        '<li>' . t('<b>Wildcard ($wildcard)</b>: If $wildcard is TRUE, cache IDs starting with $cid are deleted in addition to the exact cache ID specified by $cid. If $wildcard is TRUE and $cid is \'*\' then the entire table $table is emptied.') . '</li>' .
      '</ul>',
  );

  // Build custom settings from post back or variables.
  if (!empty($form_state['input']['flush_page_cache_custom'])) {
    $custom = flush_page_cache_custom_build($form_state['input']);
  }
  else {
    $custom = variable_get('flush_page_cache_custom', array(array('*', 'variables', 'cache', FALSE)));
  }

  $form['flush_page_cache_custom']['settings_table'] = array(
    '#theme' => 'flush_page_cache_custom_settings_table',
    '#prefix' => '<div id="flush-page-cache-custom-settings-table">',
    '#suffix' => '</div>',
  );

  $delta = 0;
  foreach ($custom as $item) {
    $form['flush_page_cache_custom']['settings_table'][$delta] = flush_page_cache_custom_settings_row($delta, $item[0],   $item[1], $item[2], $item[3]);
    $delta++;
  }

  // Add placeholder rows
  if (isset($form_state['input']['flush_page_cache_custom']['settings_table'])) {
    $number_of_empty_rows = count($form_state['input']['flush_page_cache_custom']['settings_table']) - count($custom);
    if (isset($form_state['clicked_button']['#value']) && $form_state['clicked_button']['#value'] == t('Add rows')) {
      $number_of_empty_rows += 3; // Add 3 new rows.
    }
    elseif ($number_of_empty_rows != 1) {
      $number_of_empty_rows -= 1; // Minus 1 from remove request.
    }
  }
  else {
    $number_of_empty_rows = 3; // Alway include 3 new rows.
  }
  for ($index = 0; $index < $number_of_empty_rows; $index++) {
    $form['flush_page_cache_custom']['settings_table'][$delta] = flush_page_cache_custom_settings_row($delta);
    $delta++;
  }

  $form['flush_page_cache_custom']['add'] = array(
    '#type' => 'button',
    '#value' => t('Add rows'),
    '#ajax' => array(
      'callback' => 'flush_page_cache_custom_settings_table_callback',
      'wrapper' => 'flush-page-cache-custom-settings-table',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['buttons']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Form submission handler; For flush page cache admin settings
 */
function flush_page_cache_admin_settings_submit($form, &$form_state) {
  // Footer link
  variable_set('flush_page_cache_footer_link', $form_state['input']['flush_page_cache_footer_link']);

  // Custom
  $flush_page_cache_settings = flush_page_cache_custom_build($form_state['input']);
  variable_set('flush_page_cache_custom', $flush_page_cache_settings);

  // Display message
  drupal_set_message(t('The configuration options have been saved.'));

  // DEBUG:
  // dpm($flush_page_cache_settings);
}

/**
 * AJAX callback for custom settings table.
 *
 * - AJAX Forms in Drupal 7
 *   http://drupal.org/node/752056
 */
function flush_page_cache_custom_settings_table_callback($form, $form_state) {
  return $form['flush_page_cache_custom']['settings_table'];
}


////////////////////////////////////////////////////////////////////////////////
// Admin settings form functions.
////////////////////////////////////////////////////////////////////////////////

/**
 * Build flush page cache custom settings row form elements.
 */
function flush_page_cache_custom_settings_row($delta, $path = '', $cid = '', $table = '', $wildcard = FALSE) {
  static $table_options;
  if (empty($table_options)) {
    $cache_tables = array_merge(array('', 'cache', 'cache_block', 'cache_filter', 'cache_page'), module_invoke_all('flush_caches'));
    asort($cache_tables);
    $table_options = array_combine($cache_tables, $cache_tables);
  }

  $form['path'] = array(
    '#type' => 'textfield',
    '#value' => $path,
    '#size' => 20,
  );
  $form['cid'] = array(
    '#type' => 'textfield',
    '#value' => $cid,
    '#size' => 20,
  );
  $form['table'] = array(
    '#type' => 'select',
    '#value' => $table,
    '#options' => $table_options,
  );
  $form['wildcard'] = array(
    '#title' => t('TRUE'),
    '#type' => 'checkbox',
    '#value' => $wildcard,
  );
  $form['operations'] = array(
    '#name' => 'remove_' . $delta,
    '#type' => 'button',
    '#value' => t('Remove'),
    '#ajax' => array(
      'callback' => 'flush_page_cache_custom_settings_table_callback',
      'wrapper' => 'flush-page-cache-custom-settings-table',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  return $form;
}

/**
 * Build flush page cache custom array from form values.
 */
function flush_page_cache_custom_build($values) {
  $custom = array();
  foreach ($values['flush_page_cache_custom']['settings_table'] as $delta => $item) {
    if ((isset($values['_triggering_element_name']) && $values['_triggering_element_name'] == 'remove_' . $delta) || empty($item['table'])) {
      continue;
    }

    $custom[] = array(
      (empty($item['path'])) ? '*' : trim($item['path'], '/'),
      (empty($item['cid'])) ? NULL : $item['cid'],
      $item['table'],
      (empty($item['wildcard'])) ? FALSE : TRUE,
    );
  }

  // DEBUG:
  // dpm($values); dpm($custom);

  return $custom;
}


////////////////////////////////////////////////////////////////////////////////
// Theme functions
////////////////////////////////////////////////////////////////////////////////

/**
 * Theme flush page cache custom settings table.
 */
function theme_flush_page_cache_custom_settings_table($variables) {
  $form = $variables['form'];
  $rows = array();
  foreach (element_children($form) as $key) {
    $rows[$key] = array(
      'data' => array(
        drupal_render($form[$key]['path']),
        drupal_render($form[$key]['cid']),
        drupal_render($form[$key]['table']),
        drupal_render($form[$key]['wildcard']),
        drupal_render($form[$key]['operations']),
      ),
    );
  }

  $headers = array(
    t('Path'),
    t('Cache ID'),
    t('Table'),
    t('Wildcard'),
    t('Operations'),
  );

  return theme('table', array('header' => $headers, 'rows' => $rows));
}
