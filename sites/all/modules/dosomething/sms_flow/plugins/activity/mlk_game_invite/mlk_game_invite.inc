<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('MLK Game Invite Friends'),
    'description' => t('Invite friends to the MLK game'),
    'handler' => array(
      'class' => 'ConductorActivityMLKGameInvite',
    ),
  );
}
