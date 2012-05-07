<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('DoSomething Epic 2012 Report Back'),
    'description' => t('This creates a new report back webform submission for Epic Book Drive 2012.'),
    'handler' => array(
      'class' => 'ConductorActivityDSCreateEpic2012ReportBack',
    ),
  );
}
