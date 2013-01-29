<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Follow Up Survey response -- question #2'),
    'description' => t('Process response from betas that are invited to a drive'),
    'handler' => array(
      'class' => 'ConductorActivityClubsFollowUpSurveyResponseSecond',
    ),
  );
}
