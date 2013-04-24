<?php

/**
 * Uses the mdata_id to determine which FTAF to trigger
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mdata_ftaf';
$workflow->title = 'Process FTAFs sent directly into an mData';
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
$activity->ftaf_sets = array(
  // FTAF from within the Pregnancy Text Game
  array(
    'mdata_id' => 10393,
    'beta_optin' => array(152373),
    'response_success' => 'Want info on preventing teen pregnancy? Text WAIT for waiting tips, SAFE for safe sex tips, RIGHTS for info on sexual health rights, or PARENT for teen parents.',
  ),
  // FTAF sent by a Pregnancy Text Alpha user
  array(
    'mdata_id' => 10403,
    'beta_optin' => array(152373),
    'response_success' => 'You\'re sending lots of text babies! Text back one number at a time and we\'ll send your friend a text baby',
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf');

$workflows[$workflow->name] = $workflow;