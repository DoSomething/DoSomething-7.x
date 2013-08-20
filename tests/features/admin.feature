Feature: Admin tests
  As a site user
  I have access denied or granted based on my role

  Scenario: Anon cannot see the admin page
    Given I am on "/admin"
    Then I should see "Access denied"

  Scenario: Regular user cannot see the admin page
    Given I am logged in as a regular user
    And I am on "/admin"
    Then I should see "Access denied"

  Scenario: DS Staff can see the admin page
    Given I am logged in as a staff
    And I am on "/admin"
    Then I should see "Administration"