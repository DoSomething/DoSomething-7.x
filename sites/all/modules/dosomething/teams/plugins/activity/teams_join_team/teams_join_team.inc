<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Join a Team (or not)'),
    'description' => t('Join a team based on on the team leader\'s email or mobile number.'),
    'handler' => array(
      'class' => 'ConductorActivityTeamsJoinTeam',
    ),
  );
}
