<?php

$plugin = array(
  'title' => t('Stats Counter'),
  'single' => TRUE,
  'content_types' => array('dosomething_stats_counter'),
  'all contexts' => TRUE,
  'render callback' => 'dosomething_stats_counter_content_type_render',
  'edit form' => 'dosomething_stats_counter_content_type_edit_form',
  'category' => t('dosomething'),
  'defaults' => array(
  ),
);

function dosomething_stats_counter_content_type_render($subtype, $conf, $args, $context) {
  global $user;
  $block = new stdClass();

  if (empty($context)) {
    return $block;
  }

  $argument = reset($context);
  list(, $type, $entity_type) = $argument->type;
  if ($type != 'entity') {
    return $block;
  }

  $wrapper = entity_metadata_wrapper($entity_type, $args[0]);
  $entity_id = $wrapper->getIdentifier();
  $bundle = $wrapper->getBundle();

  $output = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'dosomething-stats',
      ),
    ),
  );
  $items = array();

  if ($entity_type == 'node' && $bundle == 'action_guide') {
    $message = t('DO THIS!');
    $href = 'node/718313';
    $query = array('action_guide' => $entity_id);

    if ($user->uid) {
      // Check for any existing references to this action guide for this user (from project webforms).
      $result = db_query("SELECT f.entity_id, p.field_project_type_value 
                          FROM {field_data_field_action_guide_reference} f 
                          INNER JOIN {webform_submissions} w ON w.sid = f.entity_id 
                          LEFT JOIN {field_data_field_project_type} p ON p.entity_id = f.entity_id 
                          AND p.entity_type = 'webform_submission_entity'
                          WHERE f.field_action_guide_reference_target_id = :nid 
                          AND w.uid = :uid", 
                          array(':nid' => $entity_id, ':uid' => $user->uid));
      if ($result->rowCount()) {
        $message = t('DO THIS AGAIN!');
        foreach ($result as $record) {
          if ($record->field_project_type_value != DOSOMETHING_PROJECTS_COMPLETED) {
            $message = t('TELL US ABOUT IT!');
            $href = "node/718313/submission/$record->entity_id/edit";
            $query = array();
          }
        }
      }
    }

    $output['action_guide'] =  array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'dosomething-stats-action-guide',
        ),
      ),
      'message' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'counter-labels',
          ),
        ),
        'wants' => array(
          '#markup' => $message,
        ),
      ),
      'go' => array(
        '#type' => 'link',
        '#title' => t('GO'),
        '#href' => $href,
        '#options' => array(
          'query' => $query,
          'attributes' => array(
            'class' => array(
              'go-button',
            ),
          ),
        ),
      ),
    );
    // Show the number of action guide references for this action guide (from project_report webforms).
    $count = db_query("SELECT entity_id FROM {field_data_field_action_guide_reference} WHERE field_action_guide_reference_target_id = :nid", array(':nid' => $entity_id))->rowCount();
    $items[] = array(
      'title' => t('PEOPLE DOING IT'),
      'value' => $count,
    );
  }

  $output[] = array(
    '#theme' => 'dosomething_stats_counter',
    '#items' => $items,
  );
  $block->content = $output;
  return $block;
}

function dosomething_stats_counter_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  if (empty($form_state['contexts'])) {
    return $block;
  }

  $argument = reset($form_state['contexts']);
  list(, $type, $entity_type) = $argument->type;
  if ($type != 'entity') {
    return $block;
  }

  return $form;
}

