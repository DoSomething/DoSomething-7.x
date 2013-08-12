Feature: Petition tests
  As a site visitor
  I can sign petitions

  Background:
    Given there is a Petition
    And I am on "/petition/testing-petition-let-us-pass-tests-so-we-can-deploy-code"

  Scenario: See the basic stuff
    Then I should see "Testing petition: Let us pass tests so we can deploy code"
    And I should see "Sign this Petition"
    And I should see "Everyone at DoSomething"
    And I should see "0 of 10,000"
    And I should see "I think that we should have a lot of tests"
    And I should see "Reasons for Signing"
    And I should see "Signatures"
    But I should not see "Share this Petition"

  Scenario: Sign the petition
    When I fill in the following:
      | edit-submitted-field-webform-first-name-und-0-value--2 | Test |
      | edit-submitted-field-webform-last-name-und-0-value--2 | User |
      | edit-submitted-field-webform-email-or-cell-und-0-value--2 | testing@dosomething.org |
    Then I should see "Testing petition:"

  Scenario: Check out the other petitions
    Given I am on "/petitions"
    Then I should see "Current Petitions"
    And I should see "Testing petition"
