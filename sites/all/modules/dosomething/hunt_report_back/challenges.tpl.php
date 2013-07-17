<div class="section" id="info">
  <hr>
  <h2 class="titleline">The Actions</h2>
  <p class="sub">The actions will be released at 10:30am EST daily starting July 16th</p>

  <div id="challenges">
    <h3>What to do</h3>
    <p>Each day has two actions you can choose on one cause.</p>
    <p>The first action is about educating your friends and family on social media.</p>
    <p>The second is a real world action that helps your community.</p>
    <p>Do one or both! Make sure to take a picture of every community action you take (yknow, the non-Instagram ones) to upload below for your chance to be in our national commercial!</p>

    <?php foreach($challenges as $day => $challenge): ?>
    <h4 class="<?php print implode($challenge['classes'], ' '); ?>">Day <?php print $day; ?>: <?php print $challenge['name']; ?></h4>
    <div class="content">
      <img src="<?php print $challenge['image']; ?>" alt="<?php print $challenge['tag']; ?>" />
      <div class="copy">
        <span>Action 1:</span>
        <?php print $challenge['action_first']; ?>
        <span>Action 2:</span>
        <?php print $challenge['action_second']; ?>
        <div class="submit-challenge">
          <span>all done?</span>
          <a href="/hunt/challenges" class="go-button">show us what you did</a>
        </div> <!-- .submit-challenge -->
      </div> <!-- .copy -->
    </div> <!-- .content -->
    <?php endforeach; ?>

  </div> <!-- #challenges -->

</div> <!-- .section #info -->
