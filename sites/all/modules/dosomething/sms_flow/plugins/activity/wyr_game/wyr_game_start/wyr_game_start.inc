<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Would You Rather Game Start'),
    'description' => t('Selects random set of questions to send user to.'),
    'handler' => array(
      'class' => 'ConductorActivityWYRGameStart',
    ),
  );
}
