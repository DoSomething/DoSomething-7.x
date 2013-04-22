<?php

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

/**
 * Handle phone numbers sent in for WYR to forward friend to the game.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_wyr_ftaf';
$workflow->title = 'Would You Rather - Forward to a Friend';
$workflow->description = 'Forward friend phone numbers into the WYR game';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('args_to_context');

$activity = $workflow->newActivity('args_to_context_value');
$activity->name = 'args_to_context';
$activity->inputs = array('start');
$activity->outputs = array('ftaf');
$activity->context_field = 'ftaf_prompt:message';

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('args_to_context');
$activity->outputs = array('end');
$activity->beta_optin = array(142223, 142503, 143053);
$activity->id_override = 2;
$activity->type_override = 'sms_game';
$activity->response_error = 'Sorry! We didn\'t understand that. Text WYR to get a new set of questions. Or text TIPS for easy ways to save money.';
$activity->response_success = 'Cool, we\'ll let you know what your friend\'s say they\'d do to save some $$. Text WYR to get more ?s yourself.';

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf');

$workflows[$workflow->name] = $workflow;

/**
 * Handle all random pathing for randoming pathing and WYR-style games under one workflow
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mcommons_random_path';
$workflow->title = 'Handler for path randomizing.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('mcommons_random_paths');

$activity = $workflow->newActivity('mcommons_random_paths');
$activity->name = 'mcommons_random_paths';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->sets = array(
  // Starting paths for the financial education WYR game
  array(
    'mdata_id'     => 9783,
    'game_id'      => 2,
    'opt_in_paths' => array(142223, 142503, 143053),
  ),
  // Tips for financial education campaign
  array(
    'mdata_id'     => 9903,
    'game_id'      => 3,
    'opt_in_paths' => array(144643, 144663, 144683, 145563, 145573, 145583, 145593, 145603, 145613, 145623, 145633, 145643, 145653, 145663, 145673, 145683, 145693, 145703, 145713, 145723),
    'path_special' => 148393,
    'send_to_special_on' => 2,
  ),
  // Drive marketing tips for PBJ campaign.
  array(
    'mdata_id'     => 10103,
    'game_id'      => 4,
    'opt_in_paths' => array(148843, 148853, 148863, 148873, 148883, 148893, 148903, 148913, 148923, 148933, 148943, 149243),
  ),
  // Tips for running a PBJ campaign.
  array(
    'mdata_id'     => 10113,
    'game_id'      => 5,
    'opt_in_paths' => array(148953, 148963, 148973, 148983, 148993),
  ),
  // Pregnancy Text WAIT tips
  array(
    'mdata_id'     => 10223,
    'game_id'      => 6,
    'opt_in_paths' => array(153183, 153193, 153203, 153213, 153223, 153233, 153243, 153253, 153263, 153273),
  ),
  // Pregnancy Text SAFE tips
  array(
    'mdata_id'     => 10233,
    'game_id'      => 7,
    'opt_in_paths' => array(153283, 153293, 153303, 153313, 153323, 153333, 153343, 153353),
  ),
  // Pregnancy Text PARENT tips
  array(
    'mdata_id'     => 10243,
    'game_id'      => 8,
    'opt_in_paths' => array(153363, 153373, 153383),
  ),
  // Pregnancy Text RIGHTS tips
  array(
    'mdata_id'     => 10253,
    'game_id'      => 9,
    'opt_in_paths' => array(153393, 153403, 153413),
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mcommons_random_paths');

$workflows[$workflow->name] = $workflow;
