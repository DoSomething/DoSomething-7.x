<?php
/**
 * @file
 * dosomething_scholarship_application.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dosomething_scholarship_application_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scholarships-active-menu';
  $context->description = 'Adds active class to Scholarships menu item when viewing Scholarship Applications. ';
  $context->tag = 'Menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'scholarship_application' => 'scholarship_application',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'scholarships',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds active class to Scholarships menu item when viewing Scholarship Applications. ');
  t('Menu');
  $export['scholarships-active-menu'] = $context;

  return $export;
}
