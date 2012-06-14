<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Hunt',

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
    array('title' => 'home', 'href' => 'hunt'),
    array('title' => 'challenges', 'href' => 'hunt/challenges'),
    array('title' => 'my team', 'href' => 'my-team/hunt'),
    array('title' => 'win stuff', 'href' => 'hunt/prizes'),
    array('title' => 'quiz', 'href' => 'hunt/quiz'),
    array('title' => 'faq', 'href' => 'hunt/faq'),
    array('title' => 'blog', 'href' => 'hunt/blog'),
    array('title' => 'gallery', 'href' => 'hunt/gallery'),
  ),
);
