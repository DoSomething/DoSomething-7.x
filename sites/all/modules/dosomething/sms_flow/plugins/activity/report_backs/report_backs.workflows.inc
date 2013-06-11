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
