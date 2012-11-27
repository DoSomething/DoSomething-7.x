<?php

function clean_email($email) {
  $email = preg_replace('#[^A-Za-z0-9\-\_]#i', '_', $email);
  return $email;
}

$node = json_decode(base64_decode(($_GET['nid']))); 
function associate_emails($emails, $names) {
  foreach ($emails AS $key => $email) {
    $list["$email"] = $names["$key"];
  }

  ksort($list);
  return $list;
}

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
    $req = new apiHttpRequest('https://www.google.com/m8/feeds/contacts/default/full?max-results=1000');
    if (!$val = $client->getIo()->authenticatedRequest($req)) {
      echo "Please refresh the page and log back in to Google.";
      exit;
    }

    $xml = ($val->getResponseBody());
    $res .= '<ul id="blah">';
    $vals = array();
    preg_match_all('#<entry>(.*?)</entry>#si', $xml, $entries);
    foreach ($entries[1] AS $key => $entry) {
      preg_match('#\<title type\=("|\'|)text(\\1)\>(.*?)\<\/title\>#i', $entry, $name);
      preg_match('#<gd\:email([^(<]*)(address\=("|\'|)([^("|\'|)]*))#i', $entry, $email);

      $n = $name[3];
      $e = $email[4];

      $vals[strtolower($e)] = array(
        'e' => $e,
        'n' => $n
      );
    }

    ksort($vals);
    foreach ($vals AS $e => $s) {
      if (!empty($s['e'])) {
        $res .= '
        <li>
          <input type="checkbox" class="email-checkbox" checked="checked" name="emails[]" value="' . $s['e'] . '" id="' . clean_email($s['e']) . '" />
          <strong>' . $s['e'] . '</strong>
          <span>' . $s['n'] . '</span>
        </li>';
      }
    }

    $res .= '</ul>';

    echo $res;
  }
  exit;
}

?>
