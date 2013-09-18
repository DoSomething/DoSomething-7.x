<?php
/**
 * @file
 * Node template file for the Project content type.
 *
 */
?>

<div role="main" class="wrapper">
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">

    <?php print render($content['header']); ?>

    <section class="headline" id="headline">
      <?php if (isset($node->field_headline[LANGUAGE_NONE][0]['value'])): ?>
      <h2 class="headline-callout"><span><?php print $node->field_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>
      <?php endif; ?>
      <?php if (isset($node->field_subheadline[LANGUAGE_NONE][0]['value'])): ?>
      <h3 class="headline-callout"><span><?php print $node->field_subheadline[LANGUAGE_NONE][0]['value']; ?></span></h3>
      <?php endif; ?>
    </section>

    <?php if (isset($content['sms_referral'])): ?>
    <?php print render($content['sms_referral']); ?>
    <?php endif; ?>

    <?php if (isset($content['cta'])): ?>
    <?php print render($content['cta']); ?>
    <?php endif; ?>

    <?php if (isset($content['action_items'])): ?>
    <?php print render($content['action_items']); ?>
    <?php endif; ?>

    <?php if (isset($content['reportback'])): ?>
    <?php print render($content['reportback']); ?>
    <?php endif; ?>

    <?php if (isset($content['prizes'])): ?>
    <?php print render($content['prizes']); ?>
    <?php endif; ?>

    <?php if (isset($content['sms_example'])): ?>
    <?php print render($content['sms_example']); ?>
    <?php endif; ?>

    <?php if (isset($content['gallery'])): ?>
    <?php print render($content['gallery']); ?>
    <?php endif; ?>

    <?php if (isset($content['info'])): ?>
    <?php print render($content['info']); ?>
    <?php endif; ?>

    <?php if (isset($content['profiles'])): ?>
    <?php print render($content['profiles']); ?>
    <?php endif; ?>

    <?php if (isset($content['faq'])): ?>
    <?php print render($content['faq']); ?>
    <?php endif; ?>

    <?php if (isset($sponsors)): ?>
    <footer class="sponsor full-width" id="sponsor">
    <h3>Sponsored by:</h3>
    <p><?php print render($content['sponsors']); ?></p>
    </footer>
    <?php endif; ?>

  </div>
</div>

<?php if (isset($node->field_contact_email[LANGUAGE_NONE][0]['value'])): ?>
<footer class="contact" id="footer">
  <p>Questions? E-mail <a href="mailto:<?php print $node->field_contact_email[LANGUAGE_NONE][0]['value']; ?>"><?php print $node->field_contact_email[LANGUAGE_NONE][0]['value']; ?></a>!</p>
</footer>
<?php endif; ?>

<!--
Edvisors tracking pixel
@todo - Ideally this will be handled in a more automated fashion.  This
can be achieved by Stashing the Edvisor offer id on the campaign and
using a a standardize (but themable) webform confirmation page.
@todo - add a http referrer check as well
-->
<!-- Offer Conversion: DoSomething.org -->
<iframe style="display: none;" src="http://tracking.edvisors.com/aff_l?offer_id=98" scrolling="no" frameborder="0" width="1" height="1"></iframe>
<!-- // End Offer Conversion -->
