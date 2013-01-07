<?php

/**
 * Implements hook_drush_init().
 */
function dosomething_general_drush_init() {
  // Make sure drush commands are considered background tasks by New Relic
  if (function_exists('newrelic_background_job')) {
    newrelic_background_job(TRUE);
  }
}

/**
 * Implements hook_drush_command().
 */
function dosomething_general_drush_command() {
  $commands = array();

  $commands['dosomething-export-images'] = array(
    'description' => "Export images submitted via campaign report backs into a downloadable archive.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('dsei'),
  );

  return $commands;
}

function drush_dosomething_general_dosomething_export_images() {
  $forms = node_load_multiple(array(), array('type' => 'campaign_report_back'));
  $base_path = 'imgdump';
  $tmpdir = file_directory_temp() . DIRECTORY_SEPARATOR . $base_path;
  // Ensure we start clean.
  if (file_exists($tmpdir)) {
    file_unmanaged_delete_recursive($tmpdir);
  }
  drupal_mkdir($tmpdir, NULL, TRUE);

  $operations = array();
  foreach ($forms as $nid => $form) {
    $form = array_shift($forms);
    $operations[] = array('_drush_dosomething_general_export_images_batch_callback', array($form->nid, $tmpdir));
  }

  batch_set(array('operations' => $operations));
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();

  if (file_exists(file_directory_temp() . DIRECTORY_SEPARATOR . "$base_path.tar")) {
    file_unmanaged_delete(file_directory_temp() . DIRECTORY_SEPARATOR . "$base_path.tar");
  }

  $descriptor_spec = array(
    1 => array('pipe', 'w'),
    2 => array('pipe', 'w'),
  );

  $command = "tar -cf $base_path.tar $base_path";

  $process = proc_open($command, $descriptor_spec, $pipes, file_directory_temp(), $env);
  if (is_resource($process)) {
    $stdout = stream_get_contents($pipes[1]);
    fclose($pipes[1]);
    $stderr = stream_get_contents($pipes[2]);
    fclose($pipes[2]);

    $return_code = proc_close($process);

    if ($return_code) {
      $vars = array(
        '%command' => $command,
        '%code' => $return_code,
        '%stdout' => $stdout,
        '%stderr' => $stderr,
      );
      $text = "Invocation of '%command' exited with return code %code, emitting stdout:\n%stdout\n\nand stderr:\n%stderr";
      watchdog('ds_general', $vars, WATCHDOG_ERROR);
      throw new Exception(strtr($text, array_slice($vars, 0, 2)), E_ERROR);
    }
  }

  file_unmanaged_delete_recursive($tmpdir);
}

function _drush_dosomething_general_export_images_batch_callback($nid, $tmpdir) {
  ctools_include('webform.submissions', 'webform');

  $webform = node_load($nid);
  $tmpdir .= DIRECTORY_SEPARATOR . $nid . '-' . strtr("$webform->title", array(' ' => '.'));
  drupal_mkdir($tmpdir, NULL, TRUE);

  $submissions = webform_get_submissions($nid);
  foreach ($submissions as $submission) {
    if (empty($submission->field_webform_pictures)) {
      continue;
    }

    foreach ($submission->field_webform_pictures[LANGUAGE_NONE] as $field_contents) {
      file_unmanaged_copy($field_contents['uri'], $tmpdir . DIRECTORY_SEPARATOR . $field_contents['filename']);
    }
  }
}
