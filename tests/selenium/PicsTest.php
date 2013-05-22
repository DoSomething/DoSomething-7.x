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
      $body = $this->getText('tag name', 'body');
      $this->assertContains('Registration', $body);

      // Click the sign-in popup
      $this->findAndClick('class name', 'or-sign-in');

      // Login credentials
      $this->findAndSet('id', 'edit-name--3', 'admin');
      $this->findAndSet('id', 'edit-pass--3', 'do something about passwords');

      // Submit the login popup
      $this->findAndClick('id', 'edit-final-submit--2');

      // The page reloaded here.  Let's look for the "All Animals" dropdown.
      $selectors = $this->getText('class name', 'crazy-menu-wrapper');
      $this->assertContains('All Animals', $selectors);
    }
    catch (Exception $e) {
      $this->catchException($e, 'picsforpets_login');
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
      $this->findAndClick('class name', 'or-sign-in');
      $this->findAndSet('id', 'edit-name--3', 'admin');
      $this->findAndSet('id', 'edit-pass--3', 'do something about passwords');
      $this->findAndClick('id', 'edit-final-submit--2');

      // Check the title
      $title = $this->getText('tag name', 'title');
      $this->assertContains('Pics for Pets', $title);

      // Select cats...
      $this->findAndClick('xpath', '//*[@id="main-wrapper"]/div/div/div[3]/select[1]/option[2]');

      // Gooooooooooooo
      $this->findAndClick('class name', 'go-filter');

      // Page reloaded.  Check for Kitteh
      $wrapper = $this->getText('class name', 'view-content');
      $this->assertContains('Kitteh', $wrapper);

      // Okay, now let's go to South Carolina
      $this->findAndClick('xpath', '//*[@id="main-wrapper"]/div/div/div[3]/select[2]/option[48]');
      $this->findAndClick('class name', 'go-filter');

      // Page reloaded again.
      $nothing = $this->getText('class name', 'view-empty');
      $this->assertContains('NO POSTS YET', $nothing);

      // We good? We good. Onto "all animals" in south carolina.
      $this->findAndClick('xpath', '//*[@id="main-wrapper"]/div/div/div[3]/select[1]/option[1]');
      $this->findAndClick('class name', 'go-filter');

      // Check for bunny the bunny.
      $wrapper = $this->getText('class name', 'view-content');
      $this->assertContains('Bunny', $wrapper);
    }
    catch (Exception $e) {
      $this->catchException($e, 'picsforpets_filter');
    }
  }

  /**
   * Tests Pics for Pets filters.
   */
  public function testSubmitTest() {
    try {
      // Load up p4p
      $this->session->open('http://qa2.dosomething.org/picsforpets-2013');

      // Log in again.
      $this->findAndClick('class name', 'or-sign-in');
      $this->findAndSet('id', 'edit-name--3', 'admin');
      $this->findAndSet('id', 'edit-pass--3', 'do something about passwords');
      $this->findAndClick('id', 'edit-final-submit--2');

      // Check the title
      $title = $this->getText('tag name', 'title');
      $this->assertContains('Pics for Pets', $title);

      // Click into the submit page.
      $this->findAndClick('class name', 'submit-link');

      // This complicated section uploads an image!
      $image = $this->findAndClick('id', 'edit-submitted-field-cas-image-und-0-upload');
      $image->value($this->split_keys($this->mocksDir . '/bunny.jpg'));
      $image->click();

      // Submit the form.  This should fail.
      $this->findAndClick('id', 'edit-submit');
      $elm = $this->getText('id', 'webform-component-shelter-state');
      $this->assertContains('Shelter State', $elm);

      // This fills out the form!
      $this->findAndSet('id', 'edit-submitted-name', 'Test bunny');
      $this->findAndClick('xpath', '//*[@id="edit-submitted-type"]/option[4]');
      $this->findAndSet('id', 'edit-submitted-shelter', 'Bunny shelter');
      $this->findAndClick('xpath', '//*[@id="edit-submitted-shelter-state"]/option[10]');

      // Submit the form.  This should succeed.
      $this->findAndClick('css selector', '#edit-actions input');

      // Check for the singular post.
      $post = $this->getText('class name', 'view-content');
      $this->assertContains('Test bunny, DE', $post);
    }
    catch (Exception $e) {
      $this->catchException($e, 'picsforpets_submit');
    }
  }
  
}