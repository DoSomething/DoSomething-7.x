<?php

/**
 *  Implements hook_drush_command()
 */
function dosomething_petitions_drush_command() {
  return array(
    'petitions-check-counts' => array(
      'description' => 'Checks all petitions counts and updates incorrect variable counts.',
    ),
  );
}

/**
 *  Petitions uses the Drupal variable system to store "total signed" counts.
 *  This saves time on pageload so we don't have to count every single webform
 *  submission to make the progress bar.
 *
 *  In unlikely circumstances, the variable count may be updated incorrectly if,
 *  for example, two people are signing a particular petition at the same time.
 *
 *  This drush command confirms that all counts are correct.  It checks the webform
 *  submissions count for each petition and updates the variable if the two disagree.
 *
 *  This command can only be run once every 24 hours.
 *
 *  If, for administrative purposes, we fake the "signed #" count, set the "petition_bypass_NID"
 *  variable and this will ignore the petition that matches that NID.  If petitions_bypass_NID is
 *  not set or is set to 0, the petition will be updated.
 *
 *  @see dosomething_petitions.module lines 197-199
 */
function drush_dosomething_petitions_petitions_check_counts() {
  try {
    // Get the last time that petitions counts were confirmed.
    $last_updated = variable_get('petitions_last_updated', 0);

    // Only run this command if it's been at least 24 hours since the last update.
    if ((REQUEST_TIME - $last_updated) > 86400) {
      // Get all active petitions.
      $petitions = db_select('node', 'n')
      ->fields('n', array('nid', 'status'))
      ->condition('type', 'petition')
      ->condition('status', 1)
      ->execute()
      ->fetchAllKeyed();

      // Include webform submissions file, so we can use webform_get_submission_count() below.
      module_load_include('inc', 'webform', 'includes/webform.submissions');

      // Loop through the petitions
      foreach ($petitions AS $nid => $status) {
        // Whether or not we're faking the count -- this will let us bypass this entirely.
        $bypass_update = variable_get('petitions_bypass_' . $nid, 0);

        // Ignore this petition if we're bypassing it.
        if ($bypass_count) {
          continue;
        }

          // "Real" petition count.
        $real_count = webform_get_submission_count($nid);

        // "Current" count
        $current_count = variable_get('petitions_signed_count_' . $nid, 0);

        drush_print(dt("Checking $nid..."));
        drush_print(dt("Real count is $real_count"));
        drush_print(dt("Current count is $current_count"));

        // If the real count is not the current count, and we're not bypassing, update the count.
        if ($real_count != $current_count && !$bypass_update) {
          variable_set('petitions_signed_count_' . $nid, $real_count);
          drush_print(dt("Updating..."));
        }
      }

      // Set the last updated time to now.
      variable_set('petitions_last_updated', REQUEST_TIME);
      drush_print(t('Done.'));
    }
    else {
      drush_log(dt("It has been less than 24 hours since the last update.  Aborting."), 'error');
    }
  }
  catch (Exception $e) {
    drush_log(dt('Sorry, there was an error: @error', array('@error' => $e->getMessage())), 'error');
  }
}
