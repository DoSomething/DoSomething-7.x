<?php

/**
 *  Handles google API services for contact picker (presumably more to come).
 */
class google extends SocialServiceLayer {
  /**
   *  Provides credentials for using the Google API
   */
  private $creds;

  /**
   *  Stores the client connection to Google
   */
  private $client;

  /**
   *  Default options for the Google API request.
   */
  private $options = array(
  	'clientId' => '1000659299351.apps.googleusercontent.com',
  	'clientSecret' => 'sp-8HDxoUCFZH1bH9XOUuglO',
  	'max_results' => 1000
  );

  /**
   *  Loads required files for the Google+ API (needed to get contacts).
   */
  public function __construct() {  	
	  require_once $this->dir . '/apis/google/src/apiClient.php';
	  require_once $this->dir . '/apis/google/src/contrib/apiPlusService.php';

	  $this->client = new apiClient();
	  $this->client->setApplicationName('DoSomething Contacts Picker');
	  $this->client->setScopes('http://www.google.com/m8/feeds');

	  $this->client->setClientId($this->options['clientId']);
	  $this->client->setClientSecret($this->options['clientSecret']);
  }

  /**
   *  Sets credentials for accessing the Google API
   *
   *  @param array $credentials
   *    An array of credentials to pass into setAccessToken()
   */
  public function setCredentials($credentials) {
    // Set the credentials.
  	$this->creds = $credentials;

    // The key needs to be json encoded'd
  	$key = json_encode($credentials);

    // Set the access token.
  	$this->client->setAccessToken($key);
  }

  /**
   *  Confirms that we have a valid access token.
   *
   *  @return bool
   *    True if there is a valid access token, else false.
   */
  public function checkCredentials() {
    if ($this->client->getAccessToken()) {
      return true;
    }

    return false;
  }

  // Returns Google contacts.
  public function getContacts() {
    // If we don't have valid credentials, throw an exception.
  	if (!$this->creds) {
  	  throw new Exception('You must call setCredentials before you may call getContacts()');
  	}

    // Double checking for a rare occurance where we could have creds, but not be authed.
  	if ($this->checkCredentials()) {
      // Make the request.
	    $req = new apiHttpRequest('https://www.google.com/m8/feeds/contacts/default/full?max-results=' . $this->options['max_results']);
	    if (!$val = $this->client->getIo()->authenticatedRequest($req)) {
	      echo "Please refresh the page and log back in to Google.";
	      exit;
	    }

      // Get the response.
	    $response = ($val->getResponseBody());

      // Set default value for $vals
	    $vals = array();

      // Attempt to find contacts.
	    preg_match_all('#<entry>(.*?)</entry>#si', $response, $entries);

      // Assuming there are contacts, loop through and get information.
      if (!empty($entries[1]) && is_array($entries[1])) {
	      foreach ($entries[1] AS $key => $entry) {
          // Name
	        preg_match('#<title type\=("|\'|)text(\\1)>(.*?)<\/title>#i', $entry, $name);
          // Email
	        preg_match('#<gd\:email([^(<]*)(address\=("|\'|)([^("|\'|)]*))#i', $entry, $email);

	        if (!empty($email[4])) {
	          $n = (isset($name[3]) ? $name[3] : '');
		        $e = $email[4];

		        $vals[strtolower($e)] = array(
		          'email' => $e,
		          'name' => $n
		        );
		      }
	      }

        // As long as we have something, sort it.
        if (!empty($vals)) {
          ksort($vals);
        }
      }

      // Return it.
	    return $vals;
  	}
  }
}
