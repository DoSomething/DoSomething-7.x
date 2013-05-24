<?php

require_once 'SeleniumBaseTest.php';

/**
 * Quiz Testing
 */
class QuizzesTest extends SeleniumBaseTest {
  /**
   * Tests the quizzes landing page..
   */
  public function testQuizzesLanding() {
    try {
      // Go to the quizzes landing page.
      $this->session->open($this->base_url . '/quizzes');

      // Make sure it is the quizzes landing page.
      $header = $this->getText('id', 'page-title');
      $this->assertSame('Quizzes', $header);

      // Make sure that there are quizzes on the quizzes landing page.
      $quizzes = $this->session->elements('class name', 'views-field');
      $this->assertGreaterThan(5, count($quizzes));
    }
    catch (Exception $e) {
      $this->catchException($e, 'quizzes_landing');
    }
  }

  /**
   * Tests the quiz flow.
   */
  public function testQuizzesQuizTest() {
    try {
      // Go to the quizzes landing page.
      $this->session->open($this->base_url . '/quiz/which-pop-diva-are-you-0');

      // Make sure we're looking at the Pop Diva quiz.
      $header = $this->getText('css selector', '.pane-custom h3');
      $this->assertSame('Which Pop Diva Are You?', $header);

      // Fill out the form with arbitrary values.
      $this->findAndClick('xpath', '//*[@id="edit-submitted-free-time-2"]');
      $this->findAndClick('xpath', '//*[@id="edit-submitted-perfect-school-2"]');
      $this->findAndClick('xpath', '//*[@id="edit-submitted-describe-you-0"]');
      $this->findAndClick('xpath', '//*[@id="edit-submitted-dream-career-4"]');
      $this->findAndClick('xpath', '//*[@id="edit-submitted-dream-guy-0"]');

      // Fill out the 
      $this->findAndSet('id', 'edit-submitted-first-name', 'testy');
      $this->findAndSet('id', 'edit-submitted-email-or-cell', 'testing+' . substr(md5(time()), 0, 6) . '@dosomething.org');
      $this->findAndSet('id', 'edit-submitted-password', 'testing123');

      // Submit the quiz.
      $this->findAndClick('id', 'edit-submit');

      // Which pop diva ARE you?
      $header = $this->getText('css selector', '.pane-custom h3');
      $this->assertSame('Which Pop Diva Are You?', $header);

      // The actual result.  We're Rihanna, apparently.
      $result = $this->getText('css selector', '.pane-page-title h1');
      $this->assertSame('You are...Rihanna!', $result);

      // Descriptive text...
      $text = $this->getText('class name', 'field-name-field-body');
      $this->assertContains('You are one badass chick and do your own thing', $text);

      // Make sure the "related quizzes" block exists.
      $related = $this->getText('css selector', '.pane-narrow-block h2');
      $this->assertSame('Related Quizzes', $related);

      // Make sure there are related quizzes.  More than 1.
      $related_results = $this->session->elements('css selector', '.view-id-quizzes ul li');
      $this->assertGreaterThan(1, count($related_results));

      // We should be logged in now.  The form should have created an account for us and logged us in.
      $loggedin = $this->getText('css selector', '#block-dosomething-blocks-dosomething-utility-bar .login a');
      $this->assertSame('LOG OUT', $loggedin);
    }
    catch (Exception $e) {
      $this->catchException($e, 'quizzes_quiz');
    }
  }
}