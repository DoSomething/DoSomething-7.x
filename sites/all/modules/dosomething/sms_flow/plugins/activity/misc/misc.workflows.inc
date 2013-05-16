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

/**
 * Workflow for signing petitions via SMS. Expected initial message from the user
 * will include first name and last initial. Signing of the petition will be followed
 * by an FTAF.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_sign_petition';
$workflow->title = 'Given a user\'s info, programmatically sign a petition on that user\'s behalf';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('args_to_context');

$activity = $workflow->newActivity('args_to_context_value');
$activity->name = 'args_to_context';
$activity->inputs = array('start');
$activity->outputs = array('sign_petition');
$activity->context_field = 'sms_petition_incoming_response';

$activity = $workflow->newActivity('sms_sign_petition');
$activity->name = 'sign_petition';
$activity->inputs = array('args_to_context');
$activity->outputs = array('ftaf_prompt', 'ftaf', 'end');
// TODO: consider also supporting broadcast_id
$activity->petitions = array(
  // Band Together Broadcast signatures
  array(
    'nid' => 729172,
    'mdata_id' => 10413,
    'ftaf_beta_optin' => 154033,
    'ftaf_prompt' => "Thanks! Once we get 10K signatures they'll be delivered to the Common App Board of Directors. Organize ur friends to sign. Txt 5 friends #s to add their voice.",
    'ftaf_response_success' => 'Thanks for sharing. Get more people involved, text SIGN. Want to be in Phillp Phillips new music video? Go to: http://doso.me/h to find out how.',
    'beta_to_alpha_feedback' => 154113,
  ),
  // Band Together Beta signatures
  array(
    'nid' => 729172,
    'opt_in_path_id' => 154033,
    'skip_ftaf' => TRUE,
    'success_response' => 154153,
    'beta_to_alpha_feedback' => "Your friend @name signed the petition! You're on a roll, organize more friends to sign by texting SIGN, or join our music video challenge: http://doso.me/h",
    'alpha_campaign_id' => 116263,
  ),
);

$activity = $workflow->newActivity('sms_prompt_from_context');
$activity->name = 'ftaf_prompt';
$activity->inputs = array('sign_petition');
$activity->outputs = array('ftaf');
$activity->question_context_key = 'ftaf_prompt';

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('ftaf_prompt', 'sign_petition');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('sign_petition', 'ftaf');

$workflows[$workflow->name] = $workflow;