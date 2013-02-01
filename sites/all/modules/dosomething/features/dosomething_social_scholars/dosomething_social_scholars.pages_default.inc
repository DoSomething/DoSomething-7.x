<?php
/**
 * @file
 * dosomething_social_scholars.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dosomething_social_scholars_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
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
  $display->layout = 'flexible:social_scholars';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'service_links-service_links';
    $pane->shown = FALSE;
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
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'share-buttons';
    $pane->subtype = 'share-buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'admin_title' => 'Pretty Form',
      'title' => '',
      'body' => '<link rel="stylesheet" type="text/css" href="/sites/all/modules/dosomething/dosomething_general/css/dsfakecform.css" />
<div id="cmp">
  <div id="scholarship">
  <div class="refer5">
  <div class="refer5-inner">  
    <img class="scholar-copy" src="//files.dosomething.org/files/campaigns/alcoa/scholarship-copy.png" alt="share this fact">
    <h1 class="condensed">$2,000 scholarship</h1>

    <div class="quote-highlight">
      %node:field_tip_to_show_on_form
    </div><!-- quote-highlight -->    

    <form action="//dosomething.mcommons.com/profiles/join" method="POST">
      <input type="hidden" name="redirect_to" value="http://www.dosomething.org/redirect-with-message?type=social_scholarship&nid=%node:nid" />
      <div class="scholar-input your-input">
        <label>Your First Name:</label>
        <input type="text" name="person[first_name]" class="field space-after" placeholder="Your name:"/>
      </div>
      <div class="scholar-input your-input">
        <label>Your Cell #:</label>
        <input type="text" name="person[phone]" class="field space-after" placeholder="You cell #:" />
      </div>
      <img src="//files.dosomething.org/files/campaigns/alcoa/line.png" alt="line">
        <label class="friends">Friend\'s Cell #\'s:</label>
        <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
        <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
        <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
        <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
        <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
        <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
        <input type="hidden" name="friends_opt_in_path" value="%node:field_betas_campaign" />
        <input type="hidden" name="opt_in_path" value="%node:field_alphas_campaign" />
        <div class="clearfix"></div>
        <p class="align-button"><input type="submit" class="go-button" value="Submit" /></p>
    </form> 

  <div class="clearfix"></div>

    <div id="campaign-opt-in"><span class="ctia_bottom">
        <a class="rules" href="%node:field_official_rules_document">Official Rules.</a> 
        Msg &amp; data rates may apply. Text <strong>STOP</strong> to opt-out, <strong>HELP</strong> for help. </span>
    </div>

  </div><!-- .refer5-inner for IE8 fix -->
  </div> <!-- .refer5 -->
</div>
</div>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'page-wrap',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['center'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'center';
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
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['center'][3] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'form';
    $pane->type = 'leading_images';
    $pane->subtype = 'leading_images';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['form'][0] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'statistics';
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-724211';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Enter your info and friends\' #s. You could win $2000!',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['statistics'][0] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'statistics';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:webform';
    $pane->shown = FALSE;
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
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['statistics'][1] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'statistics';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = FALSE;
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
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['statistics'][2] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'statistics';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
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
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-9'] = $pane;
    $display->panels['statistics'][3] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'statistics';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div class="contextual-links-region panel-pane pane-block pane-webform-client-block-724211" >
      <div class="contextual-links-wrapper"><ul class="contextual-links"><li class="0 first last"><a href="/admin/structure/block/manage/webform/client-block-724211/configure?destination=node/727327">Configure block</a></li>
</ul></div>  
        <h2 class="pane-title">Enter your info and friends\' #s. You could win $2000!</h2>
    
  
  <div class="pane-content">
    <form class="webform-client-form" enctype="multipart/form-data" action="/webform/mobile-referral-form" method="post" id="webform-client-form-724211" accept-charset="UTF-8"><div><div id="edit-submitted--2" class="form-wrapper"></div><fieldset class="webform-component-fieldset form-wrapper" id="webform-component-referall-your-info"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-textfield" id="webform-component-referall-your-info--referral-first-name">
 <input type="text" id="edit-submitted-referall-your-info-referral-first-name" name="submitted[referall_your_info][referral_first_name]" value="Your First Name" size="60" maxlength="128" class="form-text" />
</div>
<div class="form-item webform-component webform-component-textfield" id="webform-component-referall-your-info--referral-phone-number">
 <input type="text" id="edit-submitted-referall-your-info-referral-phone-number" name="submitted[referall_your_info][referral_phone_number]" value="Your (xxx) xxx-xxxx" size="60" maxlength="128" class="form-text" />
</div>
<div class="form-item webform-component webform-component-markup" id="webform-component-referall-your-info--terms-and-conditions">
 <p>By clicking submit, you are opting into <a href="/files/social_scholarships/official_rules/DontBeTrashyScholarshipRules.pdf" target="_blank">these official rules</a> and our weekly updates. <a href="#" id="opt-in-help" rel="nofollow">?</a><br /></p><div id="campaign-opt-in-help">Enter your phone number to get weekly updates from DoSomething.org, including campaign news and chances to win prizes and scholarships. (Message and data rates may apply. Text <strong>STOP</strong> to opt-out. Email <a href="mailto:help@dosomething.org" rel="nofollow">help@dosomething.org</a> or text <strong>HELP</strong> for help.)</div>

</div>
</div></fieldset>
<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-referral-friend-info"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-markup" id="webform-component-referral-friend-info--your-friends-cell-numbers">
 <p>Your friends\' cell numbers:</p>

</div>
<div class="form-item webform-component webform-component-textfield" id="webform-component-referral-friend-info--referral-friend-cell-1">
 <input type="text" id="edit-submitted-referral-friend-info-referral-friend-cell-1" name="submitted[referral_friend_info][referral_friend_cell_1]" value="(xxx) xxx-xxxx" size="60" maxlength="128" class="form-text" />
</div>
<div class="form-item webform-component webform-component-textfield" id="webform-component-referral-friend-info--referral-friend-cell-2">
 <input type="text" id="edit-submitted-referral-friend-info-referral-friend-cell-2" name="submitted[referral_friend_info][referral_friend_cell_2]" value="(xxx) xxx-xxxx" size="60" maxlength="128" class="form-text" />
</div>
<div class="form-item webform-component webform-component-textfield" id="webform-component-referral-friend-info--referral-friend-cell-3">
 <input type="text" id="edit-submitted-referral-friend-info-referral-friend-cell-3" name="submitted[referral_friend_info][referral_friend_cell_3]" value="(xxx) xxx-xxxx" size="60" maxlength="128" class="form-text" />
</div>
<div class="form-item webform-component webform-component-textfield" id="webform-component-referral-friend-info--referral-friend-cell-4">
 <input type="text" id="edit-submitted-referral-friend-info-referral-friend-cell-4" name="submitted[referral_friend_info][referral_friend_cell_4]" value="(xxx) xxx-xxxx" size="60" maxlength="128" class="form-text" />
</div>
<div class="form-item webform-component webform-component-textfield" id="webform-component-referral-friend-info--referral-friend-cell-5">
 <input type="text" id="edit-submitted-referral-friend-info-referral-friend-cell-5" name="submitted[referral_friend_info][referral_friend_cell_5]" value="(xxx) xxx-xxxx" size="60" maxlength="128" class="form-text" />
</div>
</div></fieldset>
<input type="hidden" name="details[sid]" value="" />
<input type="hidden" name="details[page_num]" value="1" />
<input type="hidden" name="details[page_count]" value="1" />
<input type="hidden" name="details[finished]" value="0" />
<input type="hidden" name="form_build_id" value="form-IX5hgDl8NG9tm3E_x4EXCQsmCVFoP7PDnXzOiG8Z3lQ" />
<input type="hidden" name="form_token" value="jjQh-WXRPujFkUub2FKrQsp635lGB7G05cyIDbHyCXY" />
<input type="hidden" name="form_id" value="webform_client_form_724211" />
<div class="form-actions form-wrapper" id="edit-actions"><input class="go-button form-submit" type="submit" id="edit-submit" name="op" value="SEND" /></div></div></form>  </div>
  </div>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['statistics'][4] = 'new-10';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_social_scholars_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'animal_cruelty_stats_images';
  $page->task = 'page';
  $page->admin_title = 'Animal Cruelty Stats Images';
  $page->admin_description = '';
  $page->path = 'animal-social-stats';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_animal_cruelty_stats_images_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'animal_cruelty_stats_images';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'shary_images';
    $pane->subtype = 'shary_images';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['animal_cruelty_stats_images'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'social_scholarship_image_page';
  $page->task = 'page';
  $page->admin_title = 'Social Scholarship Image Page';
  $page->admin_description = '';
  $page->path = 'share-these-images/%node';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
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
  $handler->name = 'page_social_scholarship_image_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'social_scholarship_image_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'new_shary_images';
    $pane->subtype = 'new_shary_images';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['center'][0] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['social_scholarship_image_page'] = $page;

  return $pages;

}
