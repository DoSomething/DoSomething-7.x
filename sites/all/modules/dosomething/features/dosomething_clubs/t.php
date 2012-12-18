<?php

$surveys = db_select('dosomething_clubs_tshirt_response', 't')
	->fields('t')
	->orderBy('nid', 'ASC')
	->execute();

$filename = 'clubs_tshirt_results.csv';
$h = array(
  'filename' => $filename,
  'file_path' => drupal_realpath('private://') . '/' . $filename
);

$field_labels = array(
  t('Club ID'),
  t('Cell'),
  t('T-shirt size'),
);

$handle = fopen($h['file_path'], 'w');
fputcsv($handle, $field_labels);

foreach ($surveys->fetchAll() AS $key => $s) {
	$row = array(
		'club id' => $s->nid,
		'cell' => $s->cell,
		'size' => $s->size,
	);

	fputcsv($handle, $row);
}

fclose($handle);

echo "Done T-shirts..";