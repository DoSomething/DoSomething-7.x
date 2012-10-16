<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Invited Beta Response - Drives'),
    'description' => t('Process response from betas that are invited to a drive'),
    'handler' => array(
      'class' => 'ConductorActivityDriveInviteResponse',
    ),
  );
}
