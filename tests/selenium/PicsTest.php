<?php

require_once 'SeleniumBaseTest.php';

/**
 * Pics for Pets Testing
 */
class PicsSanityTest extends SeleniumBaseTest {

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

  /**
   * Tests Pics for Pets filters.
   */
  public function testFilterTest() {
  	try {
  	  // Load up p4p
      $this->session->open('http://qa2.dosomething.org/picsforpets-2013');

      // Log in again.
	  $this->session->element('css selector', '.or-sign-in')->click();
      $name = $this->session->element('css selector', '#edit-name--3')->value($this->split_keys('admin'));
      $this->session->element('css selector', '#edit-pass--3')->value($this->split_keys('do something about passwords'));
      $this->session->element('css selector', '#edit-final-submit--2')->click();

      // Check the title
      $title = $this->session->element('tag name', 'title')->text();
      $this->assertContains('Pics for Pets', $title);
  
      // Select cats...
      $this->session->element('xpath', '//*[@id="main-wrapper"]/div/div/div[3]/select[1]/option[2]')->click()  ;

      // Gooooooooooooo
      $this->session->element('css selector', '.go-filter')->click()  ;

      // Page reloaded.  Check for Kitteh
      $wrapper = $this->session->element('css selector', '.view-content')->text();
      $this->assertContains('Kitteh', $wrapper);

      // Okay, now let's go to South Carolina
      $this->session->element('xpath', '//*[@id="main-wrapper"]/div/div/div[3]/select[2]/option[48]')->click();
      $this->session->element('css selector', '.go-filter')->click();

      // Page reloaded again.
      $nothing = $this->session->element('css selector', '.view-empty')->text();
      $this->assertContains('NO POSTS YET', $nothing);

      // We good? We good. Onto "all animals" in south carolina.
      $this->session->element('xpath', '//*[@id="main-wrapper"]/div/div/div[3]/select[1]/option[1]')->click();
      $this->session->element('css selector', '.go-filter')->click();

      // Check for bunny the bunny.
      $wrapper = $this->session->element('css selector', '.view-content')->text();
      $this->assertContains('Bunny', $wrapper);
    }
    catch (Exception $e) {
      $this->make_screenshot('picsforpets_filter.png');
      $this->fail($e->getMessage());
    }
  }
}