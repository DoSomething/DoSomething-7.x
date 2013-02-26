<?php

//
// sms_flow_share_stat_mms
//
$workflow = new ConductorWorkflow;
$workflow->wid = 'new';
$workflow->name = 'sms_flow_share_stat_mms';
$workflow->title = 'Share a Stat MMS Handler';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->inputs = array();
$activity->outputs = array('process_mms');

$activity = $workflow->newActivity('share_stat_process_mms');
$activity->name = 'process_mms';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->routes = array(
    '145523' => array(
      'mms' => 145793,
      'no_mms' => 146293,
    ),
    '145843' => array(
      'mms' => 145853,
      'no_mms' => 146313,
    ),
    '145863' => array(
      'mms' => 145873,
      'no_mms' => 146353,
    ),
    '145963' => array(
      'mms' => 145983,
      'no-mms' => 146383,
    ),
    '146013' => array(
      'mms' => 145803,
      'no-mms' => 146303,
    ),
    '146053' => array(
      'mms' => 145913,
      'no-mms' => 146363,
    ),
    '146063' => array(
      'mms' => 145923,
      'no-mms' => 146373,
    ),
    '146133' => array(
      'mms' => 146143,
      'no-mms' => 146403,
    ),
  );

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('process_mms');
$activity->outputs = array();

$workflows[$workflow->name] = $workflow;
