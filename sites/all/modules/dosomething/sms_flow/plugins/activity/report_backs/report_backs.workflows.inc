<?php

//
// sms_flow_alcoa_report_back workflow
//
$workflow = new ConductorWorkflow();
$workflow->wid('new')
         ->name('sms_flow_alcoa_report_back')
         ->title('50 Cans Report Back')
         ->description('Submits the 50 Cans report back')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('strip_signature'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature')
         ->inputs(array('start'))
         ->outputs(array('50cans_report_back'));

$workflow->newActivity('50cans_report_back')
         ->name('50cans_report_back')
         ->inputs(array('strip_signature'))
         ->outputs(array('end'));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('50cans_report_back'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_beta_campaign_report_back workflow
//
$workflow = new ConductorWorkflow();
$workflow->wid('new')
         ->name('sms_flow_beta_campaign_report_back')
         ->title('Beta Campaign Report Back')
         ->description('Submits the report back for use with the Cleanup (beta) campaign')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('ask_trash_pickup'));

$workflow->newActivity('sms_prompt')
         ->name('ask_trash_pickup')
         ->inputs(array('start'))
         ->outputs(array('ask_people_involved'))
         ->question(t('How many pieces of trash did you pick up?'));

$workflow->newActivity('sms_prompt')
         ->name('ask_people_involved')
         ->inputs(array('ask_trash_pickup'))
         ->outputs(array('ask_zip'))
         ->question(t('How many people were involved?'));

$workflow->newActivity('sms_prompt')
         ->name('ask_zip')
         ->inputs(array('ask_people_involved'))
         ->outputs(array('ask_picture'))
         ->question(t('What zip code did you clean up?'));

$workflow->newActivity('mms_prompt')
         ->name('ask_picture')
         ->inputs(array('ask_zip'))
         ->outputs(array('strip_signature'))
         ->question(t('Send us a picture of what you did!'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature')
         ->inputs(array('ask_picture'))
         ->outputs(array('submit'));

$workflow->newActivity('beta_campaign_report_back')
         ->name('submit')
         ->inputs(array('strip_signature'))
         ->outputs(array('end'));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('submit'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;