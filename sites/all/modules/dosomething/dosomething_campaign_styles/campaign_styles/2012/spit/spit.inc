<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Give a Spit',

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
    array('title' => 'here\'s what you do', 'href' => '', 'fragment' => 'action'),
    array('title' => 'learn the issue', 'href' => '', 'fragment' => 'content-infographic'),
    array('title' => 'search for a drive', 'href' => '', 'fragment' => 'search'),
    array('title' => '$5,000 scholarship', 'href' => '', 'fragment' => 'scholarship'),
    array('title' => 'tell us about it', 'href' => '', 'fragment' => 'impact'),
    array('title' => 'questions?', 'href' => '', 'fragment' => 'faq'),
  ),
  'menu_suffix' => array(
    '#markup' => '<img src="//files.dosomething.org/files/campaigns/spit/btm-logo.png"/><p>Got questions? Email us at <a href="mailto:spit@dosomething.org">spit@dosomething.org</a>!</p>'
  ),
);
