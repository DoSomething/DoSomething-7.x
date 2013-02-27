<?php

function robocalls_drush_command() {
  return array(
    'robocall' => array(
      'description' => 'Robo Calls / etc.',
      'arguments' => array(
        'fnid' => 'The ID of the webform that runs Robocalls',
      ),
    ),
    'robo-migrate' => array(
      'description' => 'Migrates webforms &etc. for Robocalls v2',
    ),
  );
}

function drush_robocalls_robocall($fnid) {
  // Removed 2/27/13
}

function drush_robocalls_robo_migrate() {
  $w = dosomething_general_save_node_from_file(drupal_get_path('module', 'robocalls') . '/webforms/homepage.txt', 'robo-calls/homepage-webform');
  drush_print(dt('Done! See ' . $w->nid));
}

?>