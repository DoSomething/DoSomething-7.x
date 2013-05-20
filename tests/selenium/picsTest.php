<?php

require_once 'SeleniumBaseTest.php';

/**
 * Pics for Pets Testing
 */
class picsSanityTest extends SeleniumBaseTest {

  /**
   * Confirms that the login gate works.
   */
  public function testLoginTest() {
  	try {
  	  // Load up pics 4 pets.  Testing on QA for now because local isn't showing up.
  	  // @todo: change this to local
      $this->session->open("http://qa2.dosomething.org/picsforpets-2013");

      // Confirm that we're looking at the registration page.
      $body = $this->session->element('tag name', 'body')->text();
      $this->assertContains('Registration', $body);

      // Click the sign-in popup
      $this->session->element('css selector', '.or-sign-in')->click();

      // Login credentials
      $name = $this->session->element('css selector', '#edit-name--3')->value($this->split_keys('admin'));
      $this->session->element('css selector', '#edit-pass--3')->value($this->split_keys('do something about passwords'));

      // Submit the login popup
      $this->session->element('css selector', '#edit-final-submit--2')->click();

      // The page reloaded here.  Let's look for the "All Animals" dropdown.
      $selectors = $this->session->element('css selector', '.crazy-menu-wrapper')->text();
      $this->assertContains('All Animals', $selectors);
    }
    catch (Exception $e) {
      // Did we fail? Make a screenshot.
      $this->make_screenshot('picsforpets_login.png');

      // Show the error message.
      $this->fail($e->getMessage());
    }
  }
}