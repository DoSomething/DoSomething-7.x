<?php
/**
 * @file
 * dosomething_layout.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function dosomething_layout_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Android App Sidebar';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'android_app_sidebar';
  $fe_block_boxes->body = '<a href="https://play.google.com/store/apps/details?id=org.dosomething.android" target="_blank"><img class="android-app-img" src="http://files.dosomething.org/files/u/sitewide/andriod-app_0.png" alt="Android App" /></a>';

  $export['android_app_sidebar'] = $fe_block_boxes;

  return $export;
}
