<?php
/**
 * @file
 * teams.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function teams_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'team_pages';
  $page->task = 'page';
  $page->admin_title = 'Team Pages';
  $page->admin_description = '';
  $page->path = 'team/%campaign/%sid';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'campaign' => array(
      'id' => 1,
      'identifier' => 'campaign_name',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'sid' => array(
      'id' => 1,
      'identifier' => 'Webform Submission: ID',
      'name' => 'entity_id:webform_submission_entity',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_team_pages_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'team_pages';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Test',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node',
        'keyword' => 'node_3',
        'name' => 'entity:node',
        'entity_id' => '719306',
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Webform Submission (on webform_submissions.node)',
        'keyword' => 'node',
        'name' => 'entity_from_schema:nid-webform_submission_entity-node',
        'context' => 'argument_entity_id:webform_submission_entity_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'OG group from Node (on Node: Groups audience [group_audience])',
        'keyword' => 'group',
        'name' => 'entity_from_field:group_audience-node-group',
        'delta' => '0',
        'context' => 'relationship_entity_from_schema:nid-webform_submission_entity-node_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Node from OG group',
        'keyword' => 'node_2',
        'name' => 'og_node_from_group',
        'context' => 'relationship_entity_from_field:group_audience-node-group_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'test-campaign',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'campaign';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'flexible-top';
    $pane->type = 'block';
    $pane->subtype = 'teams-team_management';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['flexible-top'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'logo';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campaign_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'campaign_microsite_logo',
        'image_link' => 'content',
      ),
      'context' => 'relationship_og_node_from_group_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['logo'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'logo';
    $pane->type = 'token';
    $pane->subtype = 'node:nid';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'relationship_og_node_from_group_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['logo'][1] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'mini-info';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => 'Test!',
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
    $display->panels['mini-info'][0] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_team_pages_panel_context_4';
  $handler->task = 'page';
  $handler->subtask = 'team_pages';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Hunt Beta',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node',
        'keyword' => 'node_3',
        'name' => 'entity:node',
        'entity_id' => '722344',
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Webform Submission (on webform_submissions.node)',
        'keyword' => 'node',
        'name' => 'entity_from_schema:nid-webform_submission_entity-node',
        'context' => 'argument_entity_id:webform_submission_entity_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'OG group from Node (on Node: Groups audience [group_audience])',
        'keyword' => 'group',
        'name' => 'entity_from_field:group_audience-node-group',
        'delta' => '0',
        'context' => 'relationship_entity_from_schema:nid-webform_submission_entity-node_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Node from OG group',
        'keyword' => 'node_2',
        'name' => 'og_node_from_group',
        'context' => 'relationship_entity_from_field:group_audience-node-group_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'hunt',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'campaign';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'flexible-bot';
    $pane->type = 'panels_mini';
    $pane->subtype = 'the_hunt_2012';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '.white-bg',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['flexible-bot'][0] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'flexible-bot';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Sponsor Logos',
      'title' => '',
      'body' => '<div class="sponsor-logos">
<img src="http://files.dosomething.org/files/campaigns/hunt/bing.png" />
<img src="http://files.dosomething.org/files/campaigns/hunt/lenovo.png" />
</div>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white-bg',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['flexible-bot'][1] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'flexible-bot';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Got Questions?',
      'title' => '',
      'body' => '<div class="got_questions">
  <p">Got questions? Email us at <a href="mailto:hunt@dosomething.org">hunt@dosomething.org</a>!</p>
</div>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white-bg',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['flexible-bot'][2] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'flexible-mid';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<center>Mobile pictures coming soon.</center>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['flexible-mid'][0] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'flexible-mid';
    $pane->type = 'views_panes';
    $pane->subtype = 'hunt_team_gallery-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-9'] = $pane;
    $display->panels['flexible-mid'][1] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'flexible-top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Header information',
      'title' => '',
      'body' => '<h2>The Hunt begins on July 10th. Invite more team mates below to increase your chances at a scholarship!</h2>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white-bg header-info',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['flexible-top'][0] = 'new-10';
    $pane = new stdClass();
    $pane->pid = 'new-11';
    $pane->panel = 'flexible-top';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_team_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'team-name-title',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-11'] = $pane;
    $display->panels['flexible-top'][1] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
    $pane->panel = 'flexible-top';
    $pane->type = 'block';
    $pane->subtype = 'teams-team_management';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'team-pane',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-12'] = $pane;
    $display->panels['flexible-top'][2] = 'new-12';
    $pane = new stdClass();
    $pane->pid = 'new-13';
    $pane->panel = 'flexible-top';
    $pane->type = 'team_progress';
    $pane->subtype = 'team_progress';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'challenges' => '722991
722992
722993
722994
722995
722996
722997
722998
722999
723000',
      'start_date' => array(
        'month' => '7',
        'day' => '10',
        'year' => '2012',
      ),
      'override_title' => 1,
      'override_title_text' => 'Activity Feed',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-13'] = $pane;
    $display->panels['flexible-top'][3] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
    $pane->panel = 'logo';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campaign_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'campaign_microsite_logo',
        'image_link' => 'content',
      ),
      'context' => 'relationship_og_node_from_group_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-14'] = $pane;
    $display->panels['logo'][0] = 'new-14';
    $pane = new stdClass();
    $pane->pid = 'new-15';
    $pane->panel = 'logo';
    $pane->type = 'token';
    $pane->subtype = 'node:nid';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'relationship_og_node_from_group_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-15'] = $pane;
    $display->panels['logo'][1] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
    $pane->panel = 'mini-info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campain_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'campaign_label',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'context_entity:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-16'] = $pane;
    $display->panels['mini-info'][0] = 'new-16';
    $pane = new stdClass();
    $pane->pid = 'new-17';
    $pane->panel = 'mini-info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campaign_teaser';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'context_entity:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-17'] = $pane;
    $display->panels['mini-info'][1] = 'new-17';
    $pane = new stdClass();
    $pane->pid = 'new-18';
    $pane->panel = 'social';
    $pane->type = 'campaign_social';
    $pane->subtype = 'campaign_social';
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
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-18'] = $pane;
    $display->panels['social'][0] = 'new-18';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_team_pages_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'team_pages';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Hunt',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node',
        'keyword' => 'node_3',
        'name' => 'entity:node',
        'entity_id' => '722344',
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Webform Submission (on webform_submissions.node)',
        'keyword' => 'node',
        'name' => 'entity_from_schema:nid-webform_submission_entity-node',
        'context' => 'argument_entity_id:webform_submission_entity_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'OG group from Node (on Node: Groups audience [group_audience])',
        'keyword' => 'group',
        'name' => 'entity_from_field:group_audience-node-group',
        'delta' => '0',
        'context' => 'relationship_entity_from_schema:nid-webform_submission_entity-node_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Node from OG group',
        'keyword' => 'node_2',
        'name' => 'og_node_from_group',
        'context' => 'relationship_entity_from_field:group_audience-node-group_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'hunt',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'campaign';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-19';
    $pane->panel = 'flexible-bot';
    $pane->type = 'panels_mini';
    $pane->subtype = 'the_hunt_2012';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '.white-bg',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-19'] = $pane;
    $display->panels['flexible-bot'][0] = 'new-19';
    $pane = new stdClass();
    $pane->pid = 'new-20';
    $pane->panel = 'flexible-bot';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Sponsor Logos',
      'title' => '',
      'body' => '<div class="sponsor-logos">
<img src="http://files.dosomething.org/files/campaigns/hunt/bing.png" />
<img src="http://files.dosomething.org/files/campaigns/hunt/lenovo.png" />
</div>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white-bg',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-20'] = $pane;
    $display->panels['flexible-bot'][1] = 'new-20';
    $pane = new stdClass();
    $pane->pid = 'new-21';
    $pane->panel = 'flexible-bot';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Got Questions?',
      'title' => '',
      'body' => '<div class="got_questions">
  <p">Got questions? Email us at <a href="mailto:hunt@dosomething.org">hunt@dosomething.org</a>!</p>
</div>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white-bg',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-21'] = $pane;
    $display->panels['flexible-bot'][2] = 'new-21';
    $pane = new stdClass();
    $pane->pid = 'new-22';
    $pane->panel = 'flexible-top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Header information',
      'title' => '',
      'body' => '<h2>The Hunt begins on July 10th. Invite more team mates below to increase your chances at a scholarship!</h2>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white-bg header-info',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-22'] = $pane;
    $display->panels['flexible-top'][0] = 'new-22';
    $pane = new stdClass();
    $pane->pid = 'new-23';
    $pane->panel = 'flexible-top';
    $pane->type = 'entity_field';
    $pane->subtype = 'webform_submission_entity:field_team_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:webform_submission_entity_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'team-name-title',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-23'] = $pane;
    $display->panels['flexible-top'][1] = 'new-23';
    $pane = new stdClass();
    $pane->pid = 'new-24';
    $pane->panel = 'flexible-top';
    $pane->type = 'block';
    $pane->subtype = 'teams-team_management';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-24'] = $pane;
    $display->panels['flexible-top'][2] = 'new-24';
    $pane = new stdClass();
    $pane->pid = 'new-25';
    $pane->panel = 'logo';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campaign_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'campaign_microsite_logo',
        'image_link' => 'content',
      ),
      'context' => 'relationship_og_node_from_group_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-25'] = $pane;
    $display->panels['logo'][0] = 'new-25';
    $pane = new stdClass();
    $pane->pid = 'new-26';
    $pane->panel = 'logo';
    $pane->type = 'token';
    $pane->subtype = 'node:nid';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'relationship_og_node_from_group_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-26'] = $pane;
    $display->panels['logo'][1] = 'new-26';
    $pane = new stdClass();
    $pane->pid = 'new-27';
    $pane->panel = 'mini-info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campain_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'campaign_label',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'context_entity:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-27'] = $pane;
    $display->panels['mini-info'][0] = 'new-27';
    $pane = new stdClass();
    $pane->pid = 'new-28';
    $pane->panel = 'mini-info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campaign_teaser';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'context_entity:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-28'] = $pane;
    $display->panels['mini-info'][1] = 'new-28';
    $pane = new stdClass();
    $pane->pid = 'new-29';
    $pane->panel = 'social';
    $pane->type = 'campaign_social';
    $pane->subtype = 'campaign_social';
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
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-29'] = $pane;
    $display->panels['social'][0] = 'new-29';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_team_pages_panel_context_5';
  $handler->task = 'page';
  $handler->subtask = 'team_pages';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Spit',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'cmp',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node',
        'keyword' => 'node_3',
        'name' => 'entity:node',
        'entity_id' => '722344',
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Webform Submission (on webform_submissions.node)',
        'keyword' => 'node',
        'name' => 'entity_from_schema:nid-webform_submission_entity-node',
        'context' => 'argument_entity_id:webform_submission_entity_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'OG group from Node (on Node: Groups audience [group_audience])',
        'keyword' => 'group',
        'name' => 'entity_from_field:group_audience-node-group',
        'delta' => '0',
        'context' => 'relationship_entity_from_schema:nid-webform_submission_entity-node_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Node from OG group',
        'keyword' => 'node_2',
        'name' => 'og_node_from_group',
        'context' => 'relationship_entity_from_field:group_audience-node-group_1',
        'id' => 1,
      ),
      3 => array(
        'identifier' => 'Drive Group',
        'keyword' => 'drive_group',
        'name' => 'entity_from_field:group_audience-webform_submission_entity-group',
        'delta' => '0',
        'context' => 'argument_entity_id:webform_submission_entity_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'spit',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'campaign';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-30';
    $pane->panel = 'flexible-bot';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'og_perm',
          'settings' => array(
            'perm' => 'administer group',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Is Admin',
      'title' => '',
      'body' => '',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-30'] = $pane;
    $display->panels['flexible-bot'][0] = 'new-30';
    $pane = new stdClass();
    $pane->pid = 'new-31';
    $pane->panel = 'flexible-bot';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'og_member',
          'settings' => array(
            'state' => array(
              1 => '1',
            ),
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'og_perm',
          'settings' => array(
            'perm' => 'administer group',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Part of group, not admin',
      'title' => '',
      'body' => '',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-31'] = $pane;
    $display->panels['flexible-bot'][1] = 'new-31';
    $pane = new stdClass();
    $pane->pid = 'new-32';
    $pane->panel = 'flexible-bot';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'og_member',
          'settings' => array(
            'state' => array(
              1 => '1',
            ),
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Not part of group',
      'title' => '',
      'body' => '',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-32'] = $pane;
    $display->panels['flexible-bot'][2] = 'new-32';
    $pane = new stdClass();
    $pane->pid = 'new-33';
    $pane->panel = 'flexible-mid';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'html_source' => '2012/spit/html/content.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-33'] = $pane;
    $display->panels['flexible-mid'][0] = 'new-33';
    $pane = new stdClass();
    $pane->pid = 'new-34';
    $pane->panel = 'flexible-mid';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'html_source' => '2012/spit/html/scholarship.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-34'] = $pane;
    $display->panels['flexible-mid'][1] = 'new-34';
    $pane = new stdClass();
    $pane->pid = 'new-35';
    $pane->panel = 'flexible-mid';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'html_source' => '2012/spit/html/social.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-35'] = $pane;
    $display->panels['flexible-mid'][2] = 'new-35';
    $pane = new stdClass();
    $pane->pid = 'new-36';
    $pane->panel = 'flexible-mid';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'og_member',
          'settings' => array(
            'state' => array(
              1 => '1',
            ),
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'og_member',
          'settings' => array(
            'state' => array(
              1 => '1',
            ),
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'html_source' => '2012/spit/html/impact-participant.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-36'] = $pane;
    $display->panels['flexible-mid'][3] = 'new-36';
    $pane = new stdClass();
    $pane->pid = 'new-37';
    $pane->panel = 'flexible-mid';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'og_member',
          'settings' => array(
            'state' => array(
              1 => '1',
            ),
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'html_source' => '2012/spit/html/impact-anonymous.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-37'] = $pane;
    $display->panels['flexible-mid'][4] = 'new-37';
    $pane = new stdClass();
    $pane->pid = 'new-38';
    $pane->panel = 'flexible-mid';
    $pane->type = 'views_panes';
    $pane->subtype = 'campaign_gallery-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '5',
      'offset' => '0',
      'context' => array(
        0 => 'relationship_og_node_from_group_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'section',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-38'] = $pane;
    $display->panels['flexible-mid'][5] = 'new-38';
    $pane = new stdClass();
    $pane->pid = 'new-39';
    $pane->panel = 'flexible-mid';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'html_source' => '2012/spit/html/faq.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-39'] = $pane;
    $display->panels['flexible-mid'][6] = 'new-39';
    $pane = new stdClass();
    $pane->pid = 'new-40';
    $pane->panel = 'flexible-mid';
    $pane->type = 'campaign_sign_up';
    $pane->subtype = 'campaign_sign_up';
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
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-40'] = $pane;
    $display->panels['flexible-mid'][7] = 'new-40';
    $pane = new stdClass();
    $pane->pid = 'new-41';
    $pane->panel = 'flexible-top';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'html_source' => '2012/spit/html/header.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-41'] = $pane;
    $display->panels['flexible-top'][0] = 'new-41';
    $pane = new stdClass();
    $pane->pid = 'new-42';
    $pane->panel = 'flexible-top';
    $pane->type = 'drive';
    $pane->subtype = 'drive';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'drive',
      'css_class' => 'section',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-42'] = $pane;
    $display->panels['flexible-top'][1] = 'new-42';
    $pane = new stdClass();
    $pane->pid = 'new-43';
    $pane->panel = 'flexible-top';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'og_member',
          'settings' => array(
            'state' => array(
              1 => '1',
            ),
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'html_source' => '2012/spit/html/action-anonymous.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-43'] = $pane;
    $display->panels['flexible-top'][2] = 'new-43';
    $pane = new stdClass();
    $pane->pid = 'new-44';
    $pane->panel = 'flexible-top';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'og_member',
          'settings' => array(
            'state' => array(
              1 => '1',
            ),
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'og_perm',
          'settings' => array(
            'perm' => 'administer group',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'html_source' => '2012/spit/html/action-participant.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-44'] = $pane;
    $display->panels['flexible-top'][3] = 'new-44';
    $pane = new stdClass();
    $pane->pid = 'new-45';
    $pane->panel = 'flexible-top';
    $pane->type = 'campaign_html';
    $pane->subtype = 'campaign_html';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'og_perm',
          'settings' => array(
            'perm' => 'administer group',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'relationship_entity_from_field:group_audience-webform_submission_entity-group_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'html_source' => '2012/spit/html/action-leader.html',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-45'] = $pane;
    $display->panels['flexible-top'][4] = 'new-45';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['team_pages'] = $page;

  return $pages;

}
