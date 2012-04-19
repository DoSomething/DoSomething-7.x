<?php
/**
 * @file
 * dosomething_members_only.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_members_only_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'members_only';
  $page->task = 'page';
  $page->admin_title = 'Members Only';
  $page->admin_description = '';
  $page->path = 'members-only';
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
  $handler->name = 'page_members_only_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'members_only';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Members Only',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_two_one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'mid-left' => NULL,
      'mid-right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Members Only Slideshow',
      'title' => '',
      'body' => '<img src="/files/members_only_slide.jpg" alt=""/>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $display->content['new-1'] = $pane;
    $display->panels['top'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Members Only Blocks',
      'title' => '',
      'body' => '        <div class="block-pair">
          <a href="/user"><img src="sites/all/themes/ds/css/images/members-only-mysomethings.jpg"></a>
          <a class="members-only" href="/user">MySomethings</a>
        </div>
        <div class="block-pair">
          <a href="/node/718378"><img src="sites/all/themes/ds/css/images/members-only-whatis.jpg"></a>
          <a class="members-only" href="/node/718378">What is Membership</a>
        </div>
        <div class="block-pair last">
          <a href="/node/718379"><img src="sites/all/themes/ds/css/images/members-only-become-member.jpg"></a>
          <a class="members-only" href="/node/718379">How to Become a Member</a>
        </div>
        <div class="block-pair">
          <a href="/node/718380"><img src="sites/all/themes/ds/css/images/members-only-benefits.jpg"></a>
          <a class="members-only" href="/node/718380">Membership Benefits</a>
        </div>
        <div class="block-pair">
          <a href="/grants"><img src="sites/all/themes/ds/css/images/members-only-grants.jpg"></a>
          <a class="members-only" href="/grants">Grants</a>
        </div>
        <div class="block-pair last">
          <a href="/scholarships"><img src="sites/all/themes/ds/css/images/members-only-scholarships.jpg"></a>
          <a class="members-only" href="/scholarships">Scholarships</a>
        </div>
        <div class="block-pair">
          <a href="/clubhub"><img src="sites/all/themes/ds/css/images/members-only-clubs.jpg"></a>
          <a class="members-only" href="/clubhub">Club Hub</a>
        </div>
        <div class="block-pair">
          <a href="/node/718377"><img src="sites/all/themes/ds/css/images/members-only-faq.jpg"></a>
          <a class="members-only" href="/node/718377">FAQs</a>
        </div>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $display->content['new-2'] = $pane;
    $display->panels['top'][1] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['members_only'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'why_become_a_member_page';
  $page->task = 'page';
  $page->admin_title = 'Why become a member page';
  $page->admin_description = 'Why Become a Member page that links to the Why Become a Member left sidebar block on the home page.';
  $page->path = 'why-become-a-member';
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
  $handler->name = 'page_why_become_a_member_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'why_become_a_member_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Become a Member',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'ds-wide-thin',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_two';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Why Become a Member?';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => '1',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['left'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Static Page Content',
      'title' => '',
      'body' => '<h2>DoSomething.org is a member-based organization for young people 25 years old and under.</h2>

<p>By being a member of DoSomething.org:</p>

<ol>
<li>You make a real impact on causes you care about.

<ul>
<li>We help you be part a social movement with others like you.</li>

<li>We give you ideas because it can be hard to think of something specific to actually do.</li>

<li>We send you stuff like posters, stickers, banners, etc.</li>

<li>We recognize you for the good stuff you do (so that you can put it on your college app, impress a girl, or give it to your mom to hang on the fridge).</li>
</ul></li>
<li>You get <i>cash</i>. That\'s right. We\'re talking $$.
<ul>
<li>We give <a href="/grants">money for social change projects</a>.</li>
<li>We award <a href="/scholarships">money for school</a>.</li></ul></li>
<li>You get SWAG you can actually use.

<ul>
<li>Movie tickets, food, etc. (Send us your wish list!)</li>
<li>Celeb-signed goodies</li></ul>
</li>
</ul>

<li>You have access to invite-only things.
<ul>
<li>We invite you to exclusive events (like the <a href="/awards">Do Something Awards</a>, movie premieres, etc).</li>
<li>We give you the chance to meet a celebrity.</li></ul></li>
</ol>

<p>Go ahead and click on that box on the left to get started. We know you want to. ;)</p>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $display->content['new-4'] = $pane;
    $display->panels['left'][1] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Sign Up Button',
      'title' => '',
      'body' => '<a class="ds-button-strong" href="/user/registration" title="Join DoSomething Now">Join Now</a>',
      'format' => '3',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = '';
    $display->content['new-5'] = $pane;
    $display->panels['left'][2] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-2';
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
    $display->content['new-6'] = $pane;
    $display->panels['right'][0] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'dosomething_blocks-dosomething_social_node_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $display->content['new-7'] = $pane;
    $display->panels['top'][0] = 'new-7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['why_become_a_member_page'] = $page;

  return $pages;

}
