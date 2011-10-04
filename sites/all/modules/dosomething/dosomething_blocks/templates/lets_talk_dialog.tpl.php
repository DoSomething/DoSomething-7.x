+<?php
/**
 * @file
 * Content for Let's Talk dialog popup. 
 */
?>

<div id="lets-talk-dialog">
  <div id="lets-talk">
    <h2><?php print t('Let\'s Talk'); ?></h2>
    <div class="left-coloumn">
      <div class="lets-talk-text">
        <span class="title"><?php print t('Text with us...'); ?></span><span class="desc"><?php print t('Text HELPME to 30644'); ?></span>
      </div>
      <div class="lets-talk-chat">
        <span class="title"><?php print t('Chat with us...'); ?></span><span class="desc"><?php print t('Click <a href="NEEDLINK">here</a> to chat live'); ?> </span>; 
      </div>
      <div class="lets-talk-email">
        <span class="title"><?php print t('Email us...'); ?></span><span class="desc"><?php print l('helpme@dosomething.org', 'mailto:helpmedosomething.org'); ?> </span>
      </div>
    </div>
    <div class="right-coloumn">
      <div class="lets-talk-phone">
        <span class="title"><?php print t('Talk to us...'); ?></span><span class="desc"><?php print '(212) 254-2390'; ?></span>
      </div>
      <div class="lets-talk-faq">
        <span class="title"><?php print l('Frequently Asked Questions', 'NEEDLINK'); ?></span>
      </div>
    </div>
  </div> <!-- /#lets-talk -->
  <h2><?php print t('About Do Something'); ?></h2>
  <div class="lets-talk-about">
    <?php print t('Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque at neque sed metus rutrum adipiscing nec ut erat. Suspendisse adip'); ?>
  </div>
</div> <!-- /#lets-talk-dialog -->

