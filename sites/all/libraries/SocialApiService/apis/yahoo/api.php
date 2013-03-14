<?php

require 'globals.php';
require 'oauth_helper.php';

class YahooApi {
	private $callback = 'http://dosomething.org/contact-picker/service/yahoo';
	private $consumer_key = 'dj0yJmk9R2p0WUhCRjF1cUVvJmQ9WVdrOVYxcFBVblJNTldrbWNHbzlNVFV4T1RBM01ETTJNZy0tJnM9Y29uc3VtZXJzZWNyZXQmeD01Nw--';
	private $consumer_secret = 'febf95e9c9d8a9a2463d48a4c9f56d7198937f21';

	public $oauth_token = '';
	public $oauth_secret = '';
	public $oauth_verifier = '';
	public $redirect = '';

	public $real_oauth_token = '';
	public $real_oauth_secret = '';
	public $real_oauth_session = '';
	public $real_oauth_guid = '';

	public function __construct() {
	  if (isset($_GET['oauth_verifier']) || isset($_COOKIE['y_oauth_verifier'])) {
	    if (isset($_GET['oauth_verifier'])) {
	      setcookie('y_oauth_verifier', $_GET['oauth_verifier']);
	    }

	    if (isset($_COOKIE['y_oauth_verifier'])) {
	      $this->oauth_verifier = $_COOKIE['y_oauth_verifier'];
	    }

	    if (isset($_COOKIE['y_oauth_token'])) {
	      $this->oauth_token = $_COOKIE['y_oauth_token'];
	    }

	    if (isset($_COOKIE['y_oauth_secret'])) {
	      $this->oauth_secret = $_COOKIE['y_oauth_secret'];
	    }
	  }
	}

	public function is_authed() {
	  return (isset($_GET['oauth_token']) || isset($_COOKIE['y_oauth_verifier']));
	}

    public function authenticate() {
      $token = $this->get_request_token();

      $redirect = urldecode($token[3]['xoauth_request_auth_url']);
      $this->oauth_token = $token[3]['oauth_token'];
      setcookie('y_oauth_token', $this->oauth_token);
      $this->oauth_secret = $token[3]['oauth_token_secret'];
      setcookie('y_oauth_secret', $this->oauth_secret);

      header('location: ' . $redirect);
    }

	public function get_contacts($consumer_key, $consumer_secret, $guid, $access_token, $access_token_secret, $usePost=false, $passOAuthInHeader=true) {
	  $consumer_key = $this->consumer_key;
	  $consumer_secret = $this->consumer_secret;
	  $guid = $this->real_oauth_guid;
	  $access_token = $this->real_oauth_token;
	  $access_token_secret = $this->real_oauth_secret;
	  $usePost = false;
	  $passOAuthInHeader = true;

	  $retarr = array();  // return value
	  $response = array();

	  $url = 'http://social.yahooapis.com/v1/user/' . $guid . '/contacts';
	  $params['format'] = 'json';
	  $params['view'] = 'compact';
	  $params['oauth_version'] = '1.0';
	  $params['oauth_nonce'] = mt_rand();
	  $params['oauth_timestamp'] = time();
	  $params['oauth_consumer_key'] = $consumer_key;
	  $params['oauth_token'] = $access_token;

	  // compute hmac-sha1 signature and add it to the params list
	  $params['oauth_signature_method'] = 'HMAC-SHA1';
	  $params['oauth_signature'] =
	      oauth_compute_hmac_sig($usePost? 'POST' : 'GET', $url, $params,
	                             $consumer_secret, $access_token_secret);

	  // Pass OAuth credentials in a separate header or in the query string
	  if ($passOAuthInHeader) {
	    $query_parameter_string = oauth_http_build_query($params, true);
	    $header = build_oauth_header($params, "yahooapis.com");
	    $headers[] = $header;
	  } else {
	    $query_parameter_string = oauth_http_build_query($params);
	  }

	  // POST or GET the request
	  if ($usePost) {
	    $request_url = $url;
	    $headers[] = 'Content-Type: application/x-www-form-urlencoded';
	    $response = do_post($request_url, $query_parameter_string, 80, $headers);
	  } else {
	    $request_url = $url . ($query_parameter_string ?
	                           ('?' . $query_parameter_string) : '' );
	    $response = do_get($request_url, 80, $headers);
	  }

	  // extract successful response
	  if (! empty($response)) {
	    list($info, $header, $body) = $response;
	    if ($body) {
	     # print(json_pretty_print($body));
	    }

	    $retarr = $response;
	  }

	  return $retarr;
	}

	public function get_request_token() {
	  $retarr = array();  // return value
	  $response = array();

	  $consumer_key = $this->consumer_key;
	  $consumer_secret = $this->consumer_secret;
	  $callback = $this->callback;
	  $usePost=false;
	  $useHmacSha1Sig=true;
	  $passOAuthInHeader=true;

	  $url = 'https://api.login.yahoo.com/oauth/v2/get_request_token';
	  $params['oauth_version'] = '1.0';
	  $params['oauth_nonce'] = mt_rand();
	  $params['oauth_timestamp'] = time();
	  $params['oauth_consumer_key'] = $consumer_key;
	  $params['oauth_callback'] = $callback;

	  // compute signature and add it to the params list
	  if ($useHmacSha1Sig) {
	    $params['oauth_signature_method'] = 'HMAC-SHA1';
	    $params['oauth_signature'] =
	      oauth_compute_hmac_sig($usePost? 'POST' : 'GET', $url, $params,
	                             $consumer_secret, null);
	  } else {
	    $params['oauth_signature_method'] = 'PLAINTEXT';
	    $params['oauth_signature'] =
	      oauth_compute_plaintext_sig($consumer_secret, null);
	  }

	  // Pass OAuth credentials in a separate header or in the query string
	  if ($passOAuthInHeader) {
	      
	    $query_parameter_string = oauth_http_build_query($params, FALSE);
	    
	    $header = build_oauth_header($params, "yahooapis.com");
	    $headers[] = $header;
	  } else {
	    $query_parameter_string = oauth_http_build_query($params);
	  }
	 
	  // POST or GET the request
	  if ($usePost) {
	    $request_url = $url;
	    logit("getreqtok:INFO:request_url:$request_url");
	    logit("getreqtok:INFO:post_body:$query_parameter_string");
	    $headers[] = 'Content-Type: application/x-www-form-urlencoded';
	    $response = do_post($request_url, $query_parameter_string, 443, $headers);
	  } else {
	    $request_url = $url . ($query_parameter_string ?
	                           ('?' . $query_parameter_string) : '' );
	     
	    logit("getreqtok:INFO:request_url:$request_url");
	    
	    $response = do_get($request_url, 443, $headers);
	    
	  }
	  
	  // extract successful response
	  if (! empty($response)) {
	    list($info, $header, $body) = $response;
	    $body_parsed = oauth_parse_str($body);
	    if (! empty($body_parsed)) {
	      logit("getreqtok:INFO:response_body_parsed:");
	      #print_r($body_parsed);
	    }
	    $retarr = $response;
	    $retarr[] = $body_parsed;
	  }

	  return $retarr;
	}

	public function get_access_token() {
	  $consumer_key = $this->consumer_key;
	  $consumer_secret = $this->consumer_secret;
	  $request_token = $this->oauth_token;
	  $request_token_secret = $this->oauth_secret;
	  $oauth_verifier = $this->oauth_verifier;
	  $usePost = false;
	  $useHmacSha1Sig = true;
	  $passOAuthInHeader = true;

	  $retarr = array();  // return value
	  $response = array();

	  $url = 'https://api.login.yahoo.com/oauth/v2/get_token';
	  $params['oauth_version'] = '1.0';
	  $params['oauth_nonce'] = mt_rand();
	  $params['oauth_timestamp'] = time();
	  $params['oauth_consumer_key'] = $consumer_key;
	  $params['oauth_token']= $request_token;
	  $params['oauth_verifier'] = $oauth_verifier;

	  // compute signature and add it to the params list
	  if ($useHmacSha1Sig) {
	    $params['oauth_signature_method'] = 'HMAC-SHA1';
	    $params['oauth_signature'] =
	      oauth_compute_hmac_sig($usePost? 'POST' : 'GET', $url, $params,
	                             $consumer_secret, $request_token_secret);
	  } else {
	    $params['oauth_signature_method'] = 'PLAINTEXT';
	    $params['oauth_signature'] =
	      oauth_compute_plaintext_sig($consumer_secret, $request_token_secret);
	  }

	  // Pass OAuth credentials in a separate header or in the query string
	  if ($passOAuthInHeader) {
	    $query_parameter_string = oauth_http_build_query($params, false);
	    $header = build_oauth_header($params, "yahooapis.com");
	    $headers[] = $header;
	  } else {
	    $query_parameter_string = oauth_http_build_query($params);
	  }

	  // POST or GET the request
	  if ($usePost) {
	    $request_url = $url;
	    logit("getacctok:INFO:request_url:$request_url");
	    logit("getacctok:INFO:post_body:$query_parameter_string");
	    $headers[] = 'Content-Type: application/x-www-form-urlencoded';
	    $response = do_post($request_url, $query_parameter_string, 443, $headers);
	  } else {
	    $request_url = $url . ($query_parameter_string ?
	                           ('?' . $query_parameter_string) : '' );
	    logit("getacctok:INFO:request_url:$request_url");
	    $response = do_get($request_url, 443, $headers);
	  }

	  // extract successful response
	  if (! empty($response)) {
	    list($info, $header, $body) = $response;
	    $body_parsed = oauth_parse_str($body);
	    if (! empty($body_parsed)) {
	      logit("getacctok:INFO:response_body_parsed:");
	      #print_r($body_parsed);
	    }
	    $retarr = $response;
	    $retarr[] = $body_parsed;
	  }

	  return $retarr;
	}

}


?>