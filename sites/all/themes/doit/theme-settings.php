<?php

function doit_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['neue'] = array(
    '#type' => 'fieldset',
    '#title' => t('Neue Library Settings'),
  );
  $form['neue']['doit_homepage_neue'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Neue library on home page'),
    '#default_value' => theme_get_setting('doit_homepage_neue'),
  );
}