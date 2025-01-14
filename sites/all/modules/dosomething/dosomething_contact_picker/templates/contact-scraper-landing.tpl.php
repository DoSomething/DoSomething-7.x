<?php $path = drupal_get_path('module', 'dosomething_contact_picker'); ?>
<!doctype html>
<html>
 <head>
  <script type="text/javascript">
  <!--
    var e_body = "<?php echo ($email_body); ?>";
    var e_title = "<?php echo ($email_title); ?>";
    var path = '/<?php echo $path; ?>';
  -->
  </script>

  <script src="/<?php echo $path; ?>/js/jquery.min.js"></script>    
  <script src="/<?php echo $path; ?>/js/dosomething_contact_picker_portal.js"></script>
  <link rel="stylesheet" type="text/css" href="/<?php echo $path; ?>/css/dosomething_contact_picker_portal.css" />
  <?php echo $scripts; ?>
 </head>
<body>

<h1><?php echo t('Connect your email address book to email your contacts:'); ?></h1>

<div id="socials">
  <div class="service"><a href="#" onclick="return DS.ContactPicker.service('google')"><img class="service-image" src="/<?php echo $path; ?>/services/google/google.png" alt=""><?php echo t('Get Gmail contacts'); ?></a></div>
  <div class="service"><a href="#" onclick="return DS.ContactPicker.service('yahoo')"><img class="service-image" src="/<?php echo $path; ?>/services/yahoo/yahoo.png" alt=""><?php echo t('Get Yahoo! Mail contacts'); ?></a></div>
</div>

<p id="client-email-link"><?php echo $client_email; ?></p>

<form action="/contact-picker/invite/<?php echo $nid; ?>" method="post">
<input type="hidden" name="type" value="<?php echo $type; ?>" />
<input type="hidden" name="hash" value="<?php echo $hash; ?>" />

<div class="check-area">
  <div class="search"><input type="search" name="search" id="search-contacts" placeholder="<?php echo t('Search your contacts...'); ?>" /></div>
  <a href="#" class="check-all"><?php echo t('Check all'); ?></a>
  / <a href="#" class="check-none"><?php echo t('None'); ?></a>
</div>

<p id="loading"></p>
<div id="response">&nbsp;</div>

<div class="check-area below">
  <a href="#" class="check-all"><?php echo t('Check all'); ?></a>
  / <a href="#" class="check-none"><?php echo t('None'); ?></a>
</div>

<p class="invite-button"><input type="submit" value="<?php echo t('Invite'); ?>" id="send-emails" /></p>
<p class="rather"><a href="#" onclick="return window.parent.load_fb();"><?php echo t("I'd rather share on Facebook"); ?></a></p>

</form>

</body>
</html>
