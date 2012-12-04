<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Celebs Gone Good Voted Landing'),
  'description' => t('Says that you\'re done.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_cgg_celeb_landing'
);

function dosomething_cgg_celeb_landing($subtype, $conf, $panel_args, $context) {

	include drupal_get_path('module', 'dosomething_campaign_styles') . '/campaign_styles/2012/cgg/plugin.inc';
	$block = new stdClass();

	// "For More Info" section heading
	$output['facebook'] = array(
		'#markup' => l(t('Facebook'), 'https://www.facebook.com/dialog/feed?app_id=105775762330&link=' . url(request_uri(), array('absolute' => TRUE)) . '&picture=http://files.dosomething.org/files/campaigns/grandparents12/action2b.jpg&name=' . $facebook['title'] . '&caption=' . $facebook['caption'] . '&redirect_uri=' . $facebook['redirect_to'])
	);

	$output['twitter'] = array(
		'#markup' => '
			<a href="https://twitter.com/share" class="twitter-share-button" data-via="dosomething">Tweet</a>
			<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>'
	);

	/*$output['email'] = array(
		'#markup' => l(t('Email'), 'mailto:?subject=' . rawurlencode($email['title']) . '&body=' . rawurlencode($email['body'])),
	);*/

	$block->content = str_replace('""', '"', $output);
	return $block;
}