<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Survey response -- question #1'),
    'description' => t('Process response from betas that are invited to a drive'),
    'handler' => array(
      'class' => 'ConductorActivityClubsSurveyResponse',
    ),
  );
}
