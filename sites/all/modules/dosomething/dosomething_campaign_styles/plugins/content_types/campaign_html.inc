<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Static Campaign HTML'),
  'description' => t('Drops in static HTML pulled directly off the filesystem from within dosomething_campaign_styles.'),
  'category' => t('DoSomething Campaign'),
);

/**
 * Grab the static HTML file and return it.
 */
function dosomething_campaign_styles_campaign_html_content_type_render($subtype, $conf, $panel_args, $context) {
  $dir = drupal_get_path('module', 'dosomething_campaign_styles') . '/campaign_styles';
  $file = $dir . '/' . $conf['html_source'];
  if (!file_exists($file)) {
    watchdog('dosomething', 'Campaign static HTML grabber attempted to grab the nonexistent html file @file', array('@file' => $file));
    return '';
  }

  $block = new stdClass();
  $block->title = 'Static campaign HTML';
  $block-> content = get_include_contents($file);

  return $block;
}

/** Helper: Parses PHP in template files. */
function get_include_contents($filename) {
    if (is_file($filename)) {
        ob_start();
        include $filename;
        $contents = ob_get_contents();
        ob_end_clean();
        return $contents;
    }
    return false;
}

/**
 * Returns an edit form where the HTML file to inject is selected.
 */
function dosomething_campaign_styles_campaign_html_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  $conf = $form_state['conf'];

  $form['html_source'] = array(
    '#type' => 'textfield',
    '#title' => t('HTML source file'),
    '#default_value' => !empty($conf['html_source']) ? $conf['html_source'] : '',
    '#autocomplete_path' => 'campaign/style/autocomplete'
  );

  return $form;
}

function dosomething_campaign_styles_campaign_html_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['html_source'] = $form_state['values']['html_source'];
}

/**
 * Returns the administrative title for a type.
 */
function dosomething_campaign_styles_campaign_html_content_type_admin_title($subtype, $conf, $context) {
  $parts = explode(DIRECTORY_SEPARATOR, $conf['html_source']);
  $year = array_shift($parts);
  $campaign = array_shift($parts);
  $name = substr(array_pop($parts), 0, -5);
  return "Static Campaign HTML: $year/$campaign/$name";
}
