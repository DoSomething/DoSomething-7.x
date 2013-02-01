<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Mind On My Money',

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
    array('title' => 'sign up', 'href' => 'savings', 'fragment' => 'header'),
    array('title' => 'scholarship', 'href' => 'savings', 'fragment' => 'scholoarship'),
    array('title' => 'tell us about it', 'href' => 'savings/report-back'),
    array('title' => 'video', 'href' => 'savings', 'fragment' => 'video'),
    array('title' => 'questions', 'href' => 'savings', 'fragment' => 'faq'),
  ),
  'menu_suffix' => array(
    '#markup' => '<hr><img src="//files.dosomething.org/files/campaigns/savings/momm-hrblock-logo.png"><p>Got questions? Email Greg at <a href="mailto:save@dosomething.org">save@dosomething.org</a>!</p>'
  ),
    'menu_prefix' => array(
    '#markup' => '<p>Go To:</p>'
  ),
);
