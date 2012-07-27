<?php
/**
 * @file
 * dosomething_picsforpets_services.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function dosomething_picsforpets_services_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'mobile_app';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'services/pets';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'file' => array(
      'operations' => array(
        'create' => array(
          'enabled' => 1,
        ),
      ),
    ),
    'webform_submission' => array(
      'operations' => array(
        'create' => array(
          'enabled' => 1,
        ),
        'index' => array(
          'enabled' => 1,
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['mobile_app'] = $endpoint;

  return $export;
}
