<?php

/**
 *  Settings that don't fit within the node form.  These settings affect the campaign defined by
 *  campaign_nid below.  These settings are merged with the settings defined in the node form.
 */
$settings = array(
  // The node ID of the {scaffold} campaign.  This ensures that all campaign pages
  // gather the same settings.
  'campaign_nid' => '{nid}',

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
    '{scaffold}' => array(
      'crazy.css'
    ),
    '{scaffold}/about' => array(
      'crazy-about.css',
    ),
    '{scaffold}/submit' => array(
      'crazy-form.css',
    ),
  ),

  // Javascript
  'js' => array(
    '{scaffold}' => array(
      'crazy.js',
    ),
    '{scaffold}/submit' => array(
      'crazy-form.js',
    ),
    '{scaffold}/about' => array(
      'crazy-about.js',
    ),
  ),

  // Top menu links.
  'top_links' => array(
    '{scaffold}(/(time-.*?|[0-9]+))?$' => array(
      'title' => 'Gallery',
      'href' => '{scaffold}',
    ),
    '{scaffold}/friends' => array(
      'title' => 'Friends',
      'href' => '{scaffold}/friends',
      'attributes' => array(
        'onclick' => "return fb_auth('login', " . $fbed . ")",
      ),
    ),
    '{scaffold}/about' => array(
      'title' => 'About',
      'href' => '{scaffold}/about',
      'parent' => '/about',
    ),
    '{scaffold}/submit' => array(
      'title' => 'Submit',
      'href' => '{scaffold}/submit/start',
      'parent' => '/submit',
      'attributes' => array(
        'onclick' => "return fb_auth('submit', " . $fbed . ")",
      ),
    ),
  ),

  // Sub menus
  'sub_menus' => array(
    // Time based filters sub-menu (landing page)
    '{scaffold}(/(time-.*?|[0-9]+))?$' => array(
      'today' => array(
        'title' => 'New',
        'href' => '{scaffold}/time-today',
      ),
      'week' => array(
        'title' => 'Popular',
        'href' => '{scaffold}',
      ),
      'forever' => array(
        'title' => 'Best Ever',
        'href' => '{scaffold}/time-all',
      ),
    ),
    // About pages sub-menu
    '{scaffold}/about' => array(
      'tips' => array(
        'title' => 'Tips',
        'href' => '{scaffold}/about#tips'
      ),
      'scholarship' => array(
        'title' => 'Scholarship',
        'href' => '{scaffold}/about#scholarship',
      ),
      'video' => array(
        'title' => 'Video',
        'href' => '{scaffold}/about#video'
      ),
    ),
  ),
);
