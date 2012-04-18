<?php

/**
 * Callback function to supply a list of content types.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('DS Project Stats'),
  'description' => t('The vital stats pane for project report pages.'),
  'all contexts' => TRUE,
  'category' => t('dosomething'),
  'defaults' => '',
  'render callback' => 'dosomething_project_report_stats_content_type_render',
);

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_project_report_stats_content_type_render($subtype, $conf, $args, $context) {
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

  if ($entity_type == 'webform_submission_entity' && $bundle == 'project_report') {
    $output['title'] = array(
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
      '#markup' => t('Vital Stats'),
    );
    $uid = $wrapper->value()->uid;
    $account = user_load($uid);
    $name = dosomething_user_my_somethings_get_full_name($account);
    $profile = profile2_load_by_user($account->uid, 'main');
    $profile = entity_metadata_wrapper('profile2', $profile);
    $address = $profile->field_user_address->value();
    $misc = array();
    if ($awards = $wrapper->field_grant_winner->value()) {
      foreach ($awards as $award) {
        $misc[] = t('@award winner', array('@award' => $award->name));
      }
    }

    if ($clubs = $wrapper->field_project_clubs->value()) {
      foreach ($clubs as $club) {
        $misc[] = l($club->title, "node/$club->nid");
      }
    }

    $address = $wrapper->field_webform_address->value();
    $location = '';
    if ($address['locality'] && $address['administrative_area']) {
      $location = $address['locality'] . ', ' . $address['administrative_area'];
    }
    elseif ($address['locality'] || $address['administrative_area']) {
      $location = $address['locality'] ? $address['locality'] : $address['administrative_area'];
    }

    $output['project_facts'] =  array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'dosomething-member-facts',
        ),
      ),
      'name' => array(
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
        '#markup' => $name,
      ),
      'hometown' => array(
        '#markup' => $location,
        '#attributes' => array(
          'class' => array(
            'dosomething-project-hometown',
          ),
        ),
      ),
      'misc' => array(
        '#theme' => 'item_list',
        '#items' => $misc,
        '#attributes' => array(
          'class' => array(
            'dosomething-member-misc',
          ),
        ),
      ),
    );

    // Get related project updates.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'project_update')
      ->propertyCondition('status', 1)
      ->fieldCondition('field_webform_project_submission', 'target_id', $entity_id, '=')
      ->execute();
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $project_updates = node_load_multiple($nids);
    }

    if ($wrapper->field_impact_type->value() && $wrapper->field_impact_amount->value()) {
      $impact_key = $wrapper->field_impact_type->value();
      $field_impact_type = field_info_field('field_impact_type');
      $items['impacted'] = array(
        'title' => $field_impact_type['settings']['allowed_values'][$impact_key],
        'value' => $wrapper->field_impact_amount->value(),
      );
      // Add field_update_people_impacted values from project updates to a project.
      if (!$items['impacted']['value']) {
        $items['impacted']['value'] = 0;
      }
      if (count($project_updates)) {
        foreach ($project_updates as $project_update) {
          if (isset($project_update->field_update_people_impacted[LANGUAGE_NONE][0]['value'])) {
            $items['impacted']['value'] += $project_update->field_update_people_impacted[LANGUAGE_NONE][0]['value'];
          }
        }
      }
    }

    $instances = field_info_instances($entity_type);
    $field_labels = array(
      'field_update_people_involved' => t('People Doing It'),
    );
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

    // Add field_update_people_involved values from project updates to a project.
    if (!$items['field_update_people_involved']['value']) {
      $items['field_update_people_involved']['value'] = 0;
    }

    if (count($project_updates)) {
      foreach ($project_updates as $project_update) {
        if (isset($project_update->field_update_people_involved[LANGUAGE_NONE][0]['value'])) {
          $items['field_update_people_involved']['value'] += $project_update->field_update_people_involved[LANGUAGE_NONE][0]['value'];
        }
      }
    }

    $output[] = array(
      '#theme' => 'dosomething_stats_counter',
      '#items' => $items,
    );
  
    $block->content = $output;
  }
  return $block;
}
