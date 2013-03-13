<?php

/**
 *  Handles yahoo services, particularly for contacts.
 */
class yahoo extends SocialServiceLayer {
  /**
   *  Handles instance of the API service.
   */
  public $api;

  /**
   *  Loads the Yahoo! API and stores it in the $api property.
   */
  public function __construct() {
  	require_once $this->dir . '/apis/yahoo/api.php';
  	$this->api = new YahooApi();
  }

  /**
   *  Are we authed?
   *
   *  @return bool
   *    True if we are successfully authenticated, else false.
   */
  public function is_authed() {
  	return $this->api->is_authed();
  }

  /**
   *  Works some dark magic to get the Yahoo contacts out.
   *
   *  @return array
   *    An array of contacts.
   */
  public function getContacts() {
    // Attempt to get the access token.
    $retarr = $this->api->get_access_token();
    $info = $retarr[3];

    // If we've run into "token rejected" problem (i.e., the "user gave us permission"
    // time -- usually 1hr -- has run out), we need to ask them to auth again.
    if ($info['oauth_problem'] == 'token_rejected') {
      setcookie('y_oauth_verifier', '');
      setcookie('y_oauth_token', '');
      setcookie('y_oauth_secret', '');

      $this->authenticate();
    }

    // Redirect on a very bizarre error.
    if (isset($retarr[3]['oauth_problem']) && $retarr[3]['oauth_problem'] == 'oauth_verifier_invalid') {
      drupal_goto('contact-picker/service/yahoo');
    }

    // Set API auth tokens.
    $this->api->real_oauth_token = urldecode($info['oauth_token']);
    $this->api->real_oauth_secret = $info['oauth_token_secret'];
    $this->api->real_oauth_session = $info['oauth_session_handle'];
    $this->api->real_oauth_guid = $info['xoauth_yahoo_guid'];

    // Now that that's out of the way, let's try and get the contacts.
    $ree = $this->api->get_contacts();

    // See if we have a resposne.
    $response = json_decode($ree[2]);

    // Hopefully get a total number of contacts.
    $count = $ree->total;

    // Assign the contacts to a variable.
    $contacts = $response->contacts->contact;

    $c = array();
    // Assuming there are contacts to sort through, loop through and get data.
    if (!empty($contacts) && is_array($contacts)) {
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

      // Sort if possible.
      if (!empty($c)) {
        ksort($c);
      }
    }

    // Return contacts
    return $c;
  }

  // Handle rogue calls in case someone is trying to access the API.
  public function __call($func, $args) {
  	if (method_exists($this->api, $func)) {
  	  $this->api->$func($args);
  	}
  	else {
  	  throw new Exception("The $func() method does not exit within the Yahoo API.");
  	}
  }
}
