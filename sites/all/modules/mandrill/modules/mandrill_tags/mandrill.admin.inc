<?php
/*
 * Form to adminster exsisting Mandrill tags
 *
 * Orginally created to delete tags via the Mandrill API. There were a "run away"
 * number of tags created due to a bug. The documented limit is a 100 tags,
 * currently we're at 800. The bug reveiled the real limit is 1000.
 * 
 */

 define('MANDRILL_TAG_PAGER', 50);

 /*
  * Provide a form listing of all the tags with a checkbox to delete the tag
  * via the Madrill API.
  *
  * @return array
  *   Form elements to list and select tags for deletion
  */
function mandrill_tags_form($form, $form_state) {

  // Get a list of all the exsisting tags
  $tags = mandrill_tags_data();

  $header = array(
    'tag_name' => t('Tag Name'),
    'tag_count' => t('Count'),
  );

  $options = array();
  $tag_count = 0;
  isset($_GET['tag_start']) ? $tag_start = $_GET['tag_start'] : $tag_start = 0;
  foreach ($tags as $tag) {
    if ($tag_count >= $tag_start) {
      $options[$tag['tid']] = array(
        'tag_name' => $tag['tag_name'],
        'tag_count' => $tag['tag_count'], 
      );
    }
    $tag_count++;
    if ($tag_count >= $tag_start + MANDRILL_TAG_PAGER) {
      break;
    }
  }
  
  // Simple pager
  $next = $tag_start + MANDRILL_TAG_PAGER;
  if ($next > count($tags) - MANDRILL_TAG_PAGER)
    $next = count($tags) - MANDRILL_TAG_PAGER;
  $previous = $tag_start - MANDRILL_TAG_PAGER;
  if ($previous < 0)
    $previous = 0;
  
  $form['header'] = array(
    '#type' => 'markup',
    '#markup' => '<< <a href="/admin/config/services/mandrill/tags?tag_start=' . $previous . '">Previous</a> - ' . $tag_start . t(' to ') . $tag_count . t(' of ') . count($tags) . t(' Tags') . ' - <a href="/admin/config/services/mandrill/tags?tag_start=' . $next . '">Next</a> >>',
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
    '#value' => t('Delete'),
  );

  return $form;

}

/*
 * Submit functionality for selected tags to be deleted in bulk via the Mandrill API
 */
function mandrill_tags_form_submit($form , $form_state) {

  $results = array_filter($form_state['values']['table']);
  $api = mandrill_get_api_object();

  if ($api) {
    foreach ($results as $result => $tag) {
      $delete_result = $api->tags_delete($tag);
    }
    drupal_goto('admin/config/services/mandrill/tags');
  }
  else {
    drupal_set_message(t('Please enter a Mandrill API key to use DoSomething tag management.'));
    drupal_goto('admin/config/services/mandrill');
  }
  
}

function mandrill_tags_data() {

  $data = array();
  $api = mandrill_get_api_object();

  if ($api) {
    $tags = $api->tags_list();
    $tag_count = 0;
    foreach ($tags as $tag) {
      $data[$tag_count]['tid']      = $tag['tag'];
      $data[$tag_count]['tag_name'] = $tag['tag'];
      $data[$tag_count]['tag_count'] = $tag['sent'];
      $tag_count++;
    }
    return $data;
  }
  else {
    drupal_set_message(t('Please enter a Mandrill API key to use DoSomething tag management.'));
    drupal_goto('admin/config/services/mandrill');
  }
  
}