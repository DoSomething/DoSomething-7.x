<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('WYR QSet End'),
    'description' => t('Processes the end of a WYR question set.'),
    'handler' => array(
      'class' => 'ConductorActivityWYRQsetEnd',
    ),
  );
}
