<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Report back.'),
    'description' => t('Tell us a challenge that you completed.'),
    'handler' => array(
      'class' => 'ConductorActivityTeamsReportBack',
    ),
  );
}
