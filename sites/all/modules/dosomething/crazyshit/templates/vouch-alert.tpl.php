<h2>see your friends' stories</h2>
<p>Your friends have done some crazy things to save money. Connect with Facebook to see their stories.</p>
<p>Once connected, you will be able to help your friends by vouching for their story, or calling BS on them.</p>
<p>Think their story is crazy? Hit "Crazy" to add their story to the worldwide rankings.</p>
<p class="connect-with-facebook"><a href="https://www.facebook.com/dialog/oauth?client_id=<?php echo variable_get('fboauth_id'); ?>&redirect_uri=http://<?php echo CRAZY_DOMAIN ?>/fboauth/connect%3Fdestination%3D<?php echo $source; ?>&scope=email,user_birthday" onclick="return Drupal.behaviors.dsCrazyScripts.fb_status();">Connect with Facebook</a></p>