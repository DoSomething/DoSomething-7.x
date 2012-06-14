<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('User Name Check'),
    'description' => t('Check if a user exists and has filled out their first name.'),
    'handler' => array(
      'class' => 'ConductorActivityTeamsCheckUser',
    ),
  );
}
