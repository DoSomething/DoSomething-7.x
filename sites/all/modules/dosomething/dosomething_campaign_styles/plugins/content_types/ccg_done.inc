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

	$fbimg = file_create_url($context['argument_term_1']->data->cgg_celeb_image[LANGUAGE_NONE][0]['uri']);

	// "For More Info" section heading
	$output['facebook'] = array(
		'#markup' => l(t('Facebook'), 'https://www.facebook.com/dialog/feed?app_id=105775762330&link=' . url(request_uri(), array('absolute' => TRUE)) . '&picture=' . $fbimg . '&name=' . $facebook['title'] . '&caption=' . $facebook['caption'] . '&description=' . $facebook['description'] . '&redirect_uri=' . $facebook['redirect_to'], array('attributes' => array('class' => array('cgg_facebook'))))
	);

  // NOTE ----------------
  // the images are stored using a 'frist_last.jpg' convention at //files.dosomething.org/files/

	/*$output['twitter'] = array(
		'#markup' => '
			<a href="https://twitter.com/share" class="twitter-share-button" data-via="dosomething">Tweet</a>
			<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>'
  );*/

$output['twitter_two'] = array(
  '#markup' => /*'
  <a href="javascript:(function(){window.twttr=window.twttr||{};var D=550,A=450,C=screen.height,B=screen.width,H=Math.round((B/2)-(D/2)),G=0,F=document,E;if(C>A){G=Math.round((C/2)-(A/2))}window.twttr.shareWin=window.open(\'http://twitter.com/share\',\'\',\'left=\'+H+\',top=\'+G+\',width=\'+D+\',height=\'+A+\',personalbar=0,toolbar=0,scrollbars=1,resizable=1\');E=F.createElement(\'script\');E.src=\'http://platform.twitter.com/bookmarklets/share.js?v=1\';F.getElementsByTagName(\'head\')[0].appendChild(E)}());" class="cgg_twitter"></a>' */
  '<a href="https://twitter.com/share?url=&amp;text=Just voted in @DoSomething\'s %23CelebsGoneGood! What celebrity do you think made a big positive impact in 2012? VOTE NOW:" class="cgg_twitter" target=_blank">Share on Twitter</a>'
  );

	/*$output['email'] = array(
		'#markup' => l(t('Email'), 'mailto:?subject=' . rawurlencode($email['title']) . '&body=' . rawurlencode($email['body'])),
	);*/

	$block->content = str_replace('""', '"', $output);
	return $block;
}
