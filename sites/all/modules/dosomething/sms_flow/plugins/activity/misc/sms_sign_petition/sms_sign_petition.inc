<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('SMS Sign Petition'),
    'description' => t('Handles the user creation/retrieval and webform submission creation to sign a petition from SMS.'),
    'handler' => array(
      'class' => 'ConductorActivitySmsSignPetition',
    ),
  );
}
