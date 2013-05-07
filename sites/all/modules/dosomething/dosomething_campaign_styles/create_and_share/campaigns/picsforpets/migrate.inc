<?php

function create_and_share_import_picsforpets($nid) {
  $migrate = array();
  $migrate['Name'] = array('type' => 'textfield', 'mandatory' => 1);
  $migrate['Type'] = array(
  	'type' => 'select',
  	'extra' => array(
  	  'items' => "cat|Cat\r\ndog|Dog\r\nother|Other",
  	),
  	'mandatory' => 1,
  );
  $migrate['Shelter'] = array('type' => 'textfield', 'mandatory' => 1);
  $migrate['Shelter State'] = array(
  	'type' => 'select',
  	'extra' => array(
  	  'items' => "AL|Alabama\r\nAK|Alaska\r\nAS|American Samoa\r\nAZ|Arizona\r\nAR|Arkansas\r\nCA|California\r\nCO|Colorado\r\nCT|Connecticut\r\nDE|Delaware\r\nDC|District of Columbia\r\nFL|Florida\r\nGA|Georgia\r\nGU|Guam\r\nHI|Hawaii\r\nID|Idaho\r\nIL|Illinois\r\nIN|Indiana\r\nIA|Iowa\r\nKS|Kansas\r\nKY|Kentucky\r\nLA|Louisiana\r\nME|Maine\r\nMH|Marshall Islands\r\nMD|Maryland\r\nMA|Massachusetts\r\nMI|Michigan\r\nMN|Minnesota\r\nMS|Mississippi\r\nMO|Missouri\r\nMT|Montana\r\nNE|Nebraska\r\nNV|Nevada\r\nNH|New Hampshire\r\nNJ|New Jersey\r\nNM|New Mexico\r\nNY|New York\r\nNC|North Carolina\r\nND|North Dakota\r\nMP|Northern Marianas Islands\r\nOH|Ohio\r\nOK|Oklahoma\r\nOR|Oregon\r\nPW|Palau\r\nPA|Pennsylvania\r\nPR|Puerto Rico\r\nRI|Rhode Island\r\nSC|South Carolina\r\nSD|South Dakota\r\nTN|Tennessee\r\nTX|Texas\r\nUT|Utah\r\nVT|Vermont\r\nVI|Virgin Islands\r\nVA|Virginia\r\nWA|Washington\r\nWV|West Virgini\r\nWI|Wisconsin\r\nWY|Wyoming",
  	),
  	'mandatory' => 1,
  );
  $migrate['Adopted'] = array(
  	'type' => 'select',
  	'extra' => array(
  	  'items' => "1|Adopted",
  	  'multiple' => 1,
  	),
  	'mandatory' => 1,
  );

  return $migrate;
}
