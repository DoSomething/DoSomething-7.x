<?php

//
// sms_flow_mlk_process_beta
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mlk_process_beta';
$workflow->title = 'MLK Process Invited Beta';
$workflow->description = 'Handle Betas invited to the MLK game by Alphas';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('mlk_process_beta');

$activity = $workflow->newActivity('mlk_process_beta');
$activity->name = 'mlk_process_beta';
$activity->accept_responses = array('y','yes','yea','ya');
$activity->beta_message_accept = 'This game is 10 steps. It\'s 1961. Racial segregation is legal. Choose your role: Male black student, 22: text BLACK. White female student, 19: text WHITE.';
$activity->beta_message_reject = 'No prob. If you\'d later like to experience being a student activist in the \'60s risking ur life to stop discrimination, txt MLK. For more info, txt MLKINFO.';
$activity->inputs = array('start');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mlk_process_beta');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_end_game
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mlk_invite_end_game';
$workflow->title = 'MLK Invite End Game';
$workflow->description = 'Inviting from the end of the game';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('mlk_alpha_invite');

$activity = $workflow->newActivity('mlk_alpha_invite');
$activity->name = 'mlk_alpha_invite';
$activity->alpha_optin = 141081;
$activity->beta_optin = 140781;
$activity->sms_response = 'Thanks for sharing! Be a different character: text MLK to play again!';
$activity->inputs = array('start');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mlk_alpha_invite');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_path_1
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mlk_invite_path_1';
$workflow->title = 'MLK Invite Path 1 (SAY/OFFER)';
$workflow->description = 'Inviting from the SAY / OFFER path';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('mlk_alpha_invite');

$activity = $workflow->newActivity('mlk_alpha_invite');
$activity->name = 'mlk_alpha_invite';
$activity->alpha_optin = 140771;
$activity->beta_optin = 140781;
$activity->inputs = array('start');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mlk_alpha_invite');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_path_2
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mlk_invite_path_2';
$workflow->title = 'MLK Invite Path 2 (SITIN/OWN)';
$workflow->description = 'Inviting from the SITIN / OWN path';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('mlk_alpha_invite');

$activity = $workflow->newActivity('mlk_alpha_invite');
$activity->name = 'mlk_alpha_invite';
$activity->alpha_optin = 140831;
$activity->beta_optin = 140781;
$activity->inputs = array('start');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mlk_alpha_invite');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_path_3
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mlk_invite_path_3';
$workflow->title = 'MLK Invite Path 3 (HOME)';
$workflow->description = 'Inviting from the HOME path';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('mlk_alpha_invite');

$activity = $workflow->newActivity('mlk_alpha_invite');
$activity->name = 'mlk_alpha_invite';
$activity->alpha_optin = 140861;
$activity->beta_optin = 140781;
$activity->inputs = array('start');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mlk_alpha_invite');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_path_4
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mlk_invite_path_4';
$workflow->title = 'MLK Invite Path 4 (SEAT)';
$workflow->description = 'Inviting from the SEAT path';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('mlk_alpha_invite');

$activity = $workflow->newActivity('mlk_alpha_invite');
$activity->name = 'mlk_alpha_invite';
$activity->alpha_optin = 140891;
$activity->beta_optin = 140781;
$activity->inputs = array('start');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mlk_alpha_invite');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;
