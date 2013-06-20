<?php

//
// sms_flow_drives_create workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_drives_create';
$workflow->title = 'SMS Flow Drives Create';
$workflow->description = 'Workflow for creating a new drive, or joining an existing one';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$workflow->title = 'Start';
$workflow->description = 'Workflow for creating a new drive, or joining an existing one';
$activity->inputs = array();
$activity->outputs = array('ask_school_level');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_level';
$activity->title = 'Ask the user what level of school they\'re in.';
$activity->question = t('1/3 Great, let\'s get you started. There will be 3 questions. Are you in 1) middle/high school or 2) college? Reply with 1 or 2.');
$activity->inputs = array('start');
$activity->outputs = array('ask_school_state');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_state';
$activity->title = 'Ask the user what state they\'re in.';
$activity->question = t('2/3 What state is your school in? Reply with the 2 letter abbreviation (ex: NY)');
$activity->inputs = array('ask_school_level');
$activity->outputs = array('ask_school_name');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_name';
$activity->title = 'Ask the user the name of their school.';
$activity->question = t('3/3 Last question before we look up your school. What\'s the name of your school?');
$activity->inputs = array('ask_school_state');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->title = 'Remove the user\'s message signature crap at the end of their reply.';
$activity->inputs = array('ask_school_name');
$activity->outputs = array('school_search');

$activity = $workflow->newActivity('sms_flow_school_search');
$activity->name = 'school_search';
$activity->title = 'Lookup the school based on the user supplied info.';
$activity->inputs = array('strip_signature');
$activity->outputs = array('check_account_exists', 'end');
$activity->invalid_id_message = t('That\'s not a valid school ID. Text JEANS to search again. Or go to http://doso.me/6 for more info.');
$activity->no_school_message = t('Sorry, we couldn\'t find any matching schools. Text JEANS to search again. Or visit http://doso.me/6 for more info.');
$activity->schools_found_post_message = t('Text back your school ID# to start your drive. Didn\'t find your school? Text JEANS to try again. Or visit http://doso.me/6 for more info.');

$activity = $workflow->newActivity('sms_check_account_exists');
$activity->name = 'check_account_exists';
$activity->title = 'Check that the user exsists.';
$activity->inputs = array('school_search');
$activity->outputs = array('account_exists', 'no_account_exists');

$activity = $workflow->newActivity('activity');
$activity->name = 'account_exists';
$activity->title = 'User exsists by cell.';
$activity->inputs = array('check_account_exists');
$activity->outputs = array('create_drive');

$activity = $workflow->newActivity('activity');
$activity->name = 'no_account_exists';
$activity->title = 'No user exsists by supplied cell.';
$activity->inputs = array('check_account_exists');
$activity->outputs = array('ask_email');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_email';
$activity->title = 'Ask user for their email address.';
$activity->question = t('Cool, let\'s get started with adding you to the school\'s drive. What\'s your email address? We\'ll need it to contact you with details about your drive.');
$activity->inputs = array('no_account_exists');
$activity->outputs = array('ask_first_name');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_first_name';
$activity->title = 'What is the user\'s first name?.';
$activity->question = t('One last question - what\'s your first name?');
$activity->inputs = array('ask_email');
$activity->outputs = array('strip_signature_2');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature_2';
$activity->title = 'Remove the user\'s message signature crap at the end of their reply.';
$activity->inputs = array('ask_first_name');
$activity->outputs = array('create_account');

$activity = $workflow->newActivity('sms_flow_create_account');
$activity->name = 'create_account';
$activity->title = 'Create the new user account.';
$activity->inputs = array('strip_signature_2');
$activity->outputs = array('create_drive');

$activity = $workflow->newActivity('sms_create_drive');
$activity->name = 'create_drive';
$activity->title = 'Create a new drive at the user\'s school.';
$activity->inputs = array('account_exists', 'create_account');
$activity->outputs = array('strip_signature_post_create_drive', 'end');
$activity->campaign_url = 'teensforjeans';
$activity->sign_up_nid = 725896;
$activity->response_error = 'Sorry! We ran into a problem creating your drive. Text JEANS to try again or visit http://doso.me/6 to try online.';
$activity->response_in_drive = 'You already signed up for a drive! Login at http://doso.me/6 to visit it. Have friends you want to invite? Reply with their #\'s and we\'ll invite them!';
$activity->response_new_account = 'Great! Your school is signed up for a T4J drive and to receive a T4J banner! Login at http://doso.me/6. Ur password is: @pass. Text us your friends\' #s to invite them too';
$activity->response_success = 'Great! Your school is signed up for a T4J drive, and signed up to receive a T4J banner! Login at http://doso.me/6. Text us your friends\' #s to invite them too';

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature_post_create_drive';
$activity->inputs = array('create_drive');
$activity->outputs = array('ftaf_process');

$activity = $workflow->newActivity('sms_flow_drives_ftaf');
$activity->name = 'ftaf_process';
$activity->alpha_optin = 131891;
$activity->beta_optin = 129751;
$activity->response_success = t('We\'ve sent along invites to your friends. Reply back with TFJINVITE if you want to invite more.');
$activity->response_fail = t('Sorry, we didn\'t understand your last response. To invite ppl to your drive again, text TFJINVITE.');
$activity->inputs = array('strip_signature_post_create_drive');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('ftaf_process', 'create_drive', 'school_search');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_drives_invite workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_drives_invite';
$workflow->title = 'SMS Flow Drives Invite';
$workflow->description = 'Workflow for invitees of a drive invite';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->title = 'Start';
$activity->inputs = array();
$activity->outputs = array('drive_invite_response');

$activity = $workflow->newActivity('sms_flow_drive_invite_response');
$activity->name = 'drive_invite_response';
$activity->title = 'Process user rejection or acceptance of the invite';
$activity->inputs = array('start');
$activity->outputs = array('check_account_exists', 'end');
$activity->accept_responses = array('y','yes','yea','ya','tfjjoin','tfj join');
$activity->invite_rejected_message = t('No prob. You\'re not getting added into the drive. If you want to join in the future, text back TFJJOIN.');
$activity->no_numbers_message = t('Oops. Did you mean to invite someone to your drive? Text TFJINVITE and try to invite again. Trying to join a drive? Text TFJJOIN to try to join again.');
$activity->already_in_drive_message = t('You already previously joined this drive. You can view it online at http://doso.me/2. Want to invite friends to the drive? Text TFJINVITE.');

$activity = $workflow->newActivity('sms_check_account_exists');
$activity->name = 'check_account_exists';
$activity->inputs = array('drive_invite_response');
$activity->outputs = array('account_exists', 'no_account_exists');

$activity = $workflow->newActivity('activity');
$activity->name = 'account_exists';
$activity->inputs = array('check_account_exists');
$activity->outputs = array('process_beta');

$activity = $workflow->newActivity('activity');
$activity->name = 'no_account_exists';
$activity->inputs = array('check_account_exists');
$activity->outputs = array('ask_first_name');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_first_name';
$activity->title = 'Ask Name';
$activity->question = t('Awesome! Reply with ur first name and we\'ll set u up with a login for our website where you can learn more about the drive details and about DoSomething.org');
$activity->inputs = array('no_account_exists');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_first_name');
$activity->outputs = array('create_account');

$activity = $workflow->newActivity('sms_flow_create_account');
$activity->name = 'create_account';
$activity->inputs = array('strip_signature');
$activity->outputs = array('process_beta');

$activity = $workflow->newActivity('sms_flow_drives_invited_beta');
$activity->name = 'process_beta';
$activity->title = 'Process Drive Betas';
$activity->inputs = array('account_exists', 'create_account');
$activity->outputs = array('ftaf_prompt');
$activity->alpha_campaign_id = 99961;
$activity->alpha_message = 'Ur friend @name accepted your invite to join ur DoSomething Teens for Jeans team! Who else should be involved? Text back TFJINVITE and we\'ll invite them too.';
$activity->drive_link = 'http://doso.me/2';
$activity->success_message = t('You\'ve joined the largest youth led clothing drive in the US! - What\'s ur goal for how many jeans you\'ll collect?');
$activity->mcommons_update_field = 'TeensforJeans2013_Goals';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ftaf_prompt';
$activity->question = t('Amazing! Last year we collected over a million pairs. Text us your friends numbers to invite them to join your drive.');
$activity->inputs = array('process_beta');
$activity->outputs = array('ftaf_process');

$activity = $workflow->newActivity('sms_flow_drives_ftaf');
$activity->name = 'ftaf_process';
$activity->title = 'Forward to a Friend';
$activity->inputs = array('ftaf_prompt');
$activity->outputs = array('end');
$activity->alpha_optin = 131891;
$activity->beta_optin = 129751;
$activity->response_success = t('We\'ve sent along invites to your friends. Reply back with TFJINVITE if you want to invite more.');
$activity->response_fail = t('Sorry, we didn\'t understand your last response. To join the drive again, text TFJJOIN. To invite ppl to ur drive, text TFJINVITE.');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('drive_invite_response', 'ftaf_process');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_drives_ftaf workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_drives_ftaf';
$workflow->title = 'Forward to a Friend';
$workflow->description = 'Custom forward to a friend workflow';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->title = 'Start';
$activity->inputs = array();
$activity->outputs = array('ftaf_prompt');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ftaf_prompt';
$activity->title = 'Start prompt for FTAF';
$activity->question = t('Awesome! All you need to do is text us your friends cell phone numbers and we\'ll invite then to participate in your Teens for Jeans drive.');
$activity->inputs = array('start');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->title = 'Strip Signature';
$activity->inputs = array('ftaf_prompt');
$activity->outputs = array('ftaf_process');

$activity = $workflow->newActivity('sms_flow_drives_ftaf');
$activity->name = 'ftaf_process';
$activity->title = 'Forward to a Friend';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->alpha_optin = 131891;
$activity->beta_optin = 129751;
$activity->response_success = t('Text TFJINVITE if you want to invite more!');
$activity->response_fail = t('Sorry, we didn\'t understand your last response. To try again, reply back with TFJINVITE.');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('ftaf_process');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_gys_drives_create workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_gys_drives_create';
$workflow->title = 'SMS Flow Drives Create for DBS';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('ask_school_level');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_level';
$activity->inputs = array('start');
$activity->outputs = array('ask_school_state');
$activity->question = t('1/3 Welcome to the DoSomething energy vampire slayers! Let\'s find your school. Are you in 1) middle or high school or 2) college? Reply with 1 or 2');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_state';
$activity->inputs = array('ask_school_level');
$activity->outputs = array('ask_school_name');
$activity->question = t('2/3 What state is your school in? Reply with the 2 letter abbreviation (ex: NY)');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_name';
$activity->inputs = array('ask_school_state');
$activity->outputs = array('strip_signature');
$activity->question = t('3/3 Last question before we go looking for your school... what\'s the name of your school?');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_school_name');
$activity->outputs = array('school_search');

$activity = $workflow->newActivity('sms_flow_school_search');
$activity->name = 'school_search';
$activity->inputs = array('strip_signature');
$activity->outputs = array('check_account_exists', 'end');
$activity->invalid_id_message = t('That\'s not a valid school ID. Text POWER to try again. Or visit http://doso.me/9 for more info.');
$activity->no_school_message = t('Sorry, we couldn\'t find any matching schools. Text POWER to try again. Or visit http://doso.me/9 for more info.');
$activity->schools_found_post_message = t('Text back your school ID# to start your drive. Didn\'t find your school? Text POWER to try again. Or visit http://doso.me/9 for more info.');

$activity = $workflow->newActivity('sms_check_account_exists');
$activity->name = 'check_account_exists';
$activity->inputs = array('school_search');
$activity->outputs = array('account_exists', 'no_account_exists');

$activity = $workflow->newActivity('activity');
$activity->name = 'account_exists';
$activity->inputs = array('check_account_exists');
$activity->outputs = array('create_drive');

$activity = $workflow->newActivity('activity');
$activity->name = 'no_account_exists';
$activity->inputs = array('check_account_exists');
$activity->outputs = array('ask_email');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_email';
$activity->inputs = array('no_account_exists');
$activity->outputs = array('ask_first_name');
$activity->question = t('Cool, let\'s get started with adding you to the school\'s team. What\'s your email address? We\'ll need it to contact you with tips for fighting energy vampires.');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_first_name';
$activity->inputs = array('ask_email');
$activity->outputs = array('strip_signature_2');
$activity->question = t('One last question - what\'s your first name?');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature_2';
$activity->inputs = array('ask_first_name');
$activity->outputs = array('create_account');

$activity = $workflow->newActivity('sms_flow_create_account');
$activity->name = 'create_account';
$activity->inputs = array('strip_signature_2');
$activity->outputs = array('create_drive');
$activity->mailchimp_group_name = 'Sucker2013';

$activity = $workflow->newActivity('sms_create_drive');
$activity->name = 'create_drive';
$activity->inputs = array('account_exists', 'create_account');
$activity->outputs = array('strip_signature_post_create_drive', 'end');
$activity->campaign_url = 'sucker';
$activity->sign_up_nid = 727941;
$activity->response_error = 'Sorry! We ran into a problem creating your team. Text POWER to try again or visit http://doso.me/9 to try online.';
$activity->response_in_drive = 'You already signed up for a team! Login at http://doso.me/9 to visit it. Have friends you want to invite? Reply with their #\'s and we\'ll invite them!';
$activity->response_new_account = 'Great! You can login to see your team here http://doso.me/9. Ur password is: @pass. Grow your team of vampire slayers. Text #s to invite friends';
$activity->response_success = 'Great! You can login to see your team here: http://doso.me/9. Grow your team of vampire slayers by inviting friends. Text #s to invite';

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature_post_create_drive';
$activity->inputs = array('create_drive');
$activity->outputs = array('ftaf_process');

$activity = $workflow->newActivity('sms_flow_drives_ftaf');
$activity->name = 'ftaf_process';
$activity->alpha_optin = 143633;
$activity->beta_optin = 143653;
$activity->response_success = t('Text SLAYERS to invite more friends or text START to get your first challenge.');
$activity->response_fail = t('Sorry, we didn\'t understand your last response. To invite people to your team again, text SLAYERS. Or text START to get your first challenge.');
$activity->inputs = array('strip_signature_post_create_drive');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf_process', 'create_drive', 'school_search');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_gys_invite workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_gys_invite';
$workflow->title = 'DBS Drives Invite';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('drive_invite_response');

$activity = $workflow->newActivity('sms_flow_drive_invite_response');
$activity->name = 'drive_invite_response';
$activity->inputs = array('start');
$activity->outputs = array('check_account_exists', 'end');
$activity->accept_responses = array('y','yes','yea','ya','dbsjoin','dbs join');
$activity->invite_rejected_message = t('No prob. You\'re not getting added to the team. If you want to join in the future, text back DBSJOIN.');
$activity->no_numbers_message = t('Oops. Did you mean to invite someone to your team? Text SLAYERS and try to invite again. Trying to join a team? Text DBSJOIN to try to join again.');
$activity->already_in_drive_message = t('You already previously joined this team. You can view it online at http://doso.me/9. Text SLAYERS to invite more friends or text START to get your first challenge.');

$activity = $workflow->newActivity('sms_check_account_exists');
$activity->name = 'check_account_exists';
$activity->inputs = array('drive_invite_response');
$activity->outputs = array('account_exists', 'no_account_exists');

$activity = $workflow->newActivity('activity');
$activity->name = 'account_exists';
$activity->inputs = array('check_account_exists');
$activity->outputs = array('process_beta');

$activity = $workflow->newActivity('activity');
$activity->name = 'no_account_exists';
$activity->inputs = array('check_account_exists');
$activity->outputs = array('ask_first_name');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_first_name';
$activity->question = t('Awesome! Reply with ur first name and we\'ll set u up with a login for DoSomething.org where you can learn more about why your school sucks (energy).');
$activity->inputs = array('no_account_exists');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_first_name');
$activity->outputs = array('create_account');

$activity = $workflow->newActivity('sms_flow_create_account');
$activity->name = 'create_account';
$activity->inputs = array('strip_signature');
$activity->outputs = array('process_beta');
$activity->mailchimp_group_name = 'Sucker2013';

$activity = $workflow->newActivity('sms_flow_drives_invited_beta');
$activity->name = 'process_beta';
$activity->inputs = array('account_exists', 'create_account');
$activity->outputs = array('ftaf_process');
$activity->alpha_campaign_id = 110073;
$activity->alpha_message = 'Ur friend @name accepted your invite to join ur DoSomething team of energy vampire slayers! Who else should be involved? Text back SLAYERS and we\'ll invite them too.';
$activity->drive_link = 'http://doso.me/9';
$activity->success_message = t('Great! Grow your team of vampire slayers by inviting friends. Text back #s to invite.');

$activity = $workflow->newActivity('sms_flow_drives_ftaf');
$activity->name = 'ftaf_process';
$activity->inputs = array('process_beta');
$activity->outputs = array('end');
$activity->alpha_optin = 143633;
$activity->beta_optin = 143653;
$activity->response_success = t('Text SLAYERS to invite more friends or text START to get your first challenge.');
$activity->response_fail = t('Sorry, we didn\'t understand your last response. To join the team again, text DBSJOIN. To invite people to ur team, text SLAYERS.');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf_process');

$workflows[$workflow->name] = $workflow;

//
// sms_flow_gys_ftaf workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_gys_ftaf';
$workflow->title = 'Dont Be A Sucker Team FTAF';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ftaf_prompt');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ftaf_prompt';
$activity->question = t('Awesome! Grow your team of vampire slayers by inviting friends. Text back their #s to invite them.');
$activity->inputs = array('start');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ftaf_prompt');
$activity->outputs = array('ftaf_process');

$activity = $workflow->newActivity('sms_flow_drives_ftaf');
$activity->name = 'ftaf_process';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->alpha_optin = 143633;
$activity->beta_optin = 143653;
$activity->response_success = t('Text SLAYERS if you want to invite more friends or text START to get your first challenge.');
$activity->response_fail = t('Sorry, we didn\'t understand your last response. To try again, reply back with SLAYERS. Or text START to get your first challenge.');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ftaf_process');

$workflows[$workflow->name] = $workflow;