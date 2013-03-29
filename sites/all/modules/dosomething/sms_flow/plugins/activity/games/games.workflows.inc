<?php

/**
 * Intended to be plugged in at the end of a pregnancy text drip message as an
 * mData. Will respond to any user message that matches a given set.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_preg_text_responder';
$workflow->title = 'Pregnancy Text Out-of-Flow Responder';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('out_of_flow_responder');

$activity = $workflow->newActivity('out_of_flow_responder');
$activity->name = 'out_of_flow_responder';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->no_match_response = 'This is the no_match_response message.';
$activity->response_sets = array(
  array(
    'exact_match' => array('test1', 'test2', 'test3'),
    'AND_match'   => array(
      array('test1A', 'test2A'),
      array('test1B', 'test 2 B'),
    ),
    'negation'    => TRUE,
    'response'    => 'Response Message #1 Negation',
  ),
  array(
    'exact_match' => array('test1', 'test2', 'test3'),
    'AND_match'   => array(
      array('test1a', 'test2a'),
      array('test1B', 'test 2 B'),
    ),
    'negation'    => FALSE,
    'response'    => 'Response Message #1',
  ),
  array(
    'exact_match' => array('test4', 'test5', 'test6'),
    'AND_match'   => array(
      array('test1C', 'test2C'),
      array('test1D', 'test 2 D'),
    ),
    'negation'    => FALSE,
    'response'    => 'Response Message #2',
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('out_of_flow_responder');

$workflows[$workflow->name] = $workflow;