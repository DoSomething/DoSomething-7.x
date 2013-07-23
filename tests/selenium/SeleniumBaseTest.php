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
  protected $base_url = 'http://qa.ds.lan';

  /**
   * Base tests directory. Can be overridden in site-settings.php.
   *
   * @var string
   */
  protected $base_path_tests;

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
   * Base directory to store mocks used in tests.
   * @var string
   */
  protected $mocksDir;

  /**
   * Test case setup.
   */
  public function setUp() {
    parent::setUp();

    // Selenium setup.
    $this->wd_host = 'http://127.0.0.1:4444/wd/hub'; // This is the default selenium server.
    $this->web_driver = new WebDriver($this->wd_host);
    $this->session = $this->web_driver->session('firefox');

    // Try to get the base URL from the local Drupal settings.
    #if (!empty($GLOBALS['base_url'])) {
      #$this->base_url = $GLOBALS['base_url'];
    #} else {
      #exit('No base URL! Set $base_url in site-settings.php.');
    #}

    $this->base_path_tests = __DIR__ . '/../../tests';
    if (!empty($GLOBALS['base_path_tests'])) {
      $this->base_path_tests = $GLOBALS['base_path_tests'];
    }

    $this->screenshotDir = $this->base_path_tests . '/selenium/screenshots';
    $this->mocksDir = $this->base_path_tests . '/selenium/mocks';

    if (!is_dir($this->screenshotDir)) {
      if (FALSE === mkdir($this->screenshotDir)) {
        exit(sprintf("Can't create the screenshot directory at %s", $this->screenshotDir));
      }
      `echo 'Options +Indexes' > {$this->screenshotDir}/.htaccess`;
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

    return array();
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

  /**
   * Handles the standard exceptions.  Makes a screenshot and spits out the problems.
   *
   * @param Exception $e
   *   The exception that has been caught.
   *
   * @param string $filename
   *   The name of the file that will be created, WITHOUT extension.
   */
  protected function catchException(Exception $e, $filename = 'test_error') {
    $this->make_screenshot($filename . '.png');
    $this->fail($e->getMessage());
  }

  /**
   * Connects to a url and checks that the title matches a string.
   *
   * @param string $check_path
   *   The relative url, including leading slash, to the location you want to go.
   *
   * @param string $check_title
   *   A string that should be contained within the title of the page.
   */
  protected function basicSession($check_path, $check_title) {
    $this->session->open($this->base_url . $check_path);

    // Make sure that the title suggests it's the common app petition.
    $title = $this->getText('tag name', 'title');
    $this->assertContains($check_title, $title);
  }
}
