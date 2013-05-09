<?php

class FacebookService {
  public static $title = 'Facebook';

  public static $actions = array(
    'appid' => 'Set App ID',
    'ushare' => "Share on a user's wall",
    'fshare' => "Share on a friend's wall",
    'gate' => 'Gate a page',
  );

  public static function getActions() {
    return array(
      'title' => self::$title,
      'actions' => self::$actions,
    );
  }

  public static function appidAction(&$form, $data) {
    $form['app_id'] = array(
      '#type' => 'textfield',
      '#title' => t('App ID'),
      '#description' => t('The App ID of your Facebook app.'),
      '#attributes' => array(
      	'placeholder' => t('The App ID of your Facebook app'),
      ),
      '#default_value' => (isset($data['app_id']) ? $data['app_id'] : ''),
    );

    $form['app_secret'] = array(
      '#type' => 'textfield',
      '#title' => t('App Secret'),
      '#description' => t('The App Secret of your Facebook app.'),
      '#attributes' => array(
      	'placeholder' => t('The App Secret of your Facebook app'),
      ),
      '#default_value' => (isset($data['app_secret']) ? $data['app_secret'] : ''),
    );
  }

  public static function appidSubmit(&$data) {
    variable_set('social_manager_facebook_app_id', $data['app_id']);
    variable_set('social_manager_facebook_app_secret', $data['app_secret']);
  }

  public static function appidRender(&$page, $data) {
    $output = '
    <div id="fb-root"></div>
    <script type="text/javascript">
       window.fbAsyncInit = function() {
         FB.init({
           appId: ' . intval($data['app_id']) . ',
           status: true,
           cookie: true,
           xfbml: true,
         });';
    $output .= implode("\n", module_invoke_all('facebook_init_event'));
    $output .= "
       };
       (function() {
         var e = document.createElement('script');
         e.async = true;
         e.src = document.location.protocol + '//connect.facebook.net/" . $fb_locale . "/all.js';
         document.getElementById('fb-root').appendChild(e);
       }());
    </script>";

    $page['page_bottom']['facebook_init'] = array(
      '#markup' => $output
    );

    $element = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'fb:app_id',
        'content' => intval($data['app_id']),
      )
    );
    drupal_add_html_head($element, 'facebook_meta_app_id');
  }

  public static function ushareAction(&$form, $data) {
    $form['selector'] = array(
      '#type' => 'textfield',
      '#title' => t('Selector'),
      '#description' => t('The selector (HTML css / id attribute) that will trigger this action.'),
      '#attributes' => array(
        'placeholder' => t('.selector / #selector'),
      ),
      '#default_value' => (isset($data['selector']) ? $data['selector'] : ''),
    );

    $form['post_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Share URL (optional)'),
      '#description' => t('The URL that the user will be brought back to when they click the share.  If left blank, will share the current page.'),
      '#attributes' => array(
        'placeholder' => t('Share URL...'),
      ),
      '#default_value' => (isset($data['post_url']) ? $data['post_url'] : ''),
    );

    $form['post_image'] = array(
      '#type' => 'textfield',
      '#title' => t('Share Image (optional)'),
      '#description' => t('The image that will be shared on the user\'s wall.  If left blank, Facebook will find a likely picture and use that.'),
      '#attributes' => array(
        'placeholder' => t('Share Image...'),
      ),
      '#default_value' => (isset($data['post_image']) ? $data['post_image'] : ''),
    );

    $form['post_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Share title (optional)'),
      '#description' => t('The title of the post that will appear on the user\'s wall.  If left blank, Facebook will use the page title.'),
      '#attributes' => array(
        'placeholder' => t('Post title...'),
      ),
      '#default_value' => (isset($data['post_title']) ? $data['post_title'] : ''),
    );

    $form['post_caption'] = array(
      '#type' => 'textfield',
      '#title' => t('Share Caption (optional)'),
      '#description' => t('The caption of the post that will appear on the user\'s wall.  If left blank, Facebook will use URL to the page that is shared.'),
      '#attributes' => array(
        'placeholder' => t('Post caption...'),
      ),
      '#default_value' => (isset($data['post_caption']) ? $data['post_caption'] : ''),
    );

    $form['post_description'] = array(
      '#type' => 'textarea',
      '#title' => t('Share Description (optional)'),
      '#description' => t('The description of the post that will appear on the user\'s wall.  If left blank, Facebook will find the body text and use the leading sentences from that.'),
      '#attributes' => array(
        'placeholder' => t('Post description...'),
      ),
      '#default_value' => (isset($data['post_description']) ? $data['post_description'] : ''),
    );    
  }

  public static function ushareRender(&$page, $data) {
    drupal_add_library('connections', 'facebook');
    drupal_add_js("Drupal.behaviors.fb.feed({
      'feed_document': " . (!empty($data['post_url']) ? "'" . $data['post_url'] . "'" : 'document.location.href') . ",
      'feed_title': '" . (!empty($data['post_title']) ? $data['post_title'] : NULL) . "',
      'feed_picture': '" . (!empty($data['post_image']) ? $data['post_image'] : NULL) . "',
      'feed_caption': '" . (!empty($data['post_caption']) ? $data['post_caption'] : NULL) . "',
      'feed_description': '" . (!empty($data['post_description']) ? $data['post_description'] : NULL) . "',
      'feed_selector': '" . (!empty($data['selector']) ? $data['selector'] : NULL) . "'
    });
    ", array(
      'scope' => 'footer',
      'type' => 'inline',
      'weight' => 1000
    ));
  }

  public static function fshareAction(&$form, $data) {
    $form['selector'] = array(
      '#type' => 'textfield',
      '#title' => t('Selector'),
      '#description' => t('The selector (HTML css / id attribute) that will trigger this action.'),
      '#attributes' => array(
        'placeholder' => t('.selector / #selector'),
      ),
      '#default_value' => (isset($data['selector']) ? $data['selector'] : ''),
    );

    $form['post_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Share URL (optional)'),
      '#description' => t('The URL that the user will be brought back to when they click the share.  If left blank, will share the current page.'),
      '#attributes' => array(
        'placeholder' => t('Share URL...'),
      ),
      '#default_value' => (isset($data['post_url']) ? $data['post_url'] : ''),
    );

    $form['post_image'] = array(
      '#type' => 'textfield',
      '#title' => t('Share Image (optional)'),
      '#description' => t('The image that will be shared on the user\'s wall.  If left blank, Facebook will find a likely picture and use that.'),
      '#attributes' => array(
        'placeholder' => t('Share Image...'),
      ),
      '#default_value' => (isset($data['post_image']) ? $data['post_image'] : ''),
    );

    $form['post_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Share title (optional)'),
      '#description' => t('The title of the post that will appear on the user\'s wall.  If left blank, Facebook will use the page title.'),
      '#attributes' => array(
        'placeholder' => t('Post title...'),
      ),
      '#default_value' => (isset($data['post_title']) ? $data['post_title'] : ''),
    );

    $form['post_caption'] = array(
      '#type' => 'textfield',
      '#title' => t('Share Caption (optional)'),
      '#description' => t('The caption of the post that will appear on the user\'s wall.  If left blank, Facebook will use URL to the page that is shared.'),
      '#attributes' => array(
        'placeholder' => t('Post caption...'),
      ),
      '#default_value' => (isset($data['post_caption']) ? $data['post_caption'] : ''),
    );

    $form['post_description'] = array(
      '#type' => 'textarea',
      '#title' => t('Share Description (optional)'),
      '#description' => t('The description of the post that will appear on the user\'s wall.  If left blank, Facebook will find the body text and use the leading sentences from that.'),
      '#attributes' => array(
        'placeholder' => t('Post description...'),
      ),
      '#default_value' => (isset($data['post_description']) ? $data['post_description'] : ''),
    );    
  }

  public static function fshareRender(&$page, $data) {
    drupal_add_library('connections', 'facebook');
    drupal_add_js("Drupal.behaviors.fb.feed({
      'feed_document': " . (!empty($data['post_url']) ? "'" . $data['post_url'] . "'" : 'document.location.href') . ",
      'feed_title': '" . (!empty($data['post_title']) ? $data['post_title'] : NULL) . "',
      'feed_picture': '" . (!empty($data['post_image']) ? $data['post_image'] : NULL) . "',
      'feed_caption': '" . (!empty($data['post_caption']) ? $data['post_caption'] : NULL) . "',
      'feed_description': '" . (!empty($data['post_description']) ? $data['post_description'] : NULL) . "',
      'feed_selector': '" . (!empty($data['selector']) ? $data['selector'] : NULL) . "',
      'feed_allow_multiple': true
    });
    ", array(
      'scope' => 'footer',
      'type' => 'inline',
      'weight' => 1000
    ));
  }

  public static function gateAction(&$form, $data) {
    $form['selector'] = array(
      '#type' => 'textfield',
      '#title' => t('Selector'),
      '#description' => t('The selector (HTML css / id attribute) that will trigger this action.  <b>If nothing is specified here, the page will be gated as soon as it is loaded.</b>'),
      '#attributes' => array(
        'placeholder' => t('.selector / #selector'),
      ),
      '#default_value' => (isset($data['selector']) ? $data['selector'] : ''),
    );

    $form['redirect'] = array(
      '#type' => 'textfield',
      '#title' => t('Redirect path'),
      '#description' => t('The relative path, without leading slash ("/"), to the page that the user should be redirected to after they authenticate.  Only write in relative paths like "blog/7-facts-about-kittens" or "about/team".'),
      '#attributes' => array(
        'placeholder' => t('Redirect path...'),
      ),
      '#default_value' => (isset($data['post_url']) ? $data['post_url'] : ''),
    );
  }

  public static function gateRender(&$page, $data) {
    drupal_add_library('connections', 'facebook');
    $app_id = variable_get('social_manager_facebook_app_id');

    drupal_add_js("Drupal.behaviors.fb.gate({
      'gate_call_fb': 2,
      'gate_app_id': '" . $app_id . "',
      'gate_selector': " . (!empty($data['selector']) ? "'" . $data['selector'] . "'" : 'null') . ",
      'redirect': " . (!empty($data['redirect']) ? "'" . $data['redirect'] . "'" : 'null') . ",
    });
    ", array(
      'scope' => 'footer',
      'type' => 'inline',
      'weight' => 1000
    ));
  }
}