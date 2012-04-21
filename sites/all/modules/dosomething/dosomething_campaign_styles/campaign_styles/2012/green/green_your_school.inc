<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'CAMPAIGN TITLE',

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
    array('title' => 'home', 'href' => 'green-your-school'),
    array('title' => 'project ideas', 'href' => 'green-your-school/project-ideas'),
    array('title' => 'browse schools', 'href' => 'green-your-school/browse-schools'),
    array('title' => 'dont be trashy', 'href' => 'trashy', 'attributes' => array('target' => '_blank')),
    array('title' => 'prizes', 'href' => 'green-your-school/prizes'),
    array('title' => 'faq', 'href' => 'green-your-school/faq'),
    array('title' => 'tell us about it', 'href' => 'green-your-school/tell-us'),
  ),
);
