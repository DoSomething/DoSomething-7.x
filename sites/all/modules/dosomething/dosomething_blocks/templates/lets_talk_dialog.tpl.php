<?php
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
        <span class="title"><?php print t('Chat with us...'); ?></span><span class="desc"><?php print t('Click <a href="/chat">here</a> to chat live'); ?></span>
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
    <div class="lets-talk-about-outter">
      <div class="lets-talk-about-inner">
        <?php print t('<p>Quisque facilisis erat a dui. Nam malesuada ornare dolor. Cras gravida, diam sit amet rhoncus ornare, erat elit consectetuer erat, id egestas pede nibh eget odio.</p>
        <p>Proin tincidunt, velit vel porta elementum, magna diam molestie sapien, non aliquet massa pede eu diam. Aliquam iaculis. Fusce et ipsum et nulla tristique facilisis.</p>'); ?>
      </div>
    </div>
  </div>
</div> <!-- /#lets-talk-dialog -->

