<?php $path = drupal_get_path('module', 'dosomething_contact_picker'); ?>
<!doctype html>
<html>
  <head>
      <link rel="stylesheet" type="text/css" href="/<?php echo $path; ?>/css/dosomething_contact_picker_portal.css" />
  </head>
  <body>
    <script type="text/javascript">
    <!--
        window.parent.close_scraper_and_load_long_form();
    -->
    </script>
    <h1><?php echo t('Done.'); ?></h1>
    <p><?php echo t("Thanks for inviting your friends.  Every friend that you invite helps to make a difference in this world.  They'll invite their friends, who will invite their friends...you get the idea."); ?></p>
    <p><b><?php echo t('Now share with your friends on Facebook:'); ?></b></p>

    <p><a href="# " id="petition-fb"><?php echo t('Share on Facebook'); ?></a></p>

    <p><?php echo t('Or you can always !invite.', array('!invite' => l(t('invite more email contacts'), 'contact-picker/' . $nid))); ?></p>
</body>
</html>