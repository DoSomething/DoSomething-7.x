<section class="campaign-section content full-width" id="content">
  <h2 class="section-header"><span><?php print $node->field_project_info_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>
  <div class="content-center">
    <p><?php print $node->field_project_info_copy[LANGUAGE_NONE][0]['value']; ?></p>

    <?php foreach ($project_info_items as $item): ?>
    <h4 class="headline-callout"><?php print $item['title']; ?></h4>
    <p><?php print $item['copy']; ?></p>
    <?php endforeach; ?>

  </div>
</section>