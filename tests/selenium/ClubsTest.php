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
      $this->session->element('id', 'edit-field-no-school-associate-und')->click();
      $this->session->element('id', 'edit-field-noschool-club-name-und-0-value')->value($this->split_keys('Selenium test'));

      // Club name
      $clubname = $this->session->element('css selector', '#club-name-live span')->text();
      $this->assertSame('Selenium test', $clubname);

      // Account information
      $this->session->element('id', 'edit-field-email-und-0-value')->value($this->split_keys('mchittenden+seleniumtest' . rand(1,1000000) . '@dosomething.org'));
      $this->session->element('id', 'edit-field-phone-required-und-0-value')->value($this->split_keys('6103683195'));
      $this->session->element('id', 'edit-password')->value($this->split_keys('testin123'));

      // User information
      $this->session->element('id', 'edit-field-name-und-0-value')->value($this->split_keys('Testing'));
      $this->session->element('id', 'edit-field-name-last-und-0-value')->value($this->split_keys('User'));
      $this->session->element('id', 'edit-field-club-leader-birthdate-und-0-value-date')->value($this->split_keys('03/16/1988'));

      // Campaign
      $this->session->element('xpath', '//*[@id="edit-field-campaign-list-und"]/div[1]/input')->click();
      
      // Mailing address
      $this->session->element('id', 'edit-field-club-address-und-0-value')->value($this->split_keys('123 Vertical Rd'));
      $this->session->element('id', 'edit-field-club-city-und-0-value')->value($this->split_keys('Omaha'));
      $this->session->element('xpath', '//*[@id="edit-field-club-state-und"]/option[37]')->click();
      $this->session->element('xpath', '//*[@id="edit-field-country-und"]/option[236]')->click();
      $this->session->element('id', 'edit-field-club-zip-und-0-value')->value($this->split_keys('12345'));

      // SUbmit the form.
      $this->session->element('id', 'edit-submit')->click();

      // We should be on the "Invite your friends" page now.
      $shareheader = $this->session->element('css selector', '#share-page-header h1.title')->text();
      $this->assertSame('Invite your friends to your club.', $shareheader);

      // Make sure the cell / email containers are NOT visible.
      $cell_container = $this->session->element('id', 'cell-share-container')->displayed();
      $e_container = $this->session->element('id', 'email-share-container')->displayed();
      $this->assertFalse($cell_container);
      $this->assertFalse($e_container);

      // Click the "By Cell" button.
      $this->session->element('css selector', '#cell-share a')->click();

      // We should see the cell container now.
      $cc = $this->session->element('id', 'cell-share-container');
      $this->assertTrue($cc->displayed());
      $this->assertContains('Send your friends a text telling them to join the party', $cc->text());

      // There should be 6 visible cell fields.
      $inputs = $this->session->elements('css selector', '#cell-share-container input.cell-share-cell');
      $this->assertEquals(count($inputs), 6);

      // Click "add more" under the cell fields.
      $this->session->element('css selector', '#cell-share-container a.add-more')->click();

      // Now there should be 9.
      $now_inputs = $this->session->elements('css selector', '#cell-share-container input.cell-share-cell');
      $this->assertEquals(count($now_inputs), 9);

      // Click on "By Email"
      $this->session->element('css selector', '#email-share a')->click();

      // The email container should be visible now.
      $email = $this->session->element('id', 'email-share-container');
      $this->assertTrue($email->displayed());
      $this->assertContains('Get Gmail Contacts', $email->text());

      // ...And the cell container should NOT be visible.
      $cell_container = $this->session->element('id', 'cell-share-container')->displayed();
      $this->assertFalse($cell_container);

      // The "manual email" container should be invisible.
      $fe = $this->session->element('css selector', '#email-share-container #manual-emails');
      $this->assertFalse($fe->displayed());

      // Click "I' drather type in my own friend's email addresses"
      $this->session->element('css selector', '#email-share-container .my-own-emails')->click();

      // The "manual email" container is now visible.
      $fe = $this->session->element('css selector', '#email-share-container #manual-emails');
      $this->assertTrue($fe->displayed());

      // There should be 6 email fields.
      $es = $this->session->elements('css selector', '#manual-emails input');
      $this->assertEquals(count($es), 6);

      // Click "add more" under the emails.
      $this->session->element('css selector', '#email-share-container #manual-emails a')->click();

      // There should now be 9 email fields.
      $new_email_count = $this->session->elements('css selector', '#email-share-container input');
      $this->assertEquals(count($new_email_count), 9);

      // Continue to the actual club!
      $this->session->element('css selector', '#continue-to-club a')->click();

      // We made it! Let's make sure it's actually our club.
      $clubheader = $this->session->element('css selector', 'h1#page-title')->text();
      $this->assertEquals('Selenium test DoSomething.org Club', $clubheader);
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
      $header = $this->session->element('id', 'page-title')->text();
      $this->assertSame("Michael's Awesome DoSomething.org Club DoSomething.org Club", $header);

      // Confirm that the invite button is there.
      $invite_button = $this->session->element('css selector', '.invite-link #edit-submit');
      $this->assertTrue($invite_button instanceof WebDriverElement);

      $invite_button->click();

      $login_popup = $this->session->element('id', 'dosomething-login-register-popup-form');
      $this->assertTrue($login_popup->displayed());
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
      $header = $this->session->element('id', 'page-title')->text();
      $this->assertSame("Michael's Awesome DoSomething.org Club DoSomething.org Club", $header);

      // Confirm that the invite button is there.
      $member_button = $this->session->element('css selector', '.dosomething-stats .button-container a');
      $this->assertTrue($member_button instanceof WebDriverElement);

      // Click the "members" button
      $member_button->click();

      // Make sure the "members" pop-up appeared
      $member_popup = $this->session->element('class name', 'pane-club-members');
      $this->assertTrue($member_popup->displayed());
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

      // Confirm that the invite button is there.
      $invite_button = $this->session->element('css selector', '.invite-link #edit-submit');
      $this->assertTrue($invite_button instanceof WebDriverElement);

      // Click the "members" button
      $invite_button->click();

      // Make sure the "members" pop-up appeared
      $login_popup = $this->session->element('id', 'dosomething-login-register-popup-form');
      $this->assertTrue($login_popup->displayed());

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