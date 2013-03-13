<?php

/**
 *  SocialApiService is an extendable class that includes necessary APIs from
 *  specific sites and/or services and makes them compatible with your app by
 *  creating a "sub-library" of sorts.
 *
 *  SocialApiService is a singleton class.  It should be called as follows:
 *    $service = SocialApiService::getInstance();
 *
 *  You may then use $service as an instance of SocialApiService.
 *
 *  To include a "service layer" from another API, call "$service->get('xyz');".
 *  The variable assigned to that method will then have direct access to the
 *  service layer and the underlying API (where appropriate).
 *
 *  See documentation for SocialServiceLayer, below.
 */
class SocialApiService {
  /**
   *  Handles the requested instance of SocialApiService.
   */
  public static $_instance;

  /**
   *  Stores the directory that the SocialApiService directory linves in.
   */
  protected $dir = __DIR__;

  /**
   *  Singleton method to return an instance of the class.
   *
   *  @return object
   *    Returns and object of the SocialApiService class.
   */
  public static function getInstance() {
    // If we haven't defined an instance yet, create a new one.
  	if (is_null(self::$_instance)) {
  	  self::$_instance = new self();
  	}

    // Return it.
  	return self::$_instance;
  }

  /**
   *  Gets a service layer library and returns it as a usable object.
   *
   *  @param string $service
   *    The service to be requested.
   *
   *  @return object
   *    Returns an instance of the requested service layer.
   */
  public function get($service) {
  	require_once $this->dir . '/services/' . $service . '.inc';

    // Return a usable instance of the service layer.
  	return new $service();
  }

  /**
   *  Gets dependent scripts, or specific scripts if requested.
   *
   *  @param string $type
   *    "all" to return all scripts, or a specific service name (e.g. "google")
   *    to return only the scripts related to that.
   * 
   *  @return array
   *    An array of scripts, in the order that they were placed in scripts.txt
   *
   *  @see ./services/scripts/scripts.txt
   */
  public function getScripts($type = 'all') {
    // Get the scripts from the cached file.
    $scripts = file_get_contents($this->dir . '/services/scripts/scripts.txt');

    // Split the scripts into a nice little array.
    $scripts = preg_split("#(\r|\n|\r\n)(?!$)#", $scripts);

    // Make sure that we're returning a proper path to the script.
    array_walk($scripts, function(&$val, $key) {
      $val = 'services/scripts/' . trim($val);
    });

    // If we're asking for everything, return everything.
    if ($type == 'all') {
      return $scripts;
    }
    else {
      // Otherwise if we're asking for specific scripts, return only those.
      $return = array();
      foreach ($scripts AS $script) {
        if (FALSE !== (strpos($script, $type . '/'))) {
          $return[] = $script;
        }
      }

      return $return;
    }
  }
}

/**
 *  SocialServiceLayer class is an abstract class that extends the SocialApiService class.
 *  These classes within .inc files found within ./services called "service layers".
 *  Service layers load the actual APIs and provide helper methods to make the APIs easier to use.
 *
 *  Service layers are called from the get() method found in SocialApiService.  Any public method found
 *  Within SocialServiceLayer may be called after get is used().
 *
 *  @see SocialApiService::get()
 *  @see ./services/google.inc
 */
abstract class SocialServiceLayer extends SocialApiService {}
