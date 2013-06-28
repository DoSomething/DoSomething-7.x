<?php

/**
 * @file
 * Page callbacks for dosomething_campaigns module.
 */

/** 
 * Page callback for user/registration.  
 * - Checks if destination is set in query string, and loads campaign node values if applicable.
 */
function dosomething_login_user_registration_page() {
  global $user;
  $destination = drupal_get_destination();
  //@todo: query all campaign nodes that are Gate based, and make this check dynamic.
  $campaign_nid = variable_get('hunt_campaign_nid', 729679);
  // Check if destination is set to a gated node:
  if ($destination['destination'] == 'node/' . $campaign_nid) {
    // Use Gate vars on the node:
    $node = node_load($campaign_nid);
    $node->gate_page_title = $node->title;
    $node->gate_headline = $node->title;

  }
  // Use Default variables if we don't have a gated $node.
  else {
    $node = new StdClass();
    $node->nid = 'default';
    $node->gate_page_title = variable_get('dosomething_login_gate_page_title');
    $node->gate_headline = variable_get('dosomething_login_gate_headline');
    $node->gate_description = variable_get('dosomething_login_gate_description');
    $node->gate_sidebar_headline = variable_get('dosomething_login_gate_sidebar_headline');
    $node->gate_sidebar_description = variable_get('dosomething_login_gate_sidebar_description');
    $node->gate_sidebar_footer = variable_get('dosomething_login_gate_sidebar_footer');    
  }

  $page = theme(
  	'dosomething_login_gate',
  	array(
  	  'node' => $node,
  	  'form' => drupal_get_form('dosomething_login_register_popup_form', FALSE)
  	)
  );

  /*
  // In case you wanna render in this in the theme, Drupal head, etc. use this method:
  drupal_set_title($node->title);
  return render($page);
  */

  // Use this method if you want to completely ditch all Drupal stuff:
  print $page;	
  drupal_exit();
}
