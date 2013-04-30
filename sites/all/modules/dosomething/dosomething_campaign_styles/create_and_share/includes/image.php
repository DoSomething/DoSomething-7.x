<?php

/**
 *  Writes text to an image.  Takes the width and height of the image and places letter boxing
 *  on the top and bottom of the image according to how much text the user input.  This function
 *  takes the font file defined in the settings, and physically overwrites the image file with
 *  the text that the user writes.
 *
 *  @param array $settings
 *    An array of settings about the image writing process.  The array should be formatted as follows:
 *      image_writing = array(
 *         'enabled' => (bool) true|false,
 *         'font' => 'font_file.ttf' // found in sites/all/modules/dosomething/dosomething_campaign_styles/create_and_share/fonts  
 *       )
 *
 *  @param string $image_uri
 *    The relative URI to the image file that will be overwritten.
 *
 *  @param string $top_text
 *    The text that will appear at the top of the image.
 *
 *  @param string $bottom_text
 *    The text that will appear at the bottom of the image.
 *
 *  @param int $image_width
 *    The width of the image in question.
 *
 *  @param int $font_size
 *    The font size to use, given teh font file that will write the text.
 *
 *  @param int $break_limit
 *    How many characters into a string should it break?
 *
 *  @param bool $debug
 *    If true, does *not* overwrite the image, and instead shows the finished, processed image.
 *
 *  @return mixed
 *    If not in debug mode, returns the image exif data for overwriting later.  If in debug mode, shows the image.
 *
 */
function write_text_to_image($settings, $image_uri, $top_text, $bottom_text, $image_width = 480, $font_size = 25, $break_limit = 35, $debug = false) {
  // One final check to make sure that this is even enabled.
  if (!$settings['image_writing']['enabled']) {
    return;
  }

  $font = DRUPAL_ROOT . '/' . drupal_get_path('module', 'create_and_share') . '/fonts/' . $settings['image_writing']['font'];
  // No need to do anything if there is no text.
  if (empty($top_text) && empty($bottom_text)) {
    return;
  }

  // Ignore if the file doesn't exist.
  if (!file_exists($image_uri)) {
    return;
  }

  // Get image extension
  $pathinfo = pathinfo($image_uri);
  $pathinfo['extension'] = strtolower($pathinfo['extension']);

  // Set up the correct header(s) for the image.
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

  // Colors
  $white = imagecolorallocate($image, 255, 255, 255);
  $black = imagecolorallocate($image, 0, 0, 0);

  // Make sure that the text is all uppercase
  $upper_text = strtoupper($top_text);
  $lower_text = strtoupper($bottom_text);

  // This function puts a dropshadow behind the text.
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

  // Sets up the upper text
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

  // Sets up the lower text.
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

  // Return the exif data of this image, so it can be overwritten later.
  if (!$debug) {
    ob_start();
    $end_func($image);
    $c = ob_get_contents();
    ob_end_clean();
  }
  // If in debug mode, show the image.
  else {
    // Set the header to view
    header('Content-Type: ' . $end_header);

    // Show the image.
    $end_func($image);

    // We actually want to exit.  No need for Drupal finishing touches because we're debugging.
    exit;
  }

  // Overwrite the original image.
  $i = 'public://styles/' . $settings['fields']['picture']['style'] . '/public/' . $settings['fields']['picture']['directory'] . '/' . basename($image_uri);
  file_unmanaged_save_data($c, $i, FILE_EXISTS_REPLACE);
}
