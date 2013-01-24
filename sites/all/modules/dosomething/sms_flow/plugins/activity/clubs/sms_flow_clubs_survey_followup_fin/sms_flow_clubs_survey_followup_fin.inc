<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Follow up survey -- finished'),
    'description' => t('Process response from betas that are invited to a drive'),
    'handler' => array(
      'class' => 'ConductorActivityClubsFollowUpSurveyFin',
    ),
  );
}
