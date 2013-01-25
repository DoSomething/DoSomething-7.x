<?php

//
// sms_flow_clubs_invite workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid('new')
         ->name('sms_flow_clubs_invite')
         ->title('SMS Flow Clubs Invite')
         ->description('Workflow for invitees of a Clubs invite')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('clubs_invite_response'));

$workflow->newActivity('sms_flow_clubs_invite_response')
         ->name('clubs_invite_response')
         ->title('Handle beta\'s approval or denial of invitation.')
         ->inputs(array('start'))
         ->outputs(array('clubs_process_beta', 'ask_name', 'end'))
         ->property('accept_responses', array('y','yes','yea','ya','yeah','cjoin', 'c join'))
         ->property('invite_rejected_message', t('No prob. You won\'t be added to the club. If you want to join in the future, text back CJOIN.'));

$workflow->newActivity('sms_prompt')
         ->name('ask_name')
         ->inputs(array('clubs_invite_response'))
         ->outputs(array('strip_signature'))
         ->question(t('Awesome! Reply with ur first name and we\'ll set u up with a login for our website where you can learn more about your club and about DoSomething.org'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature')
         ->inputs(array('ask_name'))
         ->outputs(array('clubs_process_beta'));

$workflow->newActivity('sms_flow_clubs_invited_beta')
         ->name('clubs_process_beta')
         ->inputs(array('clubs_invite_response', 'strip_signature'))
         ->outputs(array('ftaf_clubs_process'))
         ->property('alpha_campaign_id', 99961);

$workflow->newActivity('sms_flow_clubs_ftaf')
         ->name('ftaf_clubs_process')
         ->inputs(array('clubs_process_beta'))
         ->outputs(array('end'))
         ->property('alpha_optin', 0)
         ->property('beta_optin', 126531)
         ->property('response_success', t('We\'ve sent along invites to your friends. Reply back with CINVITE if you want to invite more.'))
         ->property('response_fail', t('Sorry, we didn\'t understand that. To join the club again, text CJOIN. To invite ppl to ur club, text CINVITE.'));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('clubs_invite_response', 'ftaf_clubs_process'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_clubs_ftaf workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid('new')
         ->name('sms_flow_clubs_ftaf')
         ->title('Forward to a Friend Clubs Style')
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
         ->question(t('Awesome! All you need to do is text us back a bunch of your friends\' cell phone numbers and we\'ll invite then to participate in your Club.'));

$workflow->newActivity('sms_strip_signature')
         ->name('strip_signature')
         ->inputs(array('ftaf_prompt'))
         ->outputs(array('ftaf_clubs_process'));

$workflow->newActivity('sms_flow_clubs_ftaf')
         ->name('ftaf_clubs_process')
         ->inputs(array('strip_signature'))
         ->outputs(array('end'))
         ->property('alpha_optin', 0)
         ->property('beta_optin', 126531)
         ->property('response_success', t('We\'ve sent along invites to your friends. Reply back with CINVITE if you want to invite more.'))
         ->property('response_fail', t('Sorry, we didn\'t understand your last response. To join the club again, text CJOIN. To invite ppl to ur club, text CINVITE.'));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('ftaf_clubs_process'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_clubs_survey workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid('new')
         ->name('sms_flow_clubs_survey')
         ->title('SMS Flow Clubs Survey')
         ->description('Workflow for clubs servey which leads to T-shirt form.')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('clubs_survey_response'));

$workflow->newActivity('sms_flow_clubs_survey_response')
         ->name('clubs_survey_response')
         ->title('Handle club leader first response')
         ->inputs(array('start'))
         ->outputs(array('process_next_answer', 'end'))
         ->property('accept_responses', array('y','yes','yea','ya','yeah'))
         ->property('deny_responses', array('n', 'no', 'nope', 'nah', 'na'));

$workflow->newActivity('sms_flow_clubs_survey_question2')
         ->name('process_next_answer')
         ->title('Process first question answer.')
         ->inputs(array('clubs_survey_response'))
         ->outputs(array('end'))
         ->property('answers', array('a', 'b', 'c', 'd'))
         ->property('reject_message', t("Please give us some time and we'll get back to you.  - Crystal, DoSomething.org"));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('clubs_survey_response', 'process_question2'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;

//
// sms_flow_clubs_survey workflow
//
$workflow = new ConductorWorkflow;
$workflow->wid('new')
         ->name('sms_flow_clubs_followup_survey')
         ->title('SMS Flow Clubs Followup Survey')
         ->description('Workflow for clubs follow-up survey.')
         ->api_version('1.0');

$workflow->newActivity('start')
         ->name('start')
         ->inputs(array())
         ->outputs(array('clubs_survey_followup_response'));

$workflow->newActivity('sms_flow_clubs_followup_survey_response')
         ->name('clubs_survey_followup_response')
         ->title('Handle club leader first response')
         ->inputs(array('start'))
         ->outputs(array('process_next_answer', 'end'))
         ->property('accept_responses', array('y','yes','yea','ya','yeah','ok','okay'))
         ->property('deny_responses', array('n', 'no', 'nope', 'nah', 'na'))
         ->property('rejected_message', t('No prob. Thanks for your interest in DoSomething.org.'));

$workflow->newActivity('sms_prompt')
         ->name('process_next_answer')
         ->title('Are you active?')
         ->inputs(array('clubs_survey_followup_response'))
         ->outputs(array('process_club_focus'))
         ->question(t('2. Are your active club members listed on your DoSomething.org Club Profile page? Y or N'));

$workflow->newActivity('sms_prompt')
         ->name('process_club_focus')
         ->title('Club Focus?')
         ->inputs(array('process_next_answer'))
         ->outputs(array('process_club_focus_nest'))
         ->question(t('3. Does your club focus on A) general community volunteering or B) a specific cause / organization / project?'));

$workflow->newActivity('sms_flow_clubs_followup_survey_fourth')
         ->name('process_club_focus_nest')
         ->title('Process second question answer.')
         ->inputs(array('process_club_focus'))
         ->outputs(array('process_clubs_last_question'));

$workflow->newActivity('sms_prompt')
         ->name('process_clubs_last_question')
         ->title('Last question')
         ->inputs(array('process_club_focus_nest'))
         ->outputs(array('fin'))
         ->question(t('4. Last question, do you have any advice for other students looking to start (or join) a DS club?'));

$workflow->newActivity('sms_flow_clubs_survey_followup_fin')
         ->name('fin')
         ->inputs(array('process_clubs_last_question'))
         ->outputs(array('end'));

$workflow->newActivity('end')
         ->name('end')
         ->inputs(array('fin'))
         ->outputs(array());

$workflows[$workflow->name] = $workflow;