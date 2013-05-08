<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Thumb Wars',

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
    array('title' => 'get socks', 'href' => '', 'fragment' => 'header', 'external' => TRUE),
    array('title' => 'scholarship', 'href' => '', 'fragment' => 'scholarship', 'external' => TRUE),
    array('title' => 'send us your pics', 'href' => '', 'fragment' => 'impact', 'external' => TRUE),
    array('title' => 'questions?', 'href' => '', 'fragment' => 'faq', 'external' => TRUE),
  ),
  'menu_suffix' => array(
    '#markup' => '<hr><p>Got questions? Email Sarah at <a href="mailto:thumbwars@dosomething.org">thumbwars@dosomething.org</a>!<br><img src="//www.dosomething.org/files/campaigns/thumb13/sponsors.png" alt="Sprint and Toyota"></p>'
  ),
    'menu_prefix' => array(
    '#markup' => '<p>Go To:</p>'
  ),
);
