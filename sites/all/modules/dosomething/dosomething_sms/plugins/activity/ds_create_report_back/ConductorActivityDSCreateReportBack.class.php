<?php

/**
 * This is the first activity in any workflow.
 */
class ConductorActivityDSCreateReportBack extends ConductorActivity {

  public function option_definition() {
    $options = parent::option_definition();
    // The attribute to set in context.
    return $options;
  }

  /**
   * Create a user object from the context built up during this workflow run.
   */
  public function run() {
    $state = $this->getState();

    $firstName = $state->getContext('first_name:message');
    $lastName = $state->getContext('last_name:message');
    $birthDate = $state->getContext('birthday:message');
    $mobile = $state->getContext('sms_number');

    $submission = new stdClass;
    $submission->bundle = 'project_report';
    $submission->nid = 718313;
    $submission->data = array();
    // TODO: try to look up the uid from the phone number.
    $submission->uid = 0;
    $submission->submitted = REQUEST_TIME;
    $submission->remote_addr = ip_address();
    $submission->is_draft = TRUE;
    $submission->sid = NULL;

    $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);

    $wrapper->field_project_title->set($state->getContext('title:message'));
    $wrapper->field_project_goal->set($state->getContext('goal:message'));
    $wrapper->field_update_people_involved->set($state->getContext('involved:message'));
    $wrapper->field_num_people_impacted->set($state->getContext('helped:message'));

    $state->setContext('sms_response', 'Thanks!  We are thrilled to hear about your project!');

    $wrapper->save();

    $state->markCompeted();
  }

}
