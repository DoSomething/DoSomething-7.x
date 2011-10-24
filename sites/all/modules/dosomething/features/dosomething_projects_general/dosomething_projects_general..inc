<?php
/**
 * @file
 * dosomething_projects_general..inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function dosomething_projects_general_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Start A Project';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'start_a_project';
  $fe_block_boxes->body = '<a href="/project-report/start-project" title="Start a Project">START A PROJECT</a>';

  $export['start_a_project'] = $fe_block_boxes;

  return $export;
}
