<div class="dosomething-stats member-profile">
  <?php print render($member_percentage); ?>
  <div class="mem-profile">
    <div class="mem-img"><?php print $member_picture; ?></div>
    <div class="dosomething-member-facts">
      <h2><?php print $member_fullname; ?></h2>
      <ul class="upper">
        <li><span><?php print $hometown; ?></span>, <span><?php print $member_school; ?></span></li>
        <li><span class="dosomething-member-misc"><?php print render($member_clubs); ?></span></li>
      </ul>
      <ul class="lower">
        <li><span>Member Status</span><span class="mem-stat"><?php print $member_status; ?></span></li>
        <li><span>Member Since</span><span class="mem-since"><?php print $member_since; ?></span></li>
      </ul>
      <a class="update-profile" href="/user/<?php print $account->uid; ?>/edit/main">Update profile »</a>
    </div>
    <?php print render($member_vitals); ?>
  </div>
</div>
