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
      'multiple' => 0,
      'randomize' => 0,
    ),  
  );  
}

function _webform_edit_quiz_question($component) {
  $node = node_load($component['nid']);
  $nid = $node->nid;

  if (!isset($node->webform['quiz_redirects'])) {
    drupal_set_message(t('This webform does not have any configured URL redirects for quiz fields. Please !configure before attempting to add a quiz question.', array('!configure' => l(t('configure the webform'), "node/$nid/webform/configure"))), 'error');
    drupal_goto($_SERVER['HTTP_REFERER']);
    return;
  }

  $form = array();

  $form['quiz']['question'] = array(
    '#type' => 'textarea',
    '#title' => t('Quiz questions'),
    '#description' => t('Question to display.') . ' ' . t('The label above will not be displayed. It is for your organizational use only.'),
    '#default_value' => $component['extra']['quiz_question'],
    '#parents' => array('extra', 'quiz_question'),
  );

  $form['display']['multiple'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow multiple select'),
    '#description' => t('Checking this box will switch to using checkboxes instead of radios.'),
    '#default_value' => $component['extra']['multiple'],
    '#parents' => array('extra', 'multiple'),
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

  $form['display']['randomize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Randomize options'),
    '#description' => t('Randomize the display of the responses to the question. This will not affect outcome.'),
    '#default_value' => $component['extra']['randomize'],
    '#parents' => array('extra', 'randomize'),
  );

  foreach ($node->webform['quiz_redirects'] as $i => $redirect) {
    $form['quiz']['responses'][$i] = array(
      '#type' => 'textfield',
      '#title' => t('Response to redirect to: !url', array('!url' => l($redirect, $redirect))),
      '#default_value' => $component['extra']['responses'][$i],
      '#parents' => array('extra', 'responses', $i),
    );
  }
  return $form;
}

function _webform_render_quiz_question($component, $value = NULL, $filter = TRUE) {
  if ($component['extra']['randomize']) {
    $keys = array_keys($component['extra']['responses']);
    shuffle($keys);
    $return = array();
    foreach ($keys as $key) {
      $return[$key] = $component['extra']['responses'][$key];
    }
    $component['extra']['responses'] = $return;
  }

  $form_item = array(
    '#type' => ($component['extra']['multiple']) ? 'checkboxes' : 'radios',
    '#options' => $component['extra']['responses'],
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
