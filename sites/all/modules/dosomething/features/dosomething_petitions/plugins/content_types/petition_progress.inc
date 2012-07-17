<?php

function dosomething_petitions_petition_progress_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Petition Progress'),
    'description' => t('Petition progress bar towards total signatures.'),
    'category' => t('DoSomething'),
  );
}

function dosomething_petitions_petition_progress_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = menu_get_object();
  $submission_count = webform_get_submission_count($node->nid);
  $goal = $node->field_petition_goal[LANGUAGE_NONE][0]['value'];
  $percent = round($submission_count / $goal * 100, 4);
  if ($percent > 100) $percent = 100;

  $content = array(
    'label-wrapper' => array(
      '#type' => 'container',
      '#attributes' => array('id' => 'signatures-text'),
      'signatures' => array(
        '#type' => 'container',
        '#attributes' => array('id' => 'signatures-label'),
        'markup' => array(
          '#markup' => 'Signatures',
        ),
      ),
      'counter' => array(
        '#type' => 'container',
        '#attributes' => array('id' => 'signatures-count'),
        'markup' => array(
          '#markup' => number_format($submission_count) . ' of ' . number_format($goal),
        ),
      ),
    ),
    'progress-bar' => array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'progress-bar-wrapper',
        'style' => 'width: 100%',
      ),
      'progress-bar-progress' => array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'progress-bar',
          'style' => "width: $percent%",
        ),
      ),
    ),
  );

  $block = new StdClass();
  $block->content = $content;
  return $block;
}

function dosomething_petitions_petition_progress_content_type_admin_title($subtype, $conf, $context) {
  return t('Petition Progress');
}

