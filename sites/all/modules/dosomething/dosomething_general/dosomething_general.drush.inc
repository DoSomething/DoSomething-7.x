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
  $base_path = 'imgdump-' . time();
  // @todo hardcoding to /var/tmp is not great.
  $tmpdir =  '/var/tmp' . DIRECTORY_SEPARATOR . $base_path;
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

  $old_cwd = getcwd();
  chdir(file_directory_temp());
  `zip -r $base_path.zip $base_path`;
  chdir($old_cwd);

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
