<?php

class yahoo extends SocialServiceLayer {
  public $api;

  public function __construct() {
  	require_once $this->dir . '/apis/yahoo/api.php';
  	$this->api = new YahooApi();
  }

  public function is_authed() {
  	return $this->api->is_authed();
  }

  public function getContacts() {
    $retarr = $this->api->get_access_token();
    $info = $retarr[3];

    if ($info['oauth_problem'] == 'token_rejected') {
      setcookie('y_oauth_verifier', '');
      setcookie('y_oauth_token', '');
      setcookie('y_oauth_secret', '');

      $this->authenticate();
    }

    $this->api->real_oauth_token = urldecode($info['oauth_token']);
    $this->api->real_oauth_secret = $info['oauth_token_secret'];
    $this->api->real_oauth_session = $info['oauth_session_handle'];
    $this->api->real_oauth_guid = $info['xoauth_yahoo_guid'];

    $ree = $this->api->get_contacts();
    $response = json_decode($ree[2]);

    // Redirect on a very bizarre error.
    if (isset($retarr[3]['oauth_problem']) && $retarr[3]['oauth_problem'] == 'oauth_verifier_invalid') {
      drupal_goto('contact-picker/service/yahoo');
    }

    $count = $ree->total;
    $contacts = $response->contacts->contact;

    $c = array();
    foreach ($contacts AS $key => $data) {
      $name = $email = '';
      foreach ($data->fields AS $key => $field) {
      	if ($field->type == 'email') {
  		  $email = $field->value;
      	}
      	else if ($field->type == 'name') {
      	  $name = $field->value->givenName . ' ' . $field->value->familyName;
      	}
      }

      $c[$email] = array(
      	'email' => $email,
      	'name' => $name
      );
    }

    ksort($c);
    return $c;
  }

  public function __call($func, $args) {
  	if (method_exists($this->api, $func)) {
  	  $this->api->$func($args);
  	}
  	else {
  	  throw new Exception("EPIC YAHOO API FAIL");
  	}
  }
}