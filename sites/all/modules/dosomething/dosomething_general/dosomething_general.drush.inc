<?php

/**
 * Implements hook_drush_init().
 */
function dosomething_general_drush_init() {
  // Make sure drush commands are considered background tasks by New Relic
  if (function_exists('newrelic_background_job')) {
    newrelic_background_job(TRUE);
  }
}

