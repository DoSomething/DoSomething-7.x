<section class="campaign-section sms full-width" id="sms">
  <div class="content-center">
    <p class="section-intro"><?php print $node->field_sms_referral_info_copy[LANGUAGE_NONE][0]['value']; ?></p>

    <form action="//dosomething.mcommons.com/profiles/join" method="POST" class="form-default">
      <input type="hidden" name="redirect_to" value="mango">

      <div class="two-col">
        <label>Your First Name:</label>
        <input type="text" name="person[first_name]" placeholder="Your name:">
      </div>

      <div class="two-col">
        <label>Your Cell #:</label>
        <input type="text" name="person[phone]" placeholder="Your cell #:">
      </div>

      <div class="one-col">
        <label>Friend's Cell #s:</label>
      </div>

      <div class="two-col">
        <input type="text" name="friends[]" placeholder="Friend's cell #:">
        <input type="text" name="friends[]" placeholder="Friend's cell #:">
        <input type="text" name="friends[]" placeholder="Friend's cell #:">
      </div>

      <div class="two-col">
        <input type="text" name="friends[]" placeholder="Friend's cell #:">
        <input type="text" name="friends[]" placeholder="Friend's cell #:">
        <input type="text" name="friends[]" placeholder="Friend's cell #:">
      </div>

      <div class="one-col callout">
        <input type="hidden" name="opt_in_path" value="mango">
        <input type="hidden" name="friends_opt_in_path" value="mango">

        <input type="submit" class="btn primary large" value="invite friends">

        <p><a class="official-rules" href="mango" target="_blank">Official Rules &amp; Regulations</a></p>
        <p class="legal"><?php print $node->field_sms_referral_ctia_copy[LANGUAGE_NONE][0]['value']; ?></p>
      </div>
    </form>
   </div>
</section>