<section class="campaign-section sms-game-example full-width" id="sms-game-example">
  <h2 class="section-header"><span><?php print $node->field_sms_example_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>

  <div class="content-center narrow">
    <?php foreach ($node->field_sms_example_message[LANGUAGE_NONE] as $key => $message): ?>
    <div class="game-conversation <?php print ($key % 2 == 0) ? 'game-ds' : 'game-user'; ?>">
      <p><?php print $message['value']; ?></p>
    </div>
    <?php endforeach; ?>
  </div>

  <div class="callout">
    <a href="#headline" class="btn primary large js-jump-scroll"><?php print $node->field_sms_example_button_label[LANGUAGE_NONE][0]['value']; ?></a>
  </div>
</section>