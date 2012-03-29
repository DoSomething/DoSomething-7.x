<?php

$plugin = array(
  'title' => t('Featured Project Switcher'),
  'single' => TRUE,
  'content_types' => array('dosomething_project_switcher'),
  'render callback' => 'dosomething_project_switcher_content_type_render',
  'category' => t('DoSomething'),
);

function dosomething_project_switcher_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $element = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'featured-project-switcher',
      ),
    ),
  );
  $element['form'] = drupal_get_form('dosomething_featured_project_switcher_form');
  $block->content = $element;
  return $block;
}

function dosomething_featured_project_switcher_form() {
  $options = array(
    'all' => t('All Featured Projects'),
    'grant-winners' => t('Grant Winners'),
    'scholarship-winners' => t('Scholarship Winners'),
    'pod' => t('Featured Projects of the Day'),
    'club' => t('Club Projects'),
  );
  $default = 'all';
  if (isset($options[arg(2)])) {
    $default = arg(2);
  }
  $form['select'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $default,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('GO'),
  );
  return $form;
}

function dosomething_featured_project_switcher_form_submit($form, $form_state) {
  $value = $form_state['values']['select'];
  if ($value == 'all') {
    $value = '';
  }
  drupal_goto('projects/featured-projects/' . $value);
}

