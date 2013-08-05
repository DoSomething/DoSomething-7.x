Feature: Log in tests
  As an anonymous user
  If I want to log in
  I need to use the login form.

  Background:
    Given I am on "/user?destination=front"
    And there is a Blog with:
      | title | Dogs |
      | body  | cats |

  Scenario: See the basic stuff
    Then I should see "email, username or cell number"
    And I should see "password"

  Scenario: Fail log in (no data)
    When I press "Log in"
    Then I should see "email, username or cell number"
    And I should see "password"

  Scenario: Fail log in (no user)
    When I fill in the following:
      | edit-name | bohemian_test_2903420934 |
      | edit-pass | bohemian_test |
    And I press "Log in"
    Then I should see "email, username or cell number"
    And I should see "password"

  Scenario: Fail log in (wrong pass)
    When I fill in the following:
      | edit-name | bohemian_test |
      | edit-pass | bohemian_test_029340293842 |
    And I press "Log in"
    Then I should see "email, username or cell number"
    And I should see "password"

  Scenario: Succeed log in
    When I fill in the following:
      | edit-name | bohemian_test |
      | edit-pass | bohemian_test |
    And I press "Log in"
    Then I should see "CAMPAIGNS"
    And I should see "CONNECT"
