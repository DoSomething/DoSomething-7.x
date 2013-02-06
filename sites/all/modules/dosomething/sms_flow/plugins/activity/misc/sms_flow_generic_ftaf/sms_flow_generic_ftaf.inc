<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Generic Forward to a Friend'),
    'description' => t('Handler for accepting and processing numbers in a forward to a friend flow'),
    'handler' => array(
      'class' => 'ConductorActivitySmsFlowGenericFtaf',
    ),
  );
}
