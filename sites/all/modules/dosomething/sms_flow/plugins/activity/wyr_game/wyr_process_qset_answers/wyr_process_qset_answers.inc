<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Would You Rather Process QSet Answers'),
    'description' => t('Process QSet answers and send any responses to user.'),
    'handler' => array(
      'class' => 'ConductorActivityWYRProcessQSetAnswers',
    ),
  );
}
