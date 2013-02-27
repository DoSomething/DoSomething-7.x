<?php

// The title of the product
$robocalls = array(
	'title' => 'Project Prank - Pranking Your Friends for Good',

	'css' => array(
		// Matches anything under /prank
		'prank' => array(
			'robocalls.css',
		),
	),

	'js' => array(
		// Matches anything under /prank
		'prank' => array(
			'robocalls.js',
		),
		// Only shows on the front page of /prank.
		'prank(/[0-9]+)?$' => array(
			'robocalls_front.js',
		),
		// Only shows on celebrity pages.
		'prank/(?=[A-Za-z0-9\-\_ ]+)(?!walkthrough)' => array(
			'robocalls_celeb.js',
		),
	),
);

?>