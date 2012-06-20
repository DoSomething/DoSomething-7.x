<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Create a team'),
    'description' => t('Create a team.'),
    'handler' => array(
      'class' => 'ConductorActivityTeamsCreateTeam',
    ),
  );
}
