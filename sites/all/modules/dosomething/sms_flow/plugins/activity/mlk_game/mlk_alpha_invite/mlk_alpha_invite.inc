<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('MLK Alpha Invite'),
    'description' => t('Path to trigger for going through MLK game. Accepts friends\' numbers and opts Alphas and Betas into their appropriate paths.'),
    'handler' => array(
      'class' => 'ConductorActivityMLKAlphaInvite',
    ),
  );
}
