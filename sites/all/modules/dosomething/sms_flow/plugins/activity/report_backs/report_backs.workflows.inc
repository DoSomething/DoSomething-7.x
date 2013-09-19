<?php

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
  '147823' => array(
    'yes' => '147743',
    'no' => '147753'
  ),
  '149003' => array(
    'yes' => '149023',
    'no' => '149013'
  ),
  // Oklahoma Report Back
  '157773' => array(
    'yes' => '157793',
    'no' => '157783'
  ),
  // I Heart Dad 2013 Report Back
  '158811' => array(
    'yes' => '158815',
    'no' => '158813',
  ),
  // Birthday Mail 2013 Report Back
  '160639' => array(
    'yes' => '160641',
    'no' => '160645',
  ),
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
  // Hunt 2013 Report Back Day 1
  '159421' => array(
    'yes' => '159445',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 2
  '159423' => array(
    'yes' => '159447',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 3
  '159425' => array(
    'yes' => '159449',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 4
  '159427' => array(
    'yes' => '159451',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 5
  '159429' => array(
    'yes' => '159453',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 6
  '159431' => array(
    'yes' => '159455',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 7
  '159433' => array(
    'yes' => '159457',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 8
  '159435' => array(
    'yes' => '159459',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 9
  '159437' => array(
    'yes' => '159461',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 10
  '159439' => array(
    'yes' => '159463',
    'no' => '159443',
  ),
  // Hunt 2013 Report Back Day 11
  '159441' => array(
    'yes' => '159465',
    'no' => '159443',
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('can_send_mms');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

/**
 * PBJ Report Back workflow
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_pbj_report_back';
$workflow->title = 'PBJ Report Back';
$workflow->description = 'Submits the report back for use with the PBJ campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->title = 'start';
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->title = 'ask_picture';
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_jars');
$activity->should_prompt = FALSE;

$activity = $workflow->newActivity('sms_prompt');
$activity->title = 'ask_jars';
$activity->name = 'ask_jars';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_people');
$activity->question = 'Sweet Peanut Butter Batman! Next: Question 1 - How many jars did you collect in total?';

$activity = $workflow->newActivity('sms_prompt');
$activity->title = 'ask_people';
$activity->name = 'ask_people';
$activity->inputs = array('ask_jars');
$activity->outputs = array('ask_zip');
$activity->question = 'Jamtastic! Now Question 2 - How many people were involved?';

$activity = $workflow->newActivity('sms_prompt');
$activity->title = 'ask_zip';
$activity->name = 'ask_zip';
$activity->inputs = array('ask_people');
$activity->outputs = array('strip_signature');
$activity->question = 'Final question - Where did you donate your jars? (Text back the zipcode)';

$activity = $workflow->newActivity('sms_strip_signature');
$activity->title = 'strip_signature';
$activity->name = 'strip_signature';
$activity->inputs = array('ask_zip');
$activity->outputs = array('pbj_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->title = 'pbj_report_back';
$activity->name = 'pbj_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('mcommons_opt_out');
$activity->submission_fields = array(
  'ask_jars' => 2,
  'ask_people' => 8,
  'ask_zip' => 1,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 'You are a rockstar. You\'ve been entered to win @submission_count times. Have more pics to share? Text EXTRA. All set? Text FINISH!';
$activity->webform_nid = 728619;

$activity = $workflow->newActivity('mobile_commons_opt_out');
$activity->title = 'mcommons_opt_out';
$activity->name = 'mcommons_opt_out';
$activity->inputs = array('pbj_report_back');
$activity->outputs = array('end');
$activity->opt_out_ids = array(112733);

$activity = $workflow->newActivity('end');
$activity->title = 'end';
$activity->name = 'end';
$activity->inputs = array('mcommons_opt_out');

$workflows[$workflow->name] = $workflow;

/**
 * sms_flow_beta_campaign_report_back workflow
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_beta_campaign_report_back';
$workflow->title = 'Beta Campaign Report Back';
$workflow->description = 'Submits the report back for use with the Cleanup (beta) campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('ask_trash_pickup');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_trash_pickup';
$activity->question = t('How many pieces of trash did you pick up?');
$activity->inputs = array('start');
$activity->outputs = array('ask_people_involved');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people_involved';
$activity->question = t('How many people were involved?');
$activity->inputs = array('ask_trash_pickup');
$activity->outputs = array('ask_zip');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_zip';
$activity->question = t('What zip code did you clean up?');
$activity->inputs = array('ask_people_involved');
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->question = t('Send us a picture of what you did!');
$activity->inputs = array('ask_zip');
$activity->outputs = array('strip_signature');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_picture');
$activity->outputs = array('submit');

$activity = $workflow->newActivity('beta_campaign_report_back');
$activity->name = 'submit';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->title = 'End';
$activity->inputs = array('submit');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;

/**
 * Thumb Wars report back flow. User will be prompted to first submit a picture
 * by the conversation begun in Mobile Commons
 * (https://secure.mcommons.com/campaigns/116593/opt_in_paths/155733)
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_thumbwars_report_back';
$workflow->title = 'Thumb Wars Report Back';
$workflow->description = 'Submits the report back for the Thumb Wars campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->title = 'start';
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_who', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 158849;

$activity = $workflow->newActivity('sms_prompt_normalize_response');
$activity->name = 'ask_who';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_why');
$activity->question = 'Amazing! Q1: who did you share thumb socks with? (Text back: Mother, Father, Sister, Brother, Friend, Other)';
$activity->normalizedGroups = array(
  array('mother', 'mom'),
  array('father', 'dad'),
  array('sister', 'sis'),
  array('brother', 'bro'),
  array('friend', 'frend', 'firend'),
  array('select_or_other', 'other'),
);

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_why';
$activity->inputs = array('ask_who');
$activity->outputs = array('strip_signature');
$activity->question = 'Great. Q2: why did you share thumb socks with that person?';

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_why');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('mcommons_opt_out');
$activity->submission_fields = array(
  'defaults' => array(
    array('FIRST_NAME', 1),
    array('LAST_NAME', 2),
    array(1, 4),
  ),
  'ask_who' => 6,
  'ask_why' => 7,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 'You rock! Got more pics? Text MORE to share another pic or DRIVE to read & share a crazy stat about texting & driving for another entry. All set? Txt DONE';
$activity->webform_nid = 729094;

$activity = $workflow->newActivity('mobile_commons_opt_out');
$activity->title = 'mcommons_opt_out';
$activity->name = 'mcommons_opt_out';
$activity->inputs = array('submit_report_back');
$activity->outputs = array('end');
$activity->opt_out_ids = array(116593);

$activity = $workflow->newActivity('end');
$activity->title = 'end';
$activity->name = 'end';
$activity->inputs = array('mcommons_opt_out', 'ask_picture');

$workflows[$workflow->name] = $workflow;

/**
 * Oklahome Response Campaign report back workflow. User will first be prompted
 * to submit a picture from: https://secure.mcommons.com/campaigns/119613/opt_in_paths/157793
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_oklahoma_report_back';
$workflow->title = 'Oklahoma Report Back';
$workflow->description = 'Submits the report back for the Oklahoma campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_items');
$activity->should_prompt = FALSE;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_items';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_people');
$activity->question = t('Amazing! Q1: How many items did you collect?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_items');
$activity->outputs = array('strip_signature');
$activity->question = t('Fantastic. Q2: How many people helped out?');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_people');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_items' => 1,
  'ask_people' => 2,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 'Incredible job. Thanks for starting the healing process. Want to send a message of support to Moore? Text HOPE to start & we\'ll hand deliver your messages.';
$activity->webform_nid = 729395;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * I Heart Dad report back workflow. User will first be prompted to submit a
 * picture from: https://secure.mcommons.com/campaigns/120085/opt_in_paths/158815
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_iheartdad_report_back';
$workflow->title = 'I Heart Dad Report Back';
$workflow->description = 'Submits the report back for the I Heart Dad campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_systolic', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 158843;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_systolic';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_diastolic');
$activity->question = t('Looking good! Text back your dad\'s systolic blood pressure (the first number) now.');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_diastolic';
$activity->inputs = array('ask_systolic');
$activity->outputs = array('submit_report_back');
$activity->question = t('Great! Now, text back your dad\'s diastolic blood pressure (the second number).');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_diastolic');
$activity->outputs = array('blood_pressure_results');
$activity->submission_fields = array(
  'ask_systolic' => 4,
  'ask_diastolic' => 5,
  'picture' => 'ask_picture:mms',
);
$activity->webform_nid = 729555;
$activity->campaign_opt_outs = array(120085, 120233);

$activity = $workflow->newActivity('sms_blood_pressure_results');
$activity->name = 'blood_pressure_results';
$activity->inputs = array('submit_report_back');
$activity->outputs = array('end');
$activity->systolic = 'ask_systolic';
$activity->diastolic = 'ask_diastolic';
$activity->hypotension_msg = 158937;
$activity->desired_msg = 158937;
$activity->prehypertension_msg = 158939;
$activity->hypertension1_msg = 158941;
$activity->hypertension2_msg = 158943;
$activity->hypertensive_crisis_msg = 158945;
$activity->error_msg = 158937;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'blood_pressure_results');

$workflows[$workflow->name] = $workflow;

/**
 * Birthday Mail 2013 Report Back User will first be prompted to submit a
 * picture from: https://secure.mcommons.com/campaigns/121121/opt_in_paths/160639
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_birthdaymail_report_back';
$workflow->title = 'Birthday Mail Report Back';
$workflow->description = 'Submits the report back for the Birthday Mail campaign';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_cards', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 160647;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_cards';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_people');
$activity->question = t('Thanks! How many cards did you make?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_cards');
$activity->outputs = array('strip_signature');
$activity->question = t('How many people did you participate with? (If you made cards alone, text back 0.)');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_people');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_cards' => 1,
  'ask_people' => 3,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 160649;
$activity->webform_nid = 730403;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('submit_report_back', 'ask_picture');

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
$activity->outputs = array('ask_people', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 161261;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_people';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_why');
$activity->question = t('Great! Q1 - How many people came to your event?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_why';
$activity->inputs = array('ask_people');
$activity->outputs = array('strip_signature');
$activity->question = t('Cool! Q2 - Why did you sign up for Give a Spit?');

$activity = $workflow->newActivity('sms_strip_signature');
$activity->name = 'strip_signature';
$activity->inputs = array('ask_why');
$activity->outputs = array('submit_report_back');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('strip_signature');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'ask_people' => 1,
  'ask_why' => 2,
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
 * Hunt 2013 Report Back - Environment
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_enviro_report_back';
$workflow->title = 'Hunt Enviro Report Back - Day 1';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159491;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: How many pounds of trash did you have at the end of the day?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 1,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Homelessness
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_homeless_report_back';
$workflow->title = 'Hunt Homelessness Report Back - Day 2';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159493;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: What shelter did you deliver your care package to?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 2,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Education/Literacy
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_literacy_report_back';
$workflow->title = 'Hunt Literacy Report Back - Day 3';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159495;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: How many books did you donate?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 3,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Bullying
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_bully_report_back';
$workflow->title = 'Hunt Bully Report Back - Day 4';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159497;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: Tell us about the message you shared.  Who did you share it with and what did it say?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 4,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Sex & Relationships
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_sex_report_back';
$workflow->title = 'Hunt Sex/Relationship Report Back - Day 5';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159499;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: How did the guy respond when you asked him to stand up for women?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 5,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Health
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_health_report_back';
$workflow->title = 'Hunt Health Report Back - Day 6';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159501;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: What sport did you teach and who did you teach it to?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 6,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Discrimination
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_discrim_report_back';
$workflow->title = 'Hunt Discrimination Report Back - Day 7';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159503;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: Where did you wear your sign and what did it say?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 7,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Animal Welfare
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_animal_report_back';
$workflow->title = 'Hunt Animal Welfare Report Back - Day 8';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159505;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: How many towels and blankets did you donate to your local shelter?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 8,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Human Rights
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_water_report_back';
$workflow->title = 'Hunt Water/Human Rights Report Back - Day 9';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159507;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: How far did you and your friends walk?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 9,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Disaster Response & Relief
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_disaster_report_back';
$workflow->title = 'Hunt Disaster Report Back - Day 10';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159509;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: Who did you share your disaster preparedness kit with?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 10,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;

/**
 * Hunt 2013 Report Back - Fighting Apathy
 */
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_hunt_apathy_report_back';
$workflow->title = 'Hunt Apathy Report Back - Day 11';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('ask_picture');

$activity = $workflow->newActivity('mms_prompt');
$activity->name = 'ask_picture';
$activity->inputs = array('start');
$activity->outputs = array('ask_question1', 'end');
$activity->should_prompt = FALSE;
$activity->no_mms_response = 159511;

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question1';
$activity->inputs = array('ask_picture');
$activity->outputs = array('ask_question2');
$activity->question = t('Q1: How many people did you do this action with?');

$activity = $workflow->newActivity('sms_prompt');
$activity->name = 'ask_question2';
$activity->inputs = array('ask_question1');
$activity->outputs = array('submit_report_back');
$activity->question = t('Q2: Where did you draw your mural?');

$activity = $workflow->newActivity('submit_report_back');
$activity->name = 'submit_report_back';
$activity->inputs = array('ask_question2');
$activity->outputs = array('end');
$activity->submission_fields = array(
  'challenge_day' => 11,
  'picture' => 'ask_picture:mms',
);
$activity->success_response = 159489;
$activity->use_special_submitter = 'hunt2013';
$activity->webform_nid = 729683;

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('ask_picture', 'submit_report_back');

$workflows[$workflow->name] = $workflow;
