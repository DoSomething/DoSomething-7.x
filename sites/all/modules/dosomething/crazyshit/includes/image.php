<?php

function write_text_to_image($image_uri, $top_text, $bottom_text, $image_width = 480, $font = '/var/www/html/qa2/sites/all/modules/dosomething/crazyshit/fonts/DINComp-CondBold.ttf') {
	// No need to do anything if there is no text.
	if (empty($top_text) && empty($bottom_text)) {
		return;
	}

	$pathinfo = pathinfo($image_uri);
	$pathinfo['extension'] = strtolower($pathinfo['extension']);

	if ($pathinfo['extension'] == 'png') {
		$image = imagecreatefrompng($image_uri);
		$end_func = 'imagepng';
	}
	else if ($pathinfo['extension'] == 'gif') {
		$image = imagecreatefromgif($image_uri);
		$end_func = 'imagegif';
	}
	else if (in_array($pathinfo['extension'], array('jpg', 'jpeg'))) {
		$image = imagecreatefromjpeg($image_uri);
		$end_func = 'imagejpeg';
	}

	$white = imagecolorallocate($image, 255, 255, 255);
	$black = imagecolorallocate($black, 0, 0, 0);

	$upper_text = strtoupper($top_text);
	$lower_text = strtoupper($bottom_text);

	function imagettfstroketext(&$image, $size, $angle, $x, $y, &$textcolor, &$strokecolor, $fontfile, $text, $px) {
	  for($c1 = ($x-abs($px)); $c1 <= ($x+abs($px)); $c1++) {
	    for($c2 = ($y-abs($px)); $c2 <= ($y+abs($px)); $c2++) {
	       $bg = imagettftext($image, $size, $angle, $c1, $c2, $strokecolor, $fontfile, $text);
	    }
	  }

	  return imagettftext($image, $size, $angle, $x, $y, $textcolor, $fontfile, $text);
	}

	/**
	 *	Upper text
	 */
	$break = wordwrap($upper_text, 35, '\n', true);
	$a = explode('\n', $break);
	$height = 6;
	foreach ($a AS $l) {
		$box = imagettfbbox(20, 0, $font, $l);
		// Height = greater Y (lower left) - lesser Y (upper left)
		$height += ($box[0] - $box[7]) + 6; 
	}

	$top = imagecreate($image_width, $height);
	imagecopymerge($image, $top, 0, 0, 0, 0, $image_width, $height, 25);

	$i = 1;
	foreach ($a AS $line) {
		$bbox = imagettfbbox(20, 0, $font, $line);

		// 6 = top left
		// 4 = top right
		$size = imagesx($image);
		$width = ($bbox[4] - $bbox[6]);
		$centered = $width / 2;
		$c = $size / 2;

		imagettfstroketext($image, 20, 0, ($c - $centered), ($i * 25), $white, $black, $font, $line, 1);
		$i++;
	}

	/**
	 *	Lower text
	 */
	$break = wordwrap($lower_text, 35, '\n', true);
	$a = explode('\n', $break);

	$height = 6;
	foreach ($a AS $l) {
		$box = imagettfbbox(20, 0, $font, $l);
		// Height = greater Y (lower left) - lesser Y (upper left)
		$height += ($box[0] - $box[7]) + 6; 
	}
	$bottom = imagecreate($image_width, $height);
	imagecopymerge($image, $bottom, 0, (imagesy($image) - $height), 0, 0, $image_width, $height, 25);


	$i = 1;
	foreach ($a AS $line) {
		$bbox = imagettfbbox(20, 0, $font, $line);

		// 6 = top left
		// 4 = top right
		$size = imagesx($image);
		$width = ($bbox[4] - $bbox[6]);
		$centered = $width / 2;
		$c = $size / 2;

		imagettfstroketext($image, 20, 0, ($c - $centered), (imagesy($image) - $height) + ($i * 25), $white, $black, $font, $line, 1);
		$i++;
	}

	ob_start();
	$end_func($image);
	$c = ob_get_contents();
	ob_end_clean();

	$i = 'public://styles/crazy_image_dimensions/public/crazyshit/' . basename($image_uri);
	#file_unmanaged_delete($i);
	file_unmanaged_save_data($c, $i, FILE_EXISTS_REPLACE);
}
