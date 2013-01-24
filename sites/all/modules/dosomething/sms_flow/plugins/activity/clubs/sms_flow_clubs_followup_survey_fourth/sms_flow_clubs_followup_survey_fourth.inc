<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Follow Up Survey response -- question #4'),
    'description' => t('Process response from betas that are invited to a drive'),
    'handler' => array(
      'class' => 'ConductorActivityClubsFollowUpSurveyResponseFourth',
    ),
  );
}
