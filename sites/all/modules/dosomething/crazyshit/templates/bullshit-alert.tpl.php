<h2><?php if ($you) { ?>You called BS on...yourself?<?php } else { ?>Someone Called BS!<?php } ?></h2>
<p><?php if ($you) { ?>Are you going to challenge yourself like that?</p><p>Invite a friend to vouch for your story (someone that believes your story more than you do.)</p><?php } else { ?>Someone called BS on your story! Are you going to let someone challenge your honor like that? A good story deserves to live on.</p>
<p>Invite a friend who can vouch for you.</p><?php } ?>
<p><a href="#" class="fb-invite-friends" onclick="return fb_invite_friends_post(<?php echo $sid; ?>)">Invite Friends</a></p>
