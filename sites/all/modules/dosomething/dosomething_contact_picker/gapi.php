<?php

function clean_email($email) {
  $email = preg_replace('#[^A-Za-z0-9\-\_]#i', '_', $email);
  return $email;
}

$node = json_decode(base64_decode(($_GET['nid']))); 

if ($_POST['do'] == 'blah') {
  $add = '';
  if (strpos($_SERVER['HTTP_HOST'], 'qa') !== FALSE) {
    $add = 'qa2/';
  }
  require_once '/var/www/html/' . $add . '/google-api-php-client/src/apiClient.php';
  require_once '/var/www/html/' . $add . '/google-api-php-client/src/contrib/apiPlusService.php';

  $client = new apiClient();
  $client->setApplicationName('Google Contacts Test');
  $client->setScopes('http://www.google.com/m8/feeds');

  $client->setClientId('1000659299351.apps.googleusercontent.com');
  $client->setClientSecret('sp-8HDxoUCFZH1bH9XOUuglO');
  $client->setRedirectUri('http://' . $_SERVER['HTTP_HOST'] . '/sites/all/modules/dosomething/dosomething_contact_picker/gapi.php');

  $k = $_POST['key'];
  $key = json_encode(array(
    'access_token' => $k['access_token'],
    'token_type' => $k['token_type'],
    'expires_in' => $k['expires_in'],
    'created' => time()
  ));
  $client->setAccessToken($key);

  if ($client->getAccessToken()) {
    $req = new apiHttpRequest('https://www.google.com/m8/feeds/contacts/default/full');
    $val = $client->getIo()->authenticatedRequest($req);

    $response = ($val->getResponseBody());

    // Names
    preg_match_all('#type\=\'text\'\>([^(<]*)\<\/title\>#i', $response, $titles);
    // Emails
    preg_match_all('#address\=\'([^>\']+)\'#i', $response, $emails);
    // Unset and reset don't play nicely, so let's just chop the first item.
    $titles = array_slice($titles[1], 1);
    reset($titles);

    #$res .= '<a href="#" id="check-all">Check all</a> / <a href="#" id="check-none">None</a>';
    $res .= '<ul id="blah">';
    foreach ($emails[1] AS $key => $email) {
      $res .= '
      <li>
        <input type="checkbox" class="email-checkbox" checked="checked" name="emails" value="' . $email . '" id="' . clean_email($email) . '" />
        <strong>' . $email . '</strong>
        <span>' . $titles["$key"] . '</span>
      </li>';
    }
    $res .= '</ul>';

    echo $res;
  }
  exit;
}

?>
