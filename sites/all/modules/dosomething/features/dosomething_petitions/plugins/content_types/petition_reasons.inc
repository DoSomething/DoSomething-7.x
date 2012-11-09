<?php

function dosomething_petitions_petition_reasons_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Petition Reasons'),
    'description' => t('Reasons people have submitted this petition.'),
    'category' => t('DoSomething'),
  );
}

function dosomething_petitions_petition_reasons_content_type_render($subtype, $conf, $panel_args, $context) {
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $node = menu_get_object();

  // Get petition submissions that have a reason and who have checked the public checkbox
  $q = new EntityFieldQuery;
  $result = $q
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->propertyCondition('nid', $node->nid)
    ->propertyOrderBy('submitted', 'DESC')
    ->fieldCondition('field_webform_petition_reason', 'value', 'NULL', '!=')
    ->fieldCondition('field_webform_petition_signature', 'value', 1, '=')
    ->range(0, 5)
    ->execute();

  $signatures = array();
  $submissions = entity_load('webform_submission_entity', array_keys($result['webform_submission_entity']));
  foreach($submissions as $submission) {
    $name = dosomething_general_get_full_name(user_load($submission->uid));
    if (!$name) {
      $name = $submission->field_webform_first_name[LANGUAGE_NONE][0]['value'] . ' ' . $submission->field_webform_last_name[LANGUAGE_NONE][0]['value'][0];
    }
    if ($name == ' ') {
      $name = 'Anonymous';
    }

    $time = format_interval((time() - $submission->submitted), 2) . t(' ago');
    $comment = $submission->field_webform_petition_reason[LANGUAGE_NONE][0]['value'];
    $signatures[] = array(
      'name' => $name,
      'time' => $time,
      'comment' => $comment,
    );
  }

  $signatures = array_reverse($signatures);

  $content = array();
  foreach ($signatures as $sig) {
    $content[] = array(
      '#markup' => "<h2>{$sig['name']}</h2><p>{$sig['time']}</p><p>{$sig['comment']}</p>",
    );
  }

  if (empty($content)) {
    $content[] = array(
      '#markup' => "<h2>No one has added a comment yet. Add your reason above!</h2>",
    );
  }

  $block = new StdClass();
  $block->title = 'Reasons for Signing';
  $block->content = $content;
  return $block;
}

function dosomething_petitions_petition_reasons_content_type_admin_title($subtype, $conf, $context) {
  return t('Petition Reasons');
}

