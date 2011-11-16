<?php
/**
 * @file
 * dosomething_members_only.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_members_only_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'members_only';
  $page->task = 'page';
  $page->admin_title = 'Members Only';
  $page->admin_description = '';
  $page->path = 'members-only';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
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
  $display = new panels_display;
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
    $pane = new stdClass;
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
    $display->content['new-1'] = $pane;
    $display->panels['top'][0] = 'new-1';
    $pane = new stdClass;
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
          <a href="/user">MySomethings</a>
        </div>
        <div class="block-pair">
          <a href="/node/718378">What is Membership</a>
        </div>
        <div class="block-pair">
          <a href="/node/718379">How to Become a Member</a>
        </div>
        <div class="block-pair">
          <a href="/node/718380">Membership Benefits</a>
        </div>
        <div class="block-pair">
          <a href="/grants">Grants</a>
        </div>
        <div class="block-pair">
          <a href="/scholarships">Scholarships</a>
        </div>
        <div class="block-pair">
          <a href="/clubhub">Club Hub</a>
        </div>
        <div class="block-pair">
          <a href="/node/718377">FAQs</a>
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
    $display->content['new-2'] = $pane;
    $display->panels['top'][1] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['members_only'] = $page;

  $page = new stdClass;
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
  $handler = new stdClass;
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
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
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
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'left';
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
    $display->content['new-1'] = $pane;
    $display->panels['left'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Static Page Content',
      'title' => '',
      'body' => '<h2>Grants</h2>
Aliquam lectus orci, adipiscing et, sodales ac, feugiat non, lacus. Ut dictum velit nec est. Quisque posuere, purus sit amet malesuada blandit, sapien sapien auctor arcu, sed pulvinar felis mi sollicitudin tortor. Maecenas volutpat, nisl et dignissim pharetra, urna lectus ultrices est, vel pretium pede turpis id velit. Aliquam sagittis magna in felis egestas rutrum. Proin wisi libero, vestibulum eget, pulvinar nec, suscipit ut, mi. Integer in arcu ultricies leo dapibus ultricies. Sed rhoncus lobortis dolor. Suspendisse dolor. Mauris sapien velit, pulvinar non, rutrum non, consectetuer eget, metus. Morbi tincidunt lorem at urna. Etiam porta. Ut mauris. Phasellus tristique rhoncus magna. Nam tincidunt consequat urna. Sed tempor.

<h2>Scholarships</h2>
Aliquam lectus orci, adipiscing et, sodales ac, feugiat non, lacus. Ut dictum velit nec est. Quisque posuere, purus sit amet malesuada blandit, sapien sapien auctor arcu, sed pulvinar felis mi sollicitudin tortor. Maecenas volutpat, nisl et dignissim pharetra, urna lectus ultrices est, vel pretium pede turpis id velit. Aliquam sagittis magna in felis egestas rutrum. Proin wisi libero, vestibulum eget, pulvinar nec, suscipit ut, mi. Integer in arcu ultricies leo dapibus ultricies. Sed rhoncus lobortis dolor. Suspendisse dolor. Mauris sapien velit, pulvinar non, rutrum non, consectetuer eget, metus. Morbi tincidunt lorem at urna. Etiam porta. Ut mauris. Phasellus tristique rhoncus magna. Nam tincidunt consequat urna. Sed tempor.

<h2>Clubs</h2>
<ul>
<li>\'The Dormouse is asleep again,\' said the Hatter, and he poured a little  hot tea upon its nose</li>
<li> The Dormouse shook its head impatiently, and said, without opening its  eyes, \'Of course, of course; just what I was going to remark myself</li>
<li>\' \'Have you guessed the riddle yet?\' the Hatter said, turning to Alice  again</li>
<li> \'No, I give it up,\' Alice replied: \'what\'s the answer?\' \'I haven\'t the slightest idea,\' said the Hatter</li>
<li> \'Nor I,\' said the March Hare</li>
<li> Alice sighed wearily</li>
</ul>',
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
    $display->content['new-2'] = $pane;
    $display->panels['left'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
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
    $display->content['new-3'] = $pane;
    $display->panels['left'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Membership Statistics',
      'body' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse dignissim luctus massa, id gravida urna dictum sed. Cras condimentum interdum nibh, a tincidunt lacus suscipit vitae. Proin at urna risus, at tincidunt leo. Donec consectetur sollicitudin dolor id suscipit. Morbi sed sapien arcu, sit amet ornare nunc. Duis lacinia rhoncus cursus. Vestibulum nisi odio, malesuada quis viverra et, porta nec dolor. In eget nisl venenatis arcu convallis viverra. Cras volutpat pharetra lobortis. Aliquam semper lobortis faucibus. Quisque non ante non purus consequat blandit sed ut nibh. In hac habitasse platea dictumst. Pellentesque sed rutrum nisl.

Vestibulum id bibendum dui. Suspendisse ac mi nibh. Mauris tristique ipsum quis sapien blandit sit amet tristique ipsum venenatis. Sed eu dolor orci. Aliquam pretium varius orci, at placerat tortor rutrum id. Etiam commodo ultrices dapibus. Maecenas auctor tempor aliquet. Integer aliquet scelerisque cursus. Vivamus mattis tortor sodales justo consectetur non lacinia orci pulvinar. Aliquam a sapien mauris, a auctor sapien. Nam suscipit lobortis nisl vitae pulvinar. Nullam quis turpis mi. Praesent in nibh nisi.',
      'format' => '6',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'ds-pane-usergen ds-pane-top-radius',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-4'] = $pane;
    $display->panels['right'][0] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['why_become_a_member_page'] = $page;

  return $pages;

}
