<p>In order to use this module, you'll need an <a href="http://optimize.ly/OZRdc0/">Optimizely</a> account. A Free 30 day trial account is available.</p>

<p>Most of the configuration and designing of the A/B tests is done by logging into your account on the <a href="http://optimize.ly/OZRdc0/">Optimizely website</a>.</p>

<p>The default Project javascript (js) file (snippet) uses the Optimizely account ID for it's file name. The "Default" / first project entry in the
  <a href="/admin/config/system/optimizely">Project Listing</a> page uses the account ID value for the Project Code setting. The Default project entry targets all pages site wide with it's initial settings. Enabling this entry will result in the initial Optimizely experiments running site wide.</p>

<?php echo drupal_render_children($form) ?>