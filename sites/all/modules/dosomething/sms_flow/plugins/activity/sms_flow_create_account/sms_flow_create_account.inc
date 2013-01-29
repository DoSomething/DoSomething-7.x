<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Create Account'),
    'description' => t('Take phone number, first name, and optionally email to create an account for this user. If account with email is found, then update account with phone number.'),
    'handler' => array(
      'class' => 'ConductorActivitySmsFlowCreateAccount',
    ),
  );
}
