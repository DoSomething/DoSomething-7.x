Feature: Project tests
  As a site visitor
  I can submit a project.

  Background:
    Given I am on "/projects"

  Scenario: See the projects landing page
    Then I should see "Projects"
    And I should see "Start a Project"
    And I should see "next ›"

  Scenario: Start a Project, logged out
    When I follow "Start a Project"
    Then I should see "Sign In"

  Scenario: Start a Project, logged in.
    Given I am logged in as a regular user
    And I am on "/projects"
    When I follow "Start a Project"
    Then I should see "Submit Your Project"

    When I fill in the following:
      | edit-submitted-field-project-title-und-0-value | Test |
      | edit-submitted-field-essay-see-it-und-0-value | Test failures. |
      | edit-submitted-field-essay-build-it-und-0-value | Write a test so things don't fail. |
      | edit-submitted-field-link-und-0-title | Test the Web |
      | edit-submitted-field-link-und-0-url | http://www.testtheweb.org |
    And I select "-Bullying" from "edit-submitted-taxonomy-vocabulary-5-und"
    And I press "Submit"

    Then I should see "Test"
    And I should see "Test failures."
    And I should see "Write a test so things don't fail."
    And I should see "Test the Web - http://www.testtheweb.org"
    And I should see "Bullying"
    And I should see "Start a Project"
    And I should see "Related Stuff"
