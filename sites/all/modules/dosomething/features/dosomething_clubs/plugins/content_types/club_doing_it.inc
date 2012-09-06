<?php

function dosomething_clubs_club_doing_it_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething Club Doing It Block'),
    'description' => t('List of "Doing It" stuff.'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
  );
}

function dosomething_clubs_club_doing_it_content_type_render($subtype, $conf, $panel_args, $context) {
	$gid = og_get_group('node', $context->data->nid)->gid;

	$query = db_query("(
  SELECT
    node_field_data_field_campaign_list.nid AS `nid`,
    0 AS `sid`,
    1 AS `is_node`,
    `node`.`created` AS `submitted`,
    node_field_data_field_campaign_list.title AS `title`,
    `img`.`field_campaign_promo_image_fid` AS `fid`
FROM 
`node` node
LEFT JOIN `field_data_field_campaign_list` field_data_field_campaign_list ON node.nid = field_data_field_campaign_list.entity_id AND (field_data_field_campaign_list.entity_type = 'node' AND field_data_field_campaign_list.deleted = '0')
LEFT JOIN `node` node_field_data_field_campaign_list ON field_data_field_campaign_list.field_campaign_list_nid = node_field_data_field_campaign_list.nid
LEFT JOIN `field_data_field_campain_logo_thumbnail` node_field_data_field_campaign_list__field_data_field_campain_logo_thumbnail ON node_field_data_field_campaign_list.nid = node_field_data_field_campaign_list__field_data_field_campain_logo_thumbnail.entity_id AND (node_field_data_field_campaign_list__field_data_field_campain_logo_thumbnail.entity_type = 'node' AND node_field_data_field_campaign_list__field_data_field_campain_logo_thumbnail.deleted = '0')
LEFT JOIN `file_managed` file_managed_field_data_field_campain_logo_thumbnail ON node_field_data_field_campaign_list__field_data_field_campain_logo_thumbnail.field_campain_logo_thumbnail_fid = file_managed_field_data_field_campain_logo_thumbnail.fid
LEFT JOIN `field_data_field_campaign_promo_image` AS `img` ON (`img`.`entity_id` = field_data_field_campaign_list.field_campaign_list_nid)
LEFT JOIN `og_membership` og_membership_node ON node.nid = og_membership_node.etid AND og_membership_node.entity_type = 'node'
WHERE (( (node.nid = '" . $context->data->nid . "' ) )AND(( (node.status = '1') )AND( (node.type IN  ('club')) )))
ORDER BY `submitted` DESC
LIMIT 5 OFFSET 0)
UNION (
SELECT
  webform_submissions.nid AS `nid`,
  webform_submissions.sid AS `sid`,
  0 AS `is_node`,
  webform_submissions.submitted AS `submitted`,
  `pt`.`field_project_title_value` AS `title`,
  `img`.`field_picture_fid` AS `fid`
FROM 
`webform_submissions` webform_submissions
LEFT JOIN `users` users_webform_submissions ON webform_submissions.uid = users_webform_submissions.uid
LEFT JOIN `og_membership` og_membership_users ON users_webform_submissions.uid = og_membership_users.etid AND og_membership_users.entity_type = 'user'
LEFT JOIN `og` og_og_membership ON og_membership_users.gid = og_og_membership.gid
LEFT JOIN `node` node ON webform_submissions.nid = node.nid
LEFT JOIN `field_data_field_project_type` field_data_field_project_type ON webform_submissions.sid = field_data_field_project_type.entity_id AND (field_data_field_project_type.entity_type = 'webform_submission_entity' AND field_data_field_project_type.deleted = '0')
LEFT JOIN `field_data_field_project_title` AS `pt` ON (`pt`.`entity_id` = `webform_submissions`.`sid`)
LEFT JOIN `field_data_field_picture` AS `img` ON (`img`.`entity_id` = `webform_submissions`.`nid`)
WHERE (( (og_membership_users.gid = '" . $gid . "' ) )AND(( (node.type IN  ('project_report')) AND (field_data_field_project_type.field_project_type_value IN  ('2', '3')) )))
ORDER BY `submitted` DESC
LIMIT 4 OFFSET 0)")->fetchAll();

	$block = new stdClass();
	$output['title'] = array(
		'#markup' => '<h2 class="pane-title" style="margin-bottom: 15px;">Doing It</h2>'
	);

	foreach ($query AS $key => $data) {
		if (!$data->title) continue;
		$file = file_load($data->fid);
		$image = theme('image_style', array('path' => $file->uri, 'style_name' => 'project_related_thumb'));
		$link = ($data->is_node ? drupal_lookup_path('alias', 'node/' . $data->nid) : drupal_lookup_path('alias', 'webform-submission/' . $data->sid));

		$output['member_links'][] = array(
			'#markup' => '
			<div style="clear: both; height: 60px; margin: 0px 5px 10px 10px">
				<div class="views-field views-field-picture" style="float: left; margin-right: 5px;"><div class="field-content">' . $image . '</div>  </div>  
	  			<div class="views-field views-field-field-user-full-name"><div class="field-content">' . l($data->title, $link) . '</div></div>
	  		</div>
	  			'
		);
	}
	$block->content = $output;
	return $block;
}