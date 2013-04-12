<?php

$settings = array(
  // The domain that the campaign is hosted on.  Default is dosomething.org.
  'campaign_domain' => 'http://www.dosomething.org',
  // The path to the campaign minus leading slash (e.g. 'crazy')
  'campaign_root' => 'craziness',

  // The webform entity bundle for this campaign
  'form_bundle' => 'crazy_shit',
  // The font to use to write text to images
  'font' => 'DINComp-CondBold.ttf',

  // Global switch: Allow anonymous voting?
  'allow_anonymous_votes' => TRUE,
  // Global switch: Allow notifications? 
  'allow_notifications' => TRUE,
  // Global switch: Lazy loading
  'allow_lazy_loading' => TRUE,

  'fields' => array(
    'weight' => array(
      'field' => 'craziness_weight',
    ),
    'vouch' => array(
      'field' => 'crazy_vouch_count',
      'weight' => 0.75,
    ),
    'bull' => array(
      'field' => 'crazy_bullshit_count',
      'weight' => 0.5,
    ),
  ),

  // The number that votes will add up to over X amount of time.
  'point_count' => 43200,

  // Global vars for templates:
  'template_vars' => array(
    'template_a' => array(
      'tip' => 'quetty',
    ),
  ),

  // Facebook language
  'facebook' => array(
	// Vouch request
	'posts' => array(
		'title' => t('The Craziest Thing I Did to Save Money'),
		'caption' => '',
		'description' => t('I just told the story about the craziest thing I did to save money, and I need your help to vouch for me.  No one believes me, click here to support!'),
	),
	// Invite from friends page.
	'invite' => array(
		'document' => 'http://www.dosomething.org/' . CRAZY_ROOT,
		'title' => t('The Craziest Thing I Did to Save Money'),
		'caption' => '',
		'description' => t('I never told anyone this before, but this one time I did this crazy thing to save money..'),
		'image' => 'http://files.dosomething.org/files/campaigns/crazy13/logo.png',
	),
	// Share a particular post.
	'share' => array(
		'namespace' => 'dosomethingapp',
		'object' => 'crazy_thing',
		'action' => 'share',
		//'message' => t('I just posted the craziest thing I did to save money.  Now it\'s your turn! Go here to do so.'),   # Ignored -- we can't force a message on a user.
	),
  ),

  // CSS
  'css' => array(
    'craziness' => array(
      'crazy.css'
    ),
    'craziness/about' => array(
      'crazy-about.css',
    ),
    'craziness/submit' => array(
      'crazy-form.css',
    ),
  ),

  // Javascript
  'js' => array(
    'craziness' => array(
      'crazy.js',
    ),
    'craziness/submit' => array(
      'crazy-form.js',
    ),
    'craziness/about' => array(
      'crazy-about.js',
    ),
  ),
  
  'setup_pages' => array(
  	'friends',
  	'time-.*?',
  ),

  'gallery_pages' => array(2, 10, 11),
  //notification_pages = array()

  //friends_page = 'friends'
  //submit_page = 'submit'

  // Top menu links.
  'top_links' => array(
    'craziness(/(time-.*?|[0-9]+))?$' => array(
      'title' => 'Gallery',
      'href' => 'craziness',
    ),
    'craziness/friends' => array(
      'title' => 'Friends',
      'href' => 'craziness/friends',
      'attributes' => array(
        'onclick' => "return fb_auth('login', " . $fbed . ")",
      ),
    ),
    'craziness/about' => array(
      'title' => 'About',
      'href' => 'craziness/about',
      'parent' => '/about',
    ),
    'craziness/submit' => array(
      'title' => 'Submit',
      'href' => 'craziness/submit/start',
      'parent' => '/submit',
      'attributes' => array(
        'onclick' => "return fb_auth('submit', " . $fbed . ")",
      ),
    ),
  ),

  // Sub menus
  'sub_menus' => array(
    // Time based filters sub-menu (landing page)
    'craziness(/(time-.*?|[0-9]+))?$' => array(
      'today' => array(
        'title' => 'New',
        'href' => 'craziness/time-today',
      ),
      'week' => array(
        'title' => 'Popular',
        'href' => 'craziness',
      ),
      'forever' => array(
        'title' => 'Best Ever',
        'href' => 'craziness/time-all',
      ),
    ),
    // About pages sub-menu
    'craziness/about' => array(
      'tips' => array(
        'title' => 'Tips',
        'href' => 'craziness/about#tips'
      ),
      'scholarship' => array(
        'title' => 'Scholarship',
        'href' => 'craziness/about#scholarship',
      ),
      'video' => array(
        'title' => 'Video',
        'href' => 'craziness/about#video'
      ),
    ),
  ),
);