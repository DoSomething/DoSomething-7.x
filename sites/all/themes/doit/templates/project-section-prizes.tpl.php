<section class="campaign-section prizing full-width" id="prizing">
  <h2 class="section-header"><span><?php print $node->field_prizes_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>
  <p class="section-intro"><?php print $node->field_prizes_copy[LANGUAGE_NONE][0]['value']; ?></p>

  <div class="content-center">

    <?php foreach ($prizes as $key => $prize): ?>
    <div class="<?php print ($key == 0) ? 'one' : 'two'; ?>-col block">
      <img src="<?php print $prize['image']['uri']; ?>" alt="<?php print $prize['image']['alt']; ?>"/>
      <h2><?php print $prize['title']; ?></h2>
      <p><?php print $prize['copy']; ?></p>
    </div>
    <?php endforeach; ?>

    <div class="callout">
      <p><a href="#headline" class="btn primary large js-jump-scroll"><?php print $node->field_prizes_button_label[LANGUAGE_NONE][0]['value']; ?></a></p>
      <p><a href="<?php print $rules_url; ?>" class="official-rules">Official Rules &amp; Regulations</a></p>
    </div>

  </div>
</section>