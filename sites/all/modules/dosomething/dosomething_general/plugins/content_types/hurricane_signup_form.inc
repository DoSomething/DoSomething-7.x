<?php

define('ALPHA_OPT_IN_PATH', 133121);
define('BETA_OPT_IN_PATH', 133161);

$plugin = array(
  'single' => TRUE,
  'title' => t('Hurricane Text Form'),
  'description' => t('Displays the Hurricane text form.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_hurricane_text_form'
);

function dosomething_hurricane_text_form($subtype, $conf, $panel_args, $context) {
  if ($_POST['do'] == 'submit-hurricane') {
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

  $tags = array(
    27,   // Disasters
    113,  // Disaster Preparedness
    70,   // Fires
    7617, // Floods
    111,  // Hurricanes
    9384, // Terrorism
    9385, // Tornadoes
    112,  // Tsunamis
  );

  // Issues tags
  if (isset($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_5[LANGUAGE_NONE])) {
    $issues = (array) dosomething_general_array_vals_multi($context['argument_entity_id:node_1']->data->taxonomy_vocabulary_5[LANGUAGE_NONE]);
  }
  else {
    $issues = array();
  }

  // Prepare the content array
  $content = array();

  // Find if the current node has bullying tags.
  $tags = array_intersect($tags, $issues);
  
  drupal_add_css(drupal_get_path('module', 'dosomething_general') . '/plugins/content_types/hurricane-text.css', array(
    'group' => CSS_THEME,
    'weight' => 1000
  ));

  // If we have bullying tags associated with the node, show the form.
  if (!empty($tags)) {
    if (!$_GET['submitted']) {
      drupal_add_js(drupal_get_path('module', 'dosomething_general') . '/plugins/content_types/hurricane-text.js');
      drupal_add_js(drupal_get_path('module', 'dosomething_login') . '/js/jquery-validation-1.9.0/jquery.validate.min.js');
      $content[] = array(
        '#markup' => '<div id="hurricane-text">
  <div class="refer5">
    <p id="action-text">Enter 6 of your friends\' numbers to ask them to send messages of support to victims of Hurricane Sandy.</p>
    <p id="megaphone"><img src="/' . drupal_get_path('module', 'dosomething_general') . '/plugins/content_types/pantryprep/megaphone.png" alt="" /></p>

    <form action="//dosomething.mcommons.com/profiles/join" method="POST">
      <input type="hidden" name="redirect_to" value="' . url(request_uri(), array('absolute' => true)) . '?submitted=true" />
      <input type="text" class="field left" name="person[first_name]" placeholder="Your name:"/>
      <input type="text" class="field left" name="person[phone]" placeholder="Your Cell #:"/>
      <p id="line-break"><img src="/' . drupal_get_path('module', 'dosomething_general') . '/plugins/content_types/pantryprep/prep-line.png" alt="" /></p>
          <input type="text" class="field left first" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left" name="friends[]" placeholder="Friend\'s cell #:"/>
          <input type="text" class="field left last" name="friends[]" placeholder="Friend\'s cell #:"/>
          <div id="campaign-opt-in"><span class="ctia_bottom">Msg &amp; data rates may apply. Text STOP to opt-out, HELP for help.</span></div>
          <input type="submit" class="go-button" value="Submit" />
          <input type="hidden" name="friends_opt_in_path" value="' . BETA_OPT_IN_PATH . '" />
          <input type="hidden" name="opt_in_path" value="' . ALPHA_OPT_IN_PATH . '" />
    </form> 

  <div class="clearfix"></div>

  </div> <!-- .refer5 -->
  </div>',
        '#prefix' => '<div class="game-wrapper">',
        '#suffix' => '</div>'
      );
    }
    else {
      $content[] = array(
        '#type' => 'container',
        '#attributes' => array('id' => 'hurricane-thanks'),
        'thanks' => array(
          '#type' => 'markup',
          '#markup' => '<img src="/' . drupal_get_path('module', 'dosomething_general') . '/plugins/content_types/pantryprep/pantry-thanks.png" alt="" />'
        ),
        'your-friends' => array(
          '#type' => 'markup',
          '#markup' => t('Your friends will get a message to share their support.'),
          '#prefix' => '<p>',
          '#suffix' => '</p>'
        ),
        'click-here' => array(
          '#type' => 'markup',
          '#markup' => t('!click to start collecting items for those in need.', array('!click' => l(t('Click here'), 'pantryprep'))),
          '#prefix' => '<p>',
          '#suffix' => '</p>'
        )
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