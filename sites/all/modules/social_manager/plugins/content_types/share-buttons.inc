<?php

/**
 * @file
 * The standard share buttons allow us access to the Facebook "Like" API
 * and the twitter "Tweet" api.  These are fine for most purposes but generally
 * don't look uniform in their many incarnations across the site.  This plugin
 * provides a "new" set of share buttons that look and act uniformly, yet preserve
 * the original intended purpose.
 *
 * This plugin contains three services:
 *   - Facebook "Recommend" button -- Shares to your wall but no longer "Likes" things.
 *     this is on purpose as the "Like" is slowly being phased out.
 *   - Twitter "Tweet" button -- Completely untouched and in fact uses a template
 *     provided by Twitter itself.
 *   - "Print this page" button -- Links to a printable version of the page.
 *
 * The Tumblr button has been removed.
 *
 * This plugin includes a CSS and JS file specifically to handle Facebook and Twitter
 * functionality, as well as the required twitter and Facebook library.  Plugin-specific
 * CSS and JS can be found in the dosomething_general module, in the "css" and "js" folders,
 * respectively.
 *
 * This plugin may be used on any page, as it attemps to get information from the page
 * itself.
 *
 * @todo Make a pleasant and visually appealing UI for administrators.
 */

// Plugin information array
$plugin = array(
  'single' => TRUE,
  'title' => t('Updated Share Buttons'),
  'description' => t('Displays survey responses and percentages.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_share_buttons'
);

// Builds Share Button plugin.
function dosomething_share_buttons($subtype, $conf, $panel_args, $context) {
  // Include (required) twitter widget
  drupal_add_js('http://platform.twitter.com/widgets.js', 'external');
  // Include (required) Facebook library
  drupal_add_library('connections', 'facebook');

  // Include CSS and JS files specific to this plugin.
  drupal_add_css(drupal_get_path('module', 'social_manager') . '/css/share_buttons.css');
  drupal_add_js(drupal_get_path('module', 'social_manager') . '/js/share-buttons.js');

  $short = shorten_url(url(request_uri(), array('absolute' => TRUE)));

  // Get page data.
  $page = $title = $uri = '';
  if (is_object($context)) {
    $page = reset($context)->data;
    $title = (isset($page->title) ? rawurlencode($page->title) : '(Untitled)');
  }

  $uri = request_uri();
  $url = url($uri, array('absolute' => TRUE));

  // Create the share buttons "template"
  $c = '<div id="facebook-wrapper">
  <a href="#" id="ds-facebook-share-button"><i></i><b>' . t('Recommend') . '</b></a>
  <a href="#" id="facebook-count" class="arrow_box"><span>&nbsp;</span></a>
</div>

<a href="http://twitter.com/share?url=' . $short . '&amp;count=horizontal&amp;via=dosomething&amp;text=' . $title . '&amp;counturl=' . $url . '" class="twitter-share-button service-links-twitter-widget" title="Tweet This" rel="nofollow" target="_blank"><span class="element-invisible">' . t('Tweet Widget') . '</span></a>

<a href="/print' . $uri . '" title="Printable version" class="service-links-print" rel="nofollow" target="_blank"><img typeof="foaf:Image" src="/sites/all/modules/service_links/images/print.png" alt="Print HTML" /></a>';

  // Builds the content 
  $content = array();
  $content[] = array('#markup' => $c);

  // Creates the block
  $block = new StdClass();
  $block->content = $content;

  // Fin!
  return $block;
}