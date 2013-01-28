<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Invited Betas - Drives'),
    'description' => t('Handle betas that are invited to a drive'),
    'handler' => array(
      'class' => 'ConductorActivityClubsInvitedBeta',
    ),
  );
}
