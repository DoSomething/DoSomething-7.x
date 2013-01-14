<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Grandparents Gone Wired',

  // Parent campaign to inherit the styling from
  //'parent' => 'footlocker_2011',

  // Add css files in the order they should be included.
  'css' => array(
    //'style.css',
  ),

  // Add javascript files in the order you would like to have them included.
  'js' => array(
    //'custom.js',
  ),

  // An array of arrays where the first element is the providing module
  // and the second is the library to include.  These will be passed as
  // the first two parameters to drupal_add_library().  The third parameter
  // is always FALSE because these styles are campaign specific and not site
  // wide.
  //'libraries' => array(
  //  array('system', 'ui.draggable'),
  //),

  // An array of arrays indexed with 'title' and 'href'
  // These get passed to url().
  'menu' => array(
    array('title' => 'take action', 'href' => 'grandparents', 'fragment' => 'header'),
    array('title' => 'download guide', 'href' => 'grandparents', 'fragment' => 'action'),
    //array('title' => '$5,000 scholarship', 'href' => 'grandparents', 'fragment' => 'scholarship'),
    //array('title' => 'learn the issue', 'href' => 'grandparents', 'fragment' => 'social'),    
    //array('title' => 'prizes', 'href' => 'grandparents', 'fragment' => 'secondary-content'),
    //array('title' => 'tell us about it', 'href' => 'grandparents', 'fragment' => 'impact'),
    array('title' => 'questions?', 'href' => 'grandparents', 'fragment' => 'faq'),
  ),
  'menu_suffix' => array(
    '#markup' => '<div class="nav-count clearfix"><p id="sb-counter"></p><p>Grandparents<br>Wired</p></div><a href="//iq.intel.com/story/22223727/grandparents-gone-wired" target="_blank"><img src="//files.dosomething.org/files/campaigns/grandparents12/intel.jpg"/></a><p>Got questions? Email Sydney at <a href="mailto:grandparents@dosomething.org">grandparents@dosomething.org</a>!</p>'
  ),
    'menu_prefix' => array(
    '#markup' => '<p>Go To:</p>'
  ),
);
