<?php

function dosomething_contact_picker_load_service($service) {
  if (function_exists('dosomething_contact_picker_handle_' . $service)) {
  	$function = 'dosomething_contact_picker_handle_' . $service;
  	$function();
  }
}

function dosomething_contact_picker_handle_google() {
  require_once libraries_get_path('SearchApiService') . '/service.php';
  $s = EmailApiService::getInstance();
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