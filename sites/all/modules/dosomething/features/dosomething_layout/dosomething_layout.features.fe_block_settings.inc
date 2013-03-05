<?php
/**
 * @file
 * dosomething_layout.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dosomething_layout_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'dosomething_blocks-dosomething_make_impact' => array(
      'delta' => 'dosomething_make_impact',
      'module' => 'dosomething_blocks',
    ),
    'dosomething_blocks-dosomething_make_impact_front' => array(
      'delta' => 'dosomething_make_impact_front',
      'module' => 'dosomething_blocks',
    ),
    'dosomething_blocks-dosomething_social_node_buttons' => array(
      'delta' => 'dosomething_social_node_buttons',
      'module' => 'dosomething_blocks',
    ),
    'dosomething_blocks-dosomething_social_skyscraper' => array(
      'delta' => 'dosomething_social_skyscraper',
      'module' => 'dosomething_blocks',
    ),
    'dosomething_blocks-dosomething_utility_bar' => array(
      'delta' => 'dosomething_utility_bar',
      'module' => 'dosomething_blocks',
    ),
    'dosomething_campaign_styles-campaign_nav' => array(
      'delta' => 'campaign_nav',
      'module' => 'dosomething_campaign_styles',
    ),
    'dosomething_login-become_member' => array(
      'delta' => 'become_member',
      'module' => 'dosomething_login',
    ),
    'dosomething_login-register_block' => array(
      'delta' => 'register_block',
      'module' => 'dosomething_login',
    ),
    'menu-menu-footer' => array(
      'delta' => 'menu-footer',
      'module' => 'menu',
    ),
  );

  // doit
  $theme = array();

  $theme['dosomething_blocks-dosomething_make_impact'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-70',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>
start-something
action-finder
prank*',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_make_impact_front'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact_front',
    'theme' => 'doit',
    'status' => 0,
    'weight' => '-56',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_social_node_buttons'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_social_node_buttons',
    'theme' => 'doit',
    'status' => 0,
    'weight' => '-54',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_social_skyscraper'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_social_skyscraper',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-69',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'prank*',
    'title' => 'Social Stream',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_utility_bar'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_utility_bar',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-68',
    'region' => 'utility',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_campaign_styles-campaign_nav'] = array(
    'module' => 'dosomething_campaign_styles',
    'delta' => 'campaign_nav',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-75',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'calloffame*',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_login-become_member'] = array(
    'module' => 'dosomething_login',
    'delta' => 'become_member',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-71',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'judge-register
prank*',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_login-register_block'] = array(
    'module' => 'dosomething_login',
    'delta' => 'register_block',
    'theme' => 'doit',
    'status' => 0,
    'weight' => '-4',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['menu-menu-footer'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-61',
    'region' => 'footer',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['theme']['doit'] = $theme;

  // ds
  $theme = array();

  $theme['dosomething_blocks-dosomething_make_impact'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-23',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>
start-something
action-finder
prank*',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_make_impact_front'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact_front',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '-29',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_social_node_buttons'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_social_node_buttons',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '-28',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_social_skyscraper'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_social_skyscraper',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'prank*',
    'title' => 'Social Stream',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_utility_bar'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_utility_bar',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-22',
    'region' => 'utility',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_campaign_styles-campaign_nav'] = array(
    'module' => 'dosomething_campaign_styles',
    'delta' => 'campaign_nav',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-50',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'calloffame*',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_login-become_member'] = array(
    'module' => 'dosomething_login',
    'delta' => 'become_member',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-24',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'judge-register
prank*',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_login-register_block'] = array(
    'module' => 'dosomething_login',
    'delta' => 'register_block',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['menu-menu-footer'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-30',
    'region' => 'footer',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['theme']['ds'] = $theme;

  // picsforpets
  $theme = array();

  $theme['dosomething_blocks-dosomething_make_impact'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-62',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>
start-something
action-finder
prank*',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_make_impact_front'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact_front',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-56',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_social_node_buttons'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_social_node_buttons',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-54',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_social_skyscraper'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_social_skyscraper',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-61',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'prank*',
    'title' => 'Social Stream',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_utility_bar'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_utility_bar',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-68',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_campaign_styles-campaign_nav'] = array(
    'module' => 'dosomething_campaign_styles',
    'delta' => 'campaign_nav',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-69',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'calloffame*',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_login-become_member'] = array(
    'module' => 'dosomething_login',
    'delta' => 'become_member',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-63',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'judge-register
prank*',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_login-register_block'] = array(
    'module' => 'dosomething_login',
    'delta' => 'register_block',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-4',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['menu-menu-footer'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '-61',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['theme']['picsforpets'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export['theme'][$theme_key]);
    }
  }
  return $export;
}
