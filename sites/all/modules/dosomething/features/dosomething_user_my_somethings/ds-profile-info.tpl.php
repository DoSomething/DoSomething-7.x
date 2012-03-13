<div class="dosomething-stats member-profile">
  <?php print render($member_percentage); ?>
  <div>
    <img class="mem-img" />
    <div class="mem-details">
      <span class="mem-name"><?php print $member_fullname; ?></span>
      <ul class="upper">
        <li><span><?php print $hometown; ?></span>, <span><?php print $member_school; ?></span></li>
        <li><span class="mem-clubs"><?php print render($member_clubs); ?></span></li>
      </ul>
      <ul class="lower">
        <li><span>Member Status</span><span class="mem-stat"><?php print $member_status; ?></span></li>
        <li><span>Member Since</span><span class="mem-since"><?php print $member_since; ?></span></li>
      </ul>
      <a class="update-profile" href="/user/<?php print $account->uid; ?>/edit/main">Update profile >></a>
    </div>
    <div class="vital-stats"></div>
  </div>
</div>
