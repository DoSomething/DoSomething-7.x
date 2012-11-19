<?php

/**
 *	Implements hook_menu()
 */
function dosomething_metatags_menu() {
	$items['admin/config/search/meta'] = array(
		'title' => t('Manage Meta Tags'),
		'page callback' => 'dosomething_metatags_admin_meta',
		'access arguments' => array('administer site configuration')
	);

	$items['admin/config/search/meta/edit/%'] = array(
		'title' => t('Edit Meta Tag'),
		'page callback' => 'drupal_get_form',
		'page arguments' => array('dosomething_metatags_edit_form', 5),
		'access arguments' => array('administer site configuration'),
		'type' => MENU_CALLBACK
	);

	$items['admin/config/search/meta/delete/%'] = array(
		'title' => t('Delete Meta Tag'),
		'page callback' => 'drupal_get_form',
		'page arguments' => array('dosomething_metatags_admin_delete_form', 5),
		'access arguments' => array('administer site configuration'),
		'type' => MENU_CALLBACK
	);

	$items['admin/config/search/meta/add'] = array(
		'title' => t('Add Meta Tag'),
		'page callback' => 'drupal_get_form',
		'page arguments' => array('dosomething_metatags_add_form'),
		'access arguments' => array('administer site configuration')
	);

	return $items;
}

/**
 *	Delete confirmation form.
 */
function dosomething_metatags_admin_delete_form($form, &$form_state, $tag_id) {
	$form['desc'] = array(
		'#markup' => t('Are you sure you want to delete this meta tag configuration? This action <b>cannot</b> be undone.'),
		'#prefix' => '<p>',
		'#suffix' => '</p>'
	);

	$form_state['tag_id'] = $tag_id;

	$form['submit_yep'] = array(
		'#type' => 'submit',
		'#value' => t('Delete this')
	);

	$form['submit_nope'] = array(
		'#type' => 'submit',
		'#value' => t('Nope.')
	);

	$form['#submit'][] = 'dosomething_metatags_admin_delete_tag';
	return $form;
}

/**
 *	Delete processing
 */
function dosomething_metatags_admin_delete_tag($form, &$form_state) {
	db_delete('dosomething_metatags')
		->condition('tid', $form_state['tag_id'])
		->execute();

	dosomething_metatags_fetch_meta_tags('renew');
	drupal_set_message(t('Meta tags successfully deleted.'));
	drupal_goto('admin/config/search/meta');
}

/**
 *	Field validation form.
 */
function dosomething_metatags_validate(&$form, &$form_state) {
	$values = $form_state['values'];

	if (empty($values['pages'])) {
		form_set_error('pages', t('Pease let us know what page(s) you\'d like this meta description to appear on.'));
	}

	if (empty($values['description'])) {
		form_set_error('description', t('Please write a description to show up on your selected page(s)'));
	}
}

/**
 *	Meta tag adding form.
 */
function dosomething_metatags_add_form($form, &$form_state) {
	$form['desc'] = array(
		'#markup' => t('You can add meta description tags on this page.  Fill out the text box below and click the "add this" button.')
	);

	$form['pages'] = array(
		'#type' => 'textarea',
		'#attributes' => array('placeholder' => t('Write some pages here, one per line.  * is a wildcard.  <front> is the front page.')),
		'#title' => t('Pages'),
		'#description' => t('The page(s) that this description will appear on.  One per line.  * is a wildcard (e.g. blog/* applies to blog/, blog/7-facts-about-rosh-hashanah, blog/..., etc.).   <front> is the front page.'),
	);

	$form['description'] = array(
		'#type' => 'textarea',
		'#attributes' => array('placeholder' => t('Write a meta description here.')),
		'#title' => t('Description'),
		'#description' => t('A meta description.'),
	);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Add this')
	);

	$form['#validate'][] = 'dosomething_metatags_validate';
	$form['#submit'][] = 'dosomething_metatags_admin_add_tag';
	return $form;
}

/**
 *	Meta tag adding processing.
 */
function dosomething_metatags_admin_add_tag(&$form, &$form_state, $tag_id) {
	$tag = array(
		'pages' => $form_state['values']['pages'],
		'meta_tags' => serialize(array('description' => $form_state['values']['description']))
	);
	drupal_write_record('dosomething_metatags', $tag);

	dosomething_metatags_fetch_meta_tags('renew');
	drupal_set_message(t('Meta tags successfully added.'));
	drupal_goto('admin/config/search/meta');
}

/**
 *	Meta tag editing form.
 */
function dosomething_metatags_edit_form($form, &$form_state, $tag_id) {
	if (!empty($tag_id)) {
		$t = dosomething_metatags_fetch_meta_tags('fetch', $tag_id);
		$t['meta_tags'] = unserialize($t['meta_tags']);
	}

	$form['desc'] = array(
		'#markup' => t('You can edit meta description tags on this page.  Fill out the text box below and click the "edit this" button.')
	);

	$form_state['tag_id'] = $tag_id;

	$form['pages'] = array(
		'#type' => 'textarea',
		'#attributes' => array('placeholder' => t('Write some pages here, one per line.  * is a wildcard.  <front> is the front page.')),
		'#title' => t('Pages'),
		'#description' => t('The page(s) that this description will appear on.  One per line.  * is a wildcard (e.g. blog/* applies to blog/, blog/7-facts-about-rosh-hashanah, blog/..., etc.).   <front> is the front page.'),
		'#default_value' => $t['pages']
	);

	$form['description'] = array(
		'#type' => 'textarea',
		'#attributes' => array('placeholder' => t('Write a meta description here.')),
		'#title' => t('Description'),
		'#description' => t('A meta description.'),
		'#default_value' => $t['meta_tags']['description']
	);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Edit this')
	);

	$form['#validate'][] = 'dosomething_metatags_validate';
	$form['#submit'][] = 'dosomething_metatags_admin_alter_tag';
	return $form;
}

/**
 *	Edit processing
 */
function dosomething_metatags_admin_alter_tag(&$form, &$form_state, $tag_id) {
	db_update('dosomething_metatags')
		->fields(array(
			'pages' => $form_state['values']['pages'],
			'meta_tags' => serialize(array('description' => $form_state['values']['description']))
		))
		->condition('tid', $form_state['tag_id'])
		->execute();

	dosomething_metatags_fetch_meta_tags('renew');
	drupal_set_message(t('Meta tags successfully updated.'));
	drupal_goto('admin/config/search/meta');
}

/**
 *	Meta tag viewing page.	
 */
function dosomething_metatags_admin_meta() {
  $thead = array(
    array('data' => t('Page Path(s)'), 'class' => array('meta-page-path')),
    array('data' => t('Meta Description'), 'class' => array('meta-description')),
    array('data' => t('Actions'), 'class' => array('meta-actions'))
  );

  $tags = dosomething_metatags_fetch_meta_tags();

  $tags_table = array();
  foreach ($tags AS $key => $tag) {
  	$t = unserialize($tag['meta_tags']);
	$operations = array();
	$operations[] = array(
		'title' => t('Edit'),
		'href' => 'admin/config/search/meta/edit/' . $tag['tid']
	);
	$operations[] = array(
		'title' => t('Delete'),
		'href' => 'admin/config/search/meta/delete/' . $tag['tid']
	);

  	$tags_table['rows'][] = array(
  		'data' => array(
  			'paths' => htmlspecialchars(implode(', ', explode("\r\n", $tag['pages']))),
  			'meta_tags' => $t['description'],
  			'actions' => theme('links__ctools_dropbutton', array('links' => $operations, 'attributes' => array('class' => array('links', 'inline'))))
  		)
  	);
  }

  $content .= l('+ Add new meta tag configuration', 'admin/config/search/meta/add');
  $content .= theme('pager');
  $content .= '<p />' . theme('table', array('header' => $thead, 'rows' => $tags_table['rows'], 'attributes' => array('id' => 'meta-table')));
  $content .= theme('pager');

  return $content;
}