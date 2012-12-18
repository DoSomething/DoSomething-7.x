<?php

$surveys = db_select('dosomething_clubs_survey', 's')
	->fields('s')
	->orderBy('nid', 'ASC')
	->execute();

$filename = 'clubs_survey_results.csv';
$h = array(
  'filename' => $filename,
  'file_path' => drupal_realpath('private://') . '/' . $filename
);

$field_labels = array(
  t('Club ID'),
  t('Replied Y?'),
  t('Cell'),
  t('Survey answer'),
  t('Followup survey answer 1'),
  t('Followup survey answer 2'),
  t('Followup survey answer 3'),
  t('Followup survey answer 4'),
  t('Followup survey answer 5'),
  #t('Time'),
);

$handle = fopen($h['file_path'], 'w');
fputcsv($handle, $field_labels);

foreach ($surveys->fetchAll() AS $key => $s) {
	$followup = unserialize($s->followup);

	if (count($followup) == 5) {
		$f = array(
			1 => $followup['awesome'],
			2 => $followup['active'],
			3 => $followup['focus'],
			4 => $followup['specifics'],
			5 => $followup['advice'],
		);
	}
	else {
		$f = array(
			1 => $followup['awesome'],
			2 => $followup['active'],
			3 => $followup['focus'],
			4 => '',
			5 => $followup['advice'],
		);
	}

	$row = array(
		'club id' => $s->nid,
		'replied y' => $s->replied_y,
		'cell' => $s->cell,
		'survey answer' => implode('', unserialize($s->survey)),
	) + $f;

	fputcsv($handle, $row);
}

fclose($handle);

echo "Fini.";