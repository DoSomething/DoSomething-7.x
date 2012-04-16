<?php

$plugin = array(
  'title' => t('Start a _____ buttons'),
  'single' => TRUE,
  'content_types' => array('dosomething_start_button'),
  'render callback' => 'dosomething_start_button_content_type_render',
  'defaults' => array(
    'start_button' => array(
      'project' => TRUE,
    ),
  ),
  'edit form' => 'dosomething_start_button_content_type_edit_form',
  'category' => t('DoSomething'),
);

function dosomething_start_button_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $element = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'start-a-project',
      ),
    ),
  );
  if (!empty($conf['start_button']['project'])) {
    $element['project'] = array(
      '#type' => 'link',
      '#title' => t('Go'),
      '#href' => 'start-something/projects',
      '#options' => array(
        'attributes' => array(
          'title' => t('Go'),
          'class' => array(
            'go-button',
          ),
        ),
      ),
    );
  }
  if (!empty($conf['start_button']['club'])) {
    $element['club'] = array(
      '#type' => 'link',
      '#title' => t('Start a Club'),
      '#href' => 'node/add/club',
      '#options' => array(
        'attributes' => array(
          'title' => t('Start a Club'),
          'class' => array(
            'ds-button-strong',
          ),
        ),
      ),
    );
  }
  $block->content = $element;
  return $block;
}

function dosomething_start_button_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['start_button'] = array(
    '#title' => t('Buttons'),
    '#type' => 'select',
    '#multiple' => TRUE,
    '#options' => array(
      'project' => t('Project'),
      'club' => t('Club'),
    ),
    '#default_value' => !empty($conf['start_button']) ? $conf['start_button'] : array(),
  );

  return $form;
}

function dosomething_start_button_content_type_edit_form_submit(&$form, &$form_state) {
  foreach ($form_state['values']['start_button'] as $button) {
    $form_state['conf']['start_button'][$button] = TRUE;
  }
}
