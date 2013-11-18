<?php

/**
 * @file
 * Sets up the share a stat color profiles.  This file is directly correlated
 * with the "Linked campaign" and "Color scheme" fields in the SaS edit forms.
 *
 * @see dosomething_social_scholars.module lines 176-209.
 */

/**
 * @var array $campaign_styles
 *   Directly related to the "Linked campaign" field on the SaS forms.  The key
 *   here is the NID of the campaign that is related to the Share a Stat.  The
 *   array is an aray of arrays, including the 'longform' array and the
 *   'shortform' array.  The 'longform' is the form that users see on the actaul
 *   Share a Stat page.  The 'shortform' is likely unused from now on, but was
 *   basically a small bordered box with name and email.
 *
 *   The campaign profile should follow this standard:
 *   @code
 *     NID => array(
 *       'longform' => array(
 *         'background' => 'HEX_CODE',   # Background color of the SaS form.
 *         'tip' => 'HEX_CODE',          # Background color of the tip box.
 *         'font_color' => 'HEX_CODE',   # Font color of the SaS form.
 *         'tip_color' => 'HEX_CODE',    # Font color of the tip box.
 *       ),
 *       'shortform' => array(
 *         'background' => 'HEX_CODE',   # Background color of the shortform
 *         'font_color' => 'HEX_CODE',   # Font color of the shortform.
 *       ),
 *     )
 *   @endcode
 */
$campaign_styles = array(
  // Green your school
  '718328' => array(
    'longform' => array(
      'background' => '#ccc',
      'tip' => '#50B848',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#50B848',
      'font_color' => '#000',
    ),
  ),

    // Don't be a sucker
    '727940' => array(
    'longform' => array(
      'background' => '#ccc',
      'tip' => '#50B848',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#50B848',
      'font_color' => '#000',
    ),
    ),

    // PB&J
    '728618' => array(
    'longform' => array(
      'background' => '#ccc',
      'tip' => '#86005D',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#86005D',
      'font_color' => '#000',
    ),
    ),

    // Band Together
    '729203' => array(
      'longform' => array(
        'background' => '#ccc',
        'tip' => '#E31837',
        'font_color' => '#000000',
        'tip_color' => '#ffffff',
      ),
      'shortform' => array(
        'background' => '#ff9e10',
        'font_color' => '#ffffff',
      ),
    ),

    // 25,000 Women
    '729307' => array(
      'longform' => array(
        'background' => '#e8e8e8',
        'tip' => '#1891d5',
        'font_color' => '#000000',
        'tip_color' => '#ffffff',
      ),
      'shortform' => array(
        'background' => '#1891d5',
        'font_color' => '#ffffff'
      ),
    ),

    // Grandparents TBD
    '999999' => array(
      'longform' => array(
        'background' => '#ccc',
        'tip' => '#ff9e10',
        'font_color' => '#000000',
        'tip_color' => '#ffffff',
      ),
      'shortform' => array(
        'background' => '#ff9e10',
        'font_color' => '#ffffff',
      ),
    ),
  );


/**
 * @var array $campaign_styles
 *   Directly related to the "Color scheme" field on the SaS forms.  The key
 *   here is the key of the select element.  The array is an aray of arrays,
 *   including the 'longform' array and the 'shortform' array.  The 'longform'
 *   is the form that users see on the actaul Share a Stat page.  The
 *   'shortform' is likely unused from now on, but was basically a small
 *   bordered box with name and email.
 *
 *   The color profile should follow this standard:
 *   @code
 *     NID => array(
 *       'longform' => array(
 *         'background' => 'HEX_CODE',   # Background color of the SaS form.
 *         'tip' => 'HEX_CODE',          # Background color of the tip box.
 *         'font_color' => 'HEX_CODE',   # Font color of the SaS form.
 *         'tip_color' => 'HEX_CODE',    # Font color of the tip box.
 *       ),
 *       'shortform' => array(
 *         'background' => 'HEX_CODE',   # Background color of the shortform
 *         'font_color' => 'HEX_CODE',   # Font color of the shortform.
 *       ),
 *     )
 *   @endcode
 */
$scheme_styles = array(
  // Green
  'green' => array(
    'longform' => array(
      'background' => '#8dc641',
      'tip' => '#163a26',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#8dc641',
      'font_color' => '#ffffff',
    ),
  ),

  // Red
  'red' => array(
    'longform' => array(
      'background' => '#ccc',
      'tip' => '#e32f2f',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#e32f2f',
      'font_color' => '#ffffff',
    ),
  ),


  // orange
  'orange' => array(
    'longform' => array(
      'background' => '#ccc',
      'tip' => '#ff9e10',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#ff9e10',
      'font_color' => '#ffffff',
    ),
  ),

  // Black
  'black' => array(
    'longform' => array(
      'background' => '#000',
      'tip' => '#ccc',
      'font_color' => '#fff',
      'tip_color' => '#000',
    ),
    'shortform' => array(
      'background' => '#8dc641',
      'font_color' => '#ffffff',
    ),
  ),

  // Gray
  'gray' => array(
    'longform' => array(
      'background' => '#ccc',
      'tip' => '#163a26',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#8dc641',
      'font_color' => '#ffffff',
    ),
  ),

  // white
  'white' => array(
    'longform' => array(
      'background' => '#ccc',
      'tip' => '#163a26',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#8dc641',
      'font_color' => '#ffffff',
    ),
  ),

  // Yellow
  'yellow' => array(
    'longform' => array(
      'background' => '#ccc',
      'tip' => '#163a26',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#8dc641',
      'font_color' => '#ffffff',
    ),
  ),

  // Blue
  'blue' => array(
    'longform' => array(
      'background' => '#e8e8e8',
      'tip' => '#1891d5',
      'font_color' => '#000000',
      'tip_color' => '#ffffff',
    ),
    'shortform' => array(
      'background' => '#1891d5',
      'font_color' => '#ffffff'
    ),
  ),
);
