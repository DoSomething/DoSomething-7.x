<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Connections'),
  'description' => t('Display a particular connection based off of tags.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_connections_content_type_render'
);

function dosomething_connections_content_type_render($subtype, $conf, $panel_args, $context) {

  if (isset($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_5[LANGUAGE_NONE])) {
		
	  foreach ($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_5[LANGUAGE_NONE] as $key => $value) {
      $issues[$key] = $value['tid'];
    }
    $tags = implode(',', $issues);
	
		$result = db_query("
			SELECT
				`tags`.`entity_id` AS `tid`,
				TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset`, `dates`.field_connection_run_dates_value) AS date_start_real,
				TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset2`, `dates`.field_connection_run_dates_value2) AS date_end_real,
			 `dates`.entity_id,
			 `tags`.`entity_id` AS `ta`,
				TIMESTAMPADD(HOUR, 1, CONCAT(CURDATE(), ' ', CURTIME())) BETWEEN TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset`, `dates`.field_connection_run_dates_value) AND TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset2`, `dates`.field_connection_run_dates_value2) AS `btw`,
				TIMESTAMPADD(HOUR, 1, CONCAT(CURDATE(), ' ', CURTIME())) > TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset`, `dates`.field_connection_run_dates_value) AS `aft`,
		IF (`dates`.field_connection_run_dates_value = `dates`.field_connection_run_dates_value2, 1, 0) AS `eq`
	
			FROM taxonomy_term_data
				LEFT JOIN field_data_field_connection_tags AS `tags` ON (`tags`.`field_connection_tags_tid` IN (" . $tags . "))
				LEFT JOIN `field_data_field_connection_run_dates` AS `dates`
		ON `dates`.`entity_id` = `tags`.`entity_id`
	
		HAVING (
					 (`eq` = 1 AND `aft` = 1)
					 OR (`btw` = 1)
				 )
	
			ORDER BY `tid` ASC
			LIMIT 1
			")->fetchAssoc();
	
		if (!empty($result)) {
			$tid = $result['tid'];
			$term = taxonomy_term_load($tid);
			$content = array();
			$img = theme('image', array('path' => $term->field_connection_image[LANGUAGE_NONE][0]['uri'], 'height' => '100px', 'width' => '550px'));
	
			$content[] = array(
				'#markup' => l($img, $term->field_connection_url[LANGUAGE_NONE][0]['value'], array('html' => TRUE))
			);
		}
		else {
			$content[] = array(
				'#markup' => ''
			);
		}
		
	}
	else {
		$content[] = array(
			'#markup' => ''
		);
	}
	
	$block = new StdClass();
	$block->content = $content;
	return $block;

}