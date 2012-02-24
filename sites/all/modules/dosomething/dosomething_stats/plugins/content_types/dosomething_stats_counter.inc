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
  $block = new stdClass();

  if (empty($context)) {
    return $block;
  }

  $argument = reset($context);
  list(, $type, $entity_type) = $argument->type;
  if ($type != 'entity') {
    return $block;
  }

  $field_labels = array(
    'field_num_people_impacted' => t('People Helped'),
    'field_update_people_involved' => t('People Involved'),
  );

  $instances = field_info_instances($entity_type);
  $wrapper = entity_metadata_wrapper($entity_type, $args[0]);
  $entity_id = $wrapper->getIdentifier();
  $items = array();
  foreach ($argument->restrictions['type'] as $bundle) {
    foreach ($instances[$bundle] as $field_name => $field) {
      if (isset($field_labels[$field_name])) {
        $items[$field_name] = array(
          'title' => $field_labels[$field_name],
          'value' => $wrapper->{$field_name}->value(),
        );
      }
    }
  }

  $block->content = array(
    '#theme' => 'dosomething_stats_counter',
    '#items' => $items,
  );
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

function dosomething_stats_counter_content_type_edit_form_submit(&$form, &$form_state) {
}
