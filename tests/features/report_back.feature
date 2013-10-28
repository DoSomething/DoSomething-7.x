Feature: Campaign Report Backs
  As a campaign visitor
  After I finish a task
  I want to report back

  Background:
    Given I am logged in as a regular user
    And I am on "/50cans"
    And I press "Start"

  Scenario: The campaign has report back text
    Then I should see "Your challenge is simple"
    And I should see "Upload Photos"

  Scenario: The campaign has a report-back page
    When I follow "Upload Photos"
    Then I should see "50 Cans — Report Back"

  Scenario: Upload my image to report back
   When I follow "Upload Photos"
   And I fill out the report back form
   Then I should see "Thanks for reporting back for 50 Cans!"
   And I should see "Return to 50 Cans"

   When I go to "/50cans"
   Then the response should contain "test.jpg"

