<?php

class google extends EmailServiceLayer {
  private $creds;
  private $client;

  private $options = array(
  	'clientId' => '1000659299351.apps.googleusercontent.com',
  	'clientSecret' => 'sp-8HDxoUCFZH1bH9XOUuglO',
  	'max_results' => 1000
  );

  public function __construct() {  	
	require_once $this->dir . '/apis/google/src/apiClient.php';
	require_once $this->dir . '/apis/google/src/contrib/apiPlusService.php';

	$this->client = new apiClient();
	$this->client->setApplicationName('DoSomething Contacts Picker');
	$this->client->setScopes('http://www.google.com/m8/feeds');

	$this->client->setClientId($this->options['clientId']);
	$this->client->setClientSecret($this->options['clientSecret']);
  }

  public function setCredentials($credentials) {
  	$this->creds = $credentials;

  	$key = json_encode($credentials);
  	$this->client->setAccessToken($key);
  }

  public function checkCredentials() {
    if ($this->client->getAccessToken()) {
      return true;
    }

    return false;
  }

  public function getContacts() {
  	if (!$this->creds) {
  	  throw new Exception('You must call setCredentials before you may call getContacts()');
  	}

  	if ($this->checkCredentials()) {
	  $req = new apiHttpRequest('https://www.google.com/m8/feeds/contacts/default/full?max-results=' . $this->options['max_results']);
	  if (!$val = $this->client->getIo()->authenticatedRequest($req)) {
	    echo "Please refresh the page and log back in to Google.";
	    exit;
	  }

	  $response = ($val->getResponseBody());

	  $vals = array();
	  preg_match_all('#<entry>(.*?)</entry>#si', $response, $entries);
	  foreach ($entries[1] AS $key => $entry) {
	    preg_match('#<title type\=("|\'|)text(\\1)>(.*?)<\/title>#i', $entry, $name);
	    preg_match('#<gd\:email([^<]*)(address\=("|\'|)([^("|\'|)]*))#i', $entry, $email);

	    if (!empty($email[4])) {
	      $n = (isset($name[3]) ? $name[3] : '');
		  $e = $email[4];

		  $vals[strtolower($e)] = array(
		    'email' => $e,
		    'name' => $n
		  );
		}
	  }

	  ksort($vals);
	  return $vals;
  	}
  }
}