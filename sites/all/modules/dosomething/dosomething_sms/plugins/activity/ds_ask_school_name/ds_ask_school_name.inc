<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Ask for School Name'),
    'description' => t('Ask user for state and school name. Part 1 of 3 in the school-ask flow.'),
    'handler' => array(
      'class' => 'ConductorActivityDSAskSchoolName',
    ),
  );
}
