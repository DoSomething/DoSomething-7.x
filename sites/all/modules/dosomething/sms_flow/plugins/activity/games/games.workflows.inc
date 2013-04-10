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
    'phrase_match' => array('Im not up', 'Im not awake'),
    'word_match' => array('asleep'),
    'response' => array("You are now!"),
  ),
  array(
    'phrase_match' => array('I hate you', 'suck it'),
    'word_match' => array('die'),
    'response' => array("Deal with it."),
  ),
  array(
    'phrase_match' => array('Feeds baby', 'heres breakfast'),
    'word_match' => array('Eggs', 'pancakes', 'waffles', 'bagles', 'milk', 'orange juice', 'cereal', 'applesauce', 'bottle', 'feed'),
    'response' => array("Yum! I'll get you next time"),
  ),
  array(
    'phrase_match' => array('I dont want to', 'no'),
    'response' => array("But I'm the baby, you have to!"),
  ),
  array(
    'word_match' => array('Gross', 'ew'),
    'response' => array("But my cute face balances it out..."),
  ),
  array(
    'phrase_match' => array('Its okay', 'thats okay'),
    'response' => array("Thanks for understanding"),
  ),
  array(
    'phrase_match' => array('Shake baby'),
    'response' => array("OW"),
  ),
  array(
    'phrase_match' => array('I already changed you'),
    'AND_match' => array(array('change', 'already')),
    'response' => array("Well, I poop a lot.", "Call me Sir Poops A Lot"),
  ),
  array(
    'phrase_match' => array('Are you hungry', 'Do you need food', 'Do you need a bottle', 'Something to eat'),
    'response' => array("Yes please, I'm always hungry"),
  ),
  array(
    'phrase_match' => array('Please dont cry'),
    'response' => array("I'm a baby, it's what I do"),
  ),
  array(
    'AND_match' => array(array('test1', 'test2'), array('test1a', 'test2a')),
    'response' => array("Test Response 1"),
    'response_negative' => array("Test, Negative Response 1A", "Test Negative Response, 1B"),
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('out_of_flow_responder');

$workflows[$workflow->name] = $workflow;