<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Connections Block'),
  'description' => t('Display a particular connection based off of tags.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_connections_content_type_render'
);

function array_vals_multi($array,&$vals)
{
    foreach ($array as $key => $value) {

        if (is_array($value)) {
                
            array_vals_multi($value,$vals);
        
        }else{
            
            $vals[] = $value; 
        }
    }
 
    return $vals;
}

function dosomething_connections_content_type_render($subtype, $conf, $panel_args, $context) {

	$issues = (array) array_vals_multi($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_5[LANGUAGE_NONE]);
  $charities = (array) array_vals_multi($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_11[LANGUAGE_NONE]);
  $celebs = (array) array_vals_multi($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_6[LANGUAGE_NONE]);

  if (empty($issues)) { $tags = 0; }
  else { $tags = implode(',', $issues); }

  if (empty($charities)) { $chars = 0; }
  else { $chars = implode(',', $charities); }

  if (empty($celebs)) { $cels = 0; }
  else { $cels = implode(',', $celebs); }

/*SELECT GREATEST(IF(`tags`.`entity_id` IS NULL, 0, `tags`.`entity_id`), IF(`charities`.`entity_id` IS NULL, 0, `charities`.`entity_id`), IF(`celebs`.`entity_id` IS NULL, 0, `celebs`.`entity_id`)) AS `tid`, `dates`.`entity_id` AS `deid`
    FROM taxonomy_term_data
      LEFT OUTER JOIN field_data_field_connection_tags AS `tags` ON (`tags`.`field_connection_tags_tid` IN (" . $tags . "))
      LEFT OUTER JOIN `field_data_field_connection_charities` AS `charities` ON (`charities`.`field_connection_charities_tid` IN (" . $chars . "))
      LEFT OUTER JOIN `field_data_field_connection_celeb_names` AS `celebs` ON (`celebs`.`field_connection_celeb_names_tid` IN (" . $cels . "))
      LEFT JOIN `field_data_field_connection_run_dates` AS `dates` ON (1)
    WHERE IF(`dates`.field_connection_run_dates_value = `dates`.field_connection_run_dates_value2, 
      CONCAT(CURDATE(), ' ', CURTIME()) > `dates`.field_connection_run_dates_value,
      CONCAT(CURDATE(), ' ', CURTIME()) BETWEEN `dates`.field_connection_run_dates_value AND `dates`.field_connection_run_dates_value2
    )
    HAVING `deid` > 0
    ORDER BY tid ASC
    LIMIT 1*/

  $result = db_query("
    SELECT
  GREATEST(IF(`tags`.`entity_id` IS NULL, 0, `tags`.`entity_id`), IF(`charities`.`entity_id` IS NULL, 0, `charities`.`entity_id`), IF(`celebs`.`entity_id` IS NULL, 0, `celebs`.`entity_id`)) AS `tid`,
  TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset`, `dates`.field_connection_run_dates_value) AS date_start_real,
  TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset2`, `dates`.field_connection_run_dates_value2) AS date_end_real,
  `dates`.entity_id,
  `tags`.`entity_id` AS `ta`,
  `charities`.`entity_id` AS ch, `celebs`.`entity_id` AS ce,
  TIMESTAMPADD(HOUR, 1, CONCAT(CURDATE(), ' ', CURTIME())) BETWEEN TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset`, `dates`.field_connection_run_dates_value) AND TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset2`, `dates`.field_connection_run_dates_value2) AS `btw`,
  TIMESTAMPADD(HOUR, 1, CONCAT(CURDATE(), ' ', CURTIME())) > TIMESTAMPADD(SECOND, `dates`.`field_connection_run_dates_offset`, `dates`.field_connection_run_dates_value) AS `aft`,
  IF (`dates`.field_connection_run_dates_value = `dates`.field_connection_run_dates_value2, 1, 0) AS `eq`
    FROM taxonomy_term_data
      LEFT JOIN field_data_field_connection_tags AS `tags` ON (`tags`.`field_connection_tags_tid` IN (" . $tags . "))
      LEFT JOIN `field_data_field_connection_charities` AS `charities` ON (`charities`.`field_connection_charities_tid` IN (" . $chars . "))
      LEFT JOIN `field_data_field_connection_celeb_names` AS `celebs` ON (`celebs`.`field_connection_celeb_names_tid` IN (" . $cels . "))
      LEFT JOIN `field_data_field_connection_run_dates` AS `dates` ON (`dates`.`entity_id` = GREATEST(IF(`tags`.`entity_id` IS NULL, 0, `tags`.`entity_id`), IF(`charities`.`entity_id` IS NULL, 0, `charities`.`entity_id`), IF(`celebs`.`entity_id` IS NULL, 0, `celebs`.`entity_id`)))
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

  $block = new StdClass();
  $block->content = $content;
  return $block;
}
