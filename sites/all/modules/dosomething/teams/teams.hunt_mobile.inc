<?php

// hunt mobile

function teams_report_backs() {
  $report_backs = array(
    'reusedone' => array(
      'nid' => 722991,
      'cid' => 'day_one',
      'value' => '1_a',
      'response' => 'Great, that\'s 5 pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Or text HOPE1 or CANS for other challenges',
    ),
    'hopedone' => array(
      'nid' => 722991,
      'cid' => 'day_one',
      'value' => '1_b',
      'response' => 'Great, that\'s 10pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Text REUSE or CANS for other challenges',
    ),
    'cansdone' => array(
      'nid' => 722991,
      'cid' => 'day_one',
      'value' => '1_c',
      'response' => 'That\'s 20 points! We have one more question to enter you to win a Lenovo Ultrabook. Respond ULTRABOOK',
    ),

    'datingdone' => array(
      'nid' => 722992,
      'cid' => 'day_two',
      'value' => '2_a',
      'response' => 'Great, that\'s 5pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Text PREVENT2 or CENSUS for another challenge',
    ),
    'preventdone' => array(
      'nid' => 722992,
      'cid' => 'day_two',
      'value' => '2_b',
      'response' => 'Nice, that\'s 10pts! Text PREVENTIDEA to tell us your idea. Or text ONETHREE or CENSUS for another challenge',
    ),
    'censusdone' => array(
      'nid' => 722992,
      'cid' => 'day_two',
      'value' => '2_c',
      'response' => 'Wow, that\'s 20pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Text ONETHREE or PREVENT2 for another challenge',
    ),

    'spenddone' => array(
      'nid' => 722993,
      'cid' => 'day_three',
      'value' => '3_a',
      'response' => 'Great, that\'s 5pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Or Text PANTRY or FOOTPRINT for other challenges',
    ),
    'pantrydone' => array(
      'nid' => 722993,
      'cid' => 'day_three',
      'value' => '3_b',
      'response' => 'Nice, that\'s 15pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Or Text SPEND3 or FOOTPRINT for more challenges',
    ),
    'footdone' => array(
      'nid' => 722993,
      'cid' => 'day_three',
      'value' => '3_c',
      'response' => 'Fantastic, that\'s 20pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Or Text PANTRY or SPEND3 for other challenges',
    ),

    'parkdone' => array(
      'nid' => 722994,
      'cid' => 'day_four',
      'value' => '4_a',
      'response' => 'Awesome, 10pts! We need some info on your park. Respond PARKINFO and we\'ll ask you two questions',
    ),
    'musicdone' => array(
      'nid' => 722994,
      'cid' => 'day_four',
      'value' => '4_b',
      'response' => 'Nice, that\'s 5pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Or text MYPARK or TRASH4 for more challenges',
    ),
    'trashdone' => array(
      'nid' => 722994,
      'cid' => 'day_four',
      'value' => '4_c',
      'response' => 'Great! Respond TRASHCOUNT to tell us how many pieces you collected.',
    ),

    'genderdone' => array(
      'nid' => 722995,
      'cid' => 'day_five',
      'value' => '5_a',
      'response' => 'Great, that\'s 5pts! Remember to respond with a picture for +25 points. Respond with DESIGN or DISABILITY for another challenge',
    ),
    'signdone' => array(
      'nid' => 722995,
      'cid' => 'day_five',
      'value' => '5_b',
      'response' => 'Nice, that\'s 10pts! Remember to send us a picture for +25 points and for our gallery. Respond with GENDER or DISABILITY for another challenge',
    ),
    'disabledone' => array(
      'nid' => 722995,
      'cid' => 'day_five',
      'value' => '5_c',
      'response' => 'Wow, that\'s 20pts! Respond with a pic of the area (and the area name) for +25 points. Text GENDER or DESIGN for another challenge',
    ),

    'walkdone' => array(
      'nid' => 722996,
      'cid' => 'day_six',
      'value' => '6_a',
      'response' => 'Great, that\'s 20pts! We have one more question before we give you points (+25 more if you send a pic too). Respond WALKED to unlock the question',
    ),
    'mealdone' => array(
      'nid' => 722996,
      'cid' => 'day_six',
      'value' => '6_b',
      'response' => 'Nice, that\'s 10pts! Remember to send us a picture for +25 extra points. Respond with WALK6 or SUGAR for another challenge',
    ),
    'sugardone' => array(
      'nid' => 722996,
      'cid' => 'day_six',
      'value' => '6_c',
      'response' => 'Wow, that\'s 5pts! One more question for you, though (you don\'t get off that easy) respond SUGARQ for the question, or MEAL or WALK6 for more challenges',
    ),

    'homedone' => array(
      'nid' => 722997,
      'cid' => 'day_seven',
      'value' => '7_a',
      'response' => 'Great, that\'s 5pts! Remember to respond with a picture of you posting it for +25 points. Respond with NOMEAT or SHELTER7 for another challenge',
    ),
    'meatdone' => array(
      'nid' => 722997,
      'cid' => 'day_seven',
      'value' => '7_b',
      'response' => 'Nice, that\'s 10pts! Remember to send us a picture of a vegetarian meal for +25 points. Respond with NOHOME or SHELTER7 for another challenge',
    ),
    'shelterdone' => array(
      'nid' => 722997,
      'cid' => 'day_seven',
      'value' => '7_c',
      'response' => 'Wow, that\'s 20pts! Respond with a pic of you donating for +25 points. Text NOHOME or NOMEAT for another challenge',
    ),

    'detectordone' => array(
      'nid' => 722998,
      'cid' => 'day_eight',
      'value' => '8_a',
      'response' => 'Great, that\'s 5pts! Remember to respond with a picture for +25 points. Respond with PLAN8 or KIT for another challenge',
    ),
    'plandone' => array(
      'nid' => 722998,
      'cid' => 'day_eight',
      'value' => '8_b',
      'response' => 'Nice, that\'s 10pts! Remember to send us a picture for +25 points. Respond with DETECTOR or KIT for another challenge',
    ),
    'kitdone' => array(
      'nid' => 722998,
      'cid' => 'day_eight',
      'value' => '8_c',
      'response' => 'Wow, that\'s 20pts! Respond with a pic of your kit for +25 points. Text DETECTOR or PLAN8 for another challenge',
    ),

    'dropdone' => array(
      'nid' => 722999,
      'cid' => 'day_nine',
      'value' => '9_a',
      'response' => 'Great, that\'s 5pts! Remember to respond with a picture for +25 points. Respond with STUDENT or EMAIL9 for another challenge',
    ),
    'studentdone' => array(
      'nid' => 722999,
      'cid' => 'day_nine',
      'value' => '9_b',
      'response' => 'Nice, that\'s 10pts! Remember to send us a picture for +25 points and for our gallery. Respond with DROPOUT or EMAIL9 for another challenge',
    ),
    'emaildone' => array(
      'nid' => 722999,
      'cid' => 'day_nine',
      'value' => '9_c',
      'response' => 'Wow, that\'s 20pts! Respond with a pic of the area for +25 points. Text DROPOUT or STUDENT for another challenge',
    ),

    'savedone' => array(
      'nid' => 723000,
      'cid' => 'day_ten',
      'value' => '10_a',
      'response' => 'Great, that\'s 5pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Or Text DEGREES or VAMPIRE for other challenges',
    ),
    'acdone' => array(
      'nid' => 723000,
      'cid' => 'day_ten',
      'value' => '10_b',
      'response' => 'Great, that\'s 10pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Or Text SAVEWATER or VAMPIRE for other challenges',
    ),
    'vampiredone' => array(
      'nid' => 723000,
      'cid' => 'day_ten',
      'value' => '10_c',
      'response' => 'Great, that\'s 20pts! Respond with a pic of you doing it and we\'ll give you +25 pts. Or Text SAVEWATER or DEGREES for other challenges',
    ),
  );
  return $report_backs;
}
