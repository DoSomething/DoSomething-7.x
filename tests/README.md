## Writing Behat tests

[Behat](http://behat.org/) is a testing framework, based off of Rails' [Cucumber](https://github.com/cucumber/cucumber-rails), centered around the idea of [Behavior Driven Development](http://en.wikipedia.org/wiki/Behavior-driven_development).  It is assumed (though not required) that you should write tests *first*, then write your code based off of the tests that you wrote.  Your tests can and will change during your coding process.

Behat works in collaboration with Selenium to offer a headless testing experience, with any modern browser.

Behat uses a combination of **features**, **scenarios** and **steps**.  **Features** are a series of **Scenarios**, with **steps** (each individual line) that must pass for the entire scenario to pass.  Steps are written in plain english using the "Given...When...Then" syntax.

A typical feature might look like this:

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

Let's look at this test, section-by-section.

```
Feature: Log in tests
  As an anonymous user
  If I want to log in
  I need to use the log in form
```

Specifies what exactly the feature does.  Descriptive text.

```
  Background:
    Given I am on "/login"
```

***Background*** blocks run once before every scenario.  "Given I am on /login" sets up the fact that the scenario starts on /login.

```Scenario: Fail log in```

A ***Scenario*** is a test, plain and simple.  Everything under a scenario must pass for the scenario to succeed.
```
    When I fill in the following:
      | Your name | Mike |
      | Your pass  | testing456 |
```

This is a simple example but the table can be many rows long.  The left column is the label, the class name, the #id or the xpath of a field.  The right is the value that that field should 

```
   And I press "Log In"
   Then I should see "Incorrect login credentials."
```

Presses a button named "Log in" and expects the text "Incorrect login credentials" to be on the page when the page is finished loading.

All of these actions are set up automatically be a plugin used by Behat.  We do not need to write any code to make the tests work.

To run behat tests, execute the following command:

```sh
# In the root behat directory
./bin/behat
```

Behat will automatically run all feature files found in the **features** directory.
