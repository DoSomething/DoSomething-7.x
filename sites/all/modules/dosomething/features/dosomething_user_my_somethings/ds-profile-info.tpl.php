<div class="edit-profile"><a class="ds-button-strong" href="/user/<?php print $account->uid; ?>/edit/main">Edit Profile</a></div>
<div class="member-details">
  <ul>
    <li class="place"><label>Hometown:</label><span><?php print $hometown; ?></span></li>
    <li class="place"><label>School:</label><span>West High School</span></li>
  </ul>
  <ul>
    <li class="stat"><label>Member Status:</label><span><?php print $member_status; ?></span></li>
    <li class="stat"><label>Member Since:</label><span><?php print $member_since; ?></span></li>
  </ul>
</div>
<div class="member-activity">
  <ul>
   <?php /* <li><label>Issues I rock:</label><span></span></li> */ ?>
    <li><label>My DoSomething friends:</label></label><span><?php print $member_friends; ?><span><a class="invite-friends" href="/invite-friends">invite friends</a></span></li>
   <?php /* <li><label>Somethings they're doing:</label><span></span></li> */ ?>
</ul>
</div>
