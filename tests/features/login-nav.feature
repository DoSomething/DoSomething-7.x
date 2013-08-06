Feature: Login Nav tests
  As an anonymous user
  I can login to the site or register

  Scenario: See sign in link on register
    Given I am on "user/registration"
    Then I should see "sign in" in the ".toolbar" element

  Scenario: See register link on sign in
    Given I am on "user/login"
    Then I should see "register" in the ".toolbar" element
    And I should see "Sign in" in the ".headline" element
    And I should see "Forgot your password?" in the ".forgot-password-link" element

  Scenario: See register link on password
    Given I am on "user/password"
    Then I should see "register" in the ".toolbar" element
    And I should see "go back" in the ".go-back" element
    And I should see "Forgot your password?" in the ".headline" element
