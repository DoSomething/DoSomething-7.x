<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Submit External Report Back from SMS'),
    'description' => t('Takes data received during workflow and submits it to an external service.'),
    'handler' => array(
      'class' => 'ConductorActivitySubmitExternalReportBack',
    ),
  );
}
