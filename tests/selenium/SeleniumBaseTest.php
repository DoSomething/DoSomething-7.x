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
   * Base directory to store screenshots.
   * @var string
   */
  protected $screenshotDir;

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

    $this->screenshotDir = '/vagrant/tests/selenium/screenshots';

    if (!is_dir($this->screenshotDir) || !is_writable($this->screenshotDir)) {
      if (FALSE === mkdir($this->screenshotDir)) {
        exit(sprintf("Can't create the screenshot directory at %s", $this->screenshotDir));
      }
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

  /**
   * Splits keys into an array for 'value' method.
   *
   * @param string $toSend
   *   The string that should be split into characters.
   */
  public function split_keys($toSend) {
    return array('value' => preg_split("//u", $toSend, -1, PREG_SPLIT_NO_EMPTY));
  }

  /**
   * Creates a screenshot of a specific name.
   *
   * @param string $name
   *   The name the screenshot should take (e.g. error.jpg).
   */
  public function make_screenshot($name) {
    $file_name = $this->screenshotDir . '/' . $name;
    $img_data = base64_decode($this->session->screenshot());
    file_put_contents($file_name, $img_data);
  }

  /**
   * Finds an element and sets the value of that element.
   *
   * @param string $type
   *   The type of element to search for.
   *
   * @param string $selector
   *   The selector of type $type that should be found.
   *
   * @param string $value
   *   The value that the element should take.
   *
   * @return mixed WebDriverElement object|false
   *   The object, if found, or false.
   *
   * @see https://code.google.com/p/selenium/wiki/JsonWireProtocol#/session/:sessionId/element
   * @see https://code.google.com/p/selenium/wiki/JsonWireProtocol#/session/:sessionId/element/:id/value
   */
  public function findAndSet($type, $selector, $value) {
    $elm = $this->session->element($type, $selector);
    $this->assertTrue($elm instanceof WebDriverElement);
    if ($elm instanceof WebDriverElement) {
      $elm->value($this->split_keys($value));
    }

    return $elm;
  }

  /**
   * Finds an element and clicks it.
   *
   * @param string $type
   *   The type of element to search for.
   *
   * @param string $selector
   *   The selector of type $type that should be found.
   *
   * @return mixed WebDriverElement object|false
   *   The object, if found, or false.
   *
   * @see https://code.google.com/p/selenium/wiki/JsonWireProtocol#/session/:sessionId/element
   * @see https://code.google.com/p/selenium/wiki/JsonWireProtocol#/session/:sessionId/element/:id/click
   */
  public function findAndClick($type, $selector) {
    $elm = $this->session->element($type, $selector);
    $this->assertTrue($elm instanceof WebDriverElement);
    $elm->click();
    return $elm;
  }

  /**
   * Finds an element and gets its text value (stripped of all special characters and tags).
   *
   * @param string $type
   *   The type of element to search for.
   *
   * @param string $selector
   *   The selector of type $type that should be found.
   *
   * @return string|bool
   *   Either the text of the element, or false.
   *
   * @see https://code.google.com/p/selenium/wiki/JsonWireProtocol#/session/:sessionId/element
   * @see https://code.google.com/p/selenium/wiki/JsonWireProtocol#/session/:sessionId/element/:id/text
   */
  public function getText($type, $selector) {
    $elm = $this->session->element($type, $selector);
    $this->assertTrue($elm instanceof WebDriverElement);
    if ($elm instanceof WebDriverElement) {
      return $elm->text();
    }

    return FALSE;
  }

  /** 
   * Confirms whether an element is visible on the page or not.
   *
   * @param string $type
   *   The type of element to search for.
   *
   * @param string $selector
   *   The selector of type $type that should be found.
   *
   * @return bool
   *   Whether or not the element is visible.
   *
   * @see https://code.google.com/p/selenium/wiki/JsonWireProtocol#/session/:sessionId/element
   * @see https://code.google.com/p/selenium/wiki/JsonWireProtocol#/session/:sessionId/element/:id/text
   */
  public function isVisible($type, $selector) {
    $elm = $this->session->element($type, $selector);
    $this->assertTrue($elm instanceof WebDriverElement);
    return $elm->displayed();
  }
}
