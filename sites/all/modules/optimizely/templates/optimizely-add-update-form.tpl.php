<p>In order to use this module, you'll need an <a href="http://optimize.ly/OZRdc0">Optimizely account</a>. A Free 30 day trial account is available.</p>

<?php if ($variables['form']['optimizely_project_code']['#default_value'] == 0): ?>

  <ul>
    <li><strong>Add the account ID to the <a href="/admin/config/system/optimizely/settings">Account Info</a> settings page to be able to enable this
    entry</strong>.</li>
  </ul>

<?php endif; ?>
    
<p>The basic configuration and design of the A/B tests is done by logging into your account on the <a href="http://optimize.ly/OZRdc0">Optimizely website.</a></p>

<?php echo drupal_render_children($form) ?>