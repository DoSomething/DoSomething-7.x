<?php

/**
 * @file
 * Node template file for the Project content type.
 *
 */
?>
<div role="main" id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> wrapper">

  <?php print render($content['header']); ?>

  <section class="headline" id="headline">
    <h2 class="headline-callout"><span><?php print $node->field_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>
    <h3 class="headline-callout"><span><?php print $node->field_subheadline[LANGUAGE_NONE][0]['value']; ?></span></h3>
  </section>

  <?php print render($content['sms_referral']); ?>

  <?php print render($content['cta']); ?>

  <?php if ($is_action_items): ?>
  <?php print render($content['action_items']); ?>
  <?php endif; ?>

  <?php if ($is_prizes): ?>
  <?php print render($content['prizes']); ?>
  <?php endif; ?>

  <?php print render($content['sms_example']); ?>

  <?php print render($content['gallery']); ?>

  <?php print render($content['project_info']); ?>

  <?php print render($content['project_profiles']); ?>

  <?php print render($content['faq']); ?>

  <?php print render($content['sponsors']); ?>

  <footer class="contact" id="footer">
    <p>Questions? E-mail <a href="mailto:help@dosomething.org">help@dosomething.org</a>!</p>
  </footer>

  <!--
  Edvisors tracking pixel
  @todo - Ideally this will be handled in a more automated fashion.  This
  can be achieved by Stashing the Edvisor offer id on the campaign and
  using a a standardize (but themable) webform confirmation page.
  @todo - add a http referrer check as well
  -->
  <!-- Offer Conversion: DoSomething.org -->
  <iframe src="http://tracking.edvisors.com/aff_l?offer_id=98" scrolling="no" frameborder="0" width="1" height="1"></iframe>
  <!-- // End Offer Conversion -->

</div>
