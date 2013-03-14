<?php

/**
 * Starting point for the WYR game. Randomize which question set the user
 * will be sent to.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_wyr_game_start';
$workflow->title = 'Would You Rather - Start Game';
$workflow->description = 'WYR starting point. Select random question set to give the user.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('wyr_game_start');

$activity = $workflow->newActivity('game_random_path');
$activity->name = 'wyr_game_start';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->game_id = 2;
$activity->opt_in_paths = array(142223, 142503, 143053);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('wyr_game_start');

$workflows[$workflow->name] = $workflow;

/**
 * Randomizes TIPS sent to user. Uses same activity as wyr_game_start, but
 * with different id and paths.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_wyr_tips';
$workflow->title = 'Would You Rather - Tips';
$workflow->description = 'Select random tips to send to the user.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('wyr_game_tips');

$activity = $workflow->newActivity('game_random_path');
$activity->name = 'wyr_game_tips';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->game_id = 3;
$activity->opt_in_paths = array(144643, 144663, 144683, 145563, 145573, 145583, 145593, 145603, 145613, 145623, 145633, 145643, 145653, 145663, 145673, 145683, 145693, 145703, 145713, 145723);
$activity->path_special = 148393;
$activity->send_to_special_on = 2;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('wyr_game_tips');

$workflows[$workflow->name] = $workflow;

/**
 * Handle the end of WYR question sets. Process response to final answer
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_wyr_end_qset';
$workflow->title = 'Would You Rather - End of QSet';
$workflow->description = 'Process final answer to the QSet and respond to the user.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('process_qset_answers');

$activity = $workflow->newActivity('wyr_process_qset_answers');
$activity->name = 'process_qset_answers';
$activity->inputs = array('start');
$activity->outputs = array('ftaf');
$activity->game_id = 2;
$activity->type_override = 'sms_game';
$activity->default_response = 'Ah! We encountered a problem. Maybe we were too crazy with our money saving. Text WYR to try another set of questions. Or text TIPS for easy ways to save money.';

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('process_qset_answers');
$activity->outputs = array('end');
$activity->response_error = 'Sorry! We didn\'t understand that. Text WYR to get a new set of questions. Or text TIPS for easy ways to save money.';
$activity->response_success = 'We\'ll send you your friends\' answers once they complete the questions. Text WYR to get more ?s yourself.';

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf');

$workflows[$workflow->name] = $workflow;
