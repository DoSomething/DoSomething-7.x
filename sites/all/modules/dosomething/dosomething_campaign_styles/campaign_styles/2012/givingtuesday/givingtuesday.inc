<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Old People',

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
    array('title' => 'what is it?', 'href' => 'oldpeople', 'fragment' => 'action'),
    array('title' => 'share with old people', 'href' => 'oldpeople', 'fragment' => 'refer'),
    array('title' => 'take the quiz', 'href' => 'oldpeople', 'fragment' => 'quiz'),    
    array('title' => 'faqs', 'href' => 'oldpeople', 'fragment' => 'faq'),
  ),
  'menu_suffix' => array(
    '#markup' => '<div class="nav-count clearfix"><p id="sb-counter"></p><p>Quizzes<br>Taken</p></div><p class="email">Got questions? Email Liz at <a href="mailto:eeddy@dosomething.org">eeddy@dosomething.org</a>!</p>'
  ),
    'menu_prefix' => array(
    '#markup' => '<img class="bow" src="//files.dosomething.org/files/campaigns/tuesday12/bow.png" /> <p>Go To:</p>'
  ),
);
