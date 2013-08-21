<?php

/**
 * @file
 * Page callbacks for dosomething_admin module.
 */

/**
* Page callback for admin/lookup.
*/
function dosomething_admin_lookup_page() {
  drupal_goto('admin/lookup/user');
}

/**
 * Page callback for DS staff to add/edit Connections terms.
 */
function dosomething_admin_banners_page() {
	drupal_set_title('Banners');
	$rows = array();
	$terms = taxonomy_get_tree(DOSOMETHING_ADMIN_VID_BANNERS);
	foreach ($terms as $term) {
		$rows[] = array($term->name, l('edit', 'taxonomy/term/' . $term->tid . '/edit', array('query' => array('destination' => 'admin/content/banners'))));
	}
	$output = theme('table', array('rows' => $rows));
	$output .= render(drupal_get_form('dosomething_admin_add_banner_form'));
	return $output;
}

/**
 * Form for creating new Connection term.
 */
function dosomething_admin_add_banner_form($form, &$form_state) {
	$form['new_term'] = array(
		'#type' => 'fieldset',
		'#title' => t('Create New Banner'),
		'#collapsible' => FALSE,
		'#collapsed' => FALSE, 
	);
	$form['new_term']['name'] = array(
	  '#type' => 'textfield', 
	  '#title' => t('Name'), 
	  '#size' => 60, 
	  '#required' => TRUE,
	);
	$form['submit'] = array('#type' => 'submit', '#value' => t('Add'));
	return $form;
}

/** 
 * Form submit handler for new Connection form.
 */ 
function dosomething_admin_add_banner_form_submit($form, &$form_state) {
	// Save new term:
	$term = new StdClass();
	$term->name = $form_state['values']['name'];
	$term->vid = DOSOMETHING_ADMIN_VID_BANNERS;
	taxonomy_term_save($term);
  // Direct to edit page:
  drupal_goto('taxonomy/term/' . $term->tid . '/edit', array('query'=> array('destination' => 'admin/content/banners')));
}
