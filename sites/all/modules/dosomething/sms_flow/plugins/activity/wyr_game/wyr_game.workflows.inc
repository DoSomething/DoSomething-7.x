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
 * Handle the end of WYR question set #1. Process response to final answer
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_wyr_end_qset_1';
$workflow->title = 'Would You Rather - End of QSet 1';
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
$activity->incoming_opt_in_path = 142223;
$activity->type_override = 'sms_game';
$activity->opt1_valid_answers = array('a', 'a)', 'a.');
$activity->opt2_valid_answers = array('b', 'b)', 'b.');
$activity->sms_response = t("How about making shopping lists? Know what u need so u don't make excess purchases. Txt WYR for more ?s or txt back friends #s to ask what they would rather.");

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('process_qset_answers');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf');

$workflows[$workflow->name] = $workflow;

/**
 * Handle the end of WYR question set #2. Process response to final answer
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_wyr_end_qset_2';
$workflow->title = 'Would You Rather - End of QSet 2';
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
$activity->incoming_opt_in_path = 142503;
$activity->type_override = 'sms_game';
$activity->opt1_valid_answers = array('a');
$activity->opt2_valid_answers = array('b');
$activity->sms_response = t("Instead of all that, try having ppl over.Watch movies or cook food @ home instead of spending $$ out.Txt WYR for more or txt friends #s to see what they'd do");

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('process_qset_answers');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf');

$workflows[$workflow->name] = $workflow;

/**
 * Handle the end of WYR question set #3. Process response to final answer
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_wyr_end_qset_3';
$workflow->title = 'Would You Rather - End of QSet 3';
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
$activity->incoming_opt_in_path = 143053;
$activity->type_override = 'sms_game';
$activity->opt1_valid_answers = array('a');
$activity->opt2_valid_answers = array('b');
$activity->sms_response = t('Hmm, try turning off lights in ur home when leaving.Less lights on = more $$ for you! See crazy stuff ppl do to save: doso.me/8 or txt friends #s to play w them');

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('process_qset_answers');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf');

$workflows[$workflow->name] = $workflow;