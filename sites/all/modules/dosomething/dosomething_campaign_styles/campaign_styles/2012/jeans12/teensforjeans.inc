<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Teens for Jeans',

  // Parent campaign to inherit the styling from
  //'parent' => 'footlocker_2011',

  // Add css files in the order they should be included.
  'css' => array(
    //'style.css',
  ),

  // Add javascript files in the order you would like to have them included.
  'js' => array(
    'scripts/drive_pages.js',
    'scripts/nav_and_anchors.js',
    'scripts/registration.js'
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
    array('title' => 'here\'s what you do', 'href' => '', 'fragment' => 'action', 'external' => TRUE),
    array('title' => 'learn the issue', 'href' => '', 'fragment' => 'content-module', 'external' => TRUE),
    array('title' => '$5,000 scholarship', 'href' => '', 'fragment' => 'scholarship', 'external' => TRUE),
    array('title' => 'prizing', 'href' => '', 'fragment' => 'prizing', 'external' => TRUE),
    array('title' => 'tell us about it', 'href' => 'teensforjeans/report-back'),
    array('title' => 'questions?', 'href' => '', 'fragment' => 'faq', 'external' => TRUE),
  ),
  'menu_suffix' => array(
    '#markup' => '<div id="counter_wrapper"><p id="schools_participating"></p><h3>schools<br>signed up</h3></div><img src="http://files.dosomething.org/files/campaigns/jeans12/nav2.png"/><p>Got questions? Email Farah at <a href="mailto:teensforjeans@dosomething.org">teensforjeans@dosomething.org</a>!</p>'
  ),
);
