<?php

require 'globals.php';
require 'oauth_helper.php';

function associate_emails($emails, $names) {
  foreach ($emails AS $key => $email) {
    $list["$email"] = $names["$key"];
  }

  ksort($list);
  return $list;
}

class yahooauth {
	private $callback = 'http://www.dosomething.org/sites/all/modules/dosomething/dosomething_contact_picker/yo';
	private $consumer_key = 'dj0yJmk9WFlWdUFPZGoxUm1zJmQ9WVdrOVdqbHdWR3BzTTJVbWNHbzlOekUxTkRrMU1UWXkmcz1jb25zdW1lcnNlY3JldCZ4PTQ2';
	private $consumer_secret = 'ce75ff10eb700dc4d7a6dbc471f9f8c7502a11a6';

	private $oauth_token = '';
	private $oauth_secret = '';
	private $oauth_verifier = '';
	private $redirect = '';

	private $real_oauth_token = '';
	private $real_oauth_secret = '';
	private $real_oauth_session = '';
	private $real_oauth_guid = '';

	public function __construct() {
		if (!$_GET['oauth_token']) {
			$this->authenticate();
		}
		else {
			$this->oauth_verifier = $_GET['oauth_verifier'];
			if ($_COOKIE['y_oauth_token']) {
				$this->oauth_token = $_COOKIE['y_oauth_token'];
			}
			if ($_COOKIE['y_oauth_secret']) {
				$this->oauth_secret = $_COOKIE['y_oauth_secret'];
			}

			$this->step2();
		}
	}

	private function clean_email($email) {
	  $email = preg_replace('#[^A-Za-z0-9\-\_]#i', '_', $email);
	  return $email;
	}

	private function authenticate() {
		$retarr = $this->get_request_token($this->consumer_key, $this->consumer_secret, $this->callback, false, true, true);

		$this->redirect = urldecode($retarr[3]['xoauth_request_auth_url']);
		$this->oauth_token = $retarr[3]['oauth_token'];
		setcookie('y_oauth_token', $this->oauth_token);
		$this->oauth_secret = $retarr[3]['oauth_token_secret'];
		setcookie('y_oauth_secret', $this->oauth_secret);
		
		header('location: ' . $this->redirect);
	}

    private function step2() {
        $retarr = $this->get_access_token($this->consumer_key, $this->consumer_secret, $this->oauth_token, $this->oauth_secret, $this->oauth_verifier, false, true, true);
        $info = $retarr[3];

        $this->real_oauth_token = urldecode($info['oauth_token']);
        $this->real_oauth_secret = $info['oauth_token_secret'];
        $this->real_oauth_session = $info['oauth_session_handle'];
        $this->real_oauth_guid = $info['xoauth_yahoo_guid'];

        $contacts = $this->get_contacts($this->consumer_key, $this->consumer_secret, $this->real_oauth_guid, $this->real_oauth_token, $this->real_oauth_secret, false, true);
        $contacts = json_decode($contacts[2])->contacts;
        $count = $contacts->total;
	    #$res .= '<a href="#" id="check-all">Check all</a> / <a href="#" id="check-none">None</a>';
        $res .= '<ul id="blah">';
        $list = array();
        if (isset($contacts->contact) && !empty($contacts->contact)) {
	        foreach ($contacts->contact AS $key => $person) {
	            $name = $this->find_name($person->fields);
	            foreach ($person->fields AS $key => $data) {
	                if ($data->type == 'email') {
	                	$list["{$data->value}"] = $name;
	                }
	            }
	        }
	    }

	    ksort($list);
	    foreach ($list AS $email => $name) {
	      $res .= '
	      <li>
	        <input type="checkbox" class="email-checkbox" checked="checked" name="emails[]" value="' . $email . '" id="' . $this->clean_email($email) . '" />
	        <strong>' . $email . '</strong>
	        <span>' . $name . '</span>
	      </li>';
	    }

        $res .= '</ul>';

        echo '<html>';
        echo '<head>';
        echo <<< html
<script type="text/javascript" src="http://code.jquery.com/jquery-1.7.2.min.js"></script>
        <script>
	$(document).ready(function() {
		var r = $('#response').html();
		if (window.opener !== null) {
		    $('#response', window.opener.document).show().html(r);
		    window.opener.prepare_clicks();
		    $('#check-area, #send-emails, #submit-emails-block', window.opener.document).show();
		    $('#loading', window.opener.document).hide();
		    window.close();
		}
		else {
			$('#response').show().html(r);
			prepare_clicks();
			$('#check-area, #send-emails, #submit-emails-block').show();
			$('#loading').hide();
		}
    });
</script>
</head>
<body>
html;
        echo '<div id="response">' . $res . '</div></body></html>';
        exit;
    }

    private function find_name(&$list) {
            foreach ($list AS $key => $data) {
                    if ($data->type == 'name') {
                            unset($list[$key]);
                            return $data->value->givenName . ' ' . $data->value->familyName;;
                    }
            }
    }

	private function get_request_token($consumer_key, $consumer_secret, $callback, $usePost=false, $useHmacSha1Sig=true, $passOAuthInHeader=false) {
	  $retarr = array();  // return value
	  $response = array();

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

	private function get_access_token($consumer_key, $consumer_secret, $request_token, $request_token_secret, $oauth_verifier, $usePost=false, $useHmacSha1Sig=true, $passOAuthInHeader=true)
	{
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

	private function get_contacts($consumer_key, $consumer_secret, $guid, $access_token, $access_token_secret, $usePost=false, $passOAuthInHeader=true)
	{
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
	    logit("callcontact:INFO:request_url:$request_url");
	    logit("callcontact:INFO:post_body:$query_parameter_string");
	    $headers[] = 'Content-Type: application/x-www-form-urlencoded';
	    $response = do_post($request_url, $query_parameter_string, 80, $headers);
	  } else {
	    $request_url = $url . ($query_parameter_string ?
	                           ('?' . $query_parameter_string) : '' );
	    logit("callcontact:INFO:request_url:$request_url");
	    $response = do_get($request_url, 80, $headers);
	  }

	  // extract successful response
	  if (! empty($response)) {
	    list($info, $header, $body) = $response;
	    if ($body) {
	      logit("callcontact:INFO:response:");
	      print(json_pretty_print($body));
	    }
	    $retarr = $response;
	  }

	  return $retarr;
	}
}

$yahoo = new yahooauth();

?>