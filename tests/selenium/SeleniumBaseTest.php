<?php

$app_base_path = realpath(dirname(__FILE__) . '/../..');
$app_cur_path = dirname(__FILE__);

chdir($app_base_path);
require_once './sites/default/site-settings.php';

chdir($app_cur_path);
require_once $app_cur_path . '/php-webdriver/__init__.php';

/**
 * The base test for PHPUnit tests that need Selenium Web Driver. To use, 
 * extend this base class, and define public methods that start with
 * 'test'. See SanityTest for examples.
 * 
 * @see SeleniumSanityTest
 * @see https://github.com/facebook/php-webdriver
 */
class SeleniumBaseTest extends PHPUnit_Framework_TestCase {
  
  /**
   * Base URL of testing site.
   *
   * @var string
   */
  protected $base_url;
  
  /**
   * Selenium host endpoint.
   *
   * @var string
   */
  protected $wd_host;
  
  /**
   * @var WebDriver
   */
  protected $web_driver;
  
  /**
   * @var WebDriverSession
   */
  protected $session;
  
  /**
   * Test case setup.
   */
  public function setUp() {
    parent::setUp();
    
    // Selenium setup.
    $this->wd_host = 'http://127.0.0.1:4444/wd/hub'; // this is the default
    $this->web_driver = new WebDriver($this->wd_host);
    $this->session = $this->web_driver->session('firefox');  
    
    // Try to get the base URL from the local Drupal settings.
    if (!empty($GLOBALS['base_url'])) {
      $this->base_url = $GLOBALS['base_url'];
    } else {
      exit('No base URL! Set $base_url in site-settings.php.');
    }
  }
  
  /**
   * Tear down: Close the session, and any other business.
   */
  public function tearDown() {
    if (is_object($this->session)) {
      $this->session->close();
    }
    
    parent::tearDown();
  }
}
