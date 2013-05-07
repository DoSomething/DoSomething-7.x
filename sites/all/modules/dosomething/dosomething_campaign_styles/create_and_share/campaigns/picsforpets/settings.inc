<?php

/**
 *  Settings that don't fit within the node form.  These settings affect the campaign defined by
 *  campaign_nid below.  These settings are merged with the settings defined in the node form.
 */
$settings = array(
  // The node ID of the picsforpets campaign.  This ensures that all campaign pages
  // gather the same settings.
  'campaign_nid' => '729195',

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
      'title' => 'I did stuff.',
      'caption' => 'cheese',
      'description' => 'Some things.',
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
      'pics.js',
    ),
    'picsforpets/submit' => array(
      'pics-form.js',
    ),
  ),

  /*// Top menu links.
  'top_links' => array(
    'picsforpets$' => array(
      'title' => 'All',
      'href' => 'picsforpets',
    ),
    'picsforpets/cats' => array(
      'title' => 'Cats',
      'href' => 'picsforpets/cats',
    ),
    'picsforpets/dogs' => array(
      'title' => 'Dogs',
      'href' => 'picsforpets/dogs',
    ),
    'picsforpets/other' => array(
      'title' => 'Other',
      'href' => 'picsforpets/other',
    ),
  ),*/
);
