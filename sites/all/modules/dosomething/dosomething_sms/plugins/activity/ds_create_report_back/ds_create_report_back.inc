<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('DoSomething create project report'),
    'description' => t('This creates a new project report webform submission.'),
    'handler' => array(
      'class' => 'ConductorActivityDSCreateReportBack',
    ),
  );
}
