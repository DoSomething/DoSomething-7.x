<?php

/**
 * @file
 * ConductorWorkflow definitions for campaign report backs.
 */

/**
 * sms_flow_can_send_mms_report_back workflow
 *  Handles the user response to whether or not he can send MMS. The routes property
 *  uses the array key as the incoming opt-in path and the 'yes' and 'no' values as
 *  the outgoing opt-in paths depending on the user's answer.
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_can_send_mms_report_back';
$workflow->title = 'Handles response to whether or not user can send MMS.';
$workflow->description = 'Handles response to whether or not user can send MMS.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('can_send_mms');

$activity = $workflow->newActivity('can_send_mms');
$activity->name = 'can_send_mms';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->routes = array(
  // Give A Spit 2013 Report Back
  '161255' => array(
    'yes' => '161257',
    'no' => '161259',
  ),
  // Survivors 2013 Report Back
  '161419' => array(
    'yes' => '161421',
    'no' => '161425',
  ),
  // 50 Cans Report Back
  '161869' => array(
    'yes' => '161871',
    'no' => '161873',
  ),
  // Grandparents Gone Wire Report Back
  '162623' => array(
    'yes' => '162627',
    'no' => '162631',
  ),
  // Love Letters 2014 Report Back
  '163693' => array(
    'yes' => '163695',
    'no' => '163697',
  ),
  // Teens for Jeans 2014 Report Back
  '163773' => array(
    'yes' => '163775',
    'no' => '163777',
  ),
  // PBJ 2014 Report Back
  '164395' => array(
    'yes' => '164399',
    'no' => '164401',
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('can_send_mms');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

/**
 * Give A Spit 2013 Report Back. User will first be prompted to submit a pic
 * from: https://secure.mcommons.com/campaigns/119813/opt_in_paths/161255
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_spit_report_back';
$workflow->title = 'Give A Spit 2013 Report Back';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_event_type', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 161261;

$activity = $workflow->newActivity('sms_prompt_normalize_response');
$activity->name = 'ask_event_type';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_theme');
$activity->question = 'Great! Q1 - What type of event did you host? A. Party (25+ ppl), B. Get-Together (2-24ppl), C. Solo (just me). Respond with A, B, or C';
$activity->normalizedGroups = array(
  array('party', 'A'),
  array('gettogether', 'B'),
  array('solo', 'C'),
);

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_theme';
$activity->inputs = array('ask_event_type');
$activity->outputs = array('ask_people');
$activity->question = 'Awesome. Q2 - If you hosted a party or get-together, what was the theme (e.g. "Swab and Sweat" or "Swab and Sports")? If you swabbed solo, text back N/A.';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_theme');
$activity->outputs = array('ask_why');
$activity->question = 'Great! Q3 - How many people came to your event?';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_why';
$activity->inputs = array('ask_people');
$activity->outputs = array('ask_success');
$activity->question = 'Cool! Q4 - Why did you sign up for Give a Spit?';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_success';
$activity->inputs = array('ask_why');
$activity->outputs = array('strip_signature');
$activity->question = 'Awesome. Last question - Was your event successful? If so, what made it a success? If not, what could have made it better? If you swabbed solo, text back N/A.';

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_success');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_people' => 1,
  'ask_why' => 2,
  'ask_event_type' => 3,
  'ask_theme' => 4,
  'ask_success' => 5,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 161263;
$activity->webform_nid = 731005;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back', 'ask_picture');

$workflows[$workflow->name] = $workflow;

/**
 * Survivors 2013 Report Back. User will first be prompted to submit a pic
 * from: https://secure.mcommons.com/campaigns/121303/opt_in_paths/161421
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_survivors_report_back';
$workflow->title = 'Cell Phones for Survivors 2013 Report Back';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_phones', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 161429;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_phones';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_people');
$activity->question = t('Amazing! Q1 - How many phones did you collect?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_phones');
$activity->outputs = array('ask_why');
$activity->question = t('Fantastic. Q2 - How many people helped out?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_why';
$activity->inputs = array('ask_people');
$activity->outputs = array('strip_signature');
$activity->question = t('Nice! Q3 - Why did you participate in this campaign?');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_why');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_phones' => 1,
  'ask_people' => 2,
  'ask_why' => 3,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 161485;
$activity->webform_nid = 731009;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back', 'ask_picture');

$workflows[$workflow->name] = $workflow;

/**
 * Fed Up 2013 Report Back - Part 1
 * Retrieve the user's school id and text answers to questions
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_fedup_report_back_1';
$workflow->title = 'Fed Up 2013 Report Back - Part 1';
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
$activity->outputs = array('ask_q1', 'ask_state', 'end');
$activity->output_school_correct = 'ask_q1';
$activity->output_school_incorrect = 'ask_state';
$activity->question = t('This is the school we got from you before: @school_name. If this is correct, reply Y. If not, reply N.');
$activity->invalid_response_msg = t('Sorry, we didn\'t understand that. Text START to try again or go to fedup.dosomething.org.');

// If user does not have a school set or she wants to reset it, start the school search
$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_state';
$activity->inputs = array('check_user_school', 'school_found');
$activity->outputs = array('ask_school_name');
$activity->question = t('We\'re using ur pics to show the world what\'s really up with school lunch. You could win a $4,000 scholarship for sharing. What state do you live in? (ex: NY)');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_name';
$activity->inputs = array('ask_state');
$activity->outputs = array('school_search');
$activity->context_value_for_msg = 'ask_state:message';
$activity->question = t('Thanks! And what\'s the name of your school in @context_value?');

$activity = $workflow->newActivity('gs_school_search');
$activity->name = 'school_search';
$activity->inputs = array('ask_school_name');
$activity->outputs = array('ask_q1', 'end');
$activity->state_activity_name = 'ask_state';
$activity->school_activity_name = 'ask_school_name';
$activity->max_results = 5;
$activity->no_school_found_msg = t('We couldn\'t find your school @school_name in @school_state. Text START to try again or go to fedup.dosomething.org');
$activity->one_school_found_msg = t('We found @school_name in @school_city, @school_state. Reply Y if this is your school. Text START to try again or go to fedup.dosomething.org');
$activity->schools_found_msg = t('We found @num_results matches. Text back the # for your school. START to try again or go to fedup.dosomething.org');
$activity->invalid_response_msg = t('Sorry, we didn\'t understand that. Text START to try again or go to fedup.dosomething.org.');

$activity = $workflow->newActivity('sms_prompt_normalize_response');
$activity->name = 'ask_q1';
$activity->inputs = array('school_found', 'school_search');
$activity->outputs = array('ask_q2');
$activity->context_value_for_msg = 'selected_school_name';
$activity->question = t('(1/3) Now 3 ?s about @context_value\'s lunch. How often do you eat school lunch? A)0-2 times per month B)3-5 C)6-10 D)Every day. Reply A,B,C, or D');
$activity->normalizedGroups = array(
  array('0-2 times per month', 'A', 'A)', '0-2', '0 - 2', 'A)0-2'),
  array('3-5 times per month', 'B', 'B)', '3-5', '3 - 5', 'B)3-5'),
  array('6-10 times per month', 'C', 'C)', '6-10', '6 - 10', 'C)6-10'),
  array('Every day', 'D', 'D)', 'everyday', 'D)Every day'),
);

$activity = $workflow->newActivity('sms_prompt_normalize_response');
$activity->name = 'ask_q2';
$activity->inputs = array('ask_q1');
$activity->outputs = array('ask_q3');
$activity->question = t('(2/3) Of the school lunches you\'ve eaten in the past 4 weeks, how nutritious was your meal? A)Very B)Somewhat C)Not at all D)Unhealthy. Reply A,B,C, or D');
$activity->normalizedGroups = array(
  array('Very nutritious', 'A', 'A)', 'A)Very'),
  array('Somewhat nutritious', 'B', 'B)', 'B)Somewhat'),
  array('Not nutritious at all', 'C', 'C)', 'C)Not at all', 'Not at all'),
  array('Unhealthy', 'D', 'D)', 'D)Unhealthy'),
);

$activity = $workflow->newActivity('sms_prompt_normalize_response');
$activity->name = 'ask_q3';
$activity->inputs = array('ask_q2');
$activity->outputs = array('strip_signature');
$activity->question = t('(3/3) How satisfied have you been with the taste of your school lunch over the past 4 weeks? A)Very B)Somewhat C)Not sat. D)Very unsatisfied. Reply A,B,C, or D');
$activity->normalizedGroups = array(
  array('Very satisfied', 'A', 'A)', 'very', 'A)Very'),
  array('Somewhat satisfied', 'B', 'B)', 'somewhat', 'B)Somewhat'),
  array('Not satisfied', 'C', 'C)', 'not', 'not sat', 'C)Not sat.'),
  array('Very unsatisfied', 'D', 'D)', 'very', 'D)Very unsatisfied'),
);

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_q3');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_external_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->http_request_type = 'POST';
$activity->success_response = 161577;
$activity->submission_url = 'http://fedup.dosomething.org/fedup/posts.json';
$activity->submission_fields = array(
  // Key gives context name to pull data from. Value gives the name of the field to submit to
  'ask_q1:message' => 'post[extras][how_often_do_you_eat]',
  'ask_q2:message' => 'post[extras][how_nutritious]',
  'ask_q3:message' => 'post[extras][how_satisfied]',
  'selected_school_state' => 'post[state]',
  // Specific handling done for these keys
  'gsid' => 'post[school_id]',
  'uid' => 'post[uid]',
  'append_query' => 'post[flagged]=1&post[name]=placeholder&post[image]=http://www.google-analytics.com/__utm.gif&post[campaign_id]=1&key=aea12e3fe5f83f0d574fdff0342aba91',
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('school_found', 'school_search', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Fed Up 2013 Report Back - Part 2
 * Receive MMS from the user, find user's previously submitted report back, and update with the image
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_fedup_report_back_2';
$workflow->title = 'Fed Up 2013 Report Back - Part 2';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_name', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 161581;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_name';
$activity->inputs = array('ask_picture');
$activity->outputs = array('submit_report_back');
$activity->question = t('What do you want to name your lunch?');

$activity = $workflow->newActivity('submit_external_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_name');
$activity->outputs = array('end');
$activity->http_request_type = 'PUT';
$activity->uid_lookup_url = 'http://fedup.dosomething.org/fedup/posts/uid_lookup.json?key=aea12e3fe5f83f0d574fdff0342aba91';
$activity->success_response = 161579;
$activity->submission_url = 'http://fedup.dosomething.org/fedup/posts/@postId.json';
$activity->submission_fields = array(
  'ask_picture:mms' => 'post[image]',
  'ask_name:message' => 'post[name]',
  'append_query' => 'post[campaign_id]=1&post[flagged]=0&key=aea12e3fe5f83f0d574fdff0342aba91',
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back', 'ask_picture');

$workflows[$workflow->name] = $workflow;

/**
 * 50 Cans Report Back
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_50cans_report_back';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_cans', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 161875;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_cans';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_people');
$activity->question = t('Amazing! Q1 - How many cans did you collect?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_cans');
$activity->outputs = array('submit_report_back');
$activity->question = t('Fantastic. Q2 - How many people helped out?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_people');
$activity->outputs = array('end');
$activity->campaign_opt_outs = array(121663);
$activity->submission_fields = array(
  'picture' => 'ask_picture:mms',
  'ask_cans' => 2,
  'ask_people' => 3,
);
$activity->success_response = 161877;
$activity->webform_nid = 731045;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Grandparents Gone Wired 2013 Report Back
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_ggw_report_back';
$workflow->title = 'Grandparents Gone Wired 2013 Report Back';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_q1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 162633;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_q1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_q2');
$activity->question = 'Amazing! Q1: Which type(s) of technology did you teach?';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_q2';
$activity->inputs = array('ask_q1');
$activity->outputs = array('ask_q3');
$activity->question = 'Awesome. Q2: How many people did you do this with?';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_q3';
$activity->inputs = array('ask_q2');
$activity->outputs = array('ask_q4');
$activity->question = 'Sweet! Q3: Who did you teach?';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_q4';
$activity->inputs = array('ask_q3');
$activity->outputs = array('ask_q5');
$activity->question = 'Great. Q4: Where did you teach the older adults (in your home, their home, a senior center/nursing home)?';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_q5';
$activity->inputs = array('ask_q4');
$activity->outputs = array('ask_q6');
$activity->question = 'Nice. Q5: What\'s your zipcode?';

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_q6';
$activity->inputs = array('ask_q5');
$activity->outputs = array('submit_report_back');
$activity->question = 'Great. Last question! Q6: Briefly describe why teaching older adults technology is important to you.';

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_q6');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'picture' => 'ask_picture:mms',
  'ask_q1' => 3,
  'ask_q2' => 4,
  'ask_q3' => 5,
  'ask_q4' => 6,
  'ask_q5' => 7,
  'ask_q6' => 8,
);
$activity->success_response = 162637;
$activity->webform_nid = 731107;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back', 'ask_picture');

$workflows[$workflow->name] = $workflow;

/**
 * Mind on My Money 2013 Report Back
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_momm_report_back';
$workflow->title = 'Mind on My Money 2013 Report Back';
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
$activity->outputs = array('ask_state', 'ask_leader', 'end');
$activity->output_school_correct = 'ask_leader';
$activity->output_school_incorrect = 'ask_state';
$activity->question = t('First, let\'s confirm the school we got from you previously: @school_name. If this is correct, reply Y. If not, reply N.');
$activity->invalid_response_msg = t('Sorry, we didn\'t understand that. Text @keyword to try again.');
$activity->mdata_keywords = array(
  '201' => 'CREDIT',
  '311' => 'LOANS',
  '9241' => 'SAVINGS',
);

// If user does not have a school set or she wants to reset it, start the school search
$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_state';
$activity->inputs = array('check_user_school', 'school_found');
$activity->outputs = array('ask_school_name');
$activity->question = "To be eligible for the $2,500 scholarship we'll need to know what school you went to for the workshop. What state is the school in? (ex: NY)";

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_school_name';
$activity->inputs = array('ask_state');
$activity->outputs = array('school_search');
$activity->context_value_for_msg = 'ask_state:message';
$activity->question = t('Thanks! And what\'s the name of the school in @context_value?');

$activity = $workflow->newActivity('gs_school_search');
$activity->name = 'school_search';
$activity->inputs = array('ask_school_name');
$activity->outputs = array('ask_leader', 'end');
$activity->state_activity_name = 'ask_state';
$activity->school_activity_name = 'ask_school_name';
$activity->max_results = 5;
$activity->no_school_found_msg = t('We couldn\'t find your school @school_name in @school_state. Text @keyword to try again.');
$activity->one_school_found_msg = t('We found @school_name in @school_city, @school_state. Reply Y if this is your school. Text @keyword to try again.');
$activity->schools_found_msg = t('We found @num_results matches. Text back the # for your school. Or text @keyword to try again.');
$activity->invalid_response_msg = t('Sorry, we didn\'t understand that. Text @keyword to try again.');
$activity->mdata_keywords = array(
  '201' => 'CREDIT',
  '311' => 'LOANS',
  '9241' => 'SAVINGS',
);

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_leader';
$activity->inputs = array('school_found', 'school_search');
$activity->outputs = array('ask_momm2013_question');
$activity->question = "Next question. What was the first and last name of your workshop leader?";

$activity = $workflow->newActivity('mdata_sms_prompt');
$activity->name = 'ask_momm2013_question';
$activity->inputs = array('ask_leader');
$activity->outputs = array('submit_report_back');
$activity->questions = array(
  '201' => "Last question. What did you learn from the \"Matchbox 20\" game?",
  '311' => "Last question. How will you be preparing yourself for attending college?",
  '9241' => "Last question. What's the best tip you got for spending less?",
);

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_momm2013_question');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_leader' => 30,
);
$activity->success_response = 162283;
$activity->use_special_submitter = 'momm2013';
$activity->webform_nid = 731099;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('school_found', 'school_search', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Love Letters 2014 Report Back - User will first be prompted to submit a
 * picture from: https://secure.mcommons.com/campaigns/123417/opt_in_paths/163695
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_loveletters_report_back';
$workflow->title = 'Love Letters Report Back';
$workflow->description = 'Submits the report back for the Love Letters campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_cards', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 163699;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_cards';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_people');
$activity->opt_in_path_id = 163701;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_cards');
$activity->outputs = array('ask_why');
$activity->opt_in_path_id = 163703;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_why';
$activity->inputs = array('ask_people');
$activity->outputs = array('strip_signature');
$activity->opt_in_path_id = 163705;

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_why');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_cards' => 3,
  'ask_people' => 4,
  'ask_why' => 5,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 163707;
$activity->webform_nid = 731168;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back', 'ask_picture');

$workflows[$workflow->name] = $workflow;

/**
 * Teens for Jeans 2014 Report Back
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_tfj_report_back';
$workflow->title = 'Teens for Jeans 2014 Report Back';
$workflow->description = 'Submits the report back for the Teens for Jeans 2014 campaign.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_jeans', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 163779;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_jeans';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_people');
$activity->opt_in_path_id = 163781;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_jeans');
$activity->outputs = array('ask_why');
$activity->opt_in_path_id = 163783;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_why';
$activity->inputs = array('ask_people');
$activity->outputs = array('strip_signature');
$activity->opt_in_path_id = 163785;

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_why');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_jeans' => 3,
  'ask_people' => 5,
  'ask_why' => 6,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 163787;
$activity->webform_nid = 731181;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back', 'ask_picture');

$workflows[$workflow->name] = $workflow;

/**
 * Teens for Jeans 2014 Report Back
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_pbj_report_back';
$workflow->title = 'PBJ 2014 Report Back';
$workflow->description = 'Submits the report back for the PBJ 2014 campaign.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_food', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 164403;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_food';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_people');
$activity->opt_in_path_id = 164405;

$activity = $workflow->newActivity('mobile_commons_opt_in_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_food');
$activity->outputs = array('strip_signature');
$activity->opt_in_path_id = 164407;

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_people');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_food' => 2,
  'ask_people' => 3,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 164409;
$activity->webform_nid = 731236;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back', 'ask_picture');

$workflows[$workflow->name] = $workflow;
