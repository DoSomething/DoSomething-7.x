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
  $homepage_webform = dosomething_general_save_node_from_file(drupal_get_path('module', 'robocalls') . '/webforms/homepage.txt', 'robo-calls/homepage-webform');
  $walkthrough_webform = dosomething_general_save_node_from_file(drupal_get_path('module', 'robocalls') . '/webforms/walkthrough.txt', 'prank/walkthrough');
  drush_print(dt('See node/' . $homepdrage_webform->nid . ' (re-alias as robo-calls/homepage-webform) and node/' . $walkthrough_webform->nid . ' (re-alias as prank/walkthrough)'));
  $celeb_webform = dosomething_general_save_node_from_file(drupal_get_path('module', 'robocalls') . '/webforms/celeb.txt', 'robo-calls/webform');
  drush_print(dt('Updated robo-calls/webform'));
  drush_print(dt('Done!'));
}

?>