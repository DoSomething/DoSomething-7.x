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

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'webform_submission_view_http_response';
  $handler->task = 'webform_submission_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'HTTP response code',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '404',
    'destination' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'access all webform results',
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['webform_submission_view_http_response'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'webform_submission_view_panel_context';
  $handler->task = 'webform_submission_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
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
  $display = new panels_display();
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '28800',
    ),
  );
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'project_photo_slider-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:webform_submission_entity_1',
      ),
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $display->content['new-1'] = $pane;
    $display->panels['left'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'left';
    $pane->type = 'ds_project_stats';
    $pane->subtype = 'ds_project_stats';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $display->content['new-2'] = $pane;
    $display->panels['left'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_essay_see_it';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 1,
      'override_title_text' => 'The Problem',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = '';
    $display->content['new-3'] = $pane;
    $display->panels['left'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_essay_build_it';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 1,
      'override_title_text' => 'Plan of Action',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = '';
    $display->content['new-4'] = $pane;
    $display->panels['left'][3] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'left';
    $pane->type = 'ds_website_link';
    $pane->subtype = 'ds_website_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['left'][4] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_others_involved';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 1,
      'override_title_text' => 'How You Can Get Involved',
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = '';
    $display->content['new-6'] = $pane;
    $display->panels['left'][5] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'project_updates-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'fields_override' => array(
        'body' => 1,
        'field_embedded_video' => 1,
        'field_project_photo' => 1,
      ),
      'context' => array(
        0 => 'argument_entity_id:webform_submission_entity_1',
      ),
      'override_title' => 0,
      'override_title_text' => 'Updates',
      'arguments' => array(
        'sid' => '',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = '';
    $display->content['new-7'] = $pane;
    $display->panels['left'][6] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_webform_videos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'media',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'file_view_mode' => 'default',
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
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['left'][7] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'left';
    $pane->type = 'dosomething_start_button';
    $pane->subtype = 'dosomething_start_button';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'start_button' => array(
        'project' => TRUE,
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = '';
    $display->content['new-9'] = $pane;
    $display->panels['left'][8] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:taxonomy_vocabulary_5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = '';
    $display->content['new-10'] = $pane;
    $display->panels['left'][9] = 'new-10';
    $pane = new stdClass();
    $pane->pid = 'new-11';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_projects-action_sidebar_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 0,
      'items_per_page' => '5',
      'context' => array(
        0 => 'argument_entity_id:webform_submission_entity_1',
        1 => 'argument_entity_id:webform_submission_entity_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Related Stuff',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'ds-arrow-list ds-pane ds-arrow-list ds-pane ds-internal-sidebar-flush-right ds-pane-no-radius ds-pane-usergen',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $display->content['new-11'] = $pane;
    $display->panels['right'][0] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Title',
      'title' => '',
      'body' => '<h1 class="title" id="page-title">%webform_submission_entity:field_project_title</h1>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $display->content['new-12'] = $pane;
    $display->panels['top'][0] = 'new-12';
    $pane = new stdClass();
    $pane->pid = 'new-13';
    $pane->panel = 'top';
    $pane->type = 'share-buttons';
    $pane->subtype = 'share-buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-13'] = $pane;
    $display->panels['top'][1] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'service_links-service_links_not_node';
    $pane->shown = FALSE;
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
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-14'] = $pane;
    $display->panels['top'][2] = 'new-14';
    $pane = new stdClass();
    $pane->pid = 'new-15';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit own webform submissions',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Edit link',
      'title' => '',
      'body' => '<a href="/node/%webform_submission_entity:nid/submission/%webform_submission_entity:sid/edit">Edit</a>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-15'] = $pane;
    $display->panels['top'][3] = 'new-15';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['webform_submission_view_panel_context'] = $handler;

  return $export;
}
