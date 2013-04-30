<?php

class FacebookService {
  public static $actions = array(
    'Set App ID' => 'appid',
    "Share on a user's wall" => 'ushare',
    "Share on a friend's wall" => 'fshare',
    "Gate a page" => 'gate',
  );

  public static function appidAction(&$form) {
    $form['app_id'] = array(
      '#type' => 'textfield',
      '#attributes' => array(
      	'placeholder' => t('The App ID of your Facebook app'),
      ),
    );

    $form['app_secret'] = array(
      '#type' => 'textfield',
      '#attributes' => array(
      	'placeholder' => t('The App Secret of your Facebook app'),
      ),
    );
  }

  public static function ushareAction() {

  }
}