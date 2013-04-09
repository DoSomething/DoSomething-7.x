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
$activity->response_sets = array(
  array(
    'phrase_match' => array('phrase 1', 'phrase 2'),
    'AND_match'    => array(
      array('test1a', 'test2a'),
      array('test1B', 'test 2 B'),
    ),
    'word_match'  => array('test1', 'test2', 'test3'),
    'response'    => array(
      'Random Response Message #1A',
      'Random Response Message #1B',
      'Random Response Message #1C',
    ),
    'response_negative' => array(
      'Response Message #1A Negation',
      'Response Message #1B Negation',
      'Response Message #1C Negation',
    ),
  ),
  array(
    'AND_match'   => array(
      array('test1C', 'test2C'),
      array('test1D', 'test 2 D'),
    ),
    'word_match'  => array('test4', 'test5', 'test6'),
    'response'    => 'Response Message #2',
  ),
  array(
    'phrase_match' => array('i love you'),
    'response' => 'i love you too!',
  ),
  array(
    'phrase_match' => array('i dont love you'),
    'response' => 'i don\'t love you either!',
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('out_of_flow_responder');

$workflows[$workflow->name] = $workflow;