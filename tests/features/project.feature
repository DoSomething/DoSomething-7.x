Feature: Project tests
  As a site visitor
  I can view a Project

  Scenario: Anon user sees a Project when viewing a non-gated published Project
    Given there is a Project
    And I am on "/test-project"
    Then I should see "Test Project" in the "#header" element
    And I should not see an ".admin" element
    And I should see "Test Project Headline" in the "#headline" element
    And I should see "Test Project Subheadline" in the "#headline" element
    And I should see "Test Project SMS Referral Info Copy" in the ".campaign-section.sms" element
    And I should see "Test Project CTA Copy" in the ".campaign-section.call-to-action" element
    And I should see "Test Project Action Items Headline" in the ".campaign-section.how-it-works" element
    And I should see "Test Project Reportback Copy" in the ".campaign-section.reportback" element
    And I should see "Test Project Prizes Copy" in the ".campaign-section.prizing" element
    And I should see "Test Project SMS Example Headline" in the ".campaign-section.sms-game-example" element
    And I should see "Test Project Gallery Headline" in the ".campaign-section.gallery" element
    And I should see "Test Project Project Profiles Headline" in the ".campaign-section.profiles" element
    And I should see "Test Project FAQ Headline" in the ".campaign-section.faq" element
    