<?php

class SocialApiService {
  public static $_instance;
  protected $dir = __DIR__;

  public function __construct() {
    #echo "!"; exit;
  }

  public static function getInstance() {
  	if (is_null(self::$_instance)) {
  	  self::$_instance = new self();
  	}

  	return self::$_instance;
  }

  public function get($service) {
  	require_once $this->dir . '/services/' . $service . '.inc';
  	return new $service();
  }
}

abstract class SocialServiceLayer extends SocialApiService {

}