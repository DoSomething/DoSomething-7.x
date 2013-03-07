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
  drush_print(dt('Enabling the DoSomething API module...'));
  $modules = array(
    'dosomething_api',
  );
  drush_invoke_process('@self', 'en', $modules, array('--yes', '--verbose'));

  $homepage_webform = dosomething_general_save_node_from_file(drupal_get_path('module', 'robocalls') . '/webforms/homepage.txt', 'robo-calls/homepage-webform');
  #$walkthrough_webform = dosomething_general_save_node_from_file('sites/all/modules/dosomething/features/robocalls/webforms/walkthrough.txt', 'prank/walkthrough');
  drush_print(dt('See node/' . $homepage_webform->nid . ' (re-alias as robo-calls/homepage-webform).'));
  #$celeb_webform = dosomething_general_save_node_from_file(drupal_get_path('module', 'robocalls') . '/webforms/celeb.txt', 'robo-calls/webform');
  #drush_print(dt('Updated robo-calls/webform'));
  drush_print(dt('Done! See Mike for final steps.'));
}

?>