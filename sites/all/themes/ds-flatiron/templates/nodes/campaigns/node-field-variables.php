<?php

  /**
   *
   *  @TODO - REPLACE THIS FILE W/FIELDS ON THE CAMPAIGN NODE
   *
   */

  /* GENERAL VARIABLES */

  $cmp_url = 'pbj';         /* url + help e-mail                         */
  $cmp_short = 'pbjs';      /* the campaign's abbreviation               */
  $cmp_machine = 'pbjs13';  /* the campaign's machine name - a unique id */
  $cmp_name = 'Peanut Butter & Jam Slam';
  $cmp_lead = 'Saige';
  $sponsor = 'walmart';
  $files_source = '//www.dosomething.org/files/campaigns/' . $cmp_machine . '/';

  /* MOBILE COMMONS NOISE */
  $alpha_opt_in = '148093';
  $beta_opt_in = '148123';

  /* SECTIONS CONTENT */

  $project = array(
    1 => "<strong>1 out of 6</strong> Americans goes hungry every year.",
    2 => "You can change this by donating food.",
  );

  $challenge = array(
    1 => "Collect and donate <strong>10 jars</strong> of peanut butter or jam.",
    2 => "Then use the food bank finder & drop off your jars by May 14th.",
  );
  // if (isset($team) || isset($individual)) with a Group / Alone

  $contact_scope = isset($team) ? ' with a group' : '';
  $contact_scope = isset($individual) ? ' alone' : $contact_scope;

  $scholarship = array(
    1 => "We're giving away a <strong>$4,000 SCHOLARSHIP</strong>. Every 10 jars collected = another entry to win.",
    2 => "Great! You're gonna do this<span id=\"scholarship_status\">" . $contact_scope . "</span>. Here's what you need to do to qualify for the scholarship. Before you get started <a href=\"" . $files_source . 'action-guide.pdf' . "\">download</a> your PB&JS Kit.",
  );

  $cause_subject = 'Peanut Butter';
  $cause = array(
    1 => array(
      "It's one of the top requested items at food banks",
      "It's packed with protein",
      "It has a long shelf-life (2 years!)",
      "It meets most religious restrictions on food",
    ),
    2 => array(
      "There are more mouths to feed: Kids who normally get food from school nutrition programs need to get it elsewhere",
      "When you think of food drives, you normally think of the holiday season, right? Bingo. Less donations occur during spring and summer months",
      "When the economy suffers, overall donations suffer too",
      "Americans go nuts over peanut butter. Like, they actually go crazy.",
    ),
    3 => array(
      "The world's largest peanut butter factory churns out 250,000 jars of the tasty treat every day",
      "The average American consumes more than six pounds of peanuts and peanut butter products each year.",
      "Peanuts have more protein, niacin, folate and phytosterols than any nut.",
      "It takes about 540 peanuts to make a 12-ounce jar of peanut butter",
    ),
    4 => array(
      "Most importantly, make sure <strong>ALL</strong> donations are 100% sealed",
      "Host your drive in your cafeteria where there's already a process for dealing with allergies",
      "Have a nut-free school? Host your drive at a local store, church, temple, etc.",
      "Wash your hands after you donate (just in case)",
    ),
    "links" => array(
      /* There should be one less link than there are fact arrays! */
      1 => "More Facts",
      2 => "Even More Facts",
      3 => "Yes, we have even more facts",
    ),
   );

  $social = array(
    1 => "Team Crunchy or Smooth? Help settle one of biggest debates in American history.",
   );

  /* POST REPORT-BACK PAGE VIEW */
  $success = array(
    1 => "Congrats on successfully completing the challenge!",
    2 => "Thanks to you someone in your community won't go hungry.",
  );
  
  $thanks = array(
    1 => "Thanks for sharing the campaign with your friends!",
  );

?>
