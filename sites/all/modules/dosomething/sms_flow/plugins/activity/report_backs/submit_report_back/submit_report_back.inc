<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Submit Report Back from SMS'),
    'description' => t('Takes data received during workflow and submits it to the specified webform.'),
    'handler' => array(
      'class' => 'ConductorActivitySubmitReportBack',
    ),
  );
}
