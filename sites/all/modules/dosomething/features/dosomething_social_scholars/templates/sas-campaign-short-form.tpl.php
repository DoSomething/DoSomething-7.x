<form class="webform-client-form" enctype="multipart/form-data" action="/sas-redirect?from_nid=<?php echo $from_nid; ?>&amp;destination=<?php echo rawurlencode($alias); ?>" method="post" id="webform-client-form-<?php echo $nid; ?>" accept-charset="UTF-8">
<div>
<div class="form-item webform-component webform-component-markup" id="webform-component-start-header">
 <h3>Start here to join your school</h3>
</div>
<div class="field-type-email field-name-field-webform-email field-widget-email-textfield form-wrapper" id="edit-submitted-field-webform-email">
<div id="submitted-field-webform-email-add-more-wrapper" class="ds-processed">
<div class="text-full-wrapper">
<div class="form-item form-type-textfield form-item-submitted-field-webform-email-und-0-email">
<input placeholder="Email (required)" type="text" id="edit-submitted-field-webform-email-und-0-email" name="submitted[field_webform_email][und][0][email]" value="<?php echo $email; ?>" size="60" maxlength="128" class="form-text required">
</div>
</div>
</div>
</div>
<div class="field-type-text field-name-field-webform-mobile field-widget-telwidget form-wrapper" id="edit-submitted-field-webform-mobile">
<div id="submitted-field-webform-mobile-add-more-wrapper" class="ds-processed">
<div class="form-item form-type-telfield form-item-submitted-field-webform-mobile-und-0-value">
<input placeholder="Cell (optional)" type="tel" id="edit-submitted-field-webform-mobile-und-0-value" name="submitted[field_webform_mobile][und][0][value]" value="<?php echo $mobile; ?>" size="20" maxlength="64" class="form-text form-tel">
</div>
</div>
</div>
<input type="hidden" name="details[sid]" value="">
<input type="hidden" name="mailchimp_bucket" value="<?php echo $mailchimp_bucket; ?>" />
<div class="form-actions form-wrapper">
	<input type="submit" id="edit-submit" name="op" value="start" class="form-submit">
</div>
<p class='ctia'>Sign up to receive weekly updates. Msg &amp; data rates may apply. Text STOP to opt-out, HELP for help.</p>
</div>
</form>
