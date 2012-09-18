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
    array('title' => 'here\' what you do', 'href' => 'spit12', 'fragment' => 'action'),
    array('title' => 'search for a drive', 'href' => 'spit12', 'fragment' => 'search'),
    array('title' => '$5,000 scholarship', 'href' => 'spit12', 'fragment' => 'scholarship'),
    array('title' => 'tell us about it', 'href' => 'spit12/report-back'),
    array('title' => 'questions?', 'href' => 'spit12', 'fragment' => 'faq'),
  ),
);
