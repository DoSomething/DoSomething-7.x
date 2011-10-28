<?php
/**
 * @file
 * dosomething_action_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_action_guide_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_action_guide_node_info() {
  $items = array(
    'action_guide' => array(
      'name' => t('Action Guide'),
      'base' => 'node_content',
      'description' => t('An action guide.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('<h2>Hey Content Loader!</h2>
<p>Here is some helpful css for you:<br>
class="box blue"  gives you a light blue box <br>
class="logolist" gives you ds logo shapes on an unordered list ul <br>
class="goright"  class="goleft"  gives img src="" padding and floats it to the left or right<br>

'),
    ),
  );
  return $items;
}

/**
 * Implements hook_default_webform_submission_entity_type().
 */
function dosomething_action_guide_default_webform_submission_entity_type() {
  $items = array();
  $items['action_guide'] = entity_import('webform_submission_entity_type', '{ "type" : "action_guide", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
