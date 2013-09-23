Feature: Project tests
  As a site visitor
  I can view a Project

  Scenario: See a basic published Project
    Given there is a Project
    And I am on "/test-project"
    Then I should see "Test Project"
    And I should see "Test Project Headline"
    And I should see "Test Project Subheadline"
