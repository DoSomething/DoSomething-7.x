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
  	Help us save an animal's life: <a href="/picsforpets/submit">Submit your picture</a>
  <?php else: ?>
  	<a href="/picsforpets">Back to Gallery</a> <a href="/picsforpets/submit">Submit Another Pic</a>
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
		$states = array(
		    'AL' => 'AL',
		    'AK' => 'AK',
		    'AS' => 'AS',
		    'AZ' => 'AZ',
		    'AR' => 'AR',
		    'CA' => 'CA',
		    'CO' => 'CO',
		    'CT' => 'CT',
		    'DE' => 'DE',
		    'DC' => 'DC',
		    'FL' => 'FL',
		    'GA' => 'GA',
		    'GU' => 'GU',
		    'HI' => 'HI',
		    'ID' => 'ID',
		    'IL' => 'IL',
		    'IN' => 'IN',
		    'IA' => 'IA',
		    'KS' => 'KS',
		    'KY' => 'KY',
		    'LA' => 'LA',
		    'ME' => 'ME',
		    'MH' => 'MH',
		    'MD' => 'MD',
		    'MA' => 'MA',
		    'MI' => 'MI',
		    'MN' => 'MN',
		    'MS' => 'MS',
		    'MO' => 'MO',
		    'MT' => 'MT',
		    'NE' => 'NE',
		    'NV' => 'NV',
		    'NH' => 'NH',
		    'NJ' => 'NJ',
		    'NM' => 'NM',
		    'NY' => 'NY',
		    'NC' => 'NC',
		    'ND' => 'ND',
		    'MP' => 'MP',
		    'OH' => 'OH',
		    'OK' => 'OK',
		    'OR' => 'OR',
		    'PW' => 'PW',
		    'PA' => 'PA',
		    'PR' => 'PR',
		    'RI' => 'RI',
		    'SC' => 'SC',
		    'SD' => 'SD',
		    'TN' => 'TN',
		    'TX' => 'TX',
		    'UT' => 'UT',
		    'VT' => 'VT',
		    'VI' => 'VI',
		    'VA' => 'VA',
		    'WA' => 'WA',
		    'WV' => 'WV',
		    'WI' => 'WI',
		    'WY' => 'WY',
		);

		$path = request_path();
		foreach ($states as $key => $state) {
		  echo '<option value="' . $key . '"' . (strpos($path, $state) !== FALSE ? ' selected="selected"' : '') . '>' . $state . '</option>';
		}
	?>
	</select>
	<input type="button" value="Go" class="go-filter" />
</div>
