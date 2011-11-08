<?php
/**
 * @file
 * dosomething_clubs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_clubs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_clubs_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_clubs_node_info() {
  $items = array(
    'club' => array(
      'name' => t('Club'),
      'base' => 'node_content',
      'description' => t('A group of like-minded people.'),
      'has_title' => '1',
      'title_label' => t('School Name'),
      'help' => t('<p>Welcome to the Do Something Clubs sign up form. Join the network of over 1000 Do Something Clubs across the country taking action in their local communities. Just answer the questions below and we\'ll get you all set up.</p>

<p>After filling out this form, we\'ll give you tons of options, like getting your first meeting sponsored by DoSomething.org, receiving a welcome package, joining a support call, and lots more.</p>

<p>Just a reminder - the Do Something Clubs program is for anyone 25 and under. Each Club needs to have at least 5 members and complete and report back on at least 2 projects each year. The deadline for your first project report back is <strong>December 31st, 2011</strong>.</p>

<p>Have any questions? Email our Clubs team at clubs@dosomething.org and we\'ll help you out.</p>'),
    ),
  );
  return $items;
}
