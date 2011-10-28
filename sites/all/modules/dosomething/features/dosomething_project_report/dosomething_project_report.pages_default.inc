<?php
/**
 * @file
 * dosomething_project_report.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_project_report_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects';
  $page->task = 'page';
  $page->admin_title = 'projects';
  $page->admin_description = '';
  $page->path = 'projects';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'weight' => 0,
    'name' => 'navigation',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => '0',
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'width_type' => 'px',
    'percent_width' => '505',
    'rows' => '4',
    'row_1' => array(
      'columns' => '1',
      'width_1' => '505',
      'names' => array(
        0 => 'Top',
      ),
    ),
    'row_2' => array(
      'columns' => '1',
      'width_1' => '505',
      'names' => array(
        0 => 'Middle 1',
      ),
    ),
    'row_3' => array(
      'columns' => '2',
      'width_1' => '245',
      'width_2' => '245',
      'names' => array(
        0 => 'Middle 2 left',
        1 => 'Middle 2 right',
      ),
    ),
    'row_4' => array(
      'columns' => '1',
      'width_1' => '505',
      'names' => array(
        0 => 'Bottom',
      ),
    ),
    'sidebars' => array(
      'left' => 0,
      'left_width' => 200,
      'right' => 0,
      'right_width' => 200,
      'width_type' => 'px',
    ),
  );
  $display->panel_settings = array(
    'style' => 'default',
    'style_settings' => array(
      'default' => NULL,
      'row_1_1' => NULL,
      'row_2_1' => NULL,
      'row_3_1' => NULL,
      'row_3_2' => NULL,
      'row_4_1' => NULL,
    ),
    'edit_style' => 'Edit style settings',
    'did' => '20',
    'row_1_1' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
    'row_2_1' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
    'row_3_1' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
    'row_3_2' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
    'row_4_1' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects'] = $page;

  return $pages;

}
