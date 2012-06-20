<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Invite to a team'),
    'description' => t('Invite users to a team by email or cell.'),
    'handler' => array(
      'class' => 'ConductorActivityTeamsInvite',
    ),
  );
}
