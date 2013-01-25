<?php

// Whether or not to allow notifications.
$allow_notifications = true;

// The relative URI to the campaign.  Don't include a leading slash.
$crazy_root = 'crazy';
if (!defined('CRAZY_ROOT')) define('CRAZY_ROOT', $crazy_root);

// Pages where users can get notifications.
// This follows a regular expression syntax.
// If you don't know what that means, don't change this.
$crazy_notification_pages = array(
	'crazy',
	'crazy/([0-9]+)',
	'crazy/time-(today|week)',
	'crazy/friends'
);

// The first image can't be lazy loaded because it causes issues when you create a new post.
// Increase this number to turn off lazy loading for more images.
// THIS SHOULD ALWAYS BE AT LEAST 1
$lazy_load_count = 1;

// Allow lazy loading? 1 = yes, 0 = no
$allow_lazy_loading = 1;

// Campaign title
$campaign_title = "The Craziest thing I've done to save money";

// Top menu links.
$top_links = array(
	'crazy(/(time-.*?|[0-9]+))?$' => array(
		'title' => 'Gallery',
		'href' => CRAZY_ROOT,
	),
	'crazy/friends' => array(
		'title' => 'Friends',
		'href' => CRAZY_ROOT . '/friends',
		'attributes' => array(
			'onclick' => "return fb_auth('login', " . $fbed . ")",
		),
	),
	'crazy/about' => array(
		'title' => 'About',
		'href' => CRAZY_ROOT . '/about',
		'parent' => '/about',
	),
	'crazy/submit' => array(
		'title' => 'Submit',
		'href' => CRAZY_ROOT . '/submit/start',
		'parent' => '/submit',
		'attributes' => array(
			'onclick' => "return fb_auth('submit', " . $fbed . ")",
		),
	),
);

// Sub menus
$sub_menus = array(
	// Time based filters sub-menu (landing page)
	'crazy(/(time-.*?|[0-9]+))?$' => array(
		'today' => array(
			'title' => 'Today',
			'href' => CRAZY_ROOT . '/time-today',
		),
		'week' => array(
			'title' => 'This Week',
			'href' => CRAZY_ROOT . '/time-week',
		),
		'forever' => array(
			'title' => 'All Time',
			'href' => CRAZY_ROOT,
		),
	),
	// About pages sub-menu
	'crazy/about' => array(
		'tips' => array(
			'title' => 'Tips',
			'href' => CRAZY_ROOT . '/about#tips'
		),
		'scholarship' => array(
			'title' => 'Scholarship',
			'href' => CRAZY_ROOT . '/about#scholarship',
		),
		'video' => array(
			'title' => 'Video',
			'href' => CRAZY_ROOT . '/about#video'
		),
	),
);

// Submit form
$submit_form = array(
	// Submit form steps
	'steps' => array(
		'step1' => 'Step 1 of 2: Select a picture to upload.',
		'step2' => 'Step 2 of 2: Add text (optional)',
	),
);

/** 
  * An array of arrays indicating the page(s) you want CSS to show up on.
  * The sub-array should be a list of CSS files.
  *
  * Sub-sections are counted.  For example: "crazy/about" will match crazy/about/tips
  * and "crazy" by itself will match everything.
  *
  * All CSS will be loaded from /sites/all/modules/dosomething/crazyshit/css in the order
  * that they are listed below.
  */
$crazy_css = array(
	'crazy' => array(
		'crazy.css'
	),
	'crazy/about' => array(
		'crazy-about.css',
	),
	'crazy/submit' => array(
		'crazy-form.css',
	),
);

/** 
  * An array of arrays indicating the page(s) you want JS to show up on.
  * The sub-array should be a list of JS files.
  *
  * Sub-sections are counted.  For example: "crazy/about" will match crazy/about/tips
  * and "crazy" by itself will match everything.
  *
  * All javascript will be loaded from /sites/all/modules/dosomething/crazyshit/js in the order
  * that they are listed below.
  */
$crazy_js = array(
	'crazy' => array(
		'crazy.js',
	),
	'crazy/submit' => array(
		'crazy-form.js',
	),
	'crazy/about' => array(
		'crazy-about.js',
	),
);

// Money saving tips
$money_saving_tips = array(
	'Start saving early.  The more money in your savings, the more interest you make.  That means more money without doing anything.',
	"Don't bother a sleeping werewolf.",
);

// Facebook aggregation messages
// Note: Do NOT use the t() function here.
// Use !n (exclamation-point, lowercase "N") for the number.
$fb_messages = array(
	'vouch' => '!n people have vouched for you! Good for you!',
	'bs' => '!n people called BS on your submission.  Boooo...',
);

// Facebook posts
$facebook_posts = array(
	'posts' => array(
		'title' => t('Vouch for me?'),
		'caption' => t('Vouch for my submission'),
		'description' => t('So, the craziest thing I have ever done to save money...'),
	),
	'invite' => array(
		'document' => 'http://www.dosomething.org/' . CRAZY_ROOT,
		'title' => t('Crazy $#!T I did to save money'),
		'caption' => t('Craaazy Shit'),
		'description' => t('Crazy Description'),
		'image' => 'http://files.dosomething.org/files/styles/p4p_fake_button/public/pictures/actionguide/123905097.jpg',
	),
	'share' => array(
		'namespace' => 'dosomethingapp',
		'object' => 'crazy_thing',
		'action' => 'share',
		'message' => t('I just posted the craziest thing I did to save money.  Now it\'s your turn! Go here to do so.'),
	),
);

// Batch limit.  Probably better if this is left alone.
$batch_limit = 50;

/********************************
 *	Don't edit below this line  *
 ********************************/

if (!defined('CRAZY_LAZY_LOAD_COUNT')) define('CRAZY_LAZY_LOAD_COUNT', $lazy_load_count);
if (!defined('CRAZY_ALLOW_NOTIFICATIONS')) define('CRAZY_ALLOW_NOTIFICATIONS', $allow_notifications);
if (!defined('CRAZY_ALLOW_LAZY_LOADING')) define('CRAZY_ALLOW_LAZY_LOADING', $allow_lazy_loading);
