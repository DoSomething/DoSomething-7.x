<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Join User to Drive'),
    'description' => t('Join user to drive active at their school.'),
    'handler' => array(
      'class' => 'ConductorActivityJoinUserToDrive',
    ),
  );
}
