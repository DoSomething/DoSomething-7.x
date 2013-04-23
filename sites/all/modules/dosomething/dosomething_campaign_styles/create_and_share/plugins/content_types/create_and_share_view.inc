<?php

/**
 *  @file
 *  Create and Share campaigns can call any arbitrary view from the database, which is defined
 *  in a settings.inc file per campaign.  This makes it difficult to specify which view to show
 *  through panels.  This plugin, therefore, gets the settings for the campaign a user is currently
 *  looking at, and loads the view based off of those settings.
 *  
 *  @author Michael Chittenden (mchittenden@dosomething.org)
 *  @date 4/16/13
 */

// Sets up plugin information.
$plugin = array(
  'single' => TRUE,
  'title' => t('Create and Share View Handler'),
  'description' => t('Displays the correct view, given configuration for a Create and Share campaign.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'create_and_share_render_view_handler'
);

/**
 *  Handles the actual view.
 */
function create_and_share_render_view_handler($subtype, $conf, $panel_args, $context) {
  // Sets up a standard block and content.
  $block = new stdClass;
  $content = '';

  // Assuming we're looking at a campaign...
  if ($campaign = create_and_share_is_campaign_page()) {
    // Get the settings...
    $settings = create_and_share_get_settings($campaign);
    // Then load the view.
    $content = views_embed_view($settings['views']['wrapper'], $settings['views']['time-filters']);
  }

  // Set the content of the block.
  $block->content = $content;

  // Return it.
  return $block;
}