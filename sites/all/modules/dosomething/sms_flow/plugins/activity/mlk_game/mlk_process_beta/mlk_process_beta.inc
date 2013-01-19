<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('MLK Game Process Beta'),
    'description' => t('Handle invited betas who\'ve responded to an alpha\'s invite for MLK game'),
    'handler' => array(
      'class' => 'ConductorActivityMLKProcessBeta',
    ),
  );
}
