<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Receive School Name'),
    'description' => t('Receive and processstate and school name from user. Part 2 of 3 in the school-ask flow.'),
    'handler' => array(
      'class' => 'ConductorActivityDSReceiveSchoolName',
    ),
  );
}
