<?php

class TwitterService {
  public static $title = 'Twitter';

  public static $actions = array(
    'share' => "Share on a user's wall",
  );

  public static function getActions() {
    return array(
      'title' => self::$title,
      'actions' => self::$actions,
    );
  }

  // Share on a user's wall
  public static function shareAction(&$form, $data) {
    $form['selector'] = array(
      '#type' => 'textfield',
      '#title' => t('Selector'),
      '#description' => t('The selector (HTML css / id attribute) that will trigger this action.'),
      '#attributes' => array(
        'placeholder' => t('.selector / #selector'),
      ),
      '#default_value' => (isset($data['selector']) ? $data['selector'] : ''),
    );

    $form['share_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Share URL'),
      '#description' => t('The URL that will be shared in the tweet.  Leave this alone to share the cu This will be automatically shortened if the <b>shorten</b> module is enabled.'),
      '#attributes' => array(
        'placeholder' => t('Share URL...'),
      ),
      '#default_value' => (isset($data['share_url']) ? $data['share_url'] : ''),
    );

    $form['share_text'] = array(
      '#type' => 'textarea',
      '#title' => t('Share Text'),
      '#description' => t('The text that the tweet will be pre-populated with.  The user can change this (non-negotiable).'),
      '#attributes' => array(
        'placeholder' => t('Share URL...'),
      ),
      '#default_value' => (isset($data['share_url']) ? $data['share_url'] : ''),
    );

    $form['share_via'] = array(
      '#type' => 'textfield',
      '#title' => t('Share via'),
      '#description' => t('The "via" section of the tweet.  This will be at the end of the tweet text, e.g. ("via @yoursite")'),
      '#attributes' => array(
        'placeholder' => t('via @yourhandle...'),
      ),
      '#default_value' => (isset($data['share_url']) ? $data['share_url'] : ''),
    );
/*original_referer=http%3A%2F%2Fwww.dosomething.org%2Ftipsandtools%2F11-facts-about-cyber-bullying
&amp;text=11%20Facts%20About%20Cyber%20Bullying%20%7C%20Do%20Something
&amp;tw_p=tweetbutton
&amp;url=http%3A%2F%2Fdsorg.us%2FvP28Co
&amp;via=dosomething*/
  }

  public static function shareSubmit(&$data) {
    echo "!"; exit;
    // Functions to run on share submit.
  }

  public static function shareRender(&$page, $data) {
    // Stuff to run on render
  }

}