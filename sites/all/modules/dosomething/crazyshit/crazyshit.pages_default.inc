<?php
/**
 * @file
 * crazyshit.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function crazyshit_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'crazy_friends_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Crazy Friends Landing Page';
  $page->admin_description = '';
  $page->path = 'crazy/friends';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
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
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_crazy_friends_landing_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'crazy_friends_landing_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Invite Friends Button',
      'title' => '',
      'body' => '<a href="#" onclick="return fb_invite_friends()" id="invite-friends-button" class="fb-invite-friends">Invite Friends</a>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'crazy_shit_landing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'friends_view',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['crazy_friends_landing_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'crazy_scholarship';
  $page->task = 'page';
  $page->admin_title = 'Crazy #@%# Scholarship';
  $page->admin_description = '';
  $page->path = 'crazy/about';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'crazy/about*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $handler->name = 'page_crazy_scholarship_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'crazy_scholarship';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'center';
    $pane->type = 'crazy_html';
    $pane->subtype = 'crazy_html';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'html_source' => '0',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['center'][0] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['crazy_scholarship'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'crazy_shit_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Crazy Shit Landing Page';
  $page->admin_description = 'Landing page for the Crazy Shit campaign';
  $page->path = 'crazy';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
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
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_crazy_shit_landing_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'crazy_shit_landing_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'crazy_shit_landing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['center'][0] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['crazy_shit_landing_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'crazy_submit_start';
  $page->task = 'page';
  $page->admin_title = 'Crazy #@%# Submit Start';
  $page->admin_description = '';
  $page->path = 'crazy/submit/start';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'crazy/submit/start',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
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
  $handler->name = 'page_crazy_submit_start_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'crazy_submit_start';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'center';
    $pane->type = 'crazy_html';
    $pane->subtype = 'crazy_html';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'html_source' => 'about-submit.html',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'submit-start',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['center'][0] = 'new-5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['crazy_submit_start'] = $page;

  return $pages;

}
