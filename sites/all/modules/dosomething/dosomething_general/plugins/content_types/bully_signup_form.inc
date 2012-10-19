<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Bullying Game Form'),
  'description' => t('Displays the Bully Game Signup form.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_bully_game_form'
);

if (!function_exists('array_vals_multi')) {
  function array_vals_multi($array = array(), &$vals = array()) {
    foreach ($array as $key => $value) {
      if (is_array($value)) {
        array_vals_multi($value,$vals);
      }
      else{
        $vals[] = $value; 
      }
    }

    return $vals;
  }
}

function dosomething_bully_game_form($subtype, $conf, $panel_args, $context) {
  if ($_POST['do'] == 'submit-bully') {
    parse_str(urldecode($_POST['stuff']), $stuff);

    if (dosomething_general_valid_cell($stuff['person']['phone'])) {
      dosomething_general_mobile_commons_subscribe($stuff['person']['phone'], $stuff['opt_in_path'], array(
        'first_name' => $stuff['person']['first_name']
      ));
    }

    foreach ($stuff['friends'] AS $key => $friend) {
      if (dosomething_general_valid_cell($friend)) {
        dosomething_general_mobile_commons_subscribe($friend, $stuff['friends_opt_in_path']);
      }
    }

    echo 'Ok';
    drupal_exit();
  }

  $bullying = array(
    28,   // Bullying & Violence category
    9085, // Bullying
    115,  // Child Abuse
    118,  // Cyber Bullying
    7757, // Dating Abuse
    9373, // Elderly Abuse
    117,  // Gang Violence
    116,  // Gun Control
    119,  // Hate Crimes
    120,  // School Violence
    92    // Sexual Assault
  );

  // Issues tags
  if (isset($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_5[LANGUAGE_NONE])) {
    $issues = (array) array_vals_multi($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_5[LANGUAGE_NONE]);
  }
  else {
    $issues = array();
  }

  // Prepare the content array
  $content = array();

  // Find if the current node has bullying tags.
  $tags = array_intersect($bullying, $issues);
  
  drupal_add_css(drupal_get_path('module', 'dosomething_general') . '/plugins/content_types/bully-game.css', array(
    'group' => CSS_THEME,
    'weight' => 1000
  ));

  // If we have bullying tags associated with the node, show the form.
  if (!empty($tags)) {
    if (!$_GET['submitted']) {
      drupal_add_js(drupal_get_path('module', 'dosomething_general') . '/plugins/content_types/bully-game.js');
      drupal_add_js(drupal_get_path('module', 'dosomething_login') . '/js/jquery-validation-1.9.0/jquery.validate.min.js');
      $content[] = array(
        '#markup' => '<div id="bullytext-game">
  <div class="refer5">
    <img class="scholar-copy" src="/sites/all/modules/dosomething/dosomething_general/plugins/content_types/bullytext-copy.png" alt="share this fact">
    <h1 class="condensed">$2,000 SCHOLARSHIP</h1>

    <form action="//dosomething.mcommons.com/profiles/join" method="POST">
      <input type="hidden" name="redirect_to" value="' . url(request_uri(), array('absolute' => true)) . '?submitted=true" />
      <div class="scholar-input first">
        <label>Your First Name:</label>
        <input type="text" name="person[first_name]" class="field space-after" placeholder="Your name:"/>
      </div>
      <div class="scholar-input">
        <label>Your Cell #:</label>
        <input type="text" name="person[phone]" class="field space-after" placeholder="You cell #:" />
      </div>
          <label class="friends">Friend\'s Cell #\'s:</label>
          <input type="text" class="field left first" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left last" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="submit" class="go-button" value="Submit"  style="float: left" />
          <input type="hidden" name="friends_opt_in_path" value="130471" />
          <input type="hidden" name="opt_in_path" value="130451" />
    </form> 

  <div class="clearfix"></div>

  <div id="campaign-opt-in"><span class="ctia_bottom">  <a class="rules" href="//files.dosomething.org/files/campaigns/bullytext/BullyTextContestRules.pdf">Offical Rules.</a> Msg &amp; data rates may apply. Text <strong>STOP</strong> to opt-out, <strong>HELP</strong> for help. </span></div>
  </div> <!-- .refer5 -->
  </div>',
        '#prefix' => '<div class="game-wrapper">',
        '#suffix' => '</div>'
      );
    }
    else {
      $content[] = array(
        '#markup' => '<h2>Thanks for sending The Bully Text to your friends.</h2>  <p>Want more ways to take action around bullying?</p><p>Sign the petition below.</p>',
        '#prefix' => '<div id="bully-block-thanks">',
        '#suffix' => '</div>'
      );

      $content[] = array(
        '#markup' => l('<img src="http://files.dosomething.org/files/connections/Petition-Banners_Bully-Short_0.png" alt="Sign the Bullying Petition" />', 'petition/put-end-to-bullying', array('html' => TRUE)),
        '#prefix' => '<p>',
        '#suffix' => '</p>'
      );
    }
  }
  else {
    // Otherwise, show nothing.
    $content[] = array('#markup' => '');
  }

  $block = new StdClass();
  $block->content = $content;
  return $block;
}