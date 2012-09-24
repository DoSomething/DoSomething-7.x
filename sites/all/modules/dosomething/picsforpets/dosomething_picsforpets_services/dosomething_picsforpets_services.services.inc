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
  $endpoint->server_settings = array(
    'rest_server' => array(
      'formatters' => array(
        'bencode' => TRUE,
        'json' => TRUE,
        'php' => TRUE,
        'rss' => TRUE,
        'xml' => TRUE,
        'yaml' => TRUE,
        'jsonp' => FALSE,
      ),
      'parsers' => array(
        'application/json' => TRUE,
        'application/vnd.php.serialized' => TRUE,
        'application/x-www-form-urlencoded' => TRUE,
        'application/x-yaml' => TRUE,
        'multipart/form-data' => TRUE,
      ),
    ),
  );
  $endpoint->resources = array(
    'dosomething_views' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => 1,
        ),
      ),
    ),
    'sharing' => array(
      'operations' => array(
        'create' => array(
          'enabled' => 1,
        ),
      ),
    ),
    'my-animals' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => 1,
        ),
      ),
    ),
    'user' => array(
      'actions' => array(
        'login' => array(
          'enabled' => 1,
        ),
        'logout' => array(
          'enabled' => 1,
        ),
      ),
    ),
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
