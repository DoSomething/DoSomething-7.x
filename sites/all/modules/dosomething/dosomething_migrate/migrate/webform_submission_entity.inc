<?php

class MigrateDestinationWebformSubmissionEntity extends MigrateDestinationEntity {
  static public function getKeySchema() {
    return array(
      'sid' => array(
        'type' => 'int',
        'not null' => TRUE,
        'unsigned' => TRUE,
      ),
    );
  }

  /**
   * The webform of the destination.
   *
   * @var string
   */
  protected $node;
  public function getWebform() {
    return $this->node;
  }

  /**
   * An array mapping our custom names to component ids.
   *
   * @var array
   */
  protected $component_cids;

  public function __construct($node, array $options = array()) {
    // Make sure it's a webform node.
    $types = webform_variable_get('webform_node_types');
    if (!in_array($node->type, $types)) {
      throw new Exception(t('Must provide a webform node.'));
    }
    $this->node = $node;

    parent::__construct('webform_submission_entity', $node->type, $options);

    // Webform expects the component values to be keyed by cid, so we need a
    // hash to map prefixed field names to cid.
    $this->component_cids = array();
    foreach ($this->node->webform['components'] as $component) {
      $this->component_cids['data_' . $component['form_key']] = $component['cid'];
    }

    // We use the functions in this file in import() but load it here so we
    // only do it once.
    module_load_include('inc', 'webform', 'includes/webform.submissions');
  }

  /**
   * Returns a list of fields available to be mapped/
   *
   * @return array
   *   Keys: machine names of the fields (to be passed to addFieldMapping)
   *   Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    // Fields defined by the schema. nid is omitted since it should come from
    // $this->node.
    $fields = array(
      'sid' => 'The unique identifier for this submission.',
      'uid' => 'The id of the user that completed this submission.',
      'is_draft' => 'Is this a draft of the submission?',
      'submitted' => 'Timestamp of when the form was submitted.',
      'remote_addr' => 'The IP address of the user that submitted the form.',
    );

    // Create a field for each component on the webform.
    foreach ($this->node->webform['components'] as $component) {
      // TODO: Seems like we should skip over page break components.
      $fields['data_' . $component['form_key']] = t('@type: @name', array('@type' => $component['type'], '@name' => $component['name']));
    }

    // Then add in anything provided by handlers.
    $fields += migrate_handler_invoke_all('WebformSubmission', 'fields', $this->node);
    $fields += migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle);

    return $fields;
  }

  /**
   * Import a record.
   *
   * @param $entity
   *   Webform submission object to build. This is the complete object after
   *   saving.
   * @param $source_row
   *   Raw source data object - passed through to complete handlers.
   */
  public function import(stdClass $entity, stdClass $row) {
    // Updating previously-migrated content?
    $migration = Migration::currentMigration();
    if (isset($row->migrate_map_destid1)) {
      if (isset($entity->sid) && $entity->sid != $row->migrate_map_destid1) {
        throw new MigrateException(t("Incoming sid !sid and map destination sid !destid1 don't match",
          array('!sid' => $entity->sid, '!destid1' => $row->migrate_map_destid1)));
      }
      else {
        $entity->sid = $row->migrate_map_destid1;
      }
    }

    $entity->nid = $this->node->nid;
    $entity->bundle = $this->bundle;

    // Move the data from our custom keys back to webform's component ids.
    $data = array();
    foreach ($this->component_cids as $field_name => $cid) {
      if (isset($entity->$field_name)) {
        $data[$cid] = $entity->$field_name;
      }
      unset($entity->$field_name);
    }
    $entity->data = webform_submission_data($this->node, $data);

    // Invoke migration prepare handlers
    $this->prepare($entity, $row);

    migrate_instrument_start('webform_submission_update/insert');
    // Determine if it's an insert or update.
    if (empty($entity->sid)) {
      $sid = webform_submission_insert($this->node, $entity);
    }
    else {
      // If the sid was specified but doesn't exist we'll need to stick an
      // empty record in so the update has something to stick to.
      db_merge('webform_submissions')
        ->key(array(
          'sid' => $entity->sid,
          'nid' => $entity->nid,
        ))
        ->insertFields(array(
          'sid' => $entity->sid,
          'nid' => $entity->nid,
          'submitted' => $entity->submitted,
          'remote_addr' => $entity->remote_addr,
          'is_draft' => $entity->is_draft,
          'bundle' => $entity->bundle,
        ))
        ->execute();
      $sid = webform_submission_update($this->node, $entity);
    }
    migrate_instrument_stop('webform_submission_update/insert');

    if (isset($sid)) {
      $entity->sid = $sid;

      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      $return = array($sid);
    }
    else {
      $return = FALSE;
    }

    // Invoke migration complete handlers
    $this->complete($entity, $row);

    return $return;
  }

  /**
   * Delete a batch of submissions at once.
   *
   * @param $sids
   *   Array of submission IDs to be deleted.
   */
  public function bulkRollback(array $sids) {
    migrate_instrument_start(__METHOD__);
    $this->prepareRollback($sids);
    foreach (webform_get_submissions(array('sid' => $sids)) as $submission) {
      webform_submission_delete($this->node, $submission);
    }
    $this->completeRollback($sids);
    migrate_instrument_stop(__METHOD__);
  }
}