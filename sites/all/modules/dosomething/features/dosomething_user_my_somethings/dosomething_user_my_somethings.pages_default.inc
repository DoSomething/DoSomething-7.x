<?php
/**
 * @file
 * dosomething_user_my_somethings.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dosomething_user_my_somethings_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_my_somethings';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'My Somethings',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'user-my-somethings',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Logged in user',
        'keyword' => 'user_2',
        'name' => 'user',
        'type' => 'current',
        'uid' => NULL,
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_three_one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'mid-left' => NULL,
      'mid-center' => NULL,
      'mid-right' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Member Profile';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'footer';
    $pane->type = 'views_panes';
    $pane->subtype = 'member_profile-panel_pane_1';
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
    $display->content['new-1'] = $pane;
    $display->panels['footer'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'mid-center';
    $pane->type = 'ds_past_somethings';
    $pane->subtype = 'ds_past_somethings';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'user/*/doing-it
user/*/done-it
user/*/picks',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-2'] = $pane;
    $display->panels['mid-center'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'mid-left';
    $pane->type = 'ds_current_somethings';
    $pane->subtype = 'ds_current_somethings';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'user/*/doing-it
user/*/done-it
user/*/picks',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['mid-left'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'mid-right';
    $pane->type = 'views_panes';
    $pane->subtype = 'profile-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'user/*/doing-it
user/*/done-it
user/*/picks',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-4'] = $pane;
    $display->panels['mid-right'][0] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'fb_social-FB Facepile Profile';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['top'][0] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'top';
    $pane->type = 'ds_profile_info';
    $pane->subtype = 'ds_profile_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-6'] = $pane;
    $display->panels['top'][1] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'top';
    $pane->type = 'ds_current_somethings_all';
    $pane->subtype = 'ds_current_somethings_all';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/doing-it',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-7'] = $pane;
    $display->panels['top'][2] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'top';
    $pane->type = 'ds_past_somethings_all';
    $pane->subtype = 'ds_past_somethings_all';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/done-it',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-8'] = $pane;
    $display->panels['top'][3] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'top';
    $pane->type = 'views_panes';
    $pane->subtype = 'profile-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/picks',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-ds-editors-picks-all',
    );
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-9'] = $pane;
    $display->panels['top'][4] = 'new-9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_my_somethings'] = $handler;

  return $export;
}
