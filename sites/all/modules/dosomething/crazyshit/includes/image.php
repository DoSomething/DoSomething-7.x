<?php

function write_text_to_image($image_uri, $top_text, $bottom_text, $image_width = 480, $font_size = 25, $break_limit = 35, $debug = false) {
	$font = DRUPAL_ROOT . '/' . drupal_get_path('module', 'crazyshit') . '/fonts/DINComp-CondBold.ttf';
	// No need to do anything if there is no text.
	if (empty($top_text) && empty($bottom_text)) {
		return;
	}

	// Ignore if the file doesn't exist.
	if (!file_exists($image_uri)) {
		return;
	}

	$pathinfo = pathinfo($image_uri);
	$pathinfo['extension'] = strtolower($pathinfo['extension']);

	$end_func = $end_header = '';
	if ($pathinfo['extension'] == 'png') {
		$image = imagecreatefrompng($image_uri);
		$end_func = 'imagepng';
		$end_header = 'image/png';
	}
	else if ($pathinfo['extension'] == 'gif') {
		$image = imagecreatefromgif($image_uri);
		$end_func = 'imagegif';
		$end_header = 'image/gif';
	}
	else if (in_array($pathinfo['extension'], array('jpg', 'jpeg'))) {
		$image = imagecreatefromjpeg($image_uri);
		$end_func = 'imagejpeg';
		$end_header = 'image/jpeg';
	}

	$white = imagecolorallocate($image, 255, 255, 255);
	$black = imagecolorallocate($image, 0, 0, 0);

	$upper_text = strtoupper($top_text);
	$lower_text = strtoupper($bottom_text);

	if (!function_exists('imagettfstroketext')) {
		function imagettfstroketext(&$image, $size, $angle, $x, $y, &$textcolor, &$strokecolor, $fontfile, $text, $px) {
		  for($c1 = ($x-abs($px)); $c1 <= ($x+abs($px)); $c1++) {
		    for($c2 = ($y-abs($px)); $c2 <= ($y+abs($px)); $c2++) {
		       $bg = imagettftext($image, $size, $angle, $c1, $c2, $strokecolor, $fontfile, $text);
		    }
		  }

		  return imagettftext($image, $size, $angle, $x, $y, $textcolor, $fontfile, $text);
		}
	}

	/**
	 *	Upper text
	 */
	if (!empty($upper_text)) {
        	$break = wordwrap($upper_text, $break_limit, '\n', true);
        	$a = explode('\n', $break);
        	$default_height = 6;
        
        	// In theory all lines should be the same height, because they're all
        	// uppercase and all the same font face.  Let's just get the first line's
        	// bounding box and use that to define the line height
        	$box = imagettfbbox($font_size, 0, $font, $a[0]);
        	// Height = greater Y (lower left) - lesser Y (upper left)
        	$line_height = ($box[0] - $box[7]) + $default_height;
        
        	$height = count($a) * $line_height + $default_height;
        
        	$top = imagecreate($image_width, $height);
        	imagecopymerge($image, $top, 0, 0, 0, 0, $image_width, $height, 25);
        
        	$i = 1;
        	foreach ($a AS $line) {
        		$bbox = imagettfbbox($font_size, 0, $font, $line);
        
        		// 6 = top left
        		// 4 = top right
        		$size = imagesx($image);
        		$width = ($bbox[4] - $bbox[6]);
        		$centered = $width / 2;
        		$c = $size / 2;
        
        		imagettfstroketext($image, $font_size, 0, ($c - $centered), ($i * $line_height), $white, $black, $font, $line, 1);
        		$i++;
        	}
	}

	/**
	 *	Lower text
	 */

	if (!empty($lower_text)) {
		$break = wordwrap($lower_text, $break_limit, '\n', true);
		$a = explode('\n', $break);
	
		$height = count($a) * $line_height + $default_height;
		$bottom = imagecreate($image_width, $height);
		imagecopymerge($image, $bottom, 0, (imagesy($image) - $height), 0, 0, $image_width, $height, 25);
	
	
		$i = 1;
		foreach ($a AS $line) {
			$bbox = imagettfbbox($font_size, 0, $font, $line);
	
			// 6 = top left
			// 4 = top right
			$size = imagesx($image);
			$width = ($bbox[4] - $bbox[6]);
			$centered = $width / 2;
			$c = $size / 2;
	
			imagettfstroketext($image, $font_size, 0, ($c - $centered), (imagesy($image) - $height) + ($i * $line_height), $white, $black, $font, $line, 1);
			$i++;
		}
	}

	if (!$debug) {
		ob_start();
		$end_func($image);
		$c = ob_get_contents();
		ob_end_clean();
	}
	else {
		// Set the header to view
		header('Content-Type: ' . $end_header);

		// Show the image.
		$end_func($image);

		// We actually want to exit.  No need for Drupal finishing touches because we're debugging.
		exit;
	}

	$i = 'public://styles/crazy_image_dimensions/public/crazyshit/' . basename($image_uri);
	#file_unmanaged_delete($i);
	file_unmanaged_save_data($c, $i, FILE_EXISTS_REPLACE);
}
