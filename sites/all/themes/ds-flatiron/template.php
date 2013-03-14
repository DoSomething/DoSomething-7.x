<?php

function ds_flatiron_preprocess_node(&$vars) {
  if ($vars['node']->type == 'campaign') {
  	// node--campaign--[nid] <---- This should be some org wide id
  	array_push( $vars['theme_hook_suggestions'], 'node__campaign__' . $vars['node']->nid );
  	
  	// @TODO - REMOVE ME ONCE WE FIGURE OUT FIELDS

  	switch($vars['node']->nid) {
	    case '728618':  //PB&J  	  	

        // Give me the report back block
        $block = block_load('webform', 'client-block-728619');
        $content = _block_get_renderable_array(_block_render_blocks(array($block)));

  	  	$vars['content']['report_back'] = array(
  	  	  '#type' => 'markup',
  	  	  '#markup' => $content
  	  	);

  	    break;
  	}
  }
}

function ds_flatiron_preprocess_page(&$vars) {
  if ($vars['node']->type == 'campaign') {
  	$vars['page']['footer']['#access'] = FALSE;
    // @TODO - THIS SHOULD BE REVISITED
    array_push( $vars['theme_hook_suggestions'], 'page__campaign' );
  }
}

