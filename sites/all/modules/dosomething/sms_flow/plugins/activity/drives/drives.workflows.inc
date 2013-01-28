<?php

//
// sms_flow_drives_create workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid('new')
         ->name('sms_flow_drives_create')
         ->title('SMS Flow Drives Create')
         ->description('Workflow for creating a new drive, or joining an existing one')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->title('Start')
         ->inputs(array())
         ->outputs(array('ask_school_level'));

$workflow->newActivity('sms_prompt')
         ->name('ask_school_level')
         ->title('Ask the user what level of school they\'re in.')
         ->inputs(array('start'))
         ->outputs(array('ask_school_state'))
         ->question(t('1/3 Great, let\'s get you started. There will be 3 questions. Are you in 1) middle/high school or 2) college? Reply with 1 or 2.'));

$workflow->newActivity('sms_prompt')
         ->name('ask_school_state')
         ->title('Ask the user what state they\'re in.')
         ->inputs(array('ask_school_level'))
         ->outputs(array('ask_school_name'))
         ->question(t('2/3 What state is your school in? Reply with the 2 letter abbreviation (ex: NY)'));

$workflow->newActivity('sms_prompt')
         ->name('ask_school_name')
         ->title('Ask the user the name of their school.')
         ->inputs(array('ask_school_state'))
         ->outputs(array('strip_signature'))
         ->question(t('3/3 Last question before we look up your school. What\'s the name of your school?'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature')
         ->inputs(array('ask_school_name'))
         ->outputs(array('school_search'));

$workflow->newActivity('sms_flow_school_search')
         ->name('school_search')
         ->title('Lookup the school based on the user supplied info.')
         ->inputs(array('strip_signature'))
         ->outputs(array('check_account_exists', 'end'));

$workflow->newActivity('sms_check_account_exists')
         ->name('check_account_exists')
         ->title('Check that the user exsists.')
         ->inputs(array('school_search'))
         ->outputs(array('account_exists', 'no_account_exists'));

$workflow->newActivity('activity')
         ->name('account_exists')
         ->title('User exsists by cell.')
         ->inputs(array('check_account_exists'))
         ->outputs(array('create_drive'));

$workflow->newActivity('activity')
         ->name('no_account_exists')
         ->title('No user exsists by supplied cell.')
         ->inputs(array('check_account_exists'))
         ->outputs(array('ask_email'));

$workflow->newActivity('sms_prompt')
         ->name('ask_email')
         ->title('Ask user for their email address.')
         ->inputs(array('no_account_exists'))
         ->outputs(array('ask_first_name'))
         ->question(t('Cool, let\'s get started with adding you to the school\'s drive. What\'s your email address? We\'ll need it to contact you with details about your drive.'));

$workflow->newActivity('sms_prompt')
         ->name('ask_first_name')
         ->title('What is the user\'s first name?.')
         ->inputs(array('ask_email'))
         ->outputs(array('strip_signature_2'))
         ->question(t('One last question - what\'s your first name?'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature_2')
         ->inputs(array('ask_first_name'))
         ->outputs(array('create_account'));

$workflow->newActivity('sms_flow_create_account')
         ->name('create_account')
         ->title('Create the new user account.')
         ->inputs(array('strip_signature_2'))
         ->outputs(array('create_drive'));

$workflow->newActivity('sms_create_drive')
         ->name('create_drive')
         ->title('Create a new drive at the user\'s school.')
         ->inputs(array('account_exists', 'create_account'))
         ->outputs(array('strip_signature_3', 'end'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature_3')
         ->inputs(array('create_drive'))
         ->outputs(array('ftaf_process'));

$workflow->newActivity('sms_flow_ftaf')
         ->name('ftaf_process')
         ->inputs(array('strip_signature_3'))
         ->outputs(array('end'))
         ->property('alpha_optin', 131891)
         ->property('beta_optin', 129751)
         ->property('response_fail', t('Sorry, we didn\'t understand your last response. To invite ppl to your drive again, text TFJINVITE.'))
         ->property('response_success', t('We\'ve sent along invites to your friends. Reply back with TFJINVITE if you want to invite more.'));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('ftaf_process', 'create_drive', 'school_search'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_drives_invite workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid('new')
         ->name('sms_flow_drives_invite')
         ->title('SMS Flow Drives Invite')
         ->description('Workflow for invitees of a drive invite')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('drive_invite_response'));

$workflow->newActivity('sms_flow_drive_invite_response')
         ->name('drive_invite_response')
         ->title('Process user rejection or acceptance of the invite')
         ->inputs(array('start'))
         ->outputs(array('check_account_exists', 'end'))
         ->property('accept_responses', array('y','yes','yea','ya','tfjjoin','tfj join'))
         ->property('invite_rejected_message', t('No prob. You\'re not getting added into the drive. If you want to join in the future, text back TFJJOIN.'));

$workflow->newActivity('sms_check_account_exists')
         ->name('check_account_exists')
         ->inputs(array('drive_invite_response'))
         ->outputs(array('account_exists', 'no_account_exists'));

$workflow->newActivity('activity')
         ->name('account_exists')
         ->inputs(array('check_account_exists'))
         ->outputs(array('process_beta'));

$workflow->newActivity('activity')
         ->name('no_account_exists')
         ->inputs(array('check_account_exists'))
         ->outputs(array('ask_first_name'));

$workflow->newActivity('sms_prompt')
         ->name('ask_first_name')
         ->title('Ask Name')
         ->question(t('Awesome! Reply with ur first name and we\'ll set u up with a login for our website where you can learn more about the drive details and about DoSomething.org'))
         ->inputs(array('no_account_exists'))
         ->outputs(array('strip_signature'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature')
         ->inputs(array('ask_first_name'))
         ->outputs(array('create_account'));

$workflow->newActivity('sms_flow_create_account')
         ->name('create_account')
         ->inputs(array('strip_signature'))
         ->outputs(array('process_beta'));

$workflow->newActivity('sms_flow_drives_invited_beta')
         ->name('process_beta')
         ->inputs(array('account_exists', 'create_account'))
         ->outputs(array('ftaf_prompt'))
         ->property('alpha_campaign_id', 99961);

$workflow->newActivity('sms_prompt')
         ->name('ftaf_prompt')
         ->inputs(array('process_beta'))
         ->outputs(array('ftaf_process'))
         ->question(t('Amazing! Last year we collected over a million pairs. Text us your friends numbers to invite them to join your drive.'));

$workflow->newActivity('sms_flow_ftaf')
         ->name('ftaf_process')
         ->inputs(array('ftaf_prompt'))
         ->outputs(array('end'))
         ->property('alpha_optin', 131891)
         ->property('beta_optin', 129751)
         ->property('response_success', t('We\'ve sent along invites to your friends. Reply back with TFJINVITE if you want to invite more.'))
         ->property('response_fail', t('Sorry, we didn\'t understand your last response. To join the drive again, text TFJJOIN. To invite ppl to ur drive, text TFJINVITE.'));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('drive_invite_response', 'ftaf_process'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_ftaf workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid('new')
         ->name('sms_flow_ftaf')
         ->title('Forward to a Friend')
         ->description('Custom forward to a friend workflow')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('ftaf_prompt'));

$workflow->newActivity('sms_prompt')
         ->name('ftaf_prompt')
         ->inputs(array('start'))
         ->outputs(array('strip_signature'))
         ->question(t('Awesome! All you need to do is text us your friends cell phone numbers and we\'ll invite then to participate in your Teens for Jeans drive.'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature')
         ->inputs(array('ftaf_prompt'))
         ->outputs(array('ftaf_process'));

$workflow->newActivity('sms_flow_ftaf')
         ->name('ftaf_process')
         ->inputs(array('strip_signature'))
         ->outputs(array('end'))
         ->property('alpha_optin', 131891)
         ->property('beta_optin', 129751)
         ->property('response_fail', t('Sorry, we didn\'t understand your last response. To try again, reply back with TFJINVITE.'));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('ftaf_process'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;