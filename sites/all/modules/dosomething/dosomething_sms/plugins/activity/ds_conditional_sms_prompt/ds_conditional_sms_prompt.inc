<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Conditional SMS Prompt'),
    'description' => t('Similar to normal sms_prompt activity, but can set conditions for whether to execute or not.'),
    'handler' => array(
      'class' => 'ConductorActivityConditionalSMSPrompt',
    ),
  );

}