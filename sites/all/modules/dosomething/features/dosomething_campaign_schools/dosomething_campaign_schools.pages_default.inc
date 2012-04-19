<?php
/**
 * @file
 * dosomething_campaign_schools.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_campaign_schools_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'campaign_school_browser_pages';
  $page->task = 'page';
  $page->admin_title = 'Campaign School Browser pages';
  $page->admin_description = '';
  $page->path = 'school/%school/%campaign';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'school' => array(
      'id' => 1,
      'identifier' => 'School ID',
      'name' => 'entity_id:ds_school',
      'settings' => array(),
    ),
    'campaign' => array(
      'id' => 1,
      'identifier' => 'Campaign NID',
      'name' => 'entity_id:node',
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
  $handler->name = 'page_campaign_school_browser_pages_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'campaign_school_browser_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Epic Book Drive 2012',
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
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'school/*/718326',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
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
    $pane->type = 'entity_view';
    $pane->subtype = 'ds_school';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'default',
      'context' => 'argument_entity_id:ds_school_1',
      'override_title' => 1,
      'override_title_text' => '%title',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'school-name',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['flexible-top'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'flexible-top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Share Your Story',
      'title' => '',
      'body' => '<div class="content-content"><img src="http://files.dosomething.org/files/campaigns/epic/epic-share-your-story.png" />
<h1>YOUR PROJECT HERE.<br />REPORT BACK!</h1>
<a href="/epic/tell-us" class="go-button" rel="nofollow">GO</a>
</div>
<div class="clear-both"></div>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'share-your-story',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['flexible-top'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'flexible-top';
    $pane->type = 'views_panes';
    $pane->subtype = 'campaign_school_pages-member_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:ds_school_1',
        1 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Who\'s Involved',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'members-list',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['flexible-top'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'flexible-top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Drive Tools',
      'title' => '',
      'body' => '<div class="content-content"><img src="http://files.dosomething.org/files/campaigns/epic/drive-tools.png" />
<ul>
<li class="red-dot"><a href="http://files.dosomething.org/files/campaigns/epic/Epic-Drive-Flier.pdf">Drive Flyer</a></li>
<li class="red-dot"><a href="http://files.dosomething.org/files/campaigns/epic/Epic-Cheat-Sheet.pdf">Donation Locations</a></li>
<li class="red-dot"><a href="http://files.dosomething.org/files/campaigns/epic/Epic-Bookmarks.pdf">Printable Bookmarks</a></li>
<li class="red-dot"><a href="/epic/run-a-drive">11 Drive Tips</a></li>
</ul>
</div>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'drive-tools',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['flexible-top'][3] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'flexible-top';
    $pane->type = 'views_panes';
    $pane->subtype = 'campaign_school_pages-photo_gallery';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:ds_school_1',
        1 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'school-gallery',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['flexible-top'][4] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'logo';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campaign_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'campaign_microsite_logo',
        'image_link' => 'content',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['logo'][0] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
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
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['mini-info'][0] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
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
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['mini-info'][1] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'sign-up';
    $pane->type = 'campaign_sign_up';
    $pane->subtype = 'campaign_sign_up';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report_back_html' => 'Yay. You\'ve signed up. Now it\'s time to report back!',
      'override_title' => 1,
      'override_title_text' => 'Do some fun stuff for Epic Book Drive!',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-9'] = $pane;
    $display->panels['sign-up'][0] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'stats';
    $pane->type = 'campaign_counter';
    $pane->subtype = 'campaign_counter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'signup_nid' => '719307',
      'report_back_nid' => '719308',
      'count_field' => '#count',
      'counter_label' => 'People Signed Up',
      'override_title' => 1,
      'override_title_text' => '&nbsp;',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['stats'][0] = 'new-10';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_campaign_school_browser_pages_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'campaign_school_browser_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Green Your School 2012',
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
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'school/*/718328',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
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
    $pane->pid = 'new-11';
    $pane->panel = 'flexible-mid';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Browse Project Ideas',
      'body' => 'We\'ve made a list of project ideas for you, check it out.
<a href="/green-your-school/project-ideas" class="go-button" rel="nofollow">GO</a>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'three-boxes bg-green',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-11'] = $pane;
    $display->panels['flexible-mid'][0] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
    $pane->panel = 'flexible-mid';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Prizes',
      'body' => 'Here\'s your opportunity to win a scholarship or a green grant.
<a href="/green-your-school/prizes" class="go-button" rel="nofollow">GO</a>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'three-boxes bg-green',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-12'] = $pane;
    $display->panels['flexible-mid'][1] = 'new-12';
    $pane = new stdClass();
    $pane->pid = 'new-13';
    $pane->panel = 'flexible-mid';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'View Your School',
      'body' => 'Find out what schools are taking part in the challenge or register your own.
<a href="/green-your-school/browse-schools" class="go-button" rel="nofollow">GO</a>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'bg-green three-boxes',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-13'] = $pane;
    $display->panels['flexible-mid'][2] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
    $pane->panel = 'flexible-top';
    $pane->type = 'entity_view';
    $pane->subtype = 'ds_school';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'default',
      'context' => 'argument_entity_id:ds_school_1',
      'override_title' => 1,
      'override_title_text' => '%title',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'school-name',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-14'] = $pane;
    $display->panels['flexible-top'][0] = 'new-14';
    $pane = new stdClass();
    $pane->pid = 'new-15';
    $pane->panel = 'flexible-top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Share Your Story',
      'title' => '',
      'body' => '<div class="content-content"><img src="http://files.dosomething.org/files/campaigns/green/share-your-story.png" />
<h1>YOUR PROJECT HERE.<br />REPORT BACK!</h1>
<a href="/green-your-school/tell-us" class="go-button" rel="nofollow">GO</a>
</div>
<div class="clear-both"></div>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'share-your-story',
      'css_class' => 'bg-green',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-15'] = $pane;
    $display->panels['flexible-top'][1] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
    $pane->panel = 'flexible-top';
    $pane->type = 'views_panes';
    $pane->subtype = 'campaign_school_pages-member_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:ds_school_1',
        1 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Who\'s Involved',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'members-list',
      'css_class' => 'bg-green',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-16'] = $pane;
    $display->panels['flexible-top'][2] = 'new-16';
    $pane = new stdClass();
    $pane->pid = 'new-17';
    $pane->panel = 'flexible-top';
    $pane->type = 'views_panes';
    $pane->subtype = 'campaign_school_pages-photo_gallery';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:ds_school_1',
        1 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'school-gallery',
      'css_class' => 'bg-green',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-17'] = $pane;
    $display->panels['flexible-top'][3] = 'new-17';
    $pane = new stdClass();
    $pane->pid = 'new-18';
    $pane->panel = 'logo';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_campaign_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'campaign_microsite_logo',
        'image_link' => 'content',
      ),
      'context' => 'argument_entity_id:node_1',
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
    $display->panels['logo'][0] = 'new-18';
    $pane = new stdClass();
    $pane->pid = 'new-19';
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
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-19'] = $pane;
    $display->panels['mini-info'][0] = 'new-19';
    $pane = new stdClass();
    $pane->pid = 'new-20';
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
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-20'] = $pane;
    $display->panels['mini-info'][1] = 'new-20';
    $pane = new stdClass();
    $pane->pid = 'new-21';
    $pane->panel = 'sign-up';
    $pane->type = 'campaign_sign_up';
    $pane->subtype = 'campaign_sign_up';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report_back_html' => 'Yay. You\'ve signed up. Now it\'s time to report back!',
      'override_title' => 1,
      'override_title_text' => 'Got What it Takes to Go Greener than the Competition? Prove it.',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-21'] = $pane;
    $display->panels['sign-up'][0] = 'new-21';
    $pane = new stdClass();
    $pane->pid = 'new-22';
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
    $display->content['new-22'] = $pane;
    $display->panels['social'][0] = 'new-22';
    $pane = new stdClass();
    $pane->pid = 'new-23';
    $pane->panel = 'stats';
    $pane->type = 'campaign_counter';
    $pane->subtype = 'campaign_counter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'signup_nid' => '719307',
      'report_back_nid' => '719308',
      'count_field' => '#count',
      'counter_label' => 'People Signed Up',
      'override_title' => 1,
      'override_title_text' => '&nbsp;',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-23'] = $pane;
    $display->panels['stats'][0] = 'new-23';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-18';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['campaign_school_browser_pages'] = $page;

  return $pages;

}
