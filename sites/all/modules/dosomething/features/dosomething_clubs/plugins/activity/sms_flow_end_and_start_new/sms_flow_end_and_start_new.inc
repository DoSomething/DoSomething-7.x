<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('End and Start New Activity'),
    'description' => t('Ends current activity and immediately starts a new one'),
    'handler' => array(
      'class' => 'ConductorActivityEndAndStartNew',
    ),
  );
}
