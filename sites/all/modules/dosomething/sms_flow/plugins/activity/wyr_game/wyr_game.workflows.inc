<?php

require_once drupal_get_path('module', 'sms_flow') . '/sms_flow_game_constants.inc';

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
$activity->game_id = SmsFlowGameConstants::WYR_GAME;
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
    'game_id'      => SmsFlowGameConstants::WYR_GAME,
    'opt_in_paths' => array(142223, 142503, 143053),
  ),
  // Tips for financial education campaign
  array(
    'mdata_id'     => 9903,
    'game_id'      => SmsFlowGameConstants::FINANCIAL_ED_TIPS,
    'opt_in_paths' => array(144643, 144663, 144683, 145563, 145573, 145583, 145593, 145603, 145613, 145623, 145633, 145643, 145653, 145663, 145673, 145683, 145693, 145703, 145713, 145723),
    'path_special' => 148393,
    'send_to_special_on' => 2,
  ),
  // Drive marketing tips for PBJ campaign.
  array(
    'mdata_id'     => 10103,
    'game_id'      => SmsFlowGameConstants::PBJ_MARKETING_TIPS,
    'opt_in_paths' => array(148843, 148853, 148863, 148873, 148883, 148893, 148903, 148913, 148923, 148933, 148943, 149243),
  ),
  // Tips for running a PBJ campaign.
  array(
    'mdata_id'     => 10113,
    'game_id'      => SmsFlowGameConstants::PBJ_DRIVE_TIPS,
    'opt_in_paths' => array(148953, 148963, 148973, 148983, 148993),
  ),
  // Pregnancy Text WAIT tips
  array(
    'mdata_id'     => 10223,
    'game_id'      => SmsFlowGameConstants::PREGTEXT_WAIT_TIPS,
    'opt_in_paths' => array(153193, 153203, 153213, 153223, 153233, 153243, 153253, 153263, 153273),
    'path_special' => 153183,
    'send_to_special_on' => 3,
  ),
  // Pregnancy Text SAFE tips
  array(
    'mdata_id'     => 10233,
    'game_id'      => SmsFlowGameConstants::PREGTEXT_SAFE_TIPS,
    'opt_in_paths' => array(153283, 153293, 153303, 153313, 153323, 153333, 153343, 153353),
  ),
  // Pregnancy Text PARENT tips
  array(
    'mdata_id'     => 10243,
    'game_id'      => SmsFlowGameConstants::PREGTEXT_PARENT_TIPS,
    'opt_in_paths' => array(153363, 153373, 153383),
  ),
  // Pregnancy Text RIGHTS tips
  array(
    'mdata_id'     => 10253,
    'game_id'      => SmsFlowGameConstants::PREGTEXT_RIGHTS_TIPS,
    'opt_in_paths' => array(153393, 153403, 153413),
  ),
  // Thumb Wars IDEA tips
  array(
    'mdata_id'     => 10663,
    'game_id'      => SmsFlowGameConstants::THUMBWARS_IDEAS_TIPS,
    'opt_in_paths' => array(155963, 155973, 155983, 155993, 156003, 156013),
    'path_special' => 156023,
    'send_to_special_on' => 7,
  ),
  // Thumb Wars FACTS tips
  array(
    'mdata_id'     => 10673,
    'game_id'      => SmsFlowGameConstants::THUMBWARS_FACTS_TIPS,
    'opt_in_paths' => array(156033, 156043, 156053, 156063, 156073),
  ),
  // Puppy Text FAQ tips
  array(
    'mdata_id'     => 10753,
    'game_id'      => SmsFlowGameConstants::PUPPYTEXT_FAQ_TIPS,
    'opt_in_paths' => array(156573, 156583, 156593, 156603, 156613, 156623, 156713),
  ),
  // Puppy Text DOG tips
  array(
    'mdata_id'     => 10763,
    'game_id'      => SmsFlowGameConstants::PUPPYTEXT_DOG_TIPS,
    'opt_in_paths' => array(156643, 156653, 156663, 156673, 156683, 156693, 156703),
    'path_special' => 156633,
    'send_to_special_on' => 3,
  ),
  // Oklahoma ART tips
  array(
    'mdata_id'     => 10803,
    'game_id'      => SmsFlowGameConstants::OK_ART_TIPS,
    'opt_in_paths' => array(157683, 157693, 157703, 157713, 157723, 157733),
    'path_special' => 157743,
    'send_to_special_on' => 7,
  ),
  // Climate Change SAS - NINJA tips
  array(
    'mdata_id'     => 10831,
    'game_id'      => SmsFlowGameConstants::CLIMATE_SAS_NINJA,
    'opt_in_paths' => array(158717, 158719, 158721, 158723),
    'path_special' => 158725,
    'send_to_special_on' => 5,
  ),
  // I Heart Dad 2013 - Blood Pressure tips
  array(
    'mdata_id'     => 10837,
    'game_id'      => SmsFlowGameConstants::IHEARTDAD_BP_TIPS,
    'opt_in_paths' => array(158777, 158779, 158781, 158783),
    'path_special' => 158785,
    'send_to_special_on' => 5,
  ),
  // I Heart Dad 2013 - Health tips
  array(
    'mdata_id'     => 10839,
    'game_id'      => SmsFlowGameConstants::IHEARTDAD_HEALTH_TIPS,
    'opt_in_paths' => array(158795, 158797, 158799, 158801),
    'path_special' => 158803,
    'send_to_special_on' => 5,
  ),
  // Hunt 2013 - INSPIRE quotes
  array(
    'mdata_id'     => 10857,
    'game_id'      => SmsFlowGameConstants::HUNT_INSPIRE,
    'opt_in_paths' => array(159345, 159347, 159349, 159351, 159353, 159355, 159357, 159359, 159361, 159363, 159365, 159367, 159369, 159371, 159373, 159375),
    'path_special' => 159543,
    'send_to_special_on' => 3,
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mcommons_random_paths');

$workflows[$workflow->name] = $workflow;
