<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Foot Locker Internal',

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
    array('title' => 'home', 'href' => 'footlocker/associate'),
    array('title' => 'about', 'href' => 'footlocker/associate/about'),
    array('title' => 'apply', 'href' => 'footlocker/associate/status'),
    array('title' => 'faq', 'href' => 'footlocker/associate/faq'),
  ),
);
