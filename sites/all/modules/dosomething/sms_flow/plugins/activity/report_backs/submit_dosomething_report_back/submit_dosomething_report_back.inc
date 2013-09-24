<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Submit a DoSomething.org Report Back from SMS'),
    'description' => t('Uses helper functions from the dosomething_reportback module to submit report backs forms.'),
    'handler' => array(
      'class' => 'ConductorActivitySubmitDoSomethingReportBack',
    ),
  );
}
