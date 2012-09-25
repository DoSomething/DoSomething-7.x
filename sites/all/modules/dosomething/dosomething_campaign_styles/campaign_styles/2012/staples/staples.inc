<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Staples For Students',

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
    array('title' => 'home', 'href' => 'staples'),
    //array('title' => 'run a drive', 'href' => 'staples/run-a-drive'),
    //array('title' => 'raise your hand', 'href' => 'staples/raise-your-hand'),
    //array('title' => 'tell us about it', 'href' => 'staples/tell-us'),
    //array('title' => 'scholarships & prizes', 'href' => 'staples/prizes'),
    array('title' => 'faq', 'href' => 'staples/faq'),
    array('title' => 'blog', 'href' => 'staples/blog'),
    array('title' => 'gallery', 'href' => 'staples/gallery'),
  ),
);
