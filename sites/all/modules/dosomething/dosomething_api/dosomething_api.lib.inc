<?php

/**
 * @file
 * An abstraction on top of the DSAPI library 
 */

class DSAPI {
  
  /**
   * Request client
   */
  var $client;

  /**
   *  Resources
   */
  var $Users;

  function __construct($token) {
    $this->client = new Request($token);
  }
}