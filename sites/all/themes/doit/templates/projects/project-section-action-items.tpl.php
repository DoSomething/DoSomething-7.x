<section class="campaign-section how-it-works full-width" id="how-it-works">
  <h2 class="section-header"><span><?php print $node->field_action_items_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>

  <section class="how-it-works-container">

    <?php foreach ($action_items as $action_item): ?>
    <div class="three-col block">
      <img src="<?php print $action_item['image']['uri']; ?>" alt="<?php print $action_item['image']['alt']; ?>">
      <h3><?php print $action_item['title']; ?></h3>
      <?php print $action_item['copy']; ?>
    </div>
    <?php endforeach; ?>

  </section>

  <div class="action-kit callout" id="action-kit">
    <?php print $node->field_action_kit_copy[LANGUAGE_NONE][0]['value']; ?>
  </div>
</section>
