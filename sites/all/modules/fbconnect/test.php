<?php
require '/var/www/dosomething/webroot/sites/all/libraries/facebook/facebook.php';
 
  $facebook = new Facebook(array(
    'appId'  => '160632053975149',
    'secret' => '63c5ac4d7c73f0f6500a52ebf2b744ad',
   ));

// See if there is a user from a cookie
$user = $facebook->getUser();
print_r($user);

if ($user) {
  try {
    // Proceed knowing you have a logged in user who's authenticated.
    $user_profile = $facebook->api('/me');
  } catch (FacebookApiException $e) {
    echo '<pre>'.htmlspecialchars(print_r($e, true)).'</pre>';
    $user = null;
  }
}

?>

<!DOCTYPE html>
<html xmlns:fb="http://www.facebook.com/2008/fbml">
  <body>
    <?php if ($user_profile) { ?>
      Your user profile is 
      <pre>            
        <?php print htmlspecialchars(print_r($user_profile, true)) ?>
      </pre> 
    <?php } else { ?>
      <fb:login-button size="small"></fb:login-button>
    <?php } ?>
    <div id="fb-root"></div>
    <script>               
      window.fbAsyncInit = function() {
        FB.init({
          appId: '<?php echo $facebook->getAppID() ?>', 
          cookie: true, 
          xfbml: true,
          oauth: true
        });
        FB.Event.subscribe('auth.login', function(response) {
          window.location.reload();
        });
        FB.Event.subscribe('auth.logout', function(response) {
          window.location.reload();
        });
      };
      (function() {
        var e = document.createElement('script'); e.async = true;
        e.src = document.location.protocol +
          '//connect.facebook.net/en_US/all.js';
        document.getElementById('fb-root').appendChild(e);
      }());
    </script>
  </body>
</html>
