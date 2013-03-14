<?php

function ds_flatiron_preprocess_node(&$vars) {
  if ($vars['node']->type == 'campaign') {
  	// node--campaign--[nid] <---- This should be some org wide id
  	array_push( $vars['theme_hook_suggestions'], 'node__campaign__' . $vars['node']->nid );
  	
  	// @TODO - REMOVE ME ONCE WE FIGURE OUT FIELDS

  	switch($vars['node']->nid) {
	    case '728618':  //PB&J  	  	

        // Give me the contact form - individual
        $block = block_load('webform', 'client-block-728660');
        $vars['content']['contact']['individual'] = _block_get_renderable_array(
          _block_render_blocks(array($block))
        );

        // Give me the contact form - team
        $block = block_load('webform', 'client-block-728661');
        $vars['content']['contact']['team'] = _block_get_renderable_array(
          _block_render_blocks(array($block))
        );
        
        // Give me the report back block
        $block = block_load('webform', 'client-block-728619');
  	  	$vars['content']['report_back'] = _block_get_renderable_array(
          _block_render_blocks(array($block))
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

