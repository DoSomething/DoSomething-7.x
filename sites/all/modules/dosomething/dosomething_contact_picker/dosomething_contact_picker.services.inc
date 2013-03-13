<?php

/**
 *  Loads a service handler, if possible.  Run from /contact-picker/service/[$service]
 *
 *  @param string $service
 *    The name of the service that should be loaded.
 */
function dosomething_contact_picker_load_service($service) {
  // Make sure the function exists.
  if (function_exists('dosomething_contact_picker_handle_' . $service)) {
  	$function = 'dosomething_contact_picker_handle_' . $service;
  	$function();
  }
}

/**
 *  Handles the Goog.
 */
function dosomething_contact_picker_handle_google() {
  // Get the library and load Google.
  require_once libraries_get_path('SocialApiService') . '/service.php';
  $s = SocialApiService::getInstance();
  $g = $s->get('google');

  // We get the key from a jQuery POST reqest.
  // See sites/all/libraries/SocialApiService/services/scripts/google.js
  $key = $_POST['key'];
  // Ignore if the key is malformed
  if (empty($key) || (!isset($key['access_token']) || !isset($key['token_type']) || !isset($key['expires_in']))) {
    return;
  }
  else {
    // Set the Google credentials.
    $g->setCredentials(array(
      'access_token' => $key['access_token'],
      'token_type' => $key['token_type'],
      'expires_in' => $key['expires_in'],
      'created' => time(),
    ));

    // Get the contacts
    $contacts = $g->getContacts();

    // Theme them.
    echo theme('contact_picker_contacts', array(
    	'contacts' => $contacts,
    ));
  }

  // Exit so nothing from the actual layout shows up.
  drupal_exit();
}

/**
 *  Handles Yahoo
 */
function dosomething_contact_picker_handle_yahoo() {
  // Get the method and make sure it's valid.
  $method = strtolower(check_plain($_SERVER['REQUEST_METHOD']));
  if (!in_array($method, array('get', 'post'))) {
    return;
  }

  // Get the library and load Yahoo.
  require_once libraries_get_path('SocialApiService') . '/service.php';
  $s = SocialApiService::getInstance();
  $y = $s->get('yahoo');

  // If we're actually viewing this page, it's probably because we have to auth.
  if ($method == 'get') {
    // If we're unauthed...auth.
    if (!$y->is_authed()) {
      $y->authenticate();
    }
    else {
      // Otherwise we're authed.  Show the contacts...
      $contacts = $y->getContacts();

      // ...and theme them.
      echo theme('contact_picker_contacts', array(
        'contacts' => $contacts,
        'close' => TRUE,
      ));

      // The window will close itself once the contacts are loaded.
    }
  }
  // Otherwise, if it's a POST request, things are looking good.
  else if ($method == 'post') {
    // Just to make sure: If we're not authed, let us know.
    if (!$y->is_authed()) {
      echo drupal_json_encode(array(
        'state' => $y->is_authed(),
      ));
    }
    else {
      // Otherwise, load the contacts...
      $contacts = $y->getContacts();

      // ...and theme them.
      echo theme('contact_picker_contacts', array(
        'contacts' => $contacts,
      ));
    }
  }
  
  // Exit so nothing except our data shows up.
  drupal_exit();
}
