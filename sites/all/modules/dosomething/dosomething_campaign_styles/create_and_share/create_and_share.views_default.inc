<?php
/**
 * @file
 * create_and_share.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function create_and_share_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'create_and_share';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Create and Share';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crazy Shit landing page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<div class="crazy-submission"><p class="no-results">no posts yet<a class="small_button" href="/crazy/submit">submit yours!</a></p></div>';
  $handler->display->display_options['empty']['area']['format'] = '3';
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Animal type */
  $handler->display->display_options['relationships']['data']['id'] = 'data';
  $handler->display->display_options['relationships']['data']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['data']['field'] = 'data';
  $handler->display->display_options['relationships']['data']['ui_name'] = 'Animal type';
  $handler->display->display_options['relationships']['data']['label'] = 'Animal Type';
  $handler->display->display_options['relationships']['data']['webform_nid'] = '729195';
  $handler->display->display_options['relationships']['data']['webform_cid'] = '3';
  /* Relationship: Shelter State */
  $handler->display->display_options['relationships']['data_1']['id'] = 'data_1';
  $handler->display->display_options['relationships']['data_1']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['data_1']['field'] = 'data';
  $handler->display->display_options['relationships']['data_1']['ui_name'] = 'Shelter State';
  $handler->display->display_options['relationships']['data_1']['label'] = 'Shelter State';
  $handler->display->display_options['relationships']['data_1']['webform_nid'] = '729195';
  $handler->display->display_options['relationships']['data_1']['webform_cid'] = '5';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'crazy_facebook_picture';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Webform submissions: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = '';
  $handler->display->display_options['fields']['sid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sid']['separator'] = '';
  /* Field: Webform Submission: Image */
  $handler->display->display_options['fields']['field_cas_image']['id'] = 'field_cas_image';
  $handler->display->display_options['fields']['field_cas_image']['table'] = 'field_data_field_cas_image';
  $handler->display->display_options['fields']['field_cas_image']['field'] = 'field_cas_image';
  $handler->display->display_options['fields']['field_cas_image']['label'] = '';
  $handler->display->display_options['fields']['field_cas_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cas_image']['element_label_colon'] = FALSE;
  /* Field: Webform Submission: Thumbs Down Count */
  $handler->display->display_options['fields']['field_cas_thumbs_down_count']['id'] = 'field_cas_thumbs_down_count';
  $handler->display->display_options['fields']['field_cas_thumbs_down_count']['table'] = 'field_data_field_cas_thumbs_down_count';
  $handler->display->display_options['fields']['field_cas_thumbs_down_count']['field'] = 'field_cas_thumbs_down_count';
  $handler->display->display_options['fields']['field_cas_thumbs_down_count']['label'] = '';
  $handler->display->display_options['fields']['field_cas_thumbs_down_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cas_thumbs_down_count']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_2']['id'] = 'views_conditional_2';
  $handler->display->display_options['fields']['views_conditional_2']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_2']['if'] = 'field_cas_thumbs_down_count';
  $handler->display->display_options['fields']['views_conditional_2']['condition'] = '5';
  $handler->display->display_options['fields']['views_conditional_2']['then'] = '0';
  $handler->display->display_options['fields']['views_conditional_2']['or'] = '[field_cas_thumbs_down_count]';
  /* Field: Webform Submission: Thumbs Up Count */
  $handler->display->display_options['fields']['field_cas_thumbs_up_count']['id'] = 'field_cas_thumbs_up_count';
  $handler->display->display_options['fields']['field_cas_thumbs_up_count']['table'] = 'field_data_field_cas_thumbs_up_count';
  $handler->display->display_options['fields']['field_cas_thumbs_up_count']['field'] = 'field_cas_thumbs_up_count';
  $handler->display->display_options['fields']['field_cas_thumbs_up_count']['label'] = '';
  $handler->display->display_options['fields']['field_cas_thumbs_up_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cas_thumbs_up_count']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_cas_thumbs_up_count';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '5';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '0';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[field_cas_thumbs_up_count]';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_first_name']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: Submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['label'] = '';
  $handler->display->display_options['fields']['submitted']['exclude'] = TRUE;
  $handler->display->display_options['fields']['submitted']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['submitted']['date_format'] = 'field_recipient_birthdate_medium';
  /* Field: Content: Thumbs Down Text */
  $handler->display->display_options['fields']['field_cas_thumbs_down_text']['id'] = 'field_cas_thumbs_down_text';
  $handler->display->display_options['fields']['field_cas_thumbs_down_text']['table'] = 'field_data_field_cas_thumbs_down_text';
  $handler->display->display_options['fields']['field_cas_thumbs_down_text']['field'] = 'field_cas_thumbs_down_text';
  $handler->display->display_options['fields']['field_cas_thumbs_down_text']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_cas_thumbs_down_text']['label'] = '';
  $handler->display->display_options['fields']['field_cas_thumbs_down_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cas_thumbs_down_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cas_thumbs_down_text']['type'] = 'text_plain';
  /* Field: Content: Thumbs Up Text */
  $handler->display->display_options['fields']['field_cas_thumbs_up_text']['id'] = 'field_cas_thumbs_up_text';
  $handler->display->display_options['fields']['field_cas_thumbs_up_text']['table'] = 'field_data_field_cas_thumbs_up_text';
  $handler->display->display_options['fields']['field_cas_thumbs_up_text']['field'] = 'field_cas_thumbs_up_text';
  $handler->display->display_options['fields']['field_cas_thumbs_up_text']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_cas_thumbs_up_text']['label'] = '';
  $handler->display->display_options['fields']['field_cas_thumbs_up_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cas_thumbs_up_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cas_thumbs_up_text']['type'] = 'text_plain';
  /* Field: Buttons */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Buttons';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="vouch-button">
<a href="#" class="button-submit no-alert" rel="[sid]">[field_cas_thumbs_up_text]</a>
<span>[views_conditional_1]</span>
</div>
<div class="bs-button">
<a href="#" class="button-submit no-alert" rel="[sid]">[field_cas_thumbs_down_text]</a>
<span>[views_conditional_2]</span>
</div>
<div class="fb-share">
<a href="#" rel="[sid]">Share on Facebook</a>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Template */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Template';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="crazy-submission s-[sid] a-[uid]">
<div class="fb-and-pic">
<div class="flag"><a href="/crazy/flag/[sid]" data-sid="[sid]"><span>Flag</span></a></div>
<div class="fb-picture">[picture]</div>
<div class="s-[sid]-picture simg">[field_cas_image]</div>
</div>
<div class="buttons">
[nothing_1]
</div> <!-- closes [nothing_1] -->
<p class="author">[field_user_first_name]</p>
<div class="dateline">[submitted]</div>
</div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Webform Submission: Weight */
  $handler->display->display_options['fields']['field_cas_weight']['id'] = 'field_cas_weight';
  $handler->display->display_options['fields']['field_cas_weight']['table'] = 'field_data_field_cas_weight';
  $handler->display->display_options['fields']['field_cas_weight']['field'] = 'field_cas_weight';
  $handler->display->display_options['fields']['field_cas_weight']['label'] = '';
  $handler->display->display_options['fields']['field_cas_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cas_weight']['element_label_colon'] = FALSE;
  /* Sort criterion: Webform Submission: Weight (field_cas_weight) */
  $handler->display->display_options['sorts']['field_cas_weight_value_1']['id'] = 'field_cas_weight_value_1';
  $handler->display->display_options['sorts']['field_cas_weight_value_1']['table'] = 'field_data_field_cas_weight';
  $handler->display->display_options['sorts']['field_cas_weight_value_1']['field'] = 'field_cas_weight_value';
  $handler->display->display_options['sorts']['field_cas_weight_value_1']['order'] = 'DESC';
  /* Sort criterion: Webform Submission: Total Count (field_cas_total_count) */
  $handler->display->display_options['sorts']['field_cas_total_count_value_1']['id'] = 'field_cas_total_count_value_1';
  $handler->display->display_options['sorts']['field_cas_total_count_value_1']['table'] = 'field_data_field_cas_total_count';
  $handler->display->display_options['sorts']['field_cas_total_count_value_1']['field'] = 'field_cas_total_count_value';
  $handler->display->display_options['sorts']['field_cas_total_count_value_1']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'crazy_shit' => 'crazy_shit',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Webform Submission: Flagged (field_crazy_flagged) */
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['id'] = 'field_crazy_flagged_value_1';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['table'] = 'field_data_field_crazy_flagged';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['field'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['operator'] = 'not';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['group'] = 2;
  /* Filter criterion: Webform Submission: Flagged (field_crazy_flagged) */
  $handler->display->display_options['filters']['field_crazy_flagged_value']['id'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['table'] = 'field_data_field_crazy_flagged';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['field'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_crazy_flagged_value']['group'] = 2;

  /* Display: Gallery View */
  $handler = $view->new_display('block', 'Gallery View', 'create_and_share_gallery');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'create_and_share_campaign' => 'create_and_share_campaign',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Webform Submission: Flagged (field_crazy_flagged) */
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['id'] = 'field_crazy_flagged_value_1';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['table'] = 'field_data_field_crazy_flagged';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['field'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['group'] = 2;
  /* Filter criterion: Webform Submission: Flagged (field_crazy_flagged) */
  $handler->display->display_options['filters']['field_crazy_flagged_value']['id'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['table'] = 'field_data_field_crazy_flagged';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['field'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_crazy_flagged_value']['group'] = 2;
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['operator'] = 'not in';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['is_draft']['group'] = 1;

  /* Display: Friends View */
  $handler = $view->new_display('block', 'Friends View', 'friends_view');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<div class="crazy-submission"><p class="no-results">None of your friends have told their story yet. Click invite friends to get them to tell their tale.</p></div>';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'crazy_shit' => 'crazy_shit',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Webform submissions: UID */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '1';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  /* Filter criterion: Webform Submission: Flagged (field_crazy_flagged) */
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['id'] = 'field_crazy_flagged_value_1';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['table'] = 'field_data_field_crazy_flagged';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['field'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['operator'] = 'not';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['group'] = 2;
  /* Filter criterion: Webform Submission: Flagged (field_crazy_flagged) */
  $handler->display->display_options['filters']['field_crazy_flagged_value']['id'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['table'] = 'field_data_field_crazy_flagged';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['field'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_crazy_flagged_value']['group'] = 2;

  /* Display: Context */
  $handler = $view->new_display('ctools_context', 'Context', 'ctools_context_1');
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';

  /* Display: Blah */
  $handler = $view->new_display('block', 'Blah', 'blah');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'create_and_share_campaign' => 'create_and_share_campaign',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['operator'] = 'not in';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['is_draft']['group'] = 1;
  /* Filter criterion: Webform Submission: Flagged (field_cas_flagged) */
  $handler->display->display_options['filters']['field_cas_flagged_value']['id'] = 'field_cas_flagged_value';
  $handler->display->display_options['filters']['field_cas_flagged_value']['table'] = 'field_data_field_cas_flagged';
  $handler->display->display_options['filters']['field_cas_flagged_value']['field'] = 'field_cas_flagged_value';
  $handler->display->display_options['filters']['field_cas_flagged_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_cas_flagged_value']['group'] = 2;
  /* Filter criterion: Webform Submission: Flagged (field_cas_flagged) */
  $handler->display->display_options['filters']['field_cas_flagged_value_1']['id'] = 'field_cas_flagged_value_1';
  $handler->display->display_options['filters']['field_cas_flagged_value_1']['table'] = 'field_data_field_cas_flagged';
  $handler->display->display_options['filters']['field_cas_flagged_value_1']['field'] = 'field_cas_flagged_value';
  $handler->display->display_options['filters']['field_cas_flagged_value_1']['operator'] = 'not';
  $handler->display->display_options['filters']['field_cas_flagged_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_cas_flagged_value_1']['group'] = 2;

  /* Display: Gallery View */
  $handler = $view->new_display('block', 'Gallery View', 'picsforpets');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'create_and_share_campaign' => 'create_and_share_campaign',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Webform Submission: Flagged (field_crazy_flagged) */
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['id'] = 'field_crazy_flagged_value_1';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['table'] = 'field_data_field_crazy_flagged';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['field'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_crazy_flagged_value_1']['group'] = 2;
  /* Filter criterion: Webform Submission: Flagged (field_crazy_flagged) */
  $handler->display->display_options['filters']['field_crazy_flagged_value']['id'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['table'] = 'field_data_field_crazy_flagged';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['field'] = 'field_crazy_flagged_value';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_crazy_flagged_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_crazy_flagged_value']['group'] = 2;
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['operator'] = 'not in';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['is_draft']['group'] = 1;
  /* Filter criterion: Webform submission data: Data field */
  $handler->display->display_options['filters']['data']['id'] = 'data';
  $handler->display->display_options['filters']['data']['table'] = 'webform_submitted_data';
  $handler->display->display_options['filters']['data']['field'] = 'data';
  $handler->display->display_options['filters']['data']['relationship'] = 'data';
  $handler->display->display_options['filters']['data']['operator'] = 'not empty';
  $handler->display->display_options['filters']['data']['value'] = 'cat';
  /* Filter criterion: Webform submission data: Data field */
  $handler->display->display_options['filters']['data_1']['id'] = 'data_1';
  $handler->display->display_options['filters']['data_1']['table'] = 'webform_submitted_data';
  $handler->display->display_options['filters']['data_1']['field'] = 'data';
  $handler->display->display_options['filters']['data_1']['relationship'] = 'data_1';
  $handler->display->display_options['filters']['data_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['data_1']['value'] = 'NY';
  $export['create_and_share'] = $view;

  return $export;
}
