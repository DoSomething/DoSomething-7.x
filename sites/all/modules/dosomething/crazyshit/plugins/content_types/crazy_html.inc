<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Crazy #@%# HTML'),
  'description' => t('Drops static HTML from Crazy #@#%'),
  'category' => t('DoSomething Campaign'),
);

/**
 * Grab the static HTML file and return it.
 */
function crazyshit_crazy_html_content_type_render($subtype, $conf, $panel_args, $context) {
  $f = '';
  if (empty($conf['html_source'])) {
    $f = basename(request_uri()) . '.html';
  }
  else {
    $f = $conf['html_source'];
  }

  $dir = drupal_get_path('module', 'crazyshit') . '/html';
  $file = $dir . '/' . $f;

  if (!file_exists($file)) {
    watchdog('dosomething', 'Campaign static HTML grabber attempted to grab the nonexistent html file @file', array('@file' => $file));
    return '';
  }

  $block = new stdClass();
  $block->title = 'Static campaign HTML';
  $block-> content = file_get_contents($file);
  return $block;
}

/**
 * Returns an edit form where the HTML file to inject is selected.
 */
function crazyshit_crazy_html_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  $conf = $form_state['conf'];

  $dir = drupal_get_path('module', 'crazyshit') . '/html';

  $found = file_scan_directory($dir, '/.*\.html$/', array(), 2);
  // this gets us all html files, not only those in a subdir, as the mask in
  // file_scan_directory doesn't check the full uri path.
  $files = array(
    0 => t('(Detect automatically)'),
  );
  foreach ($found as $file) {
    if (preg_match('/.*html\\' . DIRECTORY_SEPARATOR . '.*html$/', $file->uri)) {
      $path = substr($file->uri, strlen($dir) + 1);
      $files[$path] = basename($path);
    }
  }

  $form['html_source'] = array(
    '#type' => 'select',
    '#title' => t('HTML source file'),
    '#default_value' => !empty($conf['html_source']) ? $conf['html_source'] : '',
    '#options' => $files,
  );

  return $form;
}

function crazyshit_crazy_html_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['html_source'] = $form_state['values']['html_source'];
}

/**
 * Returns the administrative title for a type.
 */
function crazyshit_crazy_html_content_type_admin_title($subtype, $conf, $context) {
  $parts = reset(explode(DIRECTORY_SEPARATOR, $conf['html_source']));
  if (empty($parts)) {
    $parts = t('(Detected automatically)');
  }

  return "Static Campaign HTML: $parts";
}
