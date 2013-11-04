Feature: Campaign tests
  As a site visitor
  I want to sign up for
  And participate in a campaign

  Background:
    Given I am on "/money"

  Scenario: See gate page
    Then I should see "Sign in"
    And I should see "Sign Up to Run a Workshop"

  Scenario: Log in to see campaign
    When I fill in the following:
      | edit-name | bohemian_test |
      | edit-pass | bohemian_test |
    And I press "Log in"
    Then I should see "Help arm your friends with tools to stack their cash."
    And I should see "How'd your workshop go?"
    And I should see "Gallery"
    And I should see "Frequently Asked Questions"
    And I should see "Questions? Email "

