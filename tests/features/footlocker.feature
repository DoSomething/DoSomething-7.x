Feature: Foot Locker Scholarship Application
  As a site visitor
  I can see the Foot Locker scholarship
  And I can apply and request recommendations

  Scenario: See the landing page
    Given I am on "/footlocker"
    Then I should see "Foot Locker"

  Scenario: See the About page
    Given I am on "/footlocker/about"
    Then I should see "Foot Locker"
    And I should see "The Foot Locker Scholar Athletes program honors student athletes"
    And I should see "Steps to Apply"
    And I should see "Save The Date"
    And I should see "Additional Info"

  Scenario: See the FAQ page
    Given I am on "/footlocker/faq"
    Then I should see "Foot Locker"
    And I should see "I think I’m a great candidate, what should I do?"
    And I should see "as soon as you can"

  Scenario: See the application initial page
    Given I am on "/footlocker/apply"
    Then I should see "Foot Locker"
    And I should see "About"
    And I should see "Apply"
    And I should see "FAQ"
    And I should see "Eligibility Rules"
    And I should see "What You Need"
    And I should see "Got questions?"