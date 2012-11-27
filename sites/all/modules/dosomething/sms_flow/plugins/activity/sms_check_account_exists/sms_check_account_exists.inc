<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Check Account Exists'),
    'description' => t('Check if account exists for user\'s mobile number or not'),
    'handler' => array(
      'class' => 'ConductorActivityCheckAccountExists',
    ),
  );
}
