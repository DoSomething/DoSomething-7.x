<?php
/**
 * @file
 * share_a_stat_scholarship.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function share_a_stat_scholarship_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Social Scholarship',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_scholarship' => 'social_scholarship',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
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
          0 => 11,
          1 => 2,
        ),
        'parent' => 'canvas',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 3,
          1 => 4,
        ),
        'parent' => 'main',
        'class' => '',
      ),
      3 => array(
        'type' => 'column',
        'width' => '50.035843850763214',
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 6,
        ),
        'class' => 'dosomething-share-a-stat-statistics',
      ),
      4 => array(
        'type' => 'column',
        'width' => '49.964156149236615',
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 7,
        ),
        'class' => 'dosomething-share-a-stat-form-image',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'statistics',
        ),
        'parent' => '3',
        'class' => '',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'form___image',
        ),
        'parent' => '4',
        'class' => '',
      ),
      'statistics' => array(
        'type' => 'region',
        'title' => 'Statistics',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
      ),
      'form___image' => array(
        'type' => 'region',
        'title' => 'Form / Image',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => '',
      ),
      11 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'social_stuff_',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'social_stuff_' => array(
        'type' => 'region',
        'title' => 'Top Social stuff',
        'width' => 100,
        'width_type' => '%',
        'parent' => '11',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'form___image';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:webform';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'current_webform_submitted',
          'settings' => NULL,
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:node_1',
          ),
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Send 5 friends stats to win a $5,000 scholarship',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'ds-campaign-scholarship-submit-form',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['form___image'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'social_stuff_';
    $pane->type = 'shary_images';
    $pane->subtype = 'shary_images';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'current_webform_submitted',
          'settings' => NULL,
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['social_stuff_'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'social_stuff_';
    $pane->type = 'block';
    $pane->subtype = 'service_links-service_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['social_stuff_'][1] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'statistics';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Quick Stats',
      'title' => '',
      'body' => '<h2>Quick Stats</h2>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['statistics'][0] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'statistics';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'current_webform_submitted',
          'settings' => NULL,
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:node_1',
          ),
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Quick Stats',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'quick-stats-area',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['statistics'][1] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'statistics';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'current_webform_submitted',
          'settings' => NULL,
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:node_1',
          ),
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Did these shock you?',
      'title' => '',
      'body' => 'Did these stats shock you? They sure shocked us! Help us spread the word about animal cruelty by sending these facts to your friends. Enter the phone numbers of 5 of your friends in the box to the right and you’ll be automatically entered to win a $5,000 scholarship.',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['statistics'][2] = 'new-6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  return $export;
}
