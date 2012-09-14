<?php $s = contact_scraper::get_services(); ?>
<!doctype html>
<html>
  <head>
    <script src="http://code.jquery.com/jquery.js"></script>    
    <script src="https://apis.google.com/js/client.js"></script>
    <script src="/<?php echo drupal_get_path('module', 'dosomething_contact_picker'); ?>/js/picker.js"></script>
    <link rel="stylesheet" type="text/css" href="/<?php echo drupal_get_path('module', 'dosomething_contact_picker'); ?>/css/picker.css" />
    <?php echo $s['scripts']; ?>
  </head>
  <body>
    <h1 id="connect-message">Connect your email address book to email your contacts.</h1>
    <p id="having-trouble">Having trouble? Try disabling your pop-up blocker for DoSomething.org.</p>
<div id="socials">
<?php echo $s['services']; ?>
</div>
<p id="client-email-link"><?php echo $client_email; ?></p>
<form action="/invite-by-email-scraper/<?php echo $nid; ?>" method="post">
<input type="hidden" name="do" value="email" />
<textarea name="emails" id="email_list" style=" width: 500px; height: 200px"></textarea>
<textarea name="real_emails" id="re"></textarea>
<!--<div id="choices">You may choose <span id="choices-left">5</span> more peeps.</div>-->
<div id="check-area"><a href="#" id="check-all">Check all</a> / <a href="#" id="check-none">None</a></div>
<p id="loading"></p>
<div id="response"></div>

<p><input type="submit" onclick="return submit_emails()" value="Invite" id="send-emails" /></p>
</form>
  </body>
</html>