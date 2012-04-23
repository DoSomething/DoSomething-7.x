<div class="socialWrapper clearfix">
<div class="socialButton">
<div id="fb-root"></div>
<script>(function(d, s, id) { var js, fjs = d.getElementsByTagName(s)[0];if (d.getElementById(id)) return;js = d.createElement(s); js.id = id;js.src = "//connect.facebook.net/en_US/all.js#xfbml=1";fjs.parentNode.insertBefore(js, fjs);}(document, 'script', 'facebook-jssdk'));</script>

<div class="fb-like"
  data-send="false"
  data-layout="box_count"
  data-width="48"
  data-show-faces="false"
  data-font="trebuchet ms"
  data-href="<?php echo $url; ?>"
  data-description="<?php echo $facebook_language; ?>"
></div>
</div>


<div class="socialButton">
<a href="https://twitter.com/share" class="twitter-share-button" <?php /*data-url="<?php echo $url; ?>"*/ ?> data-text="<?php echo $twitter_language; ?>" data-count="vertical">Tweet</a>
<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
</div>


<div class="socialButton">
<g:plusone size="tall" href="<?php echo $url; ?>"></g:plusone>
<script type="text/javascript">(function() {var po = document.createElement('script'); po.type = 'text/javascript'; po.async = true;po.src = 'https://apis.google.com/js/plusone.js';var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(po, s);})();</script>
</div>
</div>

<div class="fb-facepile" data-href="http://www.dosomething.org" data-max-rows="1" data-width="247"></div>
