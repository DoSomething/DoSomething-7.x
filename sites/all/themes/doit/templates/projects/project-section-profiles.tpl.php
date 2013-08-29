<section class="campaign-section profiles full-width" id="profiles">
  <h2 class="section-header"><span><?php print $node->field_project_profiles_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>

  <?php foreach($profiles as $profile): ?>
  <div class="column-break">
    <div class="three-col"><img src="<?php print $profile['image']['uri']; ?>" class="bordered" alt="<?php print $profile['image']['alt']; ?>"></div>
    <div class="three-col span-two">
     <h3><?php print $profile['title']; ?></h3>
     <p><?php print $profile['copy']; ?></p>
    </div>
  </div>
  <?php endforeach; ?>
</section>