<?php

/**
 * Handle FTAF numbers sent from the millionth-member SMS broadcast.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_million_member_ftaf';
$workflow->title = 'Process FTAFs sent from the million member broadcast';
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
$activity->beta_optin = array(151923);
// Nothing we can really do if there's an error in thise case, so just send them
// the same msg as the success message.
$activity->response_error = 'Thanks for letting ur friends into my text circle! Stay tuned, we\'ll announce the winner on Do Something\'s Facebook page! If you win you\'ll get a call from me!';
$activity->response_success = 'Thanks for letting ur friends into my text circle! Stay tuned, we\'ll announce the winner on Do Something\'s Facebook page! If you win you\'ll get a call from me!';

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf');

$workflows[$workflow->name] = $workflow;

/**
 * TODO: description
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
$activity->outputs = array('sms_petition_incoming_response');

$activity = $workflow->newActivity('sms_sign_petition');
$activity->name = 'sign_petition';
$activity->inputs = array('start');
$activity->outputs = array('ftaf_prompt', 'sms_flow_generic_ftaf', 'end');
// TODO: need success and error copy
// TODO: need beta -> alpha confirmation message
$activity->petitions = array(
  array(
    'nid' => 727420,
    'mdata_id' => 123456,
    'ftaf_beta_optin' => 123456,
  ),
);

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ftaf_prompt';
$activity->inputs = array('sign_petition');
$activity->outputs = array('ftaf');
// TODO: get actual copy
$activity->question = t('TODO: You signed the petition. Text back friends\' numbers to get them to sign too.');

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('ftaf_prompt', 'sign_petition');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('sign_petition', 'ftaf');

$workflows[$workflow->name] = $workflow;