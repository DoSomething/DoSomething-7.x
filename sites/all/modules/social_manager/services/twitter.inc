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
      '#description' => t('The selector (HTML css / id attribute) that will trigger this action.  <b>If left blank, this action will be triggered automatically when the page loads.</b>'),
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
      '#default_value' => (isset($data['share_text']) ? $data['share_text'] : ''),
    );

    $form['share_via'] = array(
      '#type' => 'textfield',
      '#title' => t('Share via'),
      '#description' => t('The "via" section of the tweet.  This will be at the end of the tweet text, e.g. ("via @yoursite")'),
      '#attributes' => array(
        'placeholder' => t('via @yourhandle...'),
      ),
      '#default_value' => (isset($data['share_via']) ? $data['share_via'] : ''),
    );

    $form['share_target'] = array(
      '#type' => 'select',
      '#title' => t('Share target'),
      '#description' => t('How should this tweet page appear? In a new window, or as a popup?'),
      '#options' => array(
        'window' => t('In a new window'),
        'popup' => t('In a popup'),
      ),
      '#default_value' => (isset($data['share_target']) ? $data['share_target'] : 'window'),
    );
  }

  public static function shareSubmit(&$data) {
    // Callback for form submit.
  }

  public static function shareRender(&$page, $data) {
    if (module_exists('shorten')) {
      $referrer = shorten_url(url(request_uri(), array('absolute' => TRUE)));
    }
    else {
      $referrer = url(request_uri(), array('absolute' => TRUE));
    }
    $text = addslashes(filter_xss($data['share_text']));

    // Remove potential mis-types from the originator.
    $via = preg_replace('#(via\s+)?\@?#i', '', strip_tags($data['share_via']));

    $pop = '';
    if ($data['share_target'] == 'popup') {
      $pop = ", '_tweet', 'width=450,height=260,scrollbars=no,resizable=no,toolbars=no'";
    }

    $clicker_start = '';
    $clicker_end = '';
    if (!empty($data['selector'])) {
      $clicker_start = "$('" . $data['selector'] . "').click(function() {";
      $clicker_end = '});';
    }

    $output = "
    <script type=\"text/javascript\">
    (function($) {
      $(document).ready(function() {
        " . $clicker_start . "
          window.open('http://www.twitter.com/intent/tweet?original_referer=" . $referrer . "&text=" . $text . "&tw_p=tweetbutton&url=" . $referrer . "&via=" . $via . "'" . $pop . ");
        " . $clicker_end . "
      });
    })(jQuery);
    </script>
    ";

    $page['page_bottom']['twitter_share_init'] = array(
      '#markup' => $output
    );
  }

}