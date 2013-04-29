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
// TODO: consider also supporting opt_in_path_id instead of just mdata_id
$activity->petitions = array(
  array(
    'nid' => 729172,
    'mdata_id' => 10413,
    'ftaf_beta_optin' => 154033,
    'ftaf_response_success' => 'Thanks for sharing. Get more people involved, text SIGN. Want to be in Phillp Phillips new music video? Go to: http://doso.me/h to find out how.',
    'beta_to_alpha_feedback' => 154113,
  ),
);

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ftaf_prompt';
$activity->inputs = array('sign_petition');
$activity->outputs = array('ftaf');
$activity->question = t('Great! Organize your friends to get involved, Text 5 friends #s to have them add their voice to the petition.');

$activity = $workflow->newActivity('sms_flow_generic_ftaf');
$activity->name = 'ftaf';
$activity->inputs = array('ftaf_prompt', 'sign_petition');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('sign_petition', 'ftaf');

$workflows[$workflow->name] = $workflow;