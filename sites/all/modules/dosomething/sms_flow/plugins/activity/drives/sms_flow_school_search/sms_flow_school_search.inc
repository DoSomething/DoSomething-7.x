<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('School Search'),
    'description' => t('Given school level, state, and school name query, returns list of matching schools'),
    'handler' => array(
      'class' => 'ConductorActivitySmsSchoolSearch',
    ),
  );
}
