 <?php

require_once 'SeleniumBaseTest.php';

// Note: This test doesn't work yet.

/*
chdir($app_base_path);
define('DRUPAL_ROOT', $app_base_path);
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
chdir($app_cur_path);
*/

class SubscribeTest extends SeleniumBaseTest {
  
  /**
   * Basic sanity test: Load the home page, and find the FAQ text in the 
   * footer.
   */
  function testSubscribeTest() {
    try {
      // This is a copy from the quizzes. 
      // Needs to be updated with a real test.
      $this->session->open($this->base_url . '/quizzes');

      // Make sure it is the quizzes landing page.
      $header = $this->getText('id', 'page-title');
      $this->assertSame('Quizzes', $header);

      // Make sure that there are quizzes on the quizzes landing page.
      $quizzes = $this->session->elements('class name', 'views-field');
      $this->assertGreaterThan(20, count($quizzes));
    }
    catch (Exception $e) {
      $this->catchException($e, 'quizzes_landing');
    }
  }
}
