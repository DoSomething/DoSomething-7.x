<?php

/**
 *  Settings that don't fit within the node form.  These settings affect the campaign defined by
 *  campaign_nid below.  These settings are merged with the settings defined in the node form.
 */
$settings = array(
  // The node ID of the picsforpets campaign.  This ensures that all campaign pages
  // gather the same settings.
  'campaign_nid' => '729048',

  // Global vars for templates:
  'template_vars' => array(
    'template_a' => array(
      'tip' => 'quetty',
    ),
  ),

  'autocomplete' => array(
    'options' => array(
      0 => "Mike's",
      1 => "Tom's",
      2 => "Jim's",
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
    // Use {name} to denote the person's name
    'notification' => array(
      'message' => t('{name} gave you a THUMBS DOWN.  Epic fail!'),
    ),
  ),

  // CSS
  'css' => array(
    'picsforpets' => array(
      'crazy.css'
    ),
    'picsforpets/about' => array(
      'crazy-about.css',
    ),
    'picsforpets/submit' => array(
      'crazy-form.css',
    ),
  ),

  // Javascript
  'js' => array(
    'picsforpets' => array(
      'crazy.js',
    ),
    'picsforpets/submit' => array(
      'crazy-form.js',
    ),
    'picsforpets/about' => array(
      'crazy-about.js',
    ),
  ),

  // Top menu links.
  'top_links' => array(
    'picsforpets(/(time-.*?|[0-9]+))?$' => array(
      'title' => 'Gallery',
      'href' => 'picsforpets',
    ),
    'picsforpets/friends' => array(
      'title' => 'Friends',
      'href' => 'picsforpets/friends',
      'attributes' => array(
        'onclick' => "return fb_auth('login', " . $fbed . ")",
      ),
    ),
    'picsforpets/about' => array(
      'title' => 'About',
      'href' => 'picsforpets/about',
      'parent' => '/about',
    ),
    'picsforpets/submit' => array(
      'title' => 'Submit',
      'href' => 'picsforpets/submit/start',
      'parent' => '/submit',
      'attributes' => array(
        'onclick' => "return fb_auth('submit', " . $fbed . ")",
      ),
    ),
  ),

  // Sub menus
  'sub_menus' => array(
    // Time based filters sub-menu (landing page)
    'picsforpets(/(time-.*?|[0-9]+))?$' => array(
      'today' => array(
        'title' => 'New',
        'href' => 'picsforpets/time-today',
      ),
      'week' => array(
        'title' => 'Popular',
        'href' => 'picsforpets',
      ),
      'forever' => array(
        'title' => 'Best Ever',
        'href' => 'picsforpets/time-all',
      ),
    ),
    // About pages sub-menu
    'picsforpets/about' => array(
      'tips' => array(
        'title' => 'Tips',
        'href' => 'picsforpets/about#tips'
      ),
      'scholarship' => array(
        'title' => 'Scholarship',
        'href' => 'picsforpets/about#scholarship',
      ),
      'video' => array(
        'title' => 'Video',
        'href' => 'picsforpets/about#video'
      ),
    ),
  ),
);
