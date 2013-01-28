<?php

//
// sms_flow_mlk_process_beta
//
$workflow = new ConductorWorkflow();
$workflow->wid('new')
         ->name('sms_flow_mlk_process_beta')
         ->title('MLK Process Invited Beta')
         ->description('Handle Betas invited to the MLK game by Alphas')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('mlk_process_beta'));

$workflow->newActivity('mlk_process_beta')
         ->name('mlk_process_beta')
         ->inputs(array('start'))
         ->outputs(array('end'))
         ->property('accept_responses', array('y','yes','yea','ya'))
         ->property('beta_message_accept', 'This game is 10 steps. It\'s 1961. Racial segregation is legal. Choose your role: Male black student, 22: text BLACK. White female student, 19: text WHITE.')
         ->property('beta_message_reject', 'No prob. If you\'d later like to experience being a student activist in the \'60s risking ur life to stop discrimination, txt MLK. For more info, txt MLKINFO.');

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('mlk_process_beta'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_end_game
//
$workflow = new ConductorWorkflow();
$workflow->wid('new')
         ->name('sms_flow_mlk_invite_end_game')
         ->title('MLK Invite End Game')
         ->description('Inviting from the end of the game')
         ->api_version('1.0');

$activity = $workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('mlk_alpha_invite'));

$activity = $workflow->newActivity('mlk_alpha_invite')
         ->name('mlk_alpha_invite')
         ->inputs(array('start'))
         ->outputs(array('end'))
         ->property('alpha_optin', 141081)
         ->property('beta_optin', 140781)
         ->property('sms_response', 'Thanks for sharing! Be a different character: text MLK to play again!');

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('mlk_alpha_invite'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_path_1
//
$workflow = new ConductorWorkflow();
$workflow->wid('new')
         ->name('sms_flow_mlk_invite_path_1')
         ->title('MLK Invite Path 1 (SAY/OFFER)')
         ->description('Inviting from the SAY / OFFER path')
         ->api_version('1.0');

$activity = $workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('mlk_alpha_invite'));

$workflow->newActivity('mlk_alpha_invite')
         ->name('mlk_alpha_invite')
         ->inputs(array('start'))
         ->outputs(array('end'))
         ->property('alpha_optin', 140771)
         ->property('beta_optin', 140781);

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('mlk_alpha_invite'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_path_2
//
$workflow = new ConductorWorkflow();
$workflow->wid('new')
         ->name('sms_flow_mlk_invite_path_2')
         ->title('MLK Invite Path 2 (SITIN/OWN)')
         ->description('Inviting from the SITIN / OWN path')
         ->api_version('1.0');

$activity = $workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('mlk_alpha_invite'));

$activity = $workflow->newActivity('mlk_alpha_invite')
         ->name('mlk_alpha_invite')
         ->inputs(array('start'))
         ->outputs(array('end'))
         ->property('alpha_optin', 140831)
         ->property('beta_optin', 140781);

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('mlk_alpha_invite'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_path_3
//
$workflow = new ConductorWorkflow();
$workflow->wid('new')
         ->name('sms_flow_mlk_invite_path_3')
         ->title('MLK Invite Path 3 (HOME)')
         ->description('Inviting from the HOME path')
         ->api_version('1.0');

$activity = $workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('mlk_alpha_invite'));

$activity = $workflow->newActivity('mlk_alpha_invite')
         ->name('mlk_alpha_invite')
         ->inputs(array('start'))
         ->outputs(array('end'))
         ->property('alpha_optin', 140861)
         ->property('beta_optin', 140781);

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('mlk_alpha_invite'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_mlk_invite_path_4
//
$workflow = new ConductorWorkflow();
$workflow->wid('new')
         ->name('sms_flow_mlk_invite_path_4')
         ->title('MLK Invite Path 4 (SEAT)')
         ->description('Inviting from the SEAT path')
         ->api_version('1.0');

$activity = $workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('mlk_alpha_invite'));

$activity = $workflow->newActivity('mlk_alpha_invite')
         ->name('mlk_alpha_invite')
         ->inputs(array('start'))
         ->outputs(array('end'))
         ->property('alpha_optin', 140891)
         ->property('beta_optin', 140781);

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('mlk_alpha_invite'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;