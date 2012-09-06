<?php

function dosomething_clubs_club_member_list_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething Club Members List'),
    'description' => t('Club Members List'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
  );
}

function dosomething_clubs_club_member_list_content_type_render($subtype, $conf, $panel_args, $context) {
	$gid = og_get_group('node', $context->data->nid)->gid;

	$query = db_query("
		SELECT DISTINCT users.picture AS users_picture, users.uid AS uid, users.name AS users_name, users.mail AS users_mail, profile_users.pid AS profile_users_pid, og_membership_users.created AS og_membership_users_created,
			`pfn`.`field_user_first_name_value` AS `first_name`,
			`pln`.`field_user_last_name_value` AS `last_name`
		FROM 
		`users` users
		LEFT JOIN `og_membership` og_membership_users ON users.uid = og_membership_users.etid AND og_membership_users.entity_type = 'user'
		LEFT JOIN `og` og_og_membership ON og_membership_users.gid = og_og_membership.gid
		LEFT JOIN `profile` profile_users ON profile_users.uid = og_membership_users.etid
		LEFT JOIN `field_data_field_user_first_name` AS `pfn` ON (`pfn`.`entity_id` = `profile_users`.`pid`)
		LEFT JOIN `field_data_field_user_last_name` AS `pln` ON (`pln`.`entity_id` = `profile_users`.`pid`)
		WHERE (( (og_membership_users.gid = '" . $gid . "' ) ))
		ORDER BY og_membership_users_created DESC
		LIMIT 4 OFFSET 0
	")->fetchAll();

	$block = new stdClass();
	$output['title'] = array(
		'#markup' => '<h2 class="pane-title" style="margin-bottom: 15px;">Club Members</h2>'
	);

	foreach ($query AS $key => $data) {
		$output['member_links'][] = array(
			'#markup' => '
			<div style="clear: both; margin: 0px 5px 35px 10px">
				<div class="views-field views-field-picture" style="float: left; margin-right: 5px;">        <div class="field-content"><img typeof="foaf:Image" src="/files/styles/project_related_thumb/public/default-profile-picture.jpg" width="60" height="60" alt="" /></div>  </div>  
	  			<div class="views-field views-field-field-user-full-name">        <div class="field-content">' . (trim($data->first_name . ' ' . substr($data->last_name, 0, 1)) ? $data->first_name . ' ' . substr($data->last_name, 0, 1) : 'Anonymous') . '</div>  </div>  
	  			<div class="views-field views-field-created"><span class="field-content">Joined ' . date('m/Y', $data->og_membership_users_created) . ' </span>  </div>
	  		</div>
	  			'
		);
	}

	$output['more_link'] = array(
		'#markup' => l(t('More >>'), '#', array(
			'attributes' => array('class' => array('member-popup-trigger'))
		)),
		'#prefix' => '<p style="text-align: right">',
		'#suffix' => '</p>'
	);
	$block->content = $output;
	return $block;
}