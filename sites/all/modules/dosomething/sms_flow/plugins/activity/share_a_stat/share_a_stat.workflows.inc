<?php

//
// sms_flow_share_stat_mms
//
$w = new ConductorWorkflow;
$w->wid = 'new';
$w->name = 'sms_flow_share_stat_mms';
$w->title = 'Share a Stat MMS Handler';
$w->api_version = '1.0';

$a = $w->newActivity('start');
$a->name = 'start';
$a->inputs = array();
$a->outputs = array('process_mms');

$a = $w->newActivity('share_stat_process_mms');
$a->name = 'process_mms';
$a->inputs = array('start');
$a->outputs = array('end');
$a->routes = array(
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

$a = $w->newActivity('end');
$a->name = 'end';
$a->inputs = array('process_mms');
$a->outputs = array();

$workflows[$w->name] = $w;
