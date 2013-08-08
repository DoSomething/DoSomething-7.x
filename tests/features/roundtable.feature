Feature: Roundtable discussion
  a short description
  of our meeting

  Background:
    Given I am on "/user/login"

  @javascript
  Scenario: I log in
    Then I should see "Sign In"
    When I fill in "edit-name" with "bohemian_test"
    And I fill in "edit-pass" with "bohemian_test"
    And I press "Log in"
    Then I should see "CAMPAIGNS"
