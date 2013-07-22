<?php

require_once 'SeleniumBaseTest.php';

/**
 * Login / reg testing
 */
class LoginRegTest extends SeleniumBaseTest {
  public function testLoginFail() {
    // try {
  	  $this->basicSession('/user', 'User account');

      $signature_block = $this->getText('id', 'user-login');
      $this->assertContains('Email, Username or Cell Number', $signature_block);
      $this->assertContains('password', $signature_block);

      $this->findAndClick('id', 'edit-submit');

      $errors = $this->getText('class name', 'error');
      $this->assertContains('Email, Username or Cell Number field is required', $errors);
      $this->assertContains('Password field is required', $errors);

    // } catch (Exception $e) {
      
    // }
  }

  public function testLoginSuccess() {
    // try {
  	  $this->basicSession('/user', 'User account');

      // Make sure the sign block exists.
      $signature_block = $this->getText('id', 'user-login');
      $this->assertContains('Email, Username or Cell Number', $signature_block);
      $this->assertContains('password', $signature_block);

      // Fill out the form
      $this->findAndSet('id', 'edit-name', 'bohemian_test');
      $this->findAndSet('id', 'edit-pass', 'bohemian_test');
      $this->findAndClick('id', 'edit-submit');

      $title = $this->getText('id', 'page-title');
      $this->assertSame('Member Profile', $title);
    // } catch (Exception $e) {
      // $this->catchException($e, 'petitions_public_signature');
    // }
  }

  public function testRegisterFail() {
    $this->basicSession('/user/register', 'Registration');

    $this->findAndClick('id', 'edit-final-submit');
    $this->assertContains('Registration', $this->getText('tag name', 'title'));
  }

  public function testRegisterSuccess() {
    $this->basicSession('/user/register', 'Registration');

    $fields = $this->getText('class name', 'popup-content');
    $this->assertContains('First Name', $fields);
    $this->assertContains('Last Name', $fields);
    $this->assertContains('Email', $fields);
    $this->assertContains('Cell', $fields);
    $this->assertContains('Password', $fields);
    $this->assertContains('Birthday', $fields);

    $this->findAndSet('id', 'edit-first-name', 'Test');
    $this->findAndSet('id', 'edit-last-name', 'User');
    $this->findAndSet('id', 'edit-email', 'testing+' . time() . '@dosomething.org');
    $this->findAndSet('id', 'edit-pass', 'testing123');
    $this->findAndSet('id', 'edit-month', '10');
    $this->findAndSet('id', 'edit-day', '05');
    $this->findAndSet('id', 'edit-year', '1995');

    $this->findAndClick('id', 'edit-final-submit');

    $this->make_screenshot('Registered.png');
    // Side bar
    $sidebar = $this->getText('class name', 'ds-member-name-bar');
    $this->assertContains('Test User', $sidebar);

    // Main nav
    $nav = $this->getText('class name', 'region-navigation');
    $this->assertContains('CAMPAIGNS', $nav);

    // Main area
    $news = $this->getText('class name', 'pane-news-stuff');
    $this->assertContains("What's Happening Now", $news);

    // Footer
    $footer = $this->getText('class name', 'region-footer');
    $this->assertContains('CONNECT', $footer);
  }
}

?>