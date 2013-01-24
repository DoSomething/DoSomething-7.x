<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Check Drive Exists'),
    'description' => t('Check if drive exists at the school identified by the user.'),
    'handler' => array(
      'class' => 'ConductorActivityCheckDriveExists',
    ),
  );
}
