<?php
/**
 * @file
 * dosomething_awesome_things_landing_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_awesome_things_landing_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'awesome_things';
  $page->task = 'page';
  $page->admin_title = 'Awesome Things';
  $page->admin_description = '';
  $page->path = 'awesome-things';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_awesome_things_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'awesome_things';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol_a';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left-top' => NULL,
      'left-bottom-left' => NULL,
      'left-bottom-right' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Awesome-Things';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'left-bottom-left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'This week\'s winner',
      'title' => 'This Week\'s winner',
      'body' => '<div id="">
<img src="http://dosomething.zivtech.com/sites/all/themes/ds/css/images/this-weeks-winner.jpg">
<h3>Coffee Compost</h3>
<p>Max and Coffee 2Compost are providing an innovative service to collect the remnants of coffee.</p>
<a class="ds-button-strong" href="">Apply Now</a>
<a href="">See more winners »</a>
</div>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'this-weeks-winner',
      'css_class' => 'ds-pane-usergen ds-pane-top-left-radius',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['left-bottom-left'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'left-bottom-right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'DoSomethng 11',
      'title' => 'DoSomething 11',
      'body' => '<div id="">
<img src="http://dosomething.zivtech.com/sites/all/themes/ds/css/images/dosomething11.jpg">
<h3>Lorem ipsum dolor</h3>
<p>Aliquam lectus orci, adipiscing et, sodales ac, feugiat non, lacus. Ut dictum velit nec est. Quisque posuere, purus sit amet malesuada blandit, sapien sapien auctor arcu,ultricies. </p>
<a href="#">Meet all 11</a>
</div>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'dosomething11',
      'css_class' => 'ds-pane-user ds-pane-top-right-radius',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-2'] = $pane;
    $display->panels['left-bottom-right'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'left-top';
    $pane->type = 'views_panes';
    $pane->subtype = 'campaign_report_back-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['left-top'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'left-top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Schools & Clubs',
      'title' => 'Schools & Clubs',
      'body' => '<div id="">
<span>The deeper you roll, the more good you can do. So grab 4 friends or classmates and team up to make a difference.</span>
<img src="http://dosomething.zivtech.com/sites/all/themes/ds/css/images/school-and-clubs.jpg">
<a class="ds-button-strong" href="">Learn More</a>
</div>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'schools-and-clubs',
      'css_class' => 'ds-pane-top-radius',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-4'] = $pane;
    $display->panels['left-top'][1] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'blog_center';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => 'Blog Center',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'ds-pane-news',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['right'][0] = 'new-5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['awesome_things'] = $page;

  return $pages;

}
