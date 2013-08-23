<?php print drupal_render($form['form_build_id']) .  drupal_render($form['form_id']); ?>

<div class="two-col">
  <label>Your First Name:</label>
  <?php print drupal_render($form['alpha_name']); ?>
</div>

<div class="two-col">
  <label>Your Cell #:</label>
  <?php print drupal_render($form['alpha_mobile']); ?>
</div>

<div class="one-col">
  <label>Friend's Cell #s:</label>
</div>

<div class="two-col">
	<?php for ($i=0; $i<=2; $i++): ?>
	<?php print drupal_render($form['beta_mobiles']['beta_mobile_' . $i]); ?>
  <?php endfor; ?>
</div>

<div class="two-col">
	<?php for ($i=3; $i<=5; $i++): ?>
	<?php print drupal_render($form['beta_mobiles']['beta_mobile_' . $i]); ?>
  <?php endfor; ?>
</div>
<?php print drupal_render($form['nid']); ?>

<div class="one-col callout">
  <?php print drupal_render($form['submit']); ?>
</div>
