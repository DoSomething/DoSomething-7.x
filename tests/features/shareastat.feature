Feature: Petition tests
  As a site visitor
  I can sign petitions

  Background:
    Given I am on "/social-scholarship/climate-change"

  Scenario: See the basic stuff
    Then I should see "Fight Climate Change Like a Ninja Scholarship"
    And I should see "Share this stat with six friends for a chance to win a $2000 Scholarship"
    And I should see "Ninjas emit 86% less CO2 than the average person. Why? Because ninjas don't drive. They use parkour."
    And I should see "Text STOP to opt-out"

  Scenario: Fail submitting the form (no data)
    When I press "Submit"
    Then I should see "You must provide a valid name"
    And I should see "Your phone number must be a valid phone number"
    And I should see "You must provide at least one valid cell phone number"

  Scenario: Succeed submission
    When I fill in the following:
      | edit-submitted-referall-your-info-referral-first-name | Test User    |
      | edit-submitted-referall-your-info-referral-phone-number | 212-660-2245 |
      | edit-submitted-referral-friend-info-referral-friend-cell-1 | 212-660-2245 |
    And I press "Submit"
    Then I should see "Cause: Environment"