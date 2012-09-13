<!doctype html>
<html>
  <head>
    <script src="http://code.jquery.com/jquery.js"></script>    
    <script src="https://apis.google.com/js/client.js"></script>
    <script src="/<?php echo drupal_get_path('module', 'dosomething_contact_picker'); ?>/js/picker.js"></script>
    <link rel="stylesheet" type="text/css" href="/<?php echo drupal_get_path('module', 'dosomething_contact_picker'); ?>/css/picker.css" />
  </head>
  <body>
    <h1>Find Contacts through Email</h1>
    <p>Click on the Gmail or Yahoo! logo below, log in, and we'll find your contacts for you.  Make sure you have your popup blocker disabled for DoSomething.org!</p>
<div id="socials">
<a href="#" onclick="return auth('gmail')" id="gmail">Find contacts on GMail</a>
<a href="#" onclick="return auth('yahoo')" id="yahoo">Find contacts on Yahoo!</a>
</div>

<p><?php echo $client_email; ?></p>
<form action="/invite-by-email-scraper/<?php echo $nid; ?>" method="post">
<input type="hidden" name="do" value="email" />
<textarea name="emails" id="email_list" style=" width: 500px; height: 200px"></textarea>
<textarea name="real_emails" id="re"></textarea>
<!--<div id="choices">You may choose <span id="choices-left">5</span> more peeps.</div>-->
<div id="check-area"><a href="#" id="check-all">Check all</a> / <a href="#" id="check-none">None</a></div>
<p id="loading"></p>
<div id="response"></div>

<p><input type="submit" onclick="return submit_emails()" value="Send emails" id="send-emails" /></p>
</form>
  </body>
</html>