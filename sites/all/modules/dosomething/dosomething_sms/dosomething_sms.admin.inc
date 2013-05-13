<?php
/**
 * @file
 * Admin page callback for the DoSomething SMS module.
 */

/**
 * Builds and returns the Optimizely Add/Update form.
 * If there are only 3 arguments in the path it builds the add form and it adds a record.
 * Otherwise it builds the update form where the fourth argument is the record ID in
 * in the optimizely table.
 */
function dosomething_sms_settings_form() {

  $form['configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration of cron_example_cron()'),
  );
  $form['configuration']['cron_example_interval'] = array(
    '#type' => 'select',
    '#title' => t('Cron interval'),
    '#description' => t('Time after which cron_example_cron will respond to a processing request.'),
    '#default_value' => variable_get('cron_example_interval', 60 * 60),
    '#options' => array(
      60 => t('1 minute'),
      300 => t('5 minutes'),
      3600 => t('1 hour'),
      60 * 60 * 24 => t('1 day'),
    ),
  );
  
    return $form;
  
}