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
    $hometown = dosomething_user_my_somethings_hometown($address);
    $misc = array();
    // TODO: add any grants, awards, or scholarships received to misc.
    if ($clubs = $wrapper->field_project_clubs->value()) {
      foreach ($clubs as $club) {
        $misc[] = l($club->title, "node/$club->nid");
      }
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
        '#markup' => $hometown,
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

    $instances = field_info_instances($entity_type);
    $field_labels = array(
      'field_num_people_impacted' => t('People Helped'),
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

    $output[] = array(
      '#theme' => 'dosomething_stats_counter',
      '#items' => $items,
    );
  
    $block->content = $output;
  }
  return $block;
}
