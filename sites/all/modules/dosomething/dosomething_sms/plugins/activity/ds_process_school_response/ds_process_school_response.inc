<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Process final school response'),
    'description' => t('Based on school search results and user\'s response, continue or go back to a previous state'),
    'handler' => array(
      'class' => 'ConductorActivityDSProcessSchoolResponse',
    ),
  );
}
