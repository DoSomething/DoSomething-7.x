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
      <span class="title"><?php print t('Online'); ?></span><span class="detail"><?php print t('<a href="/help-ticket">Submit an error ticket</a>'); ?></span>
    </div>

    <div class="row">
      <span class="title"><?php print t('Text'); ?></span><span class="detail"><?php print t('text QUESTION to 38383'); ?></span>
    </div>

    <div class="row">
      <span class="title"><?php print t('General Email'); ?></span><span class="detail"><?php print l('helpme@dosomething.org', 'mailto:helpme@dosomething.org'); ?></span>
      
      <br><span class="title"><?php print t('Press or Marketing Inquires'); ?></span><span class="detail"><?php print l('press@dosomething.org', 'mailto:press@dosomething.org'); ?></span>

      <br><span class="title"><?php print t('Clubs'); ?></span><span class="detail"><?php print l('clubs@dosomething.org', 'mailto:clubs@dosomething.org'); ?></span>

      <br><span class="title"><?php print t('Grant Program'); ?></span><span class="detail"><?php print l('grants@dosomething.org', 'mailto:grants@dosomething.org'); ?></span>

    </div>

    <div class="row">
      <span class="title"><?php print t('Phone'); ?></span><span class="detail"><?php print '(212) 254-2390'; ?></span>
    </div>

  </div> <!-- /#lets-talk-content -->
</div> <!-- /#lets-talk-dialog -->
