Feature: Petition tests
  As a site visitor
  I can sign petitions

  Background:
    Given I am on "/petition/common-app"

  Scenario: See the basic stuff
    Then I should see "Common Application: Let Students Submit Videos to Showcase Their Creativity to Colleges"
    And I should see "Sign this Petition"
    And I should see "I think the whole college process"
    And I should see "Reasons for Signing"
    And I should see "Signatures"
    But I should not see "Share this Petition"

  Scenario: Sign the petition
    When I fill in the following:
      | edit-submitted-field-webform-first-name-und-0-value--2 | Test |
      | edit-submitted-field-webform-last-name-und-0-value--2 | User |
      | edit-submitted-field-webform-email-or-cell-und-0-value--2 | testing@dosomething.org |
    Then I should see "Common Application:"

  Scenario: Check out the other petitions
    Given I am on "/petitions"
    Then I should see "Current Petitions"
    And I should see "US Congress"
    And I should see "School Administrators"
