<?php

/**
 * @file
 * ConductorWorkflow definitions for campaign sign-ups.
 */

/**
 * Teens for Jeans 2013 sign up flow.
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_tfj2014_sign_up';
$workflow->title = 'Teens for Jeans 2014 Sign Up';
$workflow->description = 'Submits a sign up for the Teens for Jeans 2013 campaign.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('check_user_school');

$activity = $workflow->newActivity('sms_flow_check_school');
$activity->name = 'check_user_school';
$activity->inputs = array('start');
$activity->outputs = array('school_found', 'ask_state');
$activity->school_found_activity = 'school_found';
$activity->no_school_found_activity = 'ask_state';

// If user does have a school set to her profile, verify the school
$activity = $workflow->newActivity('verify_school_in_profile');
$activity->name = 'school_found';
$activity->inputs = array('check_user_school');
$activity->outputs = array('ask_state', 'submit_sign_up', 'end');
$activity->output_school_correct = 'submit_sign_up';
$activity->output_school_incorrect = 'ask_state';
$activity->question = t('First, let\'s confirm the school we got from you previously: @school_name. If this is correct, reply Y. If not, reply N.');
$activity->invalid_response_msg = t('Sorry, we didn\'t understand that. Text DRIVE to try again.');

// If user does not have a school set or she wants to reset it, start the school search
$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_state';
$activity->inputs = array('check_user_school', 'school_found');
$activity->outputs = array('ask_school_name');
$activity->question = "To enter to win the $4K scholarship + be eligible for school prizes, you'll need to sign up your school. What state is your school in? (ex: NY)";

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_name';
$activity->inputs = array('ask_state');
$activity->outputs = array('school_search');
$activity->context_value_for_msg = 'ask_state:message';
$activity->question = t('Thanks! And what\'s the name of the school in @context_value?');

$activity = $workflow->newActivity('gs_school_search');
$activity->name = 'school_search';
$activity->inputs = array('ask_school_name');
$activity->outputs = array('submit_sign_up', 'school_not_found_message', 'end');
$activity->state_activity_name = 'ask_state';
$activity->school_activity_name = 'ask_school_name';
$activity->schoolNotFound_activity_name = 'school_not_found_message';
$activity->max_results = 5;
$activity->no_school_found_msg = t('We couldn\'t find your school @school_name in @school_state. Text DRIVE to try again.');
$activity->one_school_found_msg = t('We found @school_name in @school_city, @school_state. Reply Y if this is your school. Text N to try again.');
$activity->schools_found_msg = t('We found @num_results matches. Text back the # for your school. Or text N to try again.');
$activity->invalid_response_msg = t('Sorry, we didn\'t understand that. Text DRIVE to try again.');

$activity = $workflow->newActivity('sms_flow_signup_submit');
$activity->name = 'submit_sign_up';
$activity->inputs = array('school_found', 'school_search');
$activity->outputs = array('end_message');
$activity->nid = 731115;
$activity->schoolContext = 'school_gsid';

$activity = $workflow->newActivity('mobile_commons_opt_in');
$activity->name = 'end_message';
$activity->inputs = array('submit_sign_up');
$activity->outputs = array('end');
$activity->opt_in_path_id = 162835;

$activity = $workflow->newActivity('mobile_commons_opt_in');
$activity->name = 'school_not_found_message';
$activity->inputs = array('school_search');
$activity->outputs = array('end');
$activity->opt_in_path_id = 162993;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
// HACK: Placing 'school_found' before 'school_search' breaks the no_school and
// invalid_response messages. We might be using the multiple inputs/outputs in a
// matter that wasn't originally intended by Conductor. Either way, the sms_response
// context gets lost in between the school_search and the end activity, and swapping
// those two inputs seemed to fix it.
$activity->inputs = array('school_search', 'school_found', 'end_message', 'school_not_found_message');

$workflows[$workflow->name] = $workflow;

/**
 * Teen for Jeans 2013 - Ask for address to send banner to.
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_tfj2014_banner_address';
$workflow->title = 'Teens for Jeans 2014 Banner Address';
$workflow->description = 'Ask for and submit address to ship banner to for Teens for Jeans 2013.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('yesno_gate');

$activity = $workflow->newActivity('sms_flow_yesno_gate');
$activity->name = 'yesno_gate';
$activity->inputs = array('start');
$activity->outputs = array('no_banner', 'ask_street');
$activity->onNoActivity = 'no_banner';
$activity->onYesActivity = 'ask_street';

// Activity if user selects to not receive a banner
$activity = $workflow->newActivity('mobile_commons_opt_in');
$activity->name = 'no_banner';
$activity->inputs = array('yesno_gate');
$activity->outputs = array('end');
$activity->opt_in_path_id = 162843;

// Activity if user does select to receive a banner
$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_street';
$activity->inputs = array('yesno_gate');
$activity->outputs = array('ask_city');
$activity->opt_in_path_id = 162847;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_city';
$activity->inputs = array('ask_street');
$activity->outputs = array('ask_state');
$activity->opt_in_path_id = 162849;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_state';
$activity->inputs = array('ask_city');
$activity->outputs = array('ask_zip');
$activity->opt_in_path_id = 162851;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_zip';
$activity->inputs = array('ask_state');
$activity->outputs = array('ask_name');
$activity->opt_in_path_id = 162853;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_name';
$activity->inputs = array('ask_zip');
$activity->outputs = array('address_submit');
$activity->opt_in_path_id = 162855;

$activity = $workflow->newActivity('sms_flow_signup_address_submit');
$activity->name = 'address_submit';
$activity->inputs = array('ask_name');
$activity->outputs = array('end_message');
$activity->campaignNid = 731115;
$activity->addr1Context = 'ask_street:message';
$activity->cityContext = 'ask_city:message';
$activity->stateContext = 'ask_state:message';
$activity->zipContext = 'ask_zip:message';
$activity->nameContext = 'ask_name:message';

$activity = $workflow->newActivity('mobile_commons_opt_in');
$activity->name = 'end_message';
$activity->inputs = array('address_submit');
$activity->outputs = array('end');
$activity->opt_in_path_id = 162857;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('no_banner', 'end_message');

$workflows[$workflow->name] = $workflow;
