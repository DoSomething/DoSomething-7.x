Feature: Register tests
  As an anonymous user
  If I want to register
  Then I need to use the registration form

  Background:
    Given I am on "/user/registration?destination=front"

  Scenario: See the basic stuff
    Then I should see "first name"
    And I should see "last name"
    And I should see "email"
    And I should see "cell"
    And I should see "password"
    And I should see "birthday"

  Scenario: Fail registration (no data)
    When I press "Finish"
    Then I should see "first name"
    And I should see "birthday"

  Scenario: Fail registration (existing user)
    When I fill in the following:
      | edit-first-name | Test                        |
      | edit-last-name  | User                        |
      | edit-email      | mchittenden@dosomething.org |
      | edit-cell       | 212-660-2245                |
      | edit-pass       | testing123                  |
      | edit-month      | 10                          |
      | edit-day        | 05                          |
      | edit-year       | 1998                        |
    And I press "Finish"
    Then I should see "first name"
    And I should see "birthday"

  Scenario: Succeed registration
    When I fill in the following:
      | edit-first-name | Test                             |
      | edit-last-name  | User                             |
      | edit-pass       | testing123                       |
      | edit-month      | 10                               |
      | edit-day        | 05                               |
      | edit-year       | 1998                             |
    And I fill in edit-email with a random email
    And I press "Finish"
    Then I should see "CAMPAIGNS"
    And I should see "CONNECT"
