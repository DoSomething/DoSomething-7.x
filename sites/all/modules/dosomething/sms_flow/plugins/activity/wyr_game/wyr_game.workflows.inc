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

$activity = $workflow->newActivity('wyr_game_start');
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

$activity = $workflow->newActivity('wyr_game_start');
$activity->name = 'wyr_game_tips';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->game_id = 3;
$activity->opt_in_paths = array(144643, 144663, 144683);

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

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('process_qset_answers');
$activity->outputs = array('end');
$activity->response_error = 'Sorry! Looks like we\'ve run into a problem. Text WYR to get a new set of questions.';
$activity->response_success = 'We\'ll send you your friends\' answers once they complete the questions. Text WYR to get more ?s yourself.';

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf');

$workflows[$workflow->name] = $workflow;
