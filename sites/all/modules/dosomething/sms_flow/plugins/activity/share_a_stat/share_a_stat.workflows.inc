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
    '123456' => array(
      'mms' => 1,
      'no_mms' => 2
    ),
    '123457' => array(
      'mms' => 3,
      'no_mms' => 4
    )
  );

$a = $w->newActivity('end');
$a->name = 'end';
$a->inputs = array('process_mms');
$a->outputs = array();

$workflows[$w->name] = $w;
