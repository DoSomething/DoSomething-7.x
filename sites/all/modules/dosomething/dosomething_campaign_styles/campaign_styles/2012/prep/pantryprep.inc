<?php
$plugin = array(
  // Campaign title. Not used yet, but please set it.
  'title' => 'Pantry Prep',

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
    array('title' => 'take action', 'href' => 'pantryprep', 'fragment' => 'action'),
    array('title' => 'find a pantry', 'href' => 'pantryprep', 'fragment' => 'search'),
    array('title' => '$5,000 scholarship', 'href' => 'pantryprep', 'fragment' => 'impact'),
    array('title' => 'tell us about it', 'href' => 'pantryprep', 'fragment' => 'impact'),
    array('title' => 'questions?', 'href' => 'pantryprep', 'fragment' => 'faq'),
  ),
  'menu_suffix' => array(
    '#markup' => '<div class="clearfix"><p id="tackle-pounds"></p><p>Pounds<br>Collected</p></div><p>Got questions? Email Christina at <a href="mailto:tackle@dosomething.org">pantryprep@dosomething.org</a>!</p>'
  ),
    'menu_prefix' => array(
    '#markup' => '<p>Go To:</p>'
  ),
);
