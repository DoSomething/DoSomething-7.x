<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Receive School ID'),
    'description' => t('Receive, process, and respond to the school ID or NOID. Part 3 of 3 in the school-ask flow.'),
    'handler' => array(
      'class' => 'ConductorActivityDSReceiveSchoolID',
    ),
  );
}
