<div id="header">
  <div class="header_inner">
    <img class="header_logo_text" src="//files.dosomething.org/files/campaigns/crazy13/logo_text.png" alt="Craziest Thing type logo" />
    <img class="header_background" src="//files.dosomething.org/files/campaigns/crazy13/header_small.jpg" alt="People" />
    <img class="header_sponsor" src="//files.dosomething.org/files/campaigns/crazy13/sponsor.png" alt="HR Block logo" />
    <img class="header_ds_logo" src="//www.dosomething.org/sites/all/themes/doit/css/images/ds-logo.png" alt="DoSomething.org logo" />
    <img class="header_logo" src="//files.dosomething.org/files/campaigns/crazy13/logo.png" alt="Craziest Thing icon logo" />
  </div>
</div> <!-- #header -->

<div class="picsforpets-submit-area">
  <?php if ($settings['user']['post_count'] < 1): ?>
  	Help us save an animal's life: <a href="/<?php echo $settings['campaign_root']; ?>/submit">Submit your picture</a>
  <?php else: ?>
  	<a href="/<?php echo $settings['campaign_root']; ?>">Back to Gallery</a> <a href="/<?php echo $settings['campaign_root']; ?>/submit">Submit Another Pic</a>
  <?php endif; ?>
</div>

<div class="crazy-menu-wrapper" style="text-align: center; padding: 10px">
	<?php
	  $filters = explode('-', basename(request_path()));

	  $types = array('all' => '');
	  $done = false;
	  foreach ($filters AS $filter) {
	  	if (in_array($filter, array('cat', 'cats', 'dog', 'dogs', 'other', 'others'))) {
	  	  $types[$filter] = ' selected="selected"';
	  	  $done = true;
	  	}
	  	else {
	  	  $types[$filter] = '';
	  	}
	  }

	  if (!$done) {
	  	$types['all'] = ' selected="selected"';
	  }
	?>
	<select name="type-filter" class="type-filter">
		<option value="all"<?php echo $types['all']; ?>>All Animals</option>
		<option value="cats"<?php echo $types['cats']; ?>>Cats</option>
		<option value="dogs"<?php echo $types['dogs']; ?>>Dogs</option>
		<option value="other"<?php echo $types['other']; ?>>Other</option>
	</select>
	<select name="state-filter" class="state-filter">
		<option value="" selected="selected">All States</option>
	<?php
		// Load the default US states array.
		module_load_include('inc', 'webform', 'includes/webform.options');
		$states = webform_options_united_states(null, null, null, null);

		// Fills an array with basic null values.  This prevents a notice that would otherwise appear.
		$selected = array_fill_keys(array_keys($states), '');

		// Mark the selected state.
		if (preg_match('#[A-Z]{2}#', request_path(), $state)) {
		  $selected_state = $state[0];
		  $selected[$selected_state] = ' selected="selected"';
		}

		$path = request_path();
		foreach ($states as $key => $state) {
		  echo '<option value="' . $key . '"' . $selected[$key] . '>' . $state . '</option>';
		}
	?>
	</select>
	<input type="button" value="Go" class="go-filter" />
</div>
