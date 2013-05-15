<?php

function create_and_share_drush_command() {
  return array(
    'cas-migrate' => array(
      'description' => 'Migrates fields into a Create and Share campaign.',
      'arguments' => array(
        'campaign' => dt('The campaign that should be migrated in.'),
      ),
    ),
  );
}

/**
 * Gets the structure for standard component types.
 *
 * @param string $type
 *   The type of component whose structure should be returned.
 *
 * @return array
 *   The structure as represented by an array.
 */
function create_and_share_component_structure($type) {
  $component = array(
    'nid' => 0,
    'cid' => 0,
    'pid' => 0,
    'form_key' => '',
    'name' => '',
    'type' => '',
    'value' => '',
    'extra' => array(),
    'mandatory' => 0,
    'weight' => 100,
    'page_num' => 1,
  );
  switch ($type) {
    case 'textfield':
      $component = array_merge($component, array(
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'disabled' => 0,
          'unique' => 0,
          'conditional_operator' => '=',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'description' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
      ));
    break;
    case 'select':
      $component = array_merge($component, array(
        'extra' => array(
          'items' => '',
          'other_option' => 0,
          'other_text' => 'Other...',
          'multiple' => 0,
          'title_display' => 'before',
          'private' => 0,
          'aslist' => 1,
          'optrand' => 0,
          'conditional_operator' => '=',
          'description' => '',
          'custom_keys' => '',
          'options_source' => '',
          'conditional_component' => '',
          'conditional_values' => '',
        ),
      ));
    break;
  }

  return $component;
}

/**
 * Loads a migrate file and imports fields from that file into a webform.
 *
 * @param string $campaign
 *   The machine name (as in, the path to the campaign minus leading slash)
 *   of the campaign to which the fields should be added.
 */
function drush_create_and_share_cas_migrate($campaign) {
  if ($settings = create_and_share_get_settings($campaign)) {
    $path = create_and_share_get_campaign_path($campaign);
    if (file_exists($path . '/migrate.inc')) {
      drush_print(dt("Found migrate file.  Loading data into NID {$settings['campaign_nid']}..."));
      require_once $path . '/migrate.inc';
      $campaign = preg_replace('#[^a-z0-9\_]#i', '_', $campaign);
      if (function_exists('create_and_share_import_' . $campaign)) {
        // Load the function.
        $func = 'create_and_share_import_' . $campaign;
        $fields = $func($settings['campaign_nid']);

        // Standard cid and field weight.
        $cid = 1;
        $weight = 100;

        // Go through the fields and ADD THEM!
        foreach ($fields AS $name => $data) {
          // Get the field structure.
          $structure = create_and_share_component_structure($data['type']);

          // Set default values for standard fields.
          $data += array('nid' => $settings['campaign_nid'], 'cid' => ++$cid, 'name' => $name, 'form_key' => strtolower(preg_replace('#[^a-z\_]#i', '_', $name)), 'weight' => ++$weight);

          // Replace the structure array with the $data informatoin.
          $structure = array_replace_recursive($structure, $data);

          // Add the component.
          webform_component_insert($structure);
          drush_print(dt("Successfully added {$name} component."));
        }

        drush_print(dt("Migrate completed."));
      }
      else {
        // create_and_share_import_(campaign_name) doesn't exist.
        drush_print(dt("Migrate file found, but create_and_share_import_{$campaign} doesn't seem to exist.  Make sure your migrate file is set up correctly."));
      }
    }
    else {
      // No migrate.inc file found.
      drush_print(dt("No migrate file found.  Are you sure you have the right campaig name, and the campaign has a migrate.inc file?"));
    }
  }
  else {
    // No campaign named (campaign) found.
    drush_print(dt("No campaign named '{$campaign}' found."));
  }
}
