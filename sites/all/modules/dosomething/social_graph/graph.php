<?php


$me_graph = array(
  'mike' => array(
    1 => array(
      'uy',
      'desmond',
      'barry',
      'chris',
    ),
  ),
  'barry' => array(
    1 => array(
      'mike',
      'max',
      'jacob',
      'chris',
    ),
  ),
  'chris' => array(
    1 => array(
      'barry',
      'gleb',
      'mike',
    ),
  ),
  'gleb' => array(
    1 => array(
      'chris',
      'keri',
    ),
  ),
  'keri' => array(
    1 => array(
      'gleb',
      'ben',
    ),
  ),
  'ben' => array(
    1 => array(
     'keri'
    ),
  ),
);


$steps = array();
$visited = $vname = array();
foreach ($me_graph AS $w => $de) {
  foreach ($de AS $deg => $connections) {
	$do = array();
	foreach ($connections AS $name) {
  	  if ($me_graph[$name]) {
		$do[] = $name;
	  }
	}

	connect_friends($w, $do, $w);
  }
}

$dee = array();
function connect_friends($started, $who, $to, $degree = 1) {
  global $me_graph, $visited, $steps;

  foreach ($who AS $name) {
	if (isset($me_graph[$name])) {
	   foreach ($me_graph[$name] AS $deg => $connections) {
		 if ($deg > 1) break;
		 $do = array();
		 $deeeg = ($degree + 1);
		 foreach ($connections AS $n) {
	  	   if ($n != $started && !$visited[$started][$n] && !is_numeric(array_search($n, $me_graph[$started][1]))) {
		 	 $visited[$started][$n] = $deeeg;
			 $me_graph[$started][$deeeg][] = array(
			 	'name' => $n,
			 	'know_through' => $name,
			 );
			 if ($me_graph[$n]) {
			    $do[] = $n;
			 }
		   }
		 }

		 connect_friends($started, $do, $started, $deeeg);
	   }
	}
  }
}
echo '<pre>', print_r($me_graph), '</pre>'; exit;