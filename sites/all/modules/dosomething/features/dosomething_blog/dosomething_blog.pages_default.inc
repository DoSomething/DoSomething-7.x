<?php
/**
 * @file
 * dosomething_blog.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dosomething_blog_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_blog';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Blog',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
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
              'blog' => 'blog',
            ),
          ),
          'context' => 'argument_nid_1',
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
      'top' => NULL,
      'mid-left' => NULL,
      'mid-right' => NULL,
      'bottom' => NULL,
      'left-top' => NULL,
      'left-bottom-left' => NULL,
      'left-bottom-right' => NULL,
      'right' => NULL,
      'left' => NULL,
    ),
  );
  $display->cache = array(
    'method' => '0',
    'settings' => array(),
  );
  $display->title = '%node:title';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(
        1 => array(
          'name' => 'entity_field_value:node:blog:taxonomy_vocabulary_5',
          'settings' => array(
            'taxonomy_vocabulary_5' => array(
              'und' => array(
                0 => array(
                  'tid' => '23',
                ),
                1 => array(
                  'tid' => '225',
                ),
                2 => array(
                  'tid' => '9386',
                ),
                3 => array(
                  'tid' => '7571',
                ),
                4 => array(
                  'tid' => '88',
                ),
                5 => array(
                  'tid' => '85',
                ),
                6 => array(
                  'tid' => '6817',
                ),
                7 => array(
                  'tid' => '89',
                ),
              ),
            ),
            'taxonomy_vocabulary_5_tid' => array(
              0 => '23',
              1 => '225',
              2 => '9386',
              3 => '7571',
              4 => '88',
              5 => '85',
              6 => '6817',
              7 => '89',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'MLK Form',
      'title' => '',
      'body' => '<style type="text/css">
<!--
  #cmp #scholarship {
    background: #fe002b;
    overflow: visible;
    text-align: center;
    padding: 15px 10px; }
    #cmp #scholarship .scholar-headline {
      font-size: 2.6em;
      font-weight: 600;
      font-family: din-web;
      line-height: 1em;
      text-transform: uppercase;
      color: white; }
    #cmp #scholarship hr {
      border: 1px solid #ff8993;
      margin: 1%; }
    #cmp #scholarship img.scholar-copy {
      padding: 0; }
    #cmp #scholarship img {
      clear: both;
      display: block;
      margin: 0 auto;
      padding: 2% 0; }
    #cmp #scholarship h1 {
      color: white; }
    #cmp #scholarship p {
      color: white;
      width: 100%;
      margin: 1.5% auto 2%;
      font-weight: 300;
      font-family: din-web-reg;
      font-size: 1.2em; }
    #cmp #scholarship form {
      margin: 1% auto 0;
      max-width: 600px; }
    #cmp #scholarship label {
      font-weight: 400;
      color: white; }
    #cmp #scholarship .friends {
      text-align: left;
      margin: 2% 1% 0; }
    #cmp #scholarship input[type="text"] {
      padding: 0 0.5em;
      float: left;
      width: 48%;
      margin: 1%; }
    #cmp #scholarship .go-button {
      margin: 1% 0 2% 0;
      padding: 0.6em 0.7em;
      background: #241f20;
      color: white;
      font-size: 2.8em;
      font-weight: 500;
      font-family: din-web-reg;
      -webkit-border-radius: 12px;
      -moz-border-radius: 12px;
      -ms-border-radius: 12px;
      -o-border-radius: 12px;
      border-radius: 12px;
      text-align: right;
      line-height: 0.3; }
      #cmp #scholarship .go-button:hover {
        color: #ff8993; }
    #cmp #scholarship #campaign-opt-in {
      text-align: center; }
      #cmp #scholarship #campaign-opt-in a {
        color: white;
        font-weight: 500; }
    #cmp #scholarship .rule-regs {
      text-align: left;
      margin: 4% 0 1%;
      font-size: 0.9em; }
      #cmp #scholarship .rule-regs a {
        color: white;
        font-weight: 400; }
    #cmp #scholarship .quote-highlight p {
      background: #353535;
      max-width: 525px;
      margin: 0 auto 0.8em;
      padding: 2.5% 2%;
      font-family: din-web-reg;
      font-weight: 600;
      font-size: 1.5em;
      line-height: 1.4em;
      -moz-border-radius: 12px;
      -webkit-border-radius: 12px;
      -o-border-radius: 12px;
      border-radius: 12px;
      color: white; }
    #cmp #scholarship .scholar-input {
      float: left;
      width: 48%;
      margin: 1% 1% 2%; }
      #cmp #scholarship .scholar-input label {
        text-align: left; }
      #cmp #scholarship .scholar-input input {
        width: 100%;
        margin: 1% 0; }
    #cmp #scholarship .scholar-foot {
      float: left;
      width: 48%;
      margin: 1%;
      text-align: right; }
    #cmp #scholarship .msg-data {
      font-size: 0.7em;
      line-height: 1.2em;
      font-weight: 300;
      font-family: din-web-reg;
      color: white;
      text-align: left; }
    #cmp #scholarship .rules {
      font-size: 1em; }
    #cmp #scholarship #post-scholar {
      padding: 4% 10% 2%; }
      #cmp #scholarship #post-scholar p {
        color: #1e1d1c;
        text-transform: uppercase;
        font-weight: 500;
        font-size: 1.4em; }
        #cmp #scholarship #post-scholar p strong {
          font-weight: 600;
          background: #f1f1f1;
          padding: 10px 20px 6px;
          border-radius: 40px;
          border: 2px solid #e9e9e9; }
        #cmp #scholarship #post-scholar p a {
          color: #1e1d1c; }
      #cmp #scholarship #post-scholar .left, #cmp #scholarship #post-scholar .right {
        float: left;
        padding: 0 5%;
        width: 50%;
        margin-bottom: 1.5em; }
      #cmp #scholarship #post-scholar .chances {
        position: relative;
        display: inline-block;
        clear: both;
        color: black; }
        #cmp #scholarship #post-scholar .chances:before, #cmp #scholarship #post-scholar .chances:after {
          content: "";
          position: absolute;
          top: 0px;
          height: 62px;
          width: 44px; }
        #cmp #scholarship #post-scholar .chances:before {
          left: -50px;
          background-image: url("http://files.dosomething.org/files/campaigns/grandparents12/money-left.png"); }
        #cmp #scholarship #post-scholar .chances:after {
          right: -50px;
          background-image: url("http://files.dosomething.org/files/campaigns/grandparents12/money-right.png"); }
      #cmp #scholarship #post-scholar .chances-rules a {
        color: #1e1d1c;
        font-size: 0.6em;
        text-transform: none;
        font-weight: 400; }
  #cmp .refer5 {
    background: #fe002b;
    width: 110%;
    margin: 0 0 0 -4.95%;
    position: relative; }
    #cmp .refer5:before, #cmp .refer5:after {
      content: "";
      position: absolute;
      border-style: solid;
      border-width: 11px;
      top: -22px; }
    #cmp .refer5:before {
      border-color: transparent #c10021 #c10021 transparent;
      left: 0px; }
    #cmp .refer5:after {
      border-color: transparent transparent #c10021 #c10021;
      right: 1px; }
  #cmp .refer5-inner {
    padding: 3%; }
    -->
    </style>

<div id="cmp">
<div class="section" id="scholarship">

    <h2 class="scholar-headline">Send the activist game to your friends</h2>
    <p>Play with 6 friends and become an activist during the civil rights movement of the 1960\'s. You\'ll be entered to win a</p>
    <h2 class="scholar-headline">$3,000 scholarship</h2>

    <form action="//dosomething.mcommons.com/profiles/join" method="POST">
      <input type="hidden" name="redirect_to" value="http://www.dosomething.org/activist" />
      <div class="scholar-input">
        <label>Your First Name:</label>
        <input type="text" name="person[first_name]" class="field space-after" placeholder="Your name:"/>
      </div>
      <div class="scholar-input">
        <label>Your Cell #:</label>
        <input type="text" name="person[phone]" class="field space-after" placeholder="You cell #:" />
      </div>
          <hr>
          <label class="friends">Friend\'s Cell #\'s:</label>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="hidden" name="friends_opt_in_path" value="140451" />
          <input type="hidden" name="opt_in_path" value="140441" />
          <div class="scholar-foot">
            <div class="msg-data">Msg &amp; data rates may apply. Text <strong>STOP</strong> to opt-out, <strong>HELP</strong> for help.</div>
            <div class="rule-regs"><a href="http://files.dosomething.org/files/campaigns/mlk/rulesandregs.pdf">Official Rules &amp; Regulations</a></div>
          </div>
          <div class="scholar-foot">
            <input type="submit" class="go-button" value="Play" />
          </div>
    </form> 

  <div class="clearfix"></div>

</div><!-- #scholarship -->
</div><!-- #cmp -->',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['left'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_picture';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'blog/sexiest-men-good',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => 'blog_landscape',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'page',
      'settings' => array(
        'lifetime' => '15',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['left'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_picture';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'blog/sexiest-men-good',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'file_view_mode' => 'default',
        'image_style' => '',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '604800',
        'granularity' => array(
          'url' => 'url',
          'args' => 0,
          'context' => 0,
          'user' => 0,
          'user_role' => 0,
          'path' => 0,
        ),
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['left'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'left';
    $pane->type = 'connections';
    $pane->subtype = 'connections';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'page',
      'settings' => array(
        'lifetime' => '604800',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'blah-blah',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['left'][3] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_embedded_video';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'media',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'file_view_mode' => 'default',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '604800',
        'granularity' => 'context',
      ),
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
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'page',
      'settings' => array(
        'lifetime' => '15',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['left'][5] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:taxonomy_vocabulary_5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '6',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Related causes',
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
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['left'][6] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'left';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:fb_social_FB Comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
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
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['left'][7] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'links' => 1,
      'page' => 1,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '<none>',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'context' => 'argument_entity_id:node_1',
      'build_mode' => 'full',
    );
    $pane->cache = array(
      'method' => 'page',
      'settings' => array(
        'lifetime' => '604800',
      ),
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
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-723942';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'blog/how-you-can-see-beyonce-concert',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Receive Celebrity Updates from DoSomething.org',
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
    $pane->position = 9;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['left'][9] = 'new-10';
    $pane = new stdClass();
    $pane->pid = 'new-11';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-721682';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'blog/bp-oil-spill-2-years-later',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Sign up for our Week without Oil campaign',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '15',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $display->content['new-11'] = $pane;
    $display->panels['left'][10] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-724102';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'blog/bella-thorne-do-something-awards-date',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Enter for your chance to see the Do Something Awards with Bella Thorne',
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
    $pane->position = 11;
    $pane->locks = array();
    $display->content['new-12'] = $pane;
    $display->panels['left'][11] = 'new-12';
    $pane = new stdClass();
    $pane->pid = 'new-13';
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
      'display' => 'block_2',
      'context' => array(
        0 => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '3600',
        'granularity' => 'context',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'ds-pane-news',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $display->content['new-13'] = $pane;
    $display->panels['right'][0] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>&nbsp;</p>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '604800',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-14'] = $pane;
    $display->panels['right'][1] = 'new-14';
    $pane = new stdClass();
    $pane->pid = 'new-15';
    $pane->panel = 'top';
    $pane->type = 'share-buttons';
    $pane->subtype = 'share-buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-15'] = $pane;
    $display->panels['top'][0] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'dosomething_blocks-dosomething_facepile_general';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'node_status',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '43200',
        'granularity' => 'context',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $display->content['new-16'] = $pane;
    $display->panels['top'][1] = 'new-16';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_blog'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_blog_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'blog_center';
  $page->task = 'page';
  $page->admin_title = 'Blog Center';
  $page->admin_description = '';
  $page->path = 'blog';
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
  $handler->name = 'page_blog_center_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'blog_center';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Blogs - All',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'one_two';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left-top' => NULL,
      'left-bottom-left' => NULL,
      'left-bottom-right' => NULL,
      'right' => NULL,
      'top' => NULL,
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Blog Center';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'blog_center-panel_pane_3';
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
    $pane->css = array(
      'css_id' => 'blog-page-pane',
      'css_class' => '.pane-content',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $display->content['new-1'] = $pane;
    $display->panels['left'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'blogs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
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
      'override_title_text' => 'Most Popular',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '15',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $display->content['new-2'] = $pane;
    $display->panels['right'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'blog_center';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'blog_archive_block',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '86400',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'blog-archives-pane',
      'css_class' => 'ds-pane-no-radius ds-pane-news ds-internal-sidebar-flush-right',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $display->content['new-3'] = $pane;
    $display->panels['right'][1] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'top';
    $pane->type = 'share-buttons';
    $pane->subtype = 'share-buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['top'][0] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'service_links-service_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '14400',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['top'][1] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => 'Our blog updates you on the latest info, without putting you to sleep. Use the filters above to browse news, celebs, and more.',
      'format' => '1',
      'substitute' => TRUE,
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '604800',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['top'][2] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-blog_center-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 1,
      'override_title_text' => 'Sort by:',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '604800',
        'granularity' => 'args',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = '';
    $display->content['new-7'] = $pane;
    $display->panels['top'][3] = 'new-7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['blog_center'] = $page;

  return $pages;

}
