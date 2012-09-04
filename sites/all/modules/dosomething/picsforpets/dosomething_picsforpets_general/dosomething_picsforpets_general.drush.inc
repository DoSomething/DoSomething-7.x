<?php

/**
 * @file
 * Deploy DoSomething picsforpets to a copy of production.
 */

/**
 * Implements hook_drush_command().
 */
function dosomething_picsforpets_general_drush_command() {
  $items['picsforpets-deploy'] = array(
    'description' => dt('Downloads the FirePHP library from http://firephp.org/.'),
  );
  return $items;
}

function drush_dosomething_picsforpets_general_picsforpets_deploy() {
  try {
    drush_log('Enabling picsforpets modules.', 'info');
    // Enable all of our modules.
    $modules = array(
      'dosomething_picsforpets_services',
      'dosomething_picsforpets_general',
      'dosomething_picsforpets_shelters',
      'dosomething_picsforpets_shelter_migrate',
      'dosomething_fb_apps',
      'dosomething_picsforpets_fb_user',
      'dosomething_feedback',
      'picsforpets',
    );
    drush_invoke_process('@self', 'en', $modules, array('--yes', '--verbose'));
    cache_clear_all();
    # Ensure blocks for our theme are in the table.
    _block_rehash('picsforpets');
    # Ensure all blocks are disabled for our theme.
    drush_log('Disabling all blocks for the picsforpets theme.', 'info');
    db_query('UPDATE block set status=0 where theme = :picsforpets', array(':picsforpets' => 'picsforpets'));
    drush_log('Entityifying the webform pics for pets submission entity bundle.', 'info');
    $types = variable_get('webform_node_types', array());
    $types[] = 'fb_app_data_gathering_form';
    variable_set('webform_node_types', $types);
    $type = new stdClass();
    $type->type = 'fb_app_data_gathering_form';
    entity_save('webform_submission_entity_type', $type);
    webform_entity_clear_caches();
    drush_log('Generating the pics for pets pet form.', 'info');
    dosomething_picsforpets_general_regenerate_webform_node();
    drush_log('Importing pics for pets shelters....', 'info');
    drush_invoke_process('@self', 'migrate-import', array('PFPShelter'), array('--yes'));
  }
  catch (Exception $e) {
    drush_log(dt('Aw snap, something went AWFUL wrong: @error', array('@error' => $e->getMessage())), 'error');
  }
}
