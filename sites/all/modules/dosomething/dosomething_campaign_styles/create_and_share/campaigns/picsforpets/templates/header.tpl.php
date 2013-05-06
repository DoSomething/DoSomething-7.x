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
		foreach ($states as $key => $state) {
		  echo '<option value="' . $key . '">' . $state . '</option>';
		}
	?>
	</select>
</div>
