<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Create Drive'),
    'description' => t('Create drive at the school identified by the user.'),
    'handler' => array(
      'class' => 'ConductorActivityCreateDrive',
    ),
  );
}
