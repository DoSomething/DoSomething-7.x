<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Random Pathing'),
    'description' => t('Primarily for SMS game use. Users are sent to a random Mobile Commons opt-in path they have yet to be sent to.'),
    'handler' => array(
      'class' => 'ConductorActivityGameRandomPath',
    ),
  );
}
