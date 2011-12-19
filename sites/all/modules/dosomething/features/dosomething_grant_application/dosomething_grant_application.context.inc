<?php
/**
 * @file
 * dosomething_grant_application.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dosomething_grant_application_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'grants-active-menu';
  $context->description = ' Adds active class to grants menu item when viewing Grant Applications. ';
  $context->tag = 'Menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'grant_application' => 'grant_application',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'grants',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t(' Adds active class to grants menu item when viewing Grant Applications. ');
  t('Menu');
  $export['grants-active-menu'] = $context;

  return $export;
}
