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

	      // Check if the user has submitted an individual or team form
	      $contact_forms = array(
          'individual' => node_load(728660), 
          'team' => node_load(728661)
        );
	
      	foreach($contact_forms as $type => $form){
      	  $block = block_load('webform', 'client-block-' . $form->nid);
          $block_content = _block_render_blocks(array($block));
      	 
          if (!empty($block_content)) {
            $vars['content']['contact'][$type] = _block_get_renderable_array($block_content);
          }else{
            $vars[$type] = TRUE;
          }
        }  
 
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
          'destination' => 'pbj',
        )
      );
      drupal_goto('user/registration/campaign', $redirect);
    }

    if (arg(0) == 'user') {
      drupal_add_css( drupal_get_path('theme','ds-flatiron') . '/css/gate.css' );
    }

  }
}

function ds_flatiron_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'webform_client_form_728660') {
    $form['actions']['submit']['#value'] = t('I want to donate solo');
  }
  if ($form_id == 'webform_client_form_728661') {
    $form['actions']['submit']['#value'] = t('I want to run a drive');
  }
}
  