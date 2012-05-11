<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Get School ID'),
    'description' => t('Get the school ID from the user\'s mCommons profile.'),
    'handler' => array(
      'class' => 'ConductorActivityDSGetSchoolID',
    ),
  );
}

