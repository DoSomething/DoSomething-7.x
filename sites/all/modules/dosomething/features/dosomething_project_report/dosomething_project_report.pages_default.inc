<?php
/**
 * @file
 * dosomething_project_report.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dosomething_project_report_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'webform_submission_view_panel_context';
  $handler->task = 'webform_submission_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project Reports',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'ds-wider-thinner',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Webform Submission (on webform_submissions.node)',
        'keyword' => 'node',
        'name' => 'entity_from_schema:nid-webform_submission_entity-node',
        'context' => 'argument_entity_id:webform_submission_entity_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from Webform Submission (on webform_submissions.node)',
        'keyword' => 'node',
        'name' => 'entity_from_schema:nid-webform_submission_entity-node',
        'context' => 'argument_entity_id:webform_submission_entity_1',
        'id' => 2,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:webform_submission_entity',
          'settings' => array(
            'type' => array(
              'project_report' => 'project_report',
            ),
          ),
          'context' => 'argument_entity_id:webform_submission_entity_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'one_two';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Title',
      'title' => '',
      'body' => '<h1>%webform_submission_entity:field_project_title</h1>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['left'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'dosomething_blocks-dosomething_social_node_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['left'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'formatter_settings' => array(
        'image_style' => 'rotoslider_homepage_main',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['left'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Project Status',
      'title' => '',
      'body' => '<div id="project-status-ribbon-wrapper"><div id="project-status-ribbon"><div class="project-status">Project Status</div><div class="people-involved"><span class="label">People Involved</span><span class="number">%webform_submission_entity:field-update-people-involved</span></div><div class="people-impacted"><span class="label">People Impacted</span><span class="number">%webform_submission_entity:field-num-people-impacted</span></div></div></div>',
      'format' => '4',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['left'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_essay_build_it';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 1,
      'override_title_text' => 'Plan',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-5'] = $pane;
    $display->panels['left'][4] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_project_goal';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 1,
      'override_title_text' => 'Goal',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $display->content['new-6'] = $pane;
    $display->panels['left'][5] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'fb_social-FB Comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $display->content['new-7'] = $pane;
    $display->panels['left'][6] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Start a Project',
      'title' => '',
      'body' => '<div class="ds-start-project"><a class="ds-button-strong" href="/project-report/start-project" title="Start a Project">START A PROJECT</a></div>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-8'] = $pane;
    $display->panels['right'][0] = 'new-8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['webform_submission_view_panel_context'] = $handler;

  return $export;
}
