<?php

require_once 'SeleniumBaseTest.php';

class SeleniumSanityTest extends SeleniumBaseTest {
  
  /**
   * Basic sanity test: Load the home page, and find the FAQ text in the 
   * footer.
   *
   * This does NOT require a Drupal bootstrap.
   *
   * @throws NoSuchElementWebDriverError
   * @throws Exception
   */
  public function testSanityTest() {
    $this->session->open($this->base_url);
    
    // Sanity test: check that the footer has loaded by finding the FAQ link.
    $footer_elm = $this->session->element('css selector', 
                    '#block-menu-menu-footer .menu .last .menu .first a');
    
    $this->assertTrue(is_object($footer_elm));
    
    if (is_object($footer_elm)) {
      $this->assertSame('FAQ', $footer_elm->text());
    }
  }
  
  /**
   * Basic screenshot capture. This depends on the basic sanity test,
   * because the browser needs to have loaded a URL (or the screenshot
   * will be boring).
   * 
   * @depends testSanityTest
   */
  public function testSanityScreenshot() {
    
    die($this->session->url());
    
    $file_name = '/vagrant/tests/selenium/screenshot.png';
    $img_data = base64_decode($this->session->screenshot());
    file_put_contents($file_name, $img_data); 
    $this->assertTrue(file_exists($file_name));
  }
}
