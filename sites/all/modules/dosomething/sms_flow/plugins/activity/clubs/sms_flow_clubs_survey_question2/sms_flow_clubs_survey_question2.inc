<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Club leader second question response - Survey'),
    'description' => t('Process response from alphas -- question 2'),
    'handler' => array(
      'class' => 'ConductorActivityClubsSurveyNextResponse',
    ),
  );
}
