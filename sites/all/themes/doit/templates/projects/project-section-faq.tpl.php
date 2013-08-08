<section class="campaign-section faq full-width" id="faq">
  <h2 class="section-header"><span><?php print $node->field_faq_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>
  <div class="content-center">
    <?php foreach ($faq_items as $faq): ?>
    <div class="answer">
      <h4><?php print $faq['title']; ?></h4>
      <p><?php print $faq['copy']; ?></p>
    </div>
    <?php endforeach; ?>
  </div>

  <div class="callout">
    <a href="#headline" class="btn primary large js-jump-scroll"><?php print $node->field_faq_button_label[LANGUAGE_NONE][0]['value']; ?></a>
    <p><a href="#top" class="btn-top js-jump-scroll">Back to Top</a></p>
  </div>
</section>
