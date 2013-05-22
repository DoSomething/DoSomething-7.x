<?php

require_once 'SeleniumBaseTest.php';

/**
 * Clubs Testing
 */
class ClubsTest extends SeleniumBaseTest {
  /**
   * Test creating of the clubs.
   */
  public function testCreateClubFlowTest() {
    try {
      // Go to the petition.
      $this->session->open($this->base_url . '/node/add/club');

      $header = $this->session->element('css selector', 'h1#page-title');
      $this->assertTrue($header instanceof WebDriverElement);
      $this->assertSame('Start a Club', $header->text());

      // Switch to no-school-associated-club
      $this->findAndClick('id', 'edit-field-no-school-associate-und');
      $this->findAndSet('id', 'edit-field-noschool-club-name-und-0-value', 'Selenium test');

      // Club name
      $clubname = $this->getText('css selector', '#club-name-live span');
      $this->assertSame('Selenium test', $clubname);

      // Account information
      $this->findAndSet('id', 'edit-field-email-und-0-value', 'mchittenden+' . substr(md5(time()), 0, 6) . '@dosomething.org');
      $this->findAndSet('id', 'edit-field-phone-required-und-0-value', '6103683195');
      $this->findAndSet('id', 'edit-password', 'testing123');

      // User information
      $this->findAndSet('id', 'edit-field-name-und-0-value', 'Testing');
      $this->findAndSet('id', 'edit-field-name-last-und-0-value', 'User');
      $this->findAndSet('id', 'edit-field-club-leader-birthdate-und-0-value-date', '03/16/1988');

      // Campaign
      $this->findAndClick('xpath', '//*[@id="edit-field-campaign-list-und"]/div[1]/input');
      
      // Mailing address
      $this->findAndSet('id', 'edit-field-club-address-und-0-value', '123 Vertical Rd');
      $this->findAndSet('id', 'edit-field-club-city-und-0-value', 'Omaha');
      $this->findAndClick('xpath', '//*[@id="edit-field-club-state-und"]/option[37]');
      $this->findAndClick('xpath', '//*[@id="edit-field-country-und"]/option[236]');
      $this->findAndSet('id', 'edit-field-club-zip-und-0-value', '12345');

      // Submit the form.
      $this->findAndClick('id', 'edit-submit');

      // We should be on the "Invite your friends" page now.
      $shareheader = $this->getText('css selector', '#share-page-header h1.title');
      $this->assertSame('Invite your friends to your club.', $shareheader);

      // Make sure the cell / email containers are NOT visible.
      $this->assertFalse($this->isVisible('id', 'cell-share-container'));
      $this->assertFalse($this->isVisible('id', 'email-share-container'));

      // Click the "By Cell" button.
      $this->findAndClick('css selector', '#cell-share a');

      // We should see the cell container now.
      $cc = $this->session->element('id', 'cell-share-container');
      $this->assertTrue($cc->displayed());
      $this->assertContains('Send your friends a text telling them to join the party', $cc->text());

      // There should be 6 visible cell fields.
      $inputs = $this->session->elements('css selector', '#cell-share-container input.cell-share-cell');
      $this->assertEquals(count($inputs), 6);

      // Click "add more" under the cell fields.
      $this->findAndClick('css selector', '#cell-share-container a.add-more');

      // Now there should be 9.
      $now_inputs = $this->session->elements('css selector', '#cell-share-container input.cell-share-cell');
      $this->assertEquals(count($now_inputs), 9);

      // Click on "By Email"
      $this->findAndClick('css selector', '#email-share a');

      // The email container should be visible now.
      $email = $this->session->element('id', 'email-share-container');
      $this->assertTrue($email->displayed());
      $this->assertContains('Get Gmail Contacts', $email->text());

      // ...And the cell container should NOT be visible.
      $cell_container = $this->session->element('id', 'cell-share-container')->displayed();
      $this->assertFalse($cell_container);

      // The "manual email" container should be invisible.
      $this->assertFalse($this->isVisible('css selector', '#email-share-container #manual-emails'));

      // Click "I' drather type in my own friend's email addresses"
      $this->findAndClick('css selector', '#email-share-container .my-own-emails');

      // The "manual email" container is now visible.
      $this->assertTrue($this->isVisible('css selector', '#email-share-container #manual-emails'));

      // There should be 6 email fields.
      $es = $this->session->elements('css selector', '#manual-emails input');
      $this->assertEquals(count($es), 6);

      // Click "add more" under the emails.
      $this->findAndClick('css selector', '#email-share-container #manual-emails a');

      // There should now be 9 email fields.
      $new_email_count = $this->session->elements('css selector', '#email-share-container input');
      $this->assertEquals(count($new_email_count), 9);

      // Continue to the actual club!
      $this->findAndClick('css selector', '#continue-to-club a');

      // We made it! Let's make sure it's actually our club.
      $clubheader = $this->getText('css selector', 'h1#page-title');
      $this->assertSame('Selenium test DoSomething.org Club', $clubheader);
    }
    catch (Exception $e) {
      $this->make_screenshot('clubs_create.png');
      $this->fail($e->getMessage());
    }
  }

  /**
   * Test the "Join" button as a logged out member.
   */
  public function testLoggedOutJoinTest() {
    try {
      // Go to the petition.
      $this->session->open($this->base_url . '/club/michaels-awesome-dosomethingorg-club');

      // Make sure the ridiculously formed name is correct.
      $header = $this->getText('id', 'page-title');
      $this->assertSame("Michael's Awesome DoSomething.org Club DoSomething.org Club", $header);

      // Confirm that the invite button is there.
      $this->findAndClick('css selector', '.invite-link #edit-submit');

      // Make sure the login popup appears
      $this->assertTrue($this->isVisible('id', 'dosomething-login-register-popup-form'));
    }
    catch (Exception $e) {
      $this->make_screenshot('clubs_join_logged_out.png');
      $this->fail($e->getMessage());
    }
  }

  /**
   * Test the member popup.
   */
  public function testLoggedOutMembersList() {
    try {
      // Go to the petition.
      $this->session->open($this->base_url . '/club/michaels-awesome-dosomethingorg-club');

      // Make sure the ridiculously formed name is correct.
      $header = $this->getText('id', 'page-title');
      $this->assertSame("Michael's Awesome DoSomething.org Club DoSomething.org Club", $header);

      // Click the "members" button
      $this->findAndClick('css selector', '.dosomething-stats .button-container a');

      // Make sure the "members" pop-up appeared
      $this->assertTrue($this->isVisible('class name', 'pane-club-members'));
    }
    catch (Exception $e) {
      $this->make_screenshot('clubs_members_logged_out.png');
      $this->fail($e->getMessage());
    }
  }

  /**
   * Request to join flow.
   */
  public function testLoggedInJoinTest() {
    try {
      // Go to the petition.
      $this->session->open($this->base_url . '/club/michaels-awesome-dosomethingorg-club');

      // Make sure the ridiculously formed name is correct.
      $header = $this->getText('id', 'page-title');
      $this->assertSame("Michael's Awesome DoSomething.org Club DoSomething.org Club", $header);

      // Click the "Join" button.
      $this->findAndClick('css selector', '.invite-link #edit-submit');

      // Make sure the "members" pop-up appeared
      $this->assertTrue($this->isVisible('id', 'dosomething-login-register-popup-form'));

      // Fill out the register form.
      $this->findAndSet('id', 'edit-first-name--2', 'Test');
      $this->findAndSet('id', 'edit-first-name--2', 'Test');
      $this->findAndSet('id', 'edit-last-name--2', 'User');
      $this->findAndSet('id', 'edit-email', 'mchittenden+' . substr(md5(time()), 0, 6) . '@dosomething.org');
      $this->findAndSet('id', 'edit-pass', 'testing123');
      $this->findAndSet('id', 'edit-month', '03');
      $this->findAndSet('id', 'edit-day', '03');
      $this->findAndSet('id', 'edit-year', '1999');

      // Submit the register form.
      $this->findAndClick('id', 'edit-final-submit');

      // Click the "Join" button, this time as a logged-in member.
      $this->findAndClick('css selector', '.invite-link #edit-submit');

      // Make sure "YOUR MEMBERSHIP IS PENDING" is there.
      $this->assertContains("YOUR MEMBERSHIP IS PENDING", $this->getText('class name', 'invite-link'));

      // Confirm that the invite button is there.
      $this->findAndClick('css selector', '.dosomething-stats .button-container a');

      // Check the popup for...you!
      $member_popup = $this->session->element('class name', 'pane-club-members');
      $this->assertContains('This is you', $member_popup->text());
    }
    catch (Exception $e) {
      $this->make_screenshot('clubs_members_logged_in.png');
      $this->fail($e->getMessage());
    }
  }
}