<?php

//
// sms_flow_clubs_invite workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_clubs_invite';
$workflow->title = 'SMS Flow Clubs Invite';
$workflow->description = 'Workflow for invitees of a Clubs invite';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->title = 'Start';
$activity->inputs = array();
$activity->outputs = array('clubs_invite_response');

$activity = $workflow->newActivity('sms_flow_clubs_invite_response');
$activity->name = 'clubs_invite_response';
$activity->title = 'Handle beta\'s approval or denial of invitation.';
$activity->accept_responses = array('y','yes','yea','ya','yeah','cjoin', 'c join');
$activity->invite_rejected_message = t('No prob. You won\'t be added to the club. If you want to join in the future, text back CJOIN.');
$activity->inputs = array('start');
$activity->outputs = array('clubs_process_beta', 'ask_name', 'end');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_name';
$activity->title = 'Ask Name';
$activity->question = t('Awesome! Reply with ur first name and we\'ll set u up with a login for our website where you can learn more about your club and about DoSomething.org');
$activity->inputs = array('clubs_invite_response');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->title = 'Strip Signature';
$activity->inputs = array('ask_name');
$activity->outputs = array('clubs_process_beta');

$activity = $workflow->newActivity('sms_flow_clubs_invited_beta');
$activity->name = 'clubs_process_beta';
$activity->title = 'Process Clubs Betas';
$activity->alpha_campaign_id = 99961;
$activity->inputs = array('clubs_invite_response', 'strip_signature');
$activity->outputs = array('ftaf_clubs_process');

$activity = $workflow->newActivity('sms_flow_clubs_ftaf');
$activity->name = 'ftaf_clubs_process';
$activity->title = 'Forward to a Friend';
$activity->alpha_optin = 0;
$activity->beta_optin = 126531;
$activity->response_success = t('We\'ve sent along invites to your friends. Reply back with CINVITE if you want to invite more.');
$activity->response_fail = t('Sorry, we didn\'t understand that. To join the club again, text CJOIN. To invite ppl to ur club, text CINVITE.');
$activity->inputs = array('clubs_process_beta');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('clubs_invite_response', 'ftaf_clubs_process');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_clubs_ftaf workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_clubs_ftaf';
$workflow->title = 'Forward to a Friend Clubs Style';
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
$activity->question = t('Awesome! All you need to do is text us back a bunch of your friends\' cell phone numbers and we\'ll invite then to participate in your Club.');
$activity->inputs = array('start');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->title = 'Strip Signature';
$activity->inputs = array('ftaf_prompt');
$activity->outputs = array('ftaf_clubs_process');

$activity = $workflow->newActivity('sms_flow_clubs_ftaf');
$activity->name = 'ftaf_clubs_process';
$activity->title = 'Forward to a Friend';
$activity->alpha_optin = 0;
$activity->beta_optin = 126531;
$activity->response_success = t('We\'ve sent along invites to your friends. Reply back with CINVITE if you want to invite more.');
$activity->response_fail = t('Sorry, we didn\'t understand your last response. To join the club again, text CJOIN. To invite ppl to ur club, text CINVITE.');
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('ftaf_clubs_process');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_clubs_survey workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_clubs_survey';
$workflow->title = 'SMS Flow Clubs Survey';
$workflow->description = 'Workflow for clubs servey which leads to T-shirt form.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->title = 'Start';
$activity->inputs = array();
$activity->outputs = array('clubs_survey_response');

$activity = $workflow->newActivity('sms_flow_clubs_survey_response');
$activity->name = 'clubs_survey_response';
$activity->title = 'Handle club leader first response';
$activity->accept_responses = array('y','yes','yea','ya','yeah');
$activity->deny_responses = array('n', 'no', 'nope', 'nah', 'na');
$activity->rejected_message = t('No prob. Thanks for your interest in DoSomething.org.');
$activity->inputs = array('start');
$activity->outputs = array('process_next_answer', 'end');

$activity = $workflow->newActivity('sms_flow_clubs_survey_question2');
$activity->name = 'process_next_answer';
$activity->title = 'Process first question answer.';
$activity->answers = array('a', 'b', 'c', 'd');
$activity->reject_message = t("Please give us some time and we'll get back to you.  - Crystal, DoSomething.org");
$activity->inputs = array('clubs_survey_response');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('clubs_survey_response', 'process_question2');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

//
// sms_flow_clubs_survey workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_clubs_followup_survey';
$workflow->title = 'SMS Flow Clubs Followup Survey';
$workflow->description = 'Workflow for clubs follow-up survey.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->title = 'Start';
$activity->inputs = array();
$activity->outputs = array('clubs_survey_followup_response');

$activity = $workflow->newActivity('sms_flow_clubs_followup_survey_response');
$activity->name = 'clubs_survey_followup_response';
$activity->title = 'Handle club leader first response';
$activity->accept_responses = array('y','yes','yea','ya','yeah','ok','okay');
$activity->deny_responses = array('n', 'no', 'nope', 'nah', 'na');
$activity->rejected_message = t('No prob. Thanks for your interest in DoSomething.org.');
$activity->inputs = array('start');
$activity->outputs = array('process_next_answer', 'end');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'process_next_answer';
$activity->title = 'Are you active?';
$activity->question = t('2. Are your active club members listed on your DoSomething.org Club Profile page? Y or N');
$activity->inputs = array('clubs_survey_followup_response');
$activity->outputs = array('process_club_focus');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'process_club_focus';
$activity->title = 'Club Focus?';
$activity->question = t('3. Does your club focus on A) general community volunteering or B) a specific cause / organization / project?');
$activity->inputs = array('process_next_answer');
$activity->outputs = array('process_club_focus_nest');

$activity = $workflow->newActivity('sms_flow_clubs_followup_survey_fourth');
$activity->name = 'process_club_focus_nest';
$activity->title = 'Process second question answer.';
$activity->answers = array('a', 'b');
$activity->reject_message = t("Sorry, we couldn't understand that.  Please respond with A or B.");
$activity->inputs = array('process_club_focus');
$activity->outputs = array('process_clubs_last_question');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'process_clubs_last_question';
$activity->title = 'Last question';
$activity->question = t('4. Last question, do you have any advice for other students looking to start (or join) a DS club?');
$activity->inputs = array('process_club_focus_nest');
$activity->outputs = array('fin');

$activity = $workflow->newActivity('sms_flow_clubs_survey_followup_fin');
$activity->name = 'fin';
$activity->title = 'Fin.';
$activity->answers = array('a', 'b', 'c', 'd');
$activity->reject_message = t("Please give us some time and we'll get back to you.  - Crystal, DoSomething.org");
$activity->inputs = array('process_clubs_last_question');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('fin');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;