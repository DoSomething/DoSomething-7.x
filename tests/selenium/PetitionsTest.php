<?php

require_once 'SeleniumBaseTest.php';

/**
 * Petitions Testing
 */
class PetitionsTest extends SeleniumBaseTest {
  /**
   * Test public signing -- signatures should appear in the bottom right box.
   */
  public function testPublicSignatureTest() {
    try {
      // Go to the petition.
      $this->session->open($this->base_url . '/petition/common-app');

      // Make sure that the title suggests it's the common app petition.
      $title = $this->session->element('tag name', 'title')->text();
      $this->assertContains('Common App', $title);

      // Make sure the sign block exists.
      $signature_block = $this->session->element('css selector', '.pane-node-webform h2.pane-title')->text();
      $this->assertSame('Sign This Petition', $signature_block);

      // Fill out the form
      $first_name = $this->session->element('css selector', '#edit-submitted-field-webform-first-name-und-0-value--2');
      $first_name->value($this->split_keys('Test'));
      $last_name = $this->session->element('css selector', '#edit-submitted-field-webform-last-name-und-0-value--2');
      $last_name->value($this->split_keys('User'));
      $email = $this->session->element('css selector', '#edit-submitted-field-webform-email-or-cell-und-0-value--2');
      $email->value($this->split_keys('test@dosomething.org'));

      $this->session->element('css selector', '#edit-submit--2')->click();

      // Make sure the share box is up there.
      $share_box = $this->session->element('css selector', '.pane-petition-share');
      $this->assertTrue($share_box instanceof WebDriverElement);

      // Make sure the share box says "Share this Petition"
      $share_title = $this->session->element('css selector', '.pane-petition-share h2.pane-title')->text();
      $this->assertSame('Share this Petition', $share_title);

      // Make sure Test U is in the signatures list.
      $signatures = $this->session->element('css selector', '.pane-petition-signatures')->text();
      $this->assertContains('Test U', $signatures);
    }
    catch (Exception $e) {
    $this->make_screenshot('petitions_public_signature.png');
      $this->fail($e->getMessage());
    }
  }

  /**
   * Test private signing -- nothing should show up publicly.
   */
  public function testPrivateSignatureTest() {
    try {
      // Go to the petition.
      $this->session->open($this->base_url . '/petition/common-app');

      // Make sure that the title suggests it's the common app petition.
      $title = $this->session->element('tag name', 'title')->text();
      $this->assertContains('Common App', $title);

      // Make sure the sign block exists.
      $signature_block = $this->session->element('css selector', '.pane-node-webform h2.pane-title')->text();
      $this->assertSame('Sign This Petition', $signature_block);

      // Fill out the form
      $first_name = $this->session->element('css selector', '#edit-submitted-field-webform-first-name-und-0-value--2');
      $first_name->value($this->split_keys('New'));
      $last_name = $this->session->element('css selector', '#edit-submitted-field-webform-last-name-und-0-value--2');
      $last_name->value($this->split_keys('User'));
      $email = $this->session->element('css selector', '#edit-submitted-field-webform-email-or-cell-und-0-value--2');
      $email->value($this->split_keys('test@dosomething.org'));

      // Uncheck the "show my signature publicly"
      $check = $this->session->element('css selector', '#edit-submitted-field-webform-petition-signature-und--2');
      $check->click();

      $this->session->element('css selector', '#edit-submit--2')->click();

      // Make sure the share box is up there.
      $share_box = $this->session->element('css selector', '.pane-petition-share');
      $this->assertTrue($share_box instanceof WebDriverElement);

      // Make sure the share box says "Share this Petition"
      $share_title = $this->session->element('css selector', '.pane-petition-share h2.pane-title')->text();
      $this->assertSame('Share this Petition', $share_title);

      // Make sure my signature is NOT seen!
      $signatures = $this->session->element('css selector', '.pane-petition-signatures')->text();
      $this->assertNotContains('New U', $signatures);
    }
    catch (Exception $e) {
      $this->make_screenshot('petitions_private_signature.png');
      $this->fail($e->getMessage());
    }
  }

  /**
   * Show a petition reason.
   * On hold until petitions caching is figured out.
   *
  public function testPetitionReasonTest() {
    try {
      // Go to the petition.
      $this->session->open($this->base_url . '/petition/common-app');

      // Make sure that the title suggests it's the common app petition.
      $title = $this->session->element('tag name', 'title')->text();
      $this->assertContains('Common App', $title);

      // Make sure the sign block exists.
      $signature_block = $this->session->element('css selector', '.pane-node-webform h2.pane-title')->text();
      $this->assertSame('Sign This Petition', $signature_block);

      // First name
      $first_name = $this->session->element('css selector', '#edit-submitted-field-webform-first-name-und-0-value--2');
      $first_name->value($this->split_keys('Petition'));

      // Last name
      $last_name = $this->session->element('css selector', '#edit-submitted-field-webform-last-name-und-0-value--2');
      $last_name->value($this->split_keys('Reason'));

      // Email
      $email = $this->session->element('css selector', '#edit-submitted-field-webform-email-or-cell-und-0-value--2');
      $email->value($this->split_keys('test@dosomething.org'));

      // Reason
      $this->session->element('css selector', '#add-reason-link')->click();
      $this->session->element('css selector', '#edit-submitted-field-webform-petition-reason-und-0-value--2')->value($this->split_keys("It's time, Common App."));

      // Submit
      $this->session->element('css selector', '#edit-submit--2')->click();

      // Make sure the share box is up there.
      $share_box = $this->session->element('css selector', '.pane-petition-share');
      $this->assertTrue($share_box instanceof WebDriverElement);

      // Make sure the share box says "Share this Petition"
      $share_title = $this->session->element('css selector', '.pane-petition-share h2.pane-title')->text();
      $this->assertSame('Share this Petition', $share_title);

      // Check the reasons block for the submission
      $reasons_block = $this->session->element('css selector', '.pane-petition-reasons')->text();
      $this->assertContains('Petition R', $reasons_block);
      $this->assertContains("It's time, Common App.", $reasons_block);
    }
    catch (Exception $e) {
      $this->make_screenshot('petitions_reason.png');
      $this->fail($e->getMessage());
    }
  }*/
}