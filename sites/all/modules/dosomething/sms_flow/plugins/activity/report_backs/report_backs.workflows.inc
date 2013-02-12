<?php

//
// sms_flow_alcoa_report_back workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_alcoa_report_back';
$workflow->title = '50 Cans Report Back';
$workflow->description = 'Submits the 50 Cans report back';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->title = 'Start';
$activity->inputs = array();
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->title = 'Strip Signature';
$activity->inputs = array('start');
$activity->outputs = array('50cans_report_back');

$activity = $workflow->newActivity('50cans_report_back');
$activity->name = '50cans_report_back';
$activity->title = '50 Cans Report Back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('50cans_report_back');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_beta_campaign_report_back workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_beta_campaign_report_back';
$workflow->title = 'Beta Campaign Report Back';
$workflow->description = 'Submits the report back for use with the Cleanup (beta) campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('ask_trash_pickup');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_trash_pickup';
$activity->question = t('How many pieces of trash did you pick up?');
$activity->inputs = array('start');
$activity->outputs = array('ask_people_involved');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people_involved';
$activity->question = t('How many people were involved?');
$activity->inputs = array('ask_trash_pickup');
$activity->outputs = array('ask_zip');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_zip';
$activity->question = t('What zip code did you clean up?');
$activity->inputs = array('ask_people_involved');
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->question = t('Send us a picture of what you did!');
$activity->inputs = array('ask_zip');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_picture');
$activity->outputs = array('submit');

$activity = $workflow->newActivity('beta_campaign_report_back');
$activity->name = 'submit';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('submit');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_tfj2013_report_back
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_tfj2013_report_back';
$workflow->title = 'TFJ 2013 Campaign Report Back';
$workflow->description = 'Submits the report back for use with the Teens for Jeans 2013 campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('check_school');

$activity = $workflow->newActivity('sms_flow_check_school');
$activity->name = 'check_school';
$activity->inputs = array('start');
$activity->outputs = array('school_found', 'no_school_found');
$activity->webform_nid_check = 725896;

$activity = $workflow->newActivity('activity');
$activity->name = 'no_school_found';
$activity->inputs = array('check_school');
$activity->outputs = array('ask_school_level');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_level';
$activity->inputs = array('start');
$activity->outputs = array('ask_school_state');
$activity->question = '1/3 First, let\'s find your school. There will be 3 questions. Are you in 1) middle/high school or 2) college? Reply with 1 or 2.';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_state';
$activity->inputs = array('ask_school_level');
$activity->outputs = array('ask_school_name');
$activity->question = '2/3 What state is your school in? Reply with the 2 letter abbreviation (ex: NY)';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_name';
$activity->inputs = array('ask_school_state');
$activity->outputs = array('strip_signature');
$activity->question = '3/3 Last question before we look up your school. What\'s the name of your school?';

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_school_name');
$activity->outputs = array('school_search');

$activity = $workflow->newActivity('sms_flow_school_search');
$activity->name = 'school_search';
$activity->inputs = array('strip_signature');
$activity->outputs = array('school_found', 'end');
$activity->invalid_id_message = t('That\'s not a valid school ID. Go to http://doso.me/6 to submit your report back there.');
$activity->no_school_message = t('Sorry, we couldn\'t find any matching schools. Visit http://doso.me/6 to tell us what you did and earn a t-shirt.');
$activity->schools_found_post_message = t('Text back your school ID# to continue. Didn\'t find your school? Visit http://doso.me/6 for more info and tell us what you did there.');

$activity = $workflow->newActivity('activity');
$activity->name = 'school_found';
$activity->inputs = array('check_school');
$activity->outputs = array('ask_jeans');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_jeans';
$activity->inputs = array('school_found');
$activity->outputs = array('ask_people');
$activity->question = 'Awesome! How many pairs of jeans did you collect?';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_jeans');
$activity->outputs = array('ask_photo');
$activity->question = 'How many people helped with your drive?';

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_photo';
$activity->inputs = array('ask_people');
$activity->outputs = array('strip_signature_2');
$activity->question = 'Finally, send us a picture of your drive or in store drop off for a free DS tshirt.';

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature_2';
$activity->inputs = array('ask_photo');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('tfj_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_photo');
$activity->outputs = array('end');
$activity->webform_nid = 727486;
$activity->success_message = t('[TODO] Thanks for reporting back on Teens for Jeans!');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('test');

$workflows[$workflow->name] = $workflow;