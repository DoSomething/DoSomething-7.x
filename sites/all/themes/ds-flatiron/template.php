<?php

function ds_flatiron_preprocess_node(&$vars) {
  if ($vars['node']->type == 'campaign') {
  	// node--campaign--[nid] <---- This should be some org wide id
  	array_push( $vars['theme_hook_suggestions'], 'node__campaign__' . $vars['node']->nid );
  	
  	// @TODO - REMOVE ME ONCE WE FIGURE OUT FIELDS

  	switch($vars['node']->nid) {
	  case '728392':  //PB&J
	  case '728438':  //PB&J
  	  case '728618':  //PB&J
  	  	
  	  	$vars['content']['report_back'] = array(
  	  	  '#type' => 'markup',
  	  	  '#markup' => 'I AM A REPORT BACK'
  	  	);

  	    break;
  	}
  }
}

function ds_flatiron_preprocess_page(&$vars) {
  if ($vars['node']->type == 'campaign') {
  	$vars['page']['footer']['#access'] = FALSE;
  }
}

