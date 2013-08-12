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
    Given there is a Blog
    And I am on "/blog/blog-title"
    Then I should see "Blog title"
    And I should see "Hello world!"

  Scenario: See a Tips & Tools Page
    Given there is a TipsAndTools
    And I am on "/tipsandtools/test-tips-and-tools"
    Then I should see "Test Tips and Tools"
    And I should see "Hello world!"

  Scenario: See Act Now Guide
    Given there is a ActionGuide
    And I am on "/actnow/actionguide/test-action-guide"
    Then I should see "Test Action Guide"
    And I should see "DO THIS!"
    And I should see "Hello world!"
