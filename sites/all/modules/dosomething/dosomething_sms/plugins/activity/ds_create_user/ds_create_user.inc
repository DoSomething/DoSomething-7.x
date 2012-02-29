<?php

$plugin = array(
  'title' => t('DoSomething create user'),
  'description' => t('This creates a user object from sms context.'),
  'handler' => array(
    'class' => 'ConductorActivityDSCreateUser',
  ),
);
