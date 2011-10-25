<?php
/**
 * @file
 * dosomething_members_only.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_members_only_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'club_hub';
  $page->task = 'page';
  $page->admin_title = 'Club Hub';
  $page->admin_description = '';
  $page->path = 'club-hub';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'ClubHub',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_club_hub_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'club_hub';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'one_two_one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'mid-left' => NULL,
      'mid-right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Club Hub';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'mid-left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Club Hub',
      'title' => '',
      'body' => 'Estery, Hard Cider Cask Conditioned Ale Nebuchadnezzar; Musty." Original Gravity, Fermentation; Mouthfeel Malt Mug Astringent Priming. Lambic Dry beer. Fermentation Dortmunder Imperial. Tart Gueuze.

Grist Brewhouse Bock Heat Exchanger, " Oxidized Secondary Fermentation?" Berliner Weisse Estery, Flute Firkin Pitch Chill Haze Hops Final Gravity, Final Gravity. Centrifugation Dunkle Pilsner Yeast Dunkle. Fruity, Attenuation, Winy Oxygenation Double Magnum Mead Jeroboam Musty Bottle Conditioning. Caramel Diacetyl Crystal malt Hogshead, Lupulin Malt Liquor. Krug; Yard Dry beer.
<ul>
<li>Ester Wort Chiller, Gueuze Mouthfeel Wheat beer glass Brown ale Trappist! 
<li>Hang Gueuze Specific Gravity Caramel malt Wheat beer glass. 
<li>Wit Tart Steam Beer Steam Beer Heat Exchanger?
</ul>
 Infusion Malt Extract. Astringent Noble Hops Mug Pilsner Pub glass Zymurgy; Ale. Bung Draugh Double Magnum Yard Conditioning Tank Body, " Berliner Weisse Bottle Conditioning." Primary Fermentation Noble Hops, Filter All-malt.
',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['mid-left'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'dosomething_blocks-dosomething_social_node_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-2'] = $pane;
    $display->panels['top'][0] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['club_hub'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'members_only';
  $page->task = 'page';
  $page->admin_title = 'Members Only';
  $page->admin_description = '';
  $page->path = 'members-only';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_members_only_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'members_only';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Members Only',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'one_two_one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'mid-left' => NULL,
      'mid-right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Members Only Slideshow',
      'title' => '',
      'body' => '<img src="/files/members_only_slide.jpg" alt=""/>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['top'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Members Only Blocks',
      'title' => '',
      'body' => '<table>
  <tr>
  <td>MySomethings [logged in: mySomethings page, not logged in: access denied page]</td>
  <td>What is membership [standard content page]</td>
  <td>How to become a member [standard content page]</td>
  </tr>
  <tr>
  <td>Membership benefits [standard content page]</td>
  <td>Grants [Grants page]</td>
  <td><a href="/scholarships">Scholarships</a></td>
  </tr>
  <tr>
  <td><a href="/club-hub">Club Hub</a></td>
  <td>FAQs [standard content page]</td>
  </tr>
  </table>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['top'][1] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['members_only'] = $page;

  return $pages;
}
