<?php

require_once 'SeleniumBaseTest.php';

/**
 * Share a Stat Testing
 */
class SaSTest extends SeleniumBaseTest {
  private $scholarship = 'climate-change';
  /**
   * Test failing with no information.
   */
  public function testSaSFailsEverything() {
    // Go to the quizzes landing page.
    $this->session->open($this->base_url . '/social-scholarship/' . $this->scholarship);

    // Make sure it is the quizzes landing page.
    $header = $this->getText('id', 'page-title');
    $this->assertSame('Fight Climate Change Like a Ninja Scholarship', $header);

    $this->findAndClick('css selector', '#edit-submit');
    $this->make_screenshot('sas_fails_all_errors');
    $errors = $this->getText('class name', 'error');
    $this->assertContains('You must provide a valid name', $errors);
    $this->assertContains('Your phone number must be a valid phone number', $errors);
    $this->assertContains('You must provide at least one valid cell phone number', $errors);
  }

  /**
   * Test failing with your phone number, but no friends' #'s.
   */
  public function testSaSFailsFriend() {
    // Go to the quizzes landing page.
    $this->session->open($this->base_url . '/social-scholarship/' . $this->scholarship);

    // Make sure it is the quizzes landing page.
    $header = $this->getText('id', 'page-title');
    $this->assertSame('Fight Climate Change Like a Ninja Scholarship', $header);

    $this->findAndSet('css selector', '#edit-submitted-referall-your-info-referral-first-name', 'Test User');
    $this->findAndSet('css selector', '#edit-submitted-referall-your-info-referral-phone-number', '212-660-2245');

    $this->findAndClick('css selector', '#edit-submit');
    $this->make_screenshot('sas_fails_friend_errors');
    $errors = $this->getText('class name', 'error');
    $this->assertContains('You must provide at least one valid cell phone number', $errors);
  }
  /**
   * Tests the quizzes landing page..
   */
  public function testSaSSuccess() {
    try {
      // Go to the quizzes landing page.
      $this->session->open($this->base_url . '/social-scholarship/' . $this->scholarship);

      // Make sure it is the quizzes landing page.
      $header = $this->getText('id', 'page-title');
      $this->assertSame('Fight Climate Change Like a Ninja Scholarship', $header);

      $this->findAndSet('css selector', '#edit-submitted-referall-your-info-referral-first-name', 'Test User');
      $this->findAndSet('css selector', '#edit-submitted-referall-your-info-referral-phone-number', '212-660-2245');

      $this->findAndSet('css selector', '#edit-submitted-referral-friend-info-referral-friend-cell-1', '212-660-2245');

      $this->findAndClick('css selector', '#edit-submit');

      $this->make_screenshot('sas_thx_for_sharing');
      $content = $this->getText('css selector', 'div[role="main"]');
      $this->assertContains('Thanks for sharing', $content);

      $this->make_screenshot('sas.png');
    }
    catch (Exception $e) {
      $this->catchException($e, 'sas_landing');
    }
  }
}