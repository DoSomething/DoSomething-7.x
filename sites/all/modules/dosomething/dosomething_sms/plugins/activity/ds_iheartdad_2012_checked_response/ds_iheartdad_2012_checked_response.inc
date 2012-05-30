<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('I <3 Dad CHECKED final response'),
    'description' => t('Process previous states to determine final response to CHECKED workflow.'),
    'handler' => array(
      'class' => 'ConductorActivityDSIHeartDadCheckedResponse',
    ),
  );
}