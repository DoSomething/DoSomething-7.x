<?php

function ds_flatiron_preprocess_node(&$vars) {

  if ($vars['node']->type == 'campaign') {
  	// node--campaign--[nid] <---- This should be some org wide id
  	array_push( $vars['theme_hook_suggestions'], 'node__campaign__' . $vars['node']->nid );
  	
  	// @TODO - REMOVE ME ONCE WE FIGURE OUT FIELDS

  	switch($vars['node']->nid) {
	    case '728618':  //PB&J  	  	

        $params = drupal_get_query_parameters();

        // POST-REPORT BACK VIEW
        if (isset($params['success'])) {
          $vars['content']['#access'] = FALSE;
          $vars['complete'] = TRUE;
          break;
        }

        // POST-SHARE W/FRIENDS VIEW
        if (isset($params['thanks'])) {
          $vars['shared'] = TRUE;
          break;
        }

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

    if (user_is_anonymous()) {

      $redirect = array(
        'query' => array(
          'destination' => 'node/' . $vars['node']->nid,
        )
      );
      drupal_goto('user/register/campaign', $redirect);
    }

    if (arg(0) == 'user') {
      drupal_add_css( drupal_get_path('theme','ds-flatiron') . '/css/gate.css' );
    }

  }
}

