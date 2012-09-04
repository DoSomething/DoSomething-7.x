<?php
/**
 * @file
 * Views' relationship handlers.
 */

class webform_handler_relationship_submission_data extends views_handler_relationship  {

  function option_definition() {
    $options = parent::option_definition();
    $options['component_type'] = array('default' => NULL);
    $options['components'] = array('default' => array());
    return $options;
  }

  /**
   * Extends the relationship options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Group the components by type.
    $components = array();
    foreach (webform_component_instances() as $key => $data) {
      $components[$data['type']][$key] = check_plain("Webform {$data['nid']}: {$data['name']} ({$data['form_key']})");
    }

    $type_options = array();
    foreach (webform_components() as $key => $component) {
      $type_options[$key] = check_plain($component['label']);
    }
    // Only show component types that are in use.
    $type_options = array(NULL => t('- Select -')) + array_intersect_key($type_options, $components);

    ctools_include('dependent');

    $form['component_type'] = array(
      '#title' => t('Component type'),
      '#type' => 'select',
      '#description' => t('Select component type for this relationship'),
      '#required' => TRUE,
      '#default_value' => $this->options['component_type'],
      '#options' => $type_options,
    );

    foreach ($components as $type => $options) {
      $form['components'][$type] = array(
        '#title' => t('Components: %label', array('%label' => $type_options[$type])),
        '#prefix' => '<div id="' . drupal_html_id('options-components-'. $type) . '">',
        '#suffix' => '</div>',
        '#type' => 'checkboxes',
        '#options' => $options,
        '#default_value' => $this->options['component_type'] == $type && isset($this->options['components']) ? $this->options['components'] : array(),
        '#dependency' => array('edit-options-component-type' => array($type)),
        '#description' => t('Choose which components to relate. If nothing is checked then all components of this type are used.'),
      );
    }

    // @TODO: add delta selection.
  }

  function options_submit(&$form, &$form_state) {
    // Just store the checked components of the selected type.
    $component_type = $form_state['values']['options']['component_type'];
    $components = array_filter($form_state['values']['options']['components'][$component_type]);
    $form_state['values']['options']['components'] = $components;
  }

  /**
   * Called to implement a relationship in a query.
   *
   * It respects the given component ids, provided via options form.
   */
  function query() {
    $components = $this->options['components'];

    // If nothing is selected we load them all.
    if (empty($components)) {
      $components = array();
      foreach (webform_component_instances() as $key => $data) {
        if ($data['type'] == $this->options['component_type'])
        $components[] = $key;
      }
    }

    // Add the extra to the definition to filter on component ids.
    if (count($components) == 1) {
      // For a single field avoid the concat and specify separate fields so we
      // can use the table's indexes.
      list($nid, $cid) = explode('-', reset($components));
      $this->definition['extra'] = array(
        array(
          'table' => NULL,
          'field' => "%alias.nid",
          'value' => $nid,
        ),
        array(
          'table' => NULL,
          'field' => "%alias.cid",
          'value' => $cid,
        )
      );
    }
    else {
      $this->definition['extra'] = array(
        array(
          'table' => NULL,
          'field' => "CONCAT(%alias.nid, '-', %alias.cid)",
          'value' => $components,
        ),
      );
    }

    // The rest of building the join is performed by the parent.
    parent::query();
  }
}
