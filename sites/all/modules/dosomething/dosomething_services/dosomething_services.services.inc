<?php
/**
 * @file
 * dosomething_services.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function dosomething_services_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'rest';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'rest';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array(
    'rest_server' => array(
      'formatters' => array(
        'json' => TRUE,
        'xml' => TRUE,
        'bencode' => FALSE,
        'jsonp' => FALSE,
        'php' => FALSE,
        'rss' => FALSE,
        'yaml' => FALSE,
      ),
      'parsers' => array(
        'application/json' => TRUE,
        'application/x-www-form-urlencoded' => TRUE,
        'multipart/form-data' => TRUE,
        'application/vnd.php.serialized' => FALSE,
        'application/x-yaml' => FALSE,
      ),
    ),
  );
  $endpoint->resources = array(
    'file' => array(
      'alias' => 'file',
      'operations' => array(
        'create' => array(
          'enabled' => 1,
        ),
        'retrieve' => array(
          'enabled' => 1,
        ),
        'index' => array(
          'enabled' => 1,
        ),
      ),
      'actions' => array(
        'create_media' => array(
          'enabled' => 1,
        ),
      ),
    ),
    'node' => array(
      'alias' => 'node',
    ),
    'system' => array(
      'alias' => 'system',
      'actions' => array(
        'connect' => array(
          'enabled' => 1,
        ),
      ),
    ),
    'user' => array(
      'alias' => 'user',
      'operations' => array(
        'retrieve' => array(
          'enabled' => 1,
        ),
        'update' => array(
          'enabled' => 1,
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => 1,
        ),
        'logout' => array(
          'enabled' => 1,
        ),
        'register' => array(
          'enabled' => 1,
        ),
        'fblogin' => array(
          'enabled' => 1,
        ),
      ),
    ),
    'webform_submission' => array(
      'alias' => 'webform',
      'operations' => array(
        'retrieve' => array(
          'enabled' => 1,
        ),
        'create' => array(
          'enabled' => 1,
        ),
        'update' => array(
          'enabled' => 1,
        ),
        'index' => array(
          'enabled' => 1,
        ),
      ),
    ),
  );
  $endpoint->debug = 1;
  $export['rest'] = $endpoint;

  return $export;
}
