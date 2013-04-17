<?php

$settings = array(
  // The node ID of the campaign node.  This ensures that all campaign pages
  // gather the same settings.
  'campaign_nid' => '729034',

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
    // Use {name} to denote the person's name
    'notification' => array(
      'message' => t('{name} gave you a THUMBS DOWN.  Epic fail!'),
    ),
  ),

  // CSS
  'css' => array(
    'blah' => array(
      'crazy.css'
    ),
    'blah/about' => array(
      'crazy-about.css',
    ),
    'blah/submit' => array(
      'crazy-form.css',
    ),
  ),

  // Javascript
  'js' => array(
    'blah' => array(
      'crazy.js',
    ),
    'blah/submit' => array(
      'crazy-form.js',
    ),
    'blah/about' => array(
      'crazy-about.js',
    ),
  ),

  // Top menu links.
  'top_links' => array(
    'blah(/(time-.*?|[0-9]+))?$' => array(
      'title' => 'Gallery',
      'href' => 'blah',
    ),
    'blah/friends' => array(
      'title' => 'Friends',
      'href' => 'blah/friends',
      'attributes' => array(
        'onclick' => "return fb_auth('login', " . $fbed . ")",
      ),
    ),
    'blah/about' => array(
      'title' => 'About',
      'href' => 'blah/about',
      'parent' => '/about',
    ),
    'blah/submit' => array(
      'title' => 'Submit',
      'href' => 'blah/submit/start',
      'parent' => '/submit',
      'attributes' => array(
        'onclick' => "return fb_auth('submit', " . $fbed . ")",
      ),
    ),
  ),

  // Sub menus
  'sub_menus' => array(
    // Time based filters sub-menu (landing page)
    'blah(/(time-.*?|[0-9]+))?$' => array(
      'today' => array(
        'title' => 'New',
        'href' => 'blah/time-today',
      ),
      'week' => array(
        'title' => 'Popular',
        'href' => 'blah',
      ),
      'forever' => array(
        'title' => 'Best Ever',
        'href' => 'blah/time-all',
      ),
    ),
    // About pages sub-menu
    'blah/about' => array(
      'tips' => array(
        'title' => 'Tips',
        'href' => 'blah/about#tips'
      ),
      'scholarship' => array(
        'title' => 'Scholarship',
        'href' => 'blah/about#scholarship',
      ),
      'video' => array(
        'title' => 'Video',
        'href' => 'blah/about#video'
      ),
    ),
  ),
);
