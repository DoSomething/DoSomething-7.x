Feature: Content tests
  As a site visitor
  I can view content in blogs, tips and tools and action guides

  Scenario: See the front page
    Given I am on the homepage
    Then I should see "CAMPAIGNS"
    And I should see "What's Happening Now"
    And I should see "Share of the Day"
    And I should see "CONNECT"

  Scenario: See a blog page
    Given I am on "/blog/defense-marriage-act-doma-struck-down"
    Then I should see "Cheat Sheet: DOMA Struck Down"
    And I should see "On June 26, 2013, the gay rights movement saw a major win"
    And I should see "Start a gay-straight alliance in your school"
    And I should see "Related Posts"
    And I should see "Related Causes"

  Scenario: See a Tips & Tools Page
    Given I am on "/tipsandtools/11-facts-about-cyber-bullying"
    Then I should see "11 Facts About Cyber Bullying"
    And I should see "is defined as a young person tormenting, threatening"
    And I should see "Related Stuff"
    And I should see "Read more on facts about bullying"

  Scenario: See Act Now Guide
    Given I am on "/actnow/actionguide/how-to-handle-bully"
    Then I should see "How To: Handle a Bully"
    And I should see "DO THIS!"
    And I should see "Follow the Golden Rule"
    And I should see "Tell us what you're doing about this issue"
    And I should see "Related Stuff"
