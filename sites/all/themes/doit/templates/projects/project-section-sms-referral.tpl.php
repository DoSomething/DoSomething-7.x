<section class="campaign-section sms full-width" id="sms">
  <div class="content-center">
    <p class="section-intro"><?php print $node->field_sms_referral_info_copy[LANGUAGE_NONE][0]['value']; ?></p>
    <?php print render($sms_referral_form); ?>
    <p><a class="official-rules" href="mango" target="_blank">Official Rules &amp; Regulations</a></p>
    <p class="ctia legal">Message &amp; data rates may apply. Text <strong>STOP</strong> to opt-out, <strong>HELP</strong> for help.</p>
   </div>
</section>