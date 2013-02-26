<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Share A State Process MMS'),
    'description' => t('Determine if user sent an image in the last message and route to the next appropriate path.'),
    'handler' => array(
      'class' => 'ConductorActivityShareStatProcessMMS',
    ),
  );
}
