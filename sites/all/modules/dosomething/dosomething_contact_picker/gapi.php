<?php

function clean_email($email) {
  $email = preg_replace('#[^A-Za-z0-9\-\_]#i', '_', $email);
  return $email;
}

$node = json_decode(base64_decode(($_GET['nid'])));

if ($_POST['do'] == 'blah') {
  require_once '/var/www/html/google-api-php-client/src/apiClient.php';
  require_once '/var/www/html/google-api-php-client/src/contrib/apiPlusService.php';

  $client = new apiClient();
  $client->setApplicationName('Google Contacts Test');
  $client->setScopes('http://www.google.com/m8/feeds');

  $client->setClientId('1000659299351.apps.googleusercontent.com');
  $client->setClientSecret('sp-8HDxoUCFZH1bH9XOUuglO');
  $client->setRedirectUri('http://localhost:8080/gapi.php');
  #$client->setDevelopreKey

  #$client->setAccessToken(json_encode($_POST['key']));

  #$req = new apiHttpRequest('http://www.google.com/m8/feeds/contacts/default/ful');
  #$val = $client->getIo()->authenticatedRequest($req);

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

    $res = '<ul id="blah">';
    foreach ($emails[1] AS $key => $email) {
      $res .= '
      <li>
        <input type="checkbox" name="emails" value="' . $email . '" id="' . clean_email($email) . '" />
        <label for="' . clean_email($email) . '"><strong>' . $email . '</strong></label>
        <span>' . $titles["$key"] . '</span>
      </li>';
    }
    $res .= '</ul>';

    echo $res;
  }
  exit;
}
if ($_POST['do'] == 'email') {
  foreach (explode(',', $_POST['real_emails']) AS $email) {
    if (trim($email)) {
      mail(trim($email), 'HI THERE!', 'Hey Me.  How is it going?');
    }
  }
}

?>
<html>
  <head>
    <script src="http://code.jquery.com/jquery.js"></script>    
    <script src="https://apis.google.com/js/client.js"></script>
    <script>
      var authed = false;
      function auth(t) {
        if (t == 'gmail') {
          var config = {
            'client_id': '1000659299351.apps.googleusercontent.com',
            'scope': 'https://www.google.com/m8/feeds'
          };
          $('#response').show().html('<p style="text-align: center"><img src="/sites/all/modules/dosomething/dosomething_contact_picker/images/loading.gif" alt="" /> Loading.  Please wait...</p>');
          gapi.auth.authorize(config, function() {
            var t = gapi.auth.getToken();
            console.log('Login complete');
            console.log(t);
            token = t.access_token;
            
            $.post('gapi.php', { 'do': 'blah', 'key': t }, function(response) {
              $('#response').html(response);

              prepare_clicks();
            });
          });
        }
        else if (t == 'yahoo') {
          window.open('/sites/all/modules/dosomething/dosomething_contact_picker/yo/index.php', 'yahoo', 'width=500,height=350,scrollbars=no,resizeable=no,location=no,status=no,titlebar=no,toolbar=no');
        }

        return false;
      }

      function prepare_clicks() {
        $('#response').slideDown();
        $('ul#blah li:not(.clicked)').addClass('clicked').click(function() {
        var choices = parseInt($('#choices-left').text());
          var e = $(this).find('strong').html();
          if ($('#email_list').html().indexOf(e) == -1) {
        if (choices <= 0) {
          alert("You can't choose any more emails.  Uncheck some to add more.");
          return false;
        }
            $('#email_list').append(e + ', ');
            $(this).find('input').attr('checked', 'checked');
            $('#choices-left').text(choices - 1);
          }
          else {
            var t = $('#email_list').html();
            t = t.replace(e + ', ', '');
            $('#email_list').html(t);
            $(this).find('input').attr('checked', false);
            $('#choices-left').text(choices + 1);
          }
        });
      }


        function test() {
          var v = ($('#email_list').val());
          $('#re').val(v);
        }
    </script>
    <style type="text/css">
    <!--
      body { font-family: "Trebuchet MS"; font-size: 10pt; }
      ul { list-style-type: none; margin: 0px; padding: 0px; }
      li { clear: both; border-bottom: 1px solid #000000; padding: 10px; height: 20px;}
      li:hover { background: #EBEBEB; cursor: pointer; }
      li input { float: left; }
      li strong { float: left; }
      li span { float: right; }

      a#gmail {
        background: url(/sites/all/modules/dosomething/dosomething_contact_picker/images/gmail.png) top left no-repeat;
        text-decoration: none;
        display: inline-block;
        height: 35px;
        padding-left: 55px;
        width: 90px;
      }

      a#yahoo {
        background: url(/sites/all/modules/dosomething/dosomething_contact_picker/images/yahoo.jpg) top left no-repeat;
        text-decoration: none;
        display: inline-block;
        height: 35px;
        padding-left: 55px;
        width: 90px;
        margin-left: 50px;
      }

      div#choices { clear: both; }
      h1, p { text-align: center;}
      h1 { margin: 0px;}
      div#socials { 
        width: 345px;
        margin: 0px auto;
      }

      div#response {
        height: 355px;
        overflow: hidden;
        overflow: auto;
        display: none;
      }

      textarea { display: none; }
    -->
    </style>
  </head>
  <body>
    <h1>Find Contacts through Email</h1>
    <p>Click on the Gmail or Yahoo! logo below, log in, and we'll find your contacts for you.  Make sure you have your popup blocker disabled for DoSomething.org!</p>
<div id="socials">
<a href="#" onclick="return auth('gmail')" id="gmail">Find contacts on GMail</a>
<a href="#" onclick="return auth('yahoo')" id="yahoo">Find contacts on Yahoo!</a>
</div>
<p>I prefer to <a href="mailto:?subject=<?php echo ($node->title) . ' - Sign the petition!'; ?>&amp;body=<?php echo "Please join my campaign:\r\n\r\n" . $node->link; ?>">send my own email</a>.</p>
<form action="" method="post">
<input type="hidden" name="do" value="email" />
<textarea name="emails" id="email_list" style=" width: 500px; height: 200px"></textarea>
<textarea name="real_emails" id="re"></textarea>
<div id="choices">You may choose <span id="choices-left">5</span> more peeps.</div>
<div id="response"></div>

<p><input type="submit" onclick="return test()" value="Send emails" /></p>
</form>
  </body>
</html>