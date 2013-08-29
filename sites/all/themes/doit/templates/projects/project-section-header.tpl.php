<section class="header" id="header">
  
  <h1 class="header-logotype" <?php print $h1_style; ?>><?php print $node->title; ?></h1>

  <?php if ($logo_uri): ?>
  <img class="header-logotype" src="<?php print $logo_uri; ?>" alt="<?php print $logo_alt; ?>" />
  <?php endif; ?>

  <p class="header-date">
    <?php print $project_date; ?>
  </p>

  <div class="header-social">
    <!-- Facebook Like Button -->
    <div class="fb-like fb_edge_widget_with_comment fb_iframe_widget" data-href="http://developers.facebook.com/docs/reference/plugins/like" data-send="false" data-layout="button_count" data-width="90" data-show-faces="false" fb-xfbml-state="rendered"><span style="height: 20px; width: 88px;"><iframe id="f76b1fd7" name="f3f6556488" scrolling="no" title="Like this content on Facebook." class="fb_ltr" src="http://www.facebook.com/plugins/like.php?api_key=193555714029599&amp;locale=en_US&amp;sdk=joey&amp;channel_url=http%3A%2F%2Fstatic.ak.facebook.com%2Fconnect%2Fxd_arbiter.php%3Fversion%3D25%23cb%3Df362ea0734%26origin%3Dhttp%253A%252F%252Fds-neue.local%252Ff3d565afbc%26domain%3Dds-neue.local%26relation%3Dparent.parent&amp;href=http%3A%2F%2Fdevelopers.facebook.com%2Fdocs%2Freference%2Fplugins%2Flike&amp;node_type=link&amp;width=90&amp;layout=button_count&amp;colorscheme=light&amp;show_faces=false&amp;send=false&amp;extended_social_context=false" style="border: none; overflow: hidden; height: 20px; width: 88px;"></iframe></span></div>
    <!-- Twitter Tweet Button -->
    <div class="header-twitter-share">
      <iframe allowtransparency="true" frameborder="0" scrolling="no" src="http://platform.twitter.com/widgets/tweet_button.1374787011.html#_=1375730235388&amp;count=none&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer=http%3A%2F%2Fds-neue.local%2Fcampaigns.html&amp;size=m&amp;text=1%20in%206%20people%20in%20America%20will%20go%20hungry%20at%20some%20point%20during%20the%20year.%20Help%20%40dosomething%20about%20feeding%20the%20hungry%3A%20http%3A%2F%2Fwww.dosomething.org%2Fpbj&amp;url=http%3A%2F%2Fwww.dosomething.org%2Fpbj" class="twitter-share-button twitter-count-none" title="Twitter Tweet Button" data-twttr-rendered="true" style="width: 56px; height: 20px;"></iframe>
      <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
    </div>
  </div>
</section>