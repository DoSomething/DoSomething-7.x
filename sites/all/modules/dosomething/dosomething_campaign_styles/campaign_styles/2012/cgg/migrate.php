<?php

try {
    $node = new stdClass();
    $node->uid = 778374;
    $node->title = 'Celebs Gone Good - Choose a Celebrity';
    $node->log = '';
    $node->status = 1;
    $node->comment = 0;
    $node->promote = 0;
    $node->sticky = 0;
    $node->type = 'webform';
    $node->language = 'und';
    $node->created = 1354588046;
    $node->changed = 1354634383;
    $node->tnid = 0;
    $node->translate = 0;
    $node->revision_timestamp = 1354634383;
    $node->revision_uid = 778374;
    $node->body = array();
    $node->upload = array();
    $node->field_body_anonymous = array();
    $node->field_body_logged_in = array();
    $node->field_placeholder_replace = array(
        'und' => array(
            0 => array(
                'value' => 0
            )
        )
    );
    $node->field_webform_magic_fields = array();
    $node->group_audience = array();
    $node->field_mailchimp_group_id = array();
    $node->rdf_mapping = array(
            'rdftype' => array(
                0 => 'sioc:Item',
                1 => 'foaf:Document',
            ),

            'title' => array(
                'predicates' => array(
                        0 => 'dc:title',
                )
            ),

            'created' => array(
                'predicates' => array(
                        0 => 'dc:date',
                        1 => 'dc:created',
                ),
                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601',
            ),

            'changed' => array(
                'predicates' => array(
                    0 => 'dc:modified',
                ),
                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601',
            ),

            'body' => array(
                'predicates' => array(
                    0 => 'content:encoded',
                )
            ),

            'uid' => array(
                'predicates' => array(
                    0 => 'sioc:has_creator',
                ),
                'type' => 'rel',
            ),

            'name' => array(
                'predicates' => array(
                    0 => 'foaf:name',
                )
            ),

            'comment_count' => array(
                'predicates' => array(
                        0 => 'sioc:num_replies',
                ),
                'datatype' => 'xsd:integer',
            ),

            'last_activity' => array(
                'predicates' => array(
                    0 => 'sioc:last_activity_date',
                ),

                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601'
            ),
    );

    $node->webform = array
    (
            'confirmation' => '',
            'teaser' => 0,
            'submit_text' => '',
            'submit_limit' => -1,
            'submit_interval' => -1,
            'additional_validate' => '',
            'additional_submit' => '',
            'confirmation_format' => '',
            'submit_notice' => 0,
            'allow_draft' => 0,
            'redirect_url' => '',
            'block' => 0,
            'status' => 1,
            'auto_save' => 0,
            'total_submit_limit' => -1,
            'total_submit_interval' => -1,
            'webform_entity_data' => 'a:2:{s:22:"field_webform_pictures";a:2:{s:6:"weight";s:1:"0";s:3:"pid";s:1:"0";}s:20:"field_webform_videos";a:2:{s:6:"weight";s:1:"0";s:3:"pid";s:1:"0";}}',
            'record_exists' => 1,
            'roles' => array(
                    0 => 1,
                    1 => 2,
            ),

            'emails' => array(),
            'components' => array(
                1 => array(
                        'nid' => '725016',
                        'cid' => 1,
                        'pid' => 0,
                        'form_key' => 'cgg_choose_a_celebrity',
                        'name' => 'Choose a celebrity',
                        'type' => 'select',
                        'value' => '',
                        'extra' => array(
                                'items' => '9482|Scarlett Johannson',
                                'options_source' => 'celebs',
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
                                'conditional_component' => '',
                                'conditional_values' => '',
                        ),

                        'mandatory' => 1,
                        'weight' => 0,
                        'page_num' => 1,
                )
            )
    );

    $node->print_display = 1;
    $node->print_display_comment = 0;
    $node->print_display_urllist = 1;
    $node->name = 'Michael Chittenden';
    $node->picture = 201592;
    $node->data = 'b:0';
    $node->print_mail_display = 1;
    $node->print_mail_display_comment = 0;
    $node->print_mail_display_urllist = 1;
    $node->entity_view_prepared = 1;
    $node->content = array(
            '#pre_render' => array(
                    0 => '_field_extra_fields_pre_render',
                    1 => 'field_group_build_pre_render'
            ),

            '#entity_type' => 'node',
            '#bundle' => 'webform',
            '#groups' => array(),
            '#fieldgroups' => array(),
            '#group_children' => array(),
            'links' => array(
                    '#theme' => 'links__node',
                    '#pre_render' => array(
                            0 => 'drupal_pre_render_links',
                    ),

                    '#attributes' => array(
                            'class' => array(
                                    0 => 'links',
                                    1 => 'inline'
                            )

                    ),

                    'node' => array(
                            '#theme' => 'links__node__node',
                            '#links' => array(),
                            '#attributes' => array(
                                    'class' => array(
                                            0 => 'links',
                                            1 => 'inline'
                                    )

                            )

                    )

            )

    );

    echo "Saving node...";
    node_save($node);
    print_r($node);

    echo "Saved.  Creating taxonmy...";
    $taxonomy = array(
        'name' => 'Celebs Gone Good Celebrities',
        'machine_name' => 'celebs_gone_good_celebrities',
        'description' => 'Celebs Gone Good Celebrities',
        'module' => 'taxonomy',
        'hierarchy' => 1,
        'weight' => 1,
    );

    taxonomy_vocabulary_save((object) $taxonomy);
    echo "Created taxonomy.  Creating fields for taxonomy...";

    $field = array(
        'field_name' => 'ccg_celeb_image',
        'type' => 'image',
        'label' => 'Celeb Image',
    );

    field_create_field($field);

    $instance = array(
        'field_name' => 'ccg_celeb_image',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'celebs_gone_good_celebrities',
        'label' => 'Label',
        'description' => 'Celeb Image',
        'required' => TRUE,
        'widget' => array(
            'type' => 'image_image',
            'weight' => 3
        ),
    );

    field_create_instance($instance);

    echo "Done.";
    drupal_exit();
}
catch (Exception $e) {
    echo "\r\n";
    echo $e->getMessage();
    drupal_exit();
}