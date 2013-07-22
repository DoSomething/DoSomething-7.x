<?php

// Oh yeah! I am TOTALLY embedding this business logic in the main page.
if (!empty($_POST['url'])) {
  $url = trim($_POST['url']);
  
  $action = (empty($_POST['cache_action'])) ? 'check' : $_POST['cache_action'];
  
  if (!empty($url)) {
    $regex = "|^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?|";
  
    if (preg_match($regex, $url, $matches)) {
      $curl = curl_init($url);
      
      if ('purge' == $action) {
        curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "PURGE");
      }
      
      curl_setopt($curl, CURLOPT_FRESH_CONNECT, true);
      curl_setopt($curl, CURLOPT_HEADER, true);
      curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
      curl_setopt($curl, CURLOPT_TIMEOUT, 240);
      $curl_result = curl_exec($curl);
      
      // PURGE action.
      if ('purge' == $action) {
        // Successful response header should say,
        //      HTTP/1.1 200 Purged.
        // Look for that. Error otherwise.
        if (false !== strpos($curl_result, 'HTTP/1.1 200 Purged')) {
        
          $curl_status = 'URL has been cleared from Varnish.';
          $message = sprintf('SUCCESS: <a href="%s">%s</a><p>%s</p>', $url, $url, $curl_status);
        
        } elseif (false === $curl_result) {
        
          $message = "Sorry, &quot;{$url}&quot; doesn't look like a legitimate URL. Try again.";
      
        } else {
          // Get first line of error response.
          $lines = explode("\n", $curl_result, 2);
        
          $message = sprintf("Couldn't clear URL from Varnish. Response: %s", $lines[0]);
          
          if (false !== strpos($lines[0], '405')) {
            $message .= "</p><p style=\"color: red\">This means that Varnish isn't allowing purge 
              requests from whatever IP this web server is on. Alert the 
              authorities.";
          }
        
        }
      }
      
      // CHECK action.
      // We want to look for a few indicators of cache status:
      //  * The HTTP status code (Does it exist? Is it reachable? Error? etc.)
      //  * The X-Cache header, which is appended by the VCL to indicate 
      //    Varnish cache status (HIT / MISS)
      //  * The X-Drupal-Cache status (HIT / MISS)
      elseif ('check' == $action) {
        
        $results = array();
        
        // HTTP status
        $status_match = array();
        preg_match('|HTTP/1.1 (\d+)|', $curl_result, $status_match);
        
        if (!empty($status_match[1])) {
          switch ($status_match[1]) {
            case '200':
              $results['status'] = 'URL exists.';
              break;
            
            case '404':
              $results['status'] = "URL doesn't exist.";
              break;
            
            case '403':
              $results['status'] = "URL is restricted (login required).";
              break;
            
            case '301':
            case '302':
              $results['status'] = "URL redirects: ";
              
              $redirect_match = array();
              if (preg_match('|Location: (.+)|', $curl_result, $redirect_match)) {
                $results['status'] .= $redirect_match[1];
              } else {
                $results['status'] .= "Can't figure out where, though. Bummer.";
                // $results['status'] .= "<pre>" . $curl_result . "</pre>";
              }
              
              break;
            
            case '500':
              $results['status'] = "Server error!";
              break;  
              
          }
          
          // Varnish status.
          $varnish_match = array();
          if (preg_match('|X-Cache: ([A-Z]+)|', $curl_result, $varnish_match)) {
            if ('HIT' == $varnish_match[1]) {
              $results['varnish'] = 'Cached in Varnish.';
              
              // Varnish age.
              if (preg_match('|Age: (\d+)|', $curl_result, $varnish_match)) {
                $results['varnish age'] =
                  sprintf('Cached for %d seconds.', $varnish_match[1]);
              }
              
            } else {
              $results['varnish'] = 'Not cached in Varnish.';
            }
          } else {
            $results['varnish'] = 'Not served by Varnish.';
          }
          
          // Drupal cache status;
          $drupal_match = array();
          if (preg_match('|X-Drupal-Cache: ([A-Z]+)|', $curl_result, $drupal_match)) {
            if ('HIT' == $drupal_match[1]) {
              $results['drupal'] = 'Cached in Drupal.';
            } else {
              $results['drupal'] = 'Not cached in Drupal (does not affect Varnish cache status).';
            }
          } else {
            $results['drupal'] = 'Not served by Drupal.';
          }
          
          // Construct return message.
          $message = sprintf('Check URL: <a href="%s">%s</a></p>', $url, $url);
          
          $message .= '<dl>';
          foreach ($results as $header => $result) {
            $message .= sprintf('<dt><strong>%s</strong></dt><dd>%s</dd>',
              ucfirst($header), $result);
          }
          $message .= '</dl><p>';
        }
        
      }
      
    } else {
      
      $message = "Sorry, &quot;{$url}&quot; doesn't look like a legitimate URL. Try again.";
      
    }
  }
}

?>
<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Cashilator: Varnish cache management</title>
        <meta name="description" content="I manage yer Varnish.">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        
        <style>
          #url {
            width: 90%;
          }
          
          dt, dd {
            padding: 0.5em 0 0 0;
          }
          
          dt {
            float: left;
            width: 15%;
          }
          
          dd {
            float: left;
            width: 75%;
            -webkit-margin-start: 0;
          }
          
          dd:after {
            clear: both;
          }
          
          h1 {
            clear: both;
            margin-top: 1em;
          }
        </style>
    </head>
    <body>

        <?php if (!empty($message)): ?>
          <p style="color: red"><?php echo $message ?></p>
          <div style="clear: both"></div>
        <?php endif; ?>

        <!-- Add your site or application content here -->
        <h1>Cashilator</h1>
        
        <form action="" method="post" id="form-clear">
          <fieldset>
            <p>
              <label for="url">URL:</label>
              <input type="text" maxlength="255" id="url" name="url" required
                <?php if (!empty($url)): ?>value="<?php echo $url ?>"<?php endif; ?>>
            </p>
            <p>
              <label for="cache_action">Action:</label>
              <select name="cache_action" id="cache_action" required>
                <option value="check">Check cache status</option>
                <option value="purge">Purge URL</option>
              </select>
            </p>
            <p>
              <input type="submit" value="Submit">
            </p>
          </fieldset>
        </form>

        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
        <script>window.jQuery || document.write('<script src="js/vendor/jquery-1.10.2.min.js"><\/script>')</script>
    </body>
</html>
