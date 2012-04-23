<?php
/**
 * @file
 * Content for Let's Talk dialog popup.
 */
?>

<div id="lets-talk-dialog">
  <h2 id="title">Let's Talk</h2>
  <div id="content">
    <div class="row">
      <span class="title"><?php print t('Confused?'); ?></span><span class="detail"><?php print ('<a href="/faqs">FAQs</a> or <a href="blog/check-out-our-new-do">Read what\'s new</a>'); ?></span>
    </div>
   <div class="row">
      <span class="title"><?php print t('Online'); ?></span><span class="detail"><?php print t('<a href="/help-ticket">Submit a ticket</a>'); ?></span>
    </div>
    <div class="row">
      <span class="title"><?php print t('Text'); ?></span><span class="detail"><?php print t('text HELPME to 38383'); ?></span>
    </div>
    <div class="row">
      <span class="title"><?php print t('Email'); ?></span><span class="detail"><?php print l('helpme@dosomething.org', 'mailto:helpmedosomething.org'); ?></span>
    </div>
    <div class="row">
      <span class="title"><?php print t('Phone'); ?></span><span class="detail"><?php print '(212) 254-2390'; ?></span>
    </div>
  </div> <!-- /#lets-talk-content -->
</div> <!-- /#lets-talk-dialog -->