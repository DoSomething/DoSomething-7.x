<?php
/**
 * @file
 * dosomething_causes.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dosomething_causes_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Cause page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Taxonomy vocabulary',
        'keyword' => 'taxonomy_vocabulary',
        'name' => 'entity:taxonomy_vocabulary',
        'id' => '5',
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'vids' => array(
              5 => '5',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 5,
          1 => 4,
          2 => 1,
          3 => 2,
          4 => 3,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'issues_left',
          1 => 'top_right',
          2 => 'issues_right_',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'top_right' => array(
        'type' => 'region',
        'title' => 'Issues Middle',
        'width' => '33.44442922440388',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bottom_',
          1 => 'right_center',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'bottom_' => array(
        'type' => 'region',
        'title' => 'Left Center',
        'width' => '52.3577296304569',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bottom',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'bottom' => array(
        'type' => 'region',
        'title' => 'Causes Bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      'right_center' => array(
        'type' => 'region',
        'title' => 'Right Center',
        'width' => '47.6422703695431',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'issues_right',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'top_left_',
          1 => 'top_right_',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'top_left_' => array(
        'type' => 'region',
        'title' => 'Top Left',
        'width' => '61.292284019556746',
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
      ),
      'top_right_' => array(
        'type' => 'region',
        'title' => 'Causes Top Right',
        'width' => '38.707715980443254',
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
      ),
      'issues_right' => array(
        'type' => 'region',
        'title' => 'Issues Top Bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
      ),
      'issues_left' => array(
        'type' => 'region',
        'title' => 'Issues Left',
        'width' => '34.24118301873123',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      'issues_right_' => array(
        'type' => 'region',
        'title' => 'Issues Right',
        'width' => '32.314387756864875',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'top_right' => NULL,
      'bottom_' => NULL,
      'bottom' => NULL,
      'right_center' => NULL,
      'top_bottom' => NULL,
      'top_left' => NULL,
      'top_left_' => NULL,
      'top_right_' => NULL,
      'issues_left' => NULL,
      'issues_right' => NULL,
      'issues_right_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:name';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'current_campaigns-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'term_parent',
          'settings' => array(
            'vid' => '5',
          ),
          'context' => 'argument_term_1',
          'not' => TRUE,
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
    $display->content['new-1'] = $pane;
    $display->panels['bottom'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'bottom_';
    $pane->type = 'views_panes';
    $pane->subtype = 'blogs-panel_pane_1';
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
    $display->content['new-2'] = $pane;
    $display->panels['bottom_'][0] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'issues_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'current_campaigns-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'term_parent',
          'settings' => array(
            'vid' => '5',
          ),
          'context' => 'argument_term_1',
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
    $display->panels['issues_right'][0] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'right_center';
    $pane->type = 'views';
    $pane->subtype = 'polls';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
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
    $display->content['new-4'] = $pane;
    $display->panels['right_center'][0] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'top_left_';
    $pane->type = 'views_panes';
    $pane->subtype = 'causes-panel_pane_1';
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
    $display->content['new-5'] = $pane;
    $display->panels['top_left_'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'top_right_';
    $pane->type = 'views_panes';
    $pane->subtype = 'causes-panel_pane_2';
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
    $display->content['new-6'] = $pane;
    $display->panels['top_right_'][0] = 'new-6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}
