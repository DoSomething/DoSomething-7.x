<?php

function dosomething_contact_picker_load_service($service) {
  if (function_exists('dosomething_contact_picker_handle_' . $service)) {
  	$function = 'dosomething_contact_picker_handle_' . $service;
  	$function();
  }
}

function dosomething_contact_picker_handle_google() {
  require_once libraries_get_path('SocialApiService') . '/service.php';
  $s = SocialApiService::getInstance();
  $g = $s->get('google');

  $key = $_POST['key'];
  $g->setCredentials(array(
    'access_token' => $key['access_token'],
    'token_type' => $key['token_type'],
    'expires_in' => $key['expires_in'],
    'created' => time(),
  ));

  $contacts = $g->getContacts();
  echo theme('contact_picker_contacts', array(
  	'contacts' => $contacts,
  ));
  drupal_exit();
}

function dosomething_contact_picker_handle_yahoo() {
  $method = strtolower(check_plain($_SERVER['REQUEST_METHOD']));

  require_once libraries_get_path('SocialApiService') . '/service.php';
  $s = SocialApiService::getInstance();
  $y = $s->get('yahoo');

  if ($method == 'get') {
    if (!$y->is_authed()) {
      $y->authenticate();
    }
    else {
      $c = $y->getContacts();
    }
  }

  if ($method == 'post') {
    if (!$y->is_authed()) {
      echo drupal_json_encode(array(
        'state' => $y->is_authed(),
      ));
    }
    else {
      $contacts = $y->getContacts();
      echo theme('contact_picker_contacts', array(
        'contacts' => $contacts,
      ));
    }
  }
  
  drupal_exit();
}