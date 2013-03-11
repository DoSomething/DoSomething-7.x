<!doctype html>
<html>
 <head>
  <script src="/<?php echo drupal_get_path('module', 'dosomething_contact_picker'); ?>/js/jquery.min.js"></script>    
  <script src="/<?php echo drupal_get_path('module', 'dosomething_contact_picker'); ?>/js/picker.js"></script>
  <link rel="stylesheet" type="text/css" href="/<?php echo drupal_get_path('module', 'dosomething_contact_picker'); ?>/css/picker.css" />
  <?php echo $s['scripts']; ?>

  <script type="text/javascript">
  <!--
    var e_body = "<?php echo ($email_body); ?>";
    var e_title = "<?php echo ($email_title); ?>";
  -->
  </script>
 </head>
<body>
    <h1 id="connect-message">Connect your email address book to email your contacts:</h1>
<div id="socials">
<?php echo $s['services']; ?>
</div>
<p id="client-email-link"><?php echo $client_email; ?></p>
<form action="/invite-by-email-scraper/<?php echo $nid; ?>" method="post">
<input type="hidden" name="do" value="email" />
<textarea name="emails" id="email_list" style=" width: 500px; height: 200px"></textarea>
<textarea name="real_emails" id="re"></textarea>

<div id="check-area"><a href="#" id="check-all">Check all</a> / <a href="#" id="check-none">None</a></div>
<p id="loading"></p>
<div id="response" style="min-height: 10px">&nbsp;</div>
<p style="padding-bottom: 1px"><input type="submit" onclick="return submit_emails()" value="Invite" id="send-emails" /></p>

<p style="padding-top: 8px; clear: both; border-top: 1px solid #000; margin-top: 15px"><a href="#" onclick="return window.parent.load_fb();">I'd rather share on Facebook</a></p>
</form>
  </body>
</html>