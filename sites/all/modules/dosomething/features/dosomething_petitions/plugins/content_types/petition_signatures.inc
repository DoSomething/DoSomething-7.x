<?php

function dosomething_petitions_petition_signatures_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Petition Signatures'),
    'description' => t('Petition signatures.'),
    'category' => t('DoSomething'),
  );
}

function dosomething_petitions_petition_signatures_content_type_render($subtype, $conf, $panel_args, $context) {
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $node = menu_get_object();

  // load up signatures for people who have checked the signature box
  $q = new EntityFieldQuery;
  $result = $q
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->propertyCondition('nid', $node->nid)
    ->propertyOrderBy('submitted', 'DESC')
    ->fieldCondition('field_webform_petition_signature', 'value', 1, '=')
    ->execute();

  $result = $result['webform_submission_entity'];

  // load up signatures until we have 5 or we run out
  while (count($signatures) < 5 && count($result) != 0) {
    $submission = array_shift(entity_load('webform_submission_entity', array(array_shift($result)->sid)));
    $name = dosomething_general_get_full_name(user_load($submission->uid));
    
    if (!$name) {
      $name = $submission->field_webform_first_name[LANGUAGE_NONE][0]['value'] . ' ' . $submission->field_webform_last_name[LANGUAGE_NONE][0]['value'][0];
    }
    if ($name == ' ') {
      $name = 'Anonymous';
    }
    $time = format_interval((time() - $submission->submitted), 1) . t(' ago');
    $signatures[] = array(
      'name' => $name,
      'time' => $time,
    );
  }

  $content = array();
  foreach ($signatures as $sig) {
    $content[] = array(
      '#markup' => "<h2>{$sig['name']}</h2><p>{$sig['time']}</p>",
    );
  }

  $block = new StdClass();
  $block->title = 'Recent Signatures';
  $block->content = $content;
  return $block;
}

function dosomething_petitions_petition_signatures_content_type_admin_title($subtype, $conf, $context) {
  return t('Petition Signatures');
}

