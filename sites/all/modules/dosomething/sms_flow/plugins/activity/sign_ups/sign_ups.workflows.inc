<?php

/**
 * Teens for Jeans 2013 sign up flow.
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_tfj2013_sign_up';
$workflow->title = 'Teens for Jeans 2013 Sign Up';
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
$activity->outputs = array('ask_state', 'end_message', 'end');
$activity->output_school_correct = 'end_message';
$activity->output_school_incorrect = 'ask_state';
$activity->question = t('First, let\'s confirm the school we got from you previously: @school_name. If this is correct, reply Y. If not, reply N.');
$activity->invalid_response_msg = t('Sorry, we didn\'t understand that. Text SCHOOL to try again.');

// If user does not have a school set or she wants to reset it, start the school search
$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_state';
$activity->inputs = array('check_user_school', 'school_found');
$activity->outputs = array('ask_school_name');
$activity->question = "TODO: What state is the school in? (ex: NY)";

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_name';
$activity->inputs = array('ask_state');
$activity->outputs = array('school_search');
$activity->context_value_for_msg = 'ask_state:message';
$activity->question = t('Thanks! And what\'s the name of the school in @context_value?');

$activity = $workflow->newActivity('gs_school_search');
$activity->name = 'school_search';
$activity->inputs = array('ask_school_name');
$activity->outputs = array('end_message', 'end');
$activity->state_activity_name = 'ask_state';
$activity->school_activity_name = 'ask_school_name';
$activity->max_results = 5;
$activity->no_school_found_msg = t('We couldn\'t find your school @school_name in @school_state. Text SCHOOL to try again.');
$activity->one_school_found_msg = t('We found @school_name in @school_city, @school_state. Reply Y if this is your school. Text SCHOOL to try again.');
$activity->schools_found_msg = t('We found @num_results matches. Text back the # for your school. Or text SCHOOL to try again.');
$activity->invalid_response_msg = t('Sorry, we didn\'t understand that. Text SCHOOL to try again.');

$activity = $workflow->newActivity('mobile_commons_opt_in');
$activity->name = 'end_message';
$activity->inputs = array('school_found', 'school_search');
$activity->outputs = array('end');
$activity->opt_in_path_id = 0; // TODO

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('school_found', 'school_search', 'end_message');

$workflows[$workflow->name] = $workflow;