<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('DoSomething GAS 2012 Report Back'),
    'description' => t('Submits report back webform for GAS 2012'),
    'handler' => array(
      'class' => 'ConductorActivityGAS2012ReportBack',
    ),
  );
}