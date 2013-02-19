<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('TFJ Report Back'),
    'description' => t('Submit the report back for TFJ.'),
    'handler' => array(
      'class' => 'ConductorActivityTFJReportBack',
    ),
  );
}
