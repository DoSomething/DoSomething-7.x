<div id="header">
  <div class="header_inner">
    <img class="header_logo_text" src="//files.dosomething.org/files/campaigns/crazy13/logo_text.png" alt="Craziest Thing type logo" />
    <img class="header_background" src="//files.dosomething.org/files/campaigns/crazy13/header_small.jpg" alt="People" />
    <img class="header_sponsor" src="//files.dosomething.org/files/campaigns/crazy13/sponsor.png" alt="HR Block logo" />
    <img class="header_ds_logo" src="//www.dosomething.org/sites/all/themes/doit/css/images/ds-logo.png" alt="DoSomething.org logo" />
    <img class="header_logo" src="//files.dosomething.org/files/campaigns/crazy13/logo.png" alt="Craziest Thing icon logo" />
  </div>
</div> <!-- #header -->

<div class="crazy-menu-wrapper">
	<?php echo drupal_render($top_menu); ?>
	<select name="state-filter">
	<?php
		module_load_include('inc', 'webform', 'includes/webform.options.inc');
		$states = webform_options_united_states();
		foreach ($states as $key => $state) {
		  echo '<option value="' . $key . '">' . $state . '</option>';
		}
	?>
	</select>
</div>

<div class="crazy-sub-menu-header scroll-header-style">
	<h1>People do crazy things to save money</h1>
	<h2>Tell us if you believe their stories</h2>
</div>