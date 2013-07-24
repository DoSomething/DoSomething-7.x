## Writing Behat tests

(Behat)[http://behat.org/] is a testing framework, based off of Rails' (Cucumber)[https://github.com/cucumber/cucumber-rails], centered around the idea of (Behavior Driven Development)[http://en.wikipedia.org/wiki/Behavior-driven_development].  It is assumed (though not required) that you should write tests *first*, then write your code based off of the tests that you wrote.  Your tests can and will change during your coding process.

Behat works in collaboration with Selenium to offer a headless testing experience, with any modern browser.

Behat uses a combination of **features** and **steps** to make tests possible.  A typical feature might look like this:

```
Feature: Log in tests
  As an anonymous user
  If I want to log in
  I need to use the log in form

  Background:
    Given I am on "/login"

  Scenario: Fail log in
    When I fill in the following:
      | Your name | Mike |
      | Your pass  | testing123 |
   And I press "Log In"
   Then I should see "Incorrect login credentials."

  Scenario: Pass log in
    When I fill in the following:
      | Your name | Mike |
      | Your pass  | testing456 |
    And I press "Log in"
    Then I should see "Log in successful!"
```
