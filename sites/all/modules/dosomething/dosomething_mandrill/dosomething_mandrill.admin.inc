<?php
/*
 * Form to adminster exsisting Mandrill tags
 *
 * Orginally created to delete tags via the Mandrill API. There were a "run away"
 * number of tags created due to a bug. The documented limit is a 100 tags,
 * currently we're at 800. The bug reveiled the real limit is 1000.
 * 
 */
function dosomething_mandrill_tags_form($form, $form_state) {
  
  // Get a list of all the exsisting tags
  $tags = dosomething_mandrill_tags_data();
  
  // Number of rows to show per page
  $header = array(
    'tag_name' => t('Tag Name'),
    'tag_count' => t('Tag Count'),
  );
  
  $options = array();
  $tag_count = 0;
  foreach ($tags as $tag) {
    $options[$tag['tid']] = array(
      'tag_name' => $tag['tag_name'],
      'tag_count' => $tag['tag_count'], 
    );
    $tag_count++;
    if ($tag_count >= 50) {
      break;
    }
  }
  
  $form['header'] = array(
    '#markup' => ''
  );
  // @todo : move text content to template file (tpl)
  $form['header'] = array(
    '#type' => 'markup',
    '#markup' => count($options) . t(' of ') . count($tags) . t(' Tags'),
    '#weight' => 0,
  );
  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#multiple' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  // Provide a form listing of all the tags with a checkbox to delete the tag
  // via the Madrill API
  
  return $form;
  
}

function dosomething_mandrill_tags_form_submit($form , $form_state) {

  $results = array_filter($form_state['values']['table']);
  
  $api = mandrill_get_api_object();

  if ($api) {
    
    foreach ($results as $result => $tag) {
      $delete_result = $api->tags_delete($tag);
    }
    
    cache_clear_all('dosomething_mandrill_tags_data', 'cache');
    drupal_goto('admin/config/services/mandrill/tags');

  }
  else {
    drupal_set_message(t('Please enter a Mandrill API key to use DoSomething tag management.'));
    drupal_goto('admin/config/services/mandrill');
  }
  
  
}

function dosomething_mandrill_tags_data() {

  // Cache tag info to prevent hitting the Mandrill API too often
  if ($cache = cache_get('dosomething_mandrill_tags_data')) {
    return $cache->data;
  }
  
  $data = array();
  $api = mandrill_get_api_object();

  if ($api) {
  
    // tags
    $tags = $api->tags_list();
    $tag_count = 0;
    foreach ($tags as $tag) {
      $data[$tag_count]['tid']      = $tag['tag'];
      $data[$tag_count]['tag_name'] = $tag['tag'];
      $data[$tag_count]['tag_count'] = $tag['sent'];
      $tag_count++;
    }
    
    // $api->tags_info($tag['tag']
    // $api->tags_time_series($tag['tag']);
    
    cache_set('dosomething_mandrill_tags_data', $data, 'cache', CACHE_TEMPORARY);
    return $data;
    
  }
  else {
    drupal_set_message(t('Please enter a Mandrill API key to use DoSomething tag management.'));
    drupal_goto('admin/config/services/mandrill');
  }
  
}