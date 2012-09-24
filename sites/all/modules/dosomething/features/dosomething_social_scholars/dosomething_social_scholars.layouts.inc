<?php
/**
 * @file
 * dosomething_social_scholars.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function dosomething_social_scholars_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'social_scholars';
  $layout->admin_title = 'Social Scholars';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'statistics',
          1 => 'form',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'statistics' => array(
        'type' => 'region',
        'title' => 'Statistics',
        'width' => '45.28418730174165',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      'form' => array(
        'type' => 'region',
        'title' => 'Form',
        'width' => '54.71581269825835',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
    ),
  );
  $export['social_scholars'] = $layout;

  return $export;
}
