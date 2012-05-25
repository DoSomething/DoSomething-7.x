<?php

function _webform_defaults_quiz_question() {
  return array(
    'name' => '', 
    'form_key' => NULL,
    'pid' => 0,
    'weight' => 0,
    'value' => '', 
    'mandatory' => 0,
    'extra' => array(
      'title_display' => 0,
      'disabled' => 0,
      'attributes' => array(),
      'private' => FALSE,
      'quiz_question' => '',
      'quiz_multiplier' => 1,
    ),  
  );  
}

function _webform_edit_quiz_question($component) {
  $node = node_load($component['nid']);
  $form = array();

  $form['quiz']['question'] = array(
    '#type' => 'textarea',
    '#title' => t('Quiz questions'),
    '#description' => t('Question to display.') . ' ' . t('The label above will not be displayed. It is for your organizational use only.'),
    '#default_value' => $component['extra']['quiz_question'],
    '#parents' => array('extra', 'quiz_question'),
  );
  $form['quiz']['multiplier'] = array(
    '#type' => 'textfield',
    '#title' => t('Multiplier'),
    '#description' => t('The response value of this field will be multiplied by this number when calculating quiz results.'),
    '#default_value' => $component['extra']['quiz_multiplier'],
    '#size' => 3,
    '#maxlength' => 3,
    '#parents' => array('extra', 'quiz_multiplier'),
  );
  return $form;
}

function _webform_render_quiz_question($component, $value = NULL, $filter = TRUE) {
  $form_item = array(
    '#type' => 'select',
    '#options' => array(
      'yes' => 'Yes',
      'no' => 'No',
    ),
    '#title' => $fliter ? _webform_filter_xss($component['extra']['quiz_question']) : $component['extra']['quiz_question'],
    '#required' => $component['mandatory'],
    '#weight' => $component['weight'],
    '#default_value' => $filter ? _webform_filter_values($component['value']) : $component['value'],
    '#prefix' => '<div class="webform-component-quiz-question" id="webform-component-' . $component['form_key'] . '">',
    '#suffix' => '</div>',
  );

  if (isset($value)) {
    $form_item['#default_value'] = $value[0];
  }

  return $form_item;
}
