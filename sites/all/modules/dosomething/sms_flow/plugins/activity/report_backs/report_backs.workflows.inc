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