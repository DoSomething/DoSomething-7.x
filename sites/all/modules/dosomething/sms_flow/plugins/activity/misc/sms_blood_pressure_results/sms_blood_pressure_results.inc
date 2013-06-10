<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Blood Pressure Results'),
    'description' => t('Given the systolic and diastolic values, sends response back with what their numbers mean.'),
    'handler' => array(
      'class' => 'ConductorActivitySmsBloodPressureResults',
    ),
  );
}
