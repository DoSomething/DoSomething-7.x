<section class="campaign-section sms full-width" id="sms">
  <div class="content-center">
    <p class="section-intro"><?php print $node->field_sms_referral_info_copy[LANGUAGE_NONE][0]['value']; ?></p>
    <?php print drupal_render($sms_referral_form); ?>
    <p><a class="official-rules" href="mango" target="_blank">Official Rules &amp; Regulations</a></p>
    <p class="legal"><?php print $node->field_sms_referral_ctia_copy[LANGUAGE_NONE][0]['value']; ?></p>
   </div>
</section>