Feature: Share a Stat tests
  As a site visitor
  I can enter to win a scholarship
  And read about the rules on a campaign.

  Background:
    Given I am on "/women"

  Scenario: See the basic stuff
    Then I should see "Help 25,000 women in need"
    And I should see "How it Works:"
    And I should see "Example From The Experience:"
    And I should see "Start"
    And I should see "More Information On Global Poverty"
    And I should see "Who's Getting The Loans?"
    And I should see "Prizing"
    And I should see "SHARE WITH FRIENDS"
    And I should see "Frequently Asked Questions"
    And I should see "In Partnership With"
    And I should see "Questions?"

  Scenario: Fail signing up (no data)
    When I press "Share"
    Then I should see "Your First Name: field is required"
    And I should see "Your Cell #: field is required"
    And I should see "Your Email: field is required"

  Scenario: Fail signing up (no cell / email)
    When I fill in "edit-alpha-name" with "Mike"
    And I press "Share"
    Then I should see "Your Cell #: field is required"
    Then I should see "Your Email: field is required"

  Scenario: Fail signing up (no cell)
    When I fill in the following:
    | edit-alpha-name  | Mike |
    | edit-alpha-email | mchitten@gmail.com |
    And I press "Share"
    Then I should see "Your Cell #: field is required"

  Scenario: Succeed signing up
    When I fill in the following:
    | edit-alpha-name  | Mike |
    | edit-alpha-mobile  | 212-660-2245 |
    | edit-alpha-email | testing@dosomething.org |
    And I press "Share"
    Then I should see "Thanks for sharing!"
    And I should see "Thanks for sharing about the crazy working conditions poor women face."
    And I should see "Send Me"
