<?php

/**
 *  @file
 *  Surveys are webforms with questions that users can answer.  Given the arbitrary nature of
 *  of the forms (each survey will be different), we need a way to display the user's selections
 *  compared to the average of everyone else.  Views currently does not have the functionality to
 *  make this happen, so we fall back to this plugin.
 *
 *  This plugin should only be run on panelized pages that have the "%node" argument somewhere in
 *  the URL.  The argument populates the $panel_args parameter, thus allowing us to get survey results.
 *
 *  This plugin does a number of things:
 *  
 *  1. Get a list of all webform components (questions) and store them.
 *  2. Get all of your answers and, given we're unsure of whether people can answer more than once,
 *     loop through them until we revisit a component id we've already seen before (essentially limiting
 *     it to one full loop of questions).  When we have all of your answers, save them in a structured
 *     array for later use.
 *  3. Get the total count of webform submissions, given the node and all of the component IDs found in
 *     your answers.
 *  4. Get counts of how many times each question and sub-option (if applicable) are checked by other
 *     users.  Loop through results to make an array full of percentages that we can use later.
 *  5. Loop through all questions (found in step 1) and build the structure of the survey to show results:
 *      a. Show the original question and any related options below it.
 *      b. For each question or option, if it's your answer, show some sort of label to denote that
 *      c. Show the percentage of people who chose that answer.
 */

// Plugin information array
$plugin = array(
  'single' => TRUE,
  'title' => t('Survey Responses'),
  'description' => t('Displays survey responses and percentages.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_survey_responses'
);

// Builds the survey response plugin.
function dosomething_survey_responses($subtype, $conf, $panel_args, $context) {
  // We need the $user object to get your user information.
  global $user;

  // For debug purposes.
  define('SHOW_HIDDEN_SURVEY_ANSWERS', false);

  // Adds survey response page CSS.
  drupal_add_css(drupal_get_path('module', 'dosomething_general') . '/css/survey-responses.css');

  // Load $node with the node ID found in the URL.
  $node = reset($panel_args);

  // Begin the eventual content string
  $layout = '';

  // Get all of the form components (questions) for the survey.
  $components = db_query("SELECT cid, form_key, name, extra from webform_component where nid = :nid AND `extra` NOT LIKE '%s:13:\"title_display\";s:4:\"none\";%' ORDER BY weight ASC", array(':nid' => $node))->fetchAll();

  /**
   * Get all of your answers from the survey.  We can't limit this to any particular number
   * because every survey will have an arbitrary number of questions
   */
  $your_answers = db_query("
    select d.cid, d.no, d.data
    FROM
    webform_submissions s
      left join webform_submitted_data d ON (s.sid = d.sid and (d.nid = {$node}))
      left join node on s.nid = node.nid
    where node.type IN ('webform') AND node.nid = {$node} AND s.uid = {$user->uid}
    order by s.submitted desc
  ")->fetchAll();

  $ya = $gt = array();
  $last = 0;
  $i = 0;
  foreach ($your_answers AS $key => $answer) {
    if (isset($answer->no)) {
      /**
       * If we've already seen this component ID, it's safe to say that we've looped
       * through the answers once.  Break out!
       */
      if ($gt[$answer->cid]) {
        break;
      }

      /**
       * If the last component ID we saw is NOT the same as the current component ID,
       * mark the last component ID as "visited"
       */
      if ($last != $answer->cid) {
        $gt[$last] = true;
      }

      /**
       * If the key for the question happens to be numeric, don't store the number but
       * instead store the data.  This will make it easier later.
       */
      if (is_numeric($answer->no)) {
        $answer->no = $answer->data;
      }

      // Store your answers with the component ID, the answer key, and the answer given.
      $ya[$answer->cid][$answer->no] = $answer->data;

      // Mark the "last" variable as the current cid, for when we loop around.
      $last = $answer->cid;
    }
  }

  // Find all of the component IDs (the array keys from the "your answer" array)
  $cids = array_keys($ya);

  // Get the total count of submissions given the node and component IDs
  $count = db_query("SELECT * FROM webform_submitted_data d WHERE d.nid = {$node} AND d.cid IN (" . implode(',', $cids) . ") GROUP BY sid")->rowCount();

  // KILLED 2/21/13: This ate everything!
  /**
   * Get data from the results:
   * - Component IDs, answers, count
   */
  /*$results = db_query("
    SELECT distinct sid, d.cid, data, IF (no REGEXP '^[0-9]+$', c.form_key, no) AS no, IF (no REGEXP '^[0-9]+$', 1, 0) AS changed, count(distinct sid) AS fcount
    FROM webform_submitted_data d
      LEFT JOIN webform_component c ON (c.cid = d.cid)
    WHERE (d.nid = {$node} AND d.cid IN (" . implode(',', $cids) . "))
    GROUP BY no, data, c.cid;
  ")->fetchAll();

  $totals = array();
  // Loop through results and make percentages
  foreach ($results AS $key => $r) {
    if ($r->changed) {
      $r->no = $r->data;
    }

    // Adds to $totals array
    $totals[$r->cid][$r->no][$r->data] = round(($r->fcount / $count) * 100);
  }*/

  // Sets up language for your responses vs. worldwide responses
  $stat = array(
    'yours' => 'you said: <span class="you">!answer</span>',
    #'theirs' => '!percent% said: <span class="them">!answer</span>',
  );
  $answers = array();

  $i = 1;
  // Loops through components and builds visual structure.
  foreach ($components AS $key => $component) {
    // Builds the "question" div
    $layout .= '<div class="component' . (($i % 2) ? ' alternate' : '') . '">';
    // $component->name is the original (top level) question.
    $layout .= '<h2>' . $component->name . '</h2>';

    // The component "extra" field has answers of sub-questions (e.g. on a scale'd question)
    $cs = unserialize($component->extra);

    // If component extra has "items" array, we're in just a question-and-answer model.
    if (!empty($cs['items'])) {
      $layout .= '<div class="results">';

      #$top = dosomething_general_array_vals_multi($totals[$component->cid]);
      #$thetop = array_search(max($top), $top);

      // Get human readable names for fields.
      preg_match_all('#([a-zA-Z0-9\_\-]+)\|(.*)#i', $cs['items'], $options);
      // Loop through questions and print them out.
      foreach ($options[2] AS $key => $title) {
        $yours = $ya[$component->cid][$options[1]["$key"]];
        #$t = ($options[1]["$key"] == $thetop);

        if ($yours/* || $t*/) {

          // Get the percentage of people who chose this answer.
          #$percentage = $totals[$component->cid][$options[1]["$key"]][$options[1]["$key"]];

          if ($t) {
            #$answers['theirs'] = t($stat['theirs'], array('!percent' => $percentage, '!answer' => strtoupper($title)));
          }
          if ($yours) {
            $answers['yours'] = t($stat['yours'], array('!answer' => strtoupper($title)));
          }
        }
        /*else if (defined('SHOW_HIDDEN_SURVEY_ANSWERS') && SHOW_HIDDEN_SURVEY_ANSWERS === true) {
          $layout .= '<li style="color: red">';
          $layout .= '<div class="question-answer" style="display: inline-block">' . $title . '</div>';

          // Get the percentage of people who chose this answer.
          $percentage = $totals[$component->cid][$options[1]["$key"]][$options[1]["$key"]];

          // If the percentage is greater than 0% (because it looks ridiculous otherwise), show...
          $layout .= '<div style="margin-left: 150px; display: inline-block">' . t('!percentage% of people said this.', array('!percentage' => intval($percentage))) . '</div>';

          $layout .= '</li>';
        }*/
      }

      $lr = '';
      foreach ($stat AS $type => $val) {
        $lr .= '<div class="' . $type . ' result">' . $answers["$type"] . '</div>';
      }
      $layout .= $lr;

      $layout .= '</div>';
    }
    /**
     * Otherwise, it's likely we're within a grid-style component.  This has two
     * completely different arrays: questions and options.
     *
     * - questions contains all of the questions (e.g. "How safe is..." - "Your School")
     *   in the above case, "Your School" is the question for the grid.
     * - options contains all of the items on a scale (e.g. "Somewhat safe")
     */
    else if (!empty($cs['questions']) && !empty($cs['options'])) {
      // Match human readable options and store them.
      preg_match_all('#([a-zA-Z0-9\_\-]+)\|(.*)#i', $cs['options'], $options);
      preg_match_all('#([a-zA-Z0-9\_\-]+)\|(.*)#i', $cs['questions'], $questions);

      $layout .= '<ul>';
      // Loop through questions and show them.
      foreach ($questions[2] AS $qkey => $question) {
        $layout .= '<li>';
        $layout .= '<div class="question sub">' . $question . '</div>';

        #$top = dosomething_general_array_vals_multi($totals[$component->cid][$questions[1][$qkey]]);
        #$thetop = array_search(max($top), $top);

        $layout .= '<div class="results">';
        #$layout .= '<ul class="grid-options">';
        // Show the grid options
        foreach ($options[2] AS $okey => $option) {
          $yours = $ya[$component->cid][$questions[1][$qkey]] == $options[1][$okey];
          #$t = ($options[1]["$okey"] == $thetop);

          #if ($t) {
           # $answers['theirs'] = t($stat['theirs'], array('!percent' => $percentage, '!answer' => strtoupper($option)));
          #}
          if ($yours) {
            $answers['yours'] = t($stat['yours'], array('!answer' => strtoupper($option)));
          }

          $item = '';
          /*if ($yours || $t) {
          }
          else if (defined('SHOW_HIDDEN_SURVEY_ANSWERS') && SHOW_HIDDEN_SURVEY_ANSWERS === true) {
            $layout .= '<li style="color: red">';
            $layout .= '<div class="question-answer sub-answer" style="display: inline-block">' . $option . '</div>';

            // Get the percentage of people who chose this answer.
            $percentage = $totals[$component->cid][$questions[1][$qkey]][$options[1]["$okey"]];

            // If the percentage is greater than 0% (because it looks ridiculous otherwise), show...
            $layout .= '<div style="margin-left: 150px; display: inline-block">' . t('!percentage% of people said this.', array('!percentage' => intval($percentage))) . '</div>';

            $layout .= '</li>';
          }*/
        }

        $lr = '';
        foreach ($stat AS $type => $val) {
          $lr .= '<div class="' . $type . ' result">' . $answers["$type"] . '</div>';
        }
        $layout .= $lr;

        $layout .= '</div>';

        #$layout .= '</ul>';
        $layout .= '</li>';
      }

      $layout .= '</ul>';
    }

    $i++;
    $layout .= '</div>';
  }

  // Builds the content 
  $content = array();
  $content[] = array('#markup' => $layout);

  // Creates the block
  $block = new StdClass();
  $block->content = $content;

  // Fin!
  return $block;
}
