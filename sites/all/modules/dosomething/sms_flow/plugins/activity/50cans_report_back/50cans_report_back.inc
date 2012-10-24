<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('50 Cans Report Back'),
    'description' => t('Final step in 50 Cans report back. Accepts final input and processes webform.'),
    'handler' => array(
      'class' => 'ConductorActivity50CansReportBack',
    ),
  );
}
