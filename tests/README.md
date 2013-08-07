## Writing Behat tests

### Introduction

[Behat](http://behat.org/) is a testing framework, based off of Rails' [Cucumber](https://github.com/cucumber/cucumber-rails), centered around the idea of [Behavior Driven Development](http://en.wikipedia.org/wiki/Behavior-driven_development).  It is assumed (though not required) that you should write tests *first*, then write your code based off of the tests that you wrote.  Your tests can and will change during your coding process.

Behat works in collaboration with Selenium to offer a headless testing experience, with any modern browser.

Behat uses a combination of **features**, **scenarios** and **steps**.  **Features** are a series of **Scenarios**, with **steps** (each individual line) that must pass for the entire scenario to pass.  Steps are written in plain english using the "Given...When...Then" syntax.

---

### A .feature file at a glance.

So now that we have the basics out of the way, let's take a look at an example feature file.  These files all reside in ```tests/features```.  You can name a .feature file whatever you want.  ```blah.feature``` will be run just fine, as will ```login.feature```.

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

***Background*** blocks are optional blocks that run once before every scenario.  "Given I am on /login" sets up the fact that the scenario starts on /login.

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

---

### Behat default steps

Behat comes with a number of steps (e.g. ```Given I am on "/page"```) by default, allowing us to write a ton of tests without writing any code at all!

Here they are, with an example of the step written as a comment above each.  You can view the entire list by typing ```bin/behat -di``` from within the ```tests``` directory.

```
# e.g. Given there is a Campaign with:
#  | title | Campaign title |
Given /^there is a (?<factory>[A-Za-z0-9]+) with:$/
    # FeatureContext::thereIsAFactoryWithTheFollowingData()

# e.g. Given there is a Blog
Given /^there is a (?<factory>[A-Za-z0-9]+)$/
    # FeatureContext::thereIsAFactory()

# e.g. Given I am logged in as a regular user
Given /^I am logged in as an? (?<role>regular user|administrator)$/
    # FeatureContext::iAmLoggedInAsRole()

# e.g. Given I am logged in as "user" with pass "abc123"
Given /^I am logged in as "(?<user>[^"]*)" with pass "(?<pass>[^"]*)"$/
    # FeatureContext::iAmLoggedInAsPersonWithPass()

# e.g. Given I log out
Given /^I log out$/
    # FeatureContext::iLogOut()

# e.g. Given I fill in #edit-email with a random email
Given /^I fill in (?<field>.*?) with a random email$/
    # FeatureContext::iFillInARandomEmail()

# e.g. "Given I am on the homepage
Given /^(?:|I )am on (?:|the )homepage$/
    - Opens homepage.
    # FeatureContext::iAmOnHomepage()

# e.g. When I go to the homepage
 When /^(?:|I )go to (?:|the )homepage$/
    - Opens homepage.
    # FeatureContext::iAmOnHomepage()

# e.g. Given I am on "/about"
Given /^(?:|I )am on "(?P<page>[^"]+)"$/
    - Opens specified page.
    # FeatureContext::visit()

# e.g. When I go to "/staff"
 When /^(?:|I )go to "(?P<page>[^"]+)"$/
    - Opens specified page.
    # FeatureContext::visit()

# e.g. When I reload the page
 When /^(?:|I )reload the page$/
    - Reloads current page.
    # FeatureContext::reload()

# e.g. When I move backward one page
 When /^(?:|I )move backward one page$/
    - Moves backward one page in history.
    # FeatureContext::back()

# e.g. When I move forward one page
 When /^(?:|I )move forward one page$/
    - Moves forward one page in history
    # FeatureContext::forward()

# e.g. When I press "Log in"
 When /^(?:|I )press "(?P<button>(?:[^"]|\\")*)"$/
    - Presses button with specified id|name|title|alt|value.
    # FeatureContext::pressButton()

# e.g. When I follow "Read this blog post"
 When /^(?:|I )follow "(?P<link>(?:[^"]|\\")*)"$/
    - Clicks link with specified id|title|alt|text.
    # FeatureContext::clickLink()

# e.g. When I fill in "#edit-name" with "Mike"
 When /^(?:|I )fill in "(?P<field>(?:[^"]|\\")*)" with "(?P<value>(?:[^"]|\\")*)"$/
    - Fills in form field with specified id|name|label|value.
    # FeatureContext::fillField()

# e.g. When I fill in "#edit-desc" with:
# | Blah blah |
# | Some more |
 When /^(?:|I )fill in "(?P<field>(?:[^"]|\\")*)" with:$/
    - Fills in form field with specified id|name|label|value.
    # FeatureContext::fillField()

# e.g. When I fill in "Mike" for "#edit-name"
 When /^(?:|I )fill in "(?P<value>(?:[^"]|\\")*)" for "(?P<field>(?:[^"]|\\")*)"$/
    - Fills in form field with specified id|name|label|value.
    # FeatureContext::fillField()

# e.g. When I fill in the following:
# | edit-name | Mike |
# | edit-last | Sea  |
 When /^(?:|I )fill in the following:$/
    - Fills in form fields with provided table.
    # FeatureContext::fillFields()

# e.g. When I select "Cats" from "Animal Type"
 When /^(?:|I )select "(?P<option>(?:[^"]|\\")*)" from "(?P<select>(?:[^"]|\\")*)"$/
    - Selects option in select field with specified id|name|label|value.
    # FeatureContext::selectOption()

# e.g. When I additionally select "dogs" from "Animal Type"
 When /^(?:|I )additionally select "(?P<option>(?:[^"]|\\")*)" from "(?P<select>(?:[^"]|\\")*)"$/
    - Selects additional option in select field with specified id|name|label|value.
    # FeatureContext::additionallySelectOption()

# e.g. When I check "Follow this thread"
 When /^(?:|I )check "(?P<option>(?:[^"]|\\")*)"$/
    - Checks checkbox with specified id|name|label|value.
    # FeatureContext::checkOption()

# e.g. When I uncheck "Close this thread"
 When /^(?:|I )uncheck "(?P<option>(?:[^"]|\\")*)"$/
    - Unchecks checkbox with specified id|name|label|value.
    # FeatureContext::uncheckOption()

# e.g. When I attach the file "/mocks/mock.jpg" to "Upload your image"
 When /^(?:|I )attach the file "(?P[^"]*)" to "(?P<field>(?:[^"]|\\")*)"$/
    - Attaches file to field with specified id|name|label|value.
    # FeatureContext::attachFileToField()

# e.g. Then I should be on "/blog/hello-world"
 Then /^(?:|I )should be on "(?P<page>[^"]+)"$/
    - Checks, that current page PATH is equal to specified.
    # FeatureContext::assertPageAddress()

# e.g. Then I should be on the homepage
 Then /^(?:|I )should be on (?:|the )homepage$/
    - Checks, that current page is the homepage.
    # FeatureContext::assertHomepage()

# e.g. Then the url should match "/about/team"
 Then /^the (?i)url(?-i) should match (?P<pattern>"([^"]|\\")*")$/
    - Checks, that current page PATH matches regular expression.
    # FeatureContext::assertUrlRegExp()

# e.g. Then the response status code should be 200
 Then /^the response status code should be (?P<code>\d+)$/
    - Checks, that current page response status is equal to specified.
    # FeatureContext::assertResponseStatus()

# e.g. Then the response status code should not be 404
 Then /^the response status code should not be (?P<code>\d+)$/
    - Checks, that current page response status is not equal to specified.
    # FeatureContext::assertResponseStatusIsNot()

# e.g. Then I should see "Welcome to DoSomething"
 Then /^(?:|I )should see "(?P<text>(?:[^"]|\\")*)"$/
    - Checks, that page contains specified text.
    # FeatureContext::assertPageContainsText()

# e.g. Then I should not see "Sorry, you don't have permission to see this page"
 Then /^(?:|I )should not see "(?P<text>(?:[^"]|\\")*)"$/
    - Checks, that page doesn't contain specified text.
    # FeatureContext::assertPageNotContainsText()

# e.g. Then I should see text matching "Remember me"
 Then /^(?:|I )should see text matching (?P<pattern>"(?:[^"]|\\")*")$/
    - Checks, that page contains text matching specified pattern.
    # FeatureContext::assertPageMatchesText()

# e.g. Then I should not see text matching "Banned"
 Then /^(?:|I )should not see text matching (?P<pattern>"(?:[^"]|\\")*")$/
    - Checks, that page doesn't contain text matching specified pattern.
    # FeatureContext::assertPageNotMatchesText()

# e.g. Then the response should contain "OK"
 Then /^the response should contain "(?P<text>(?:[^"]|\\")*)"$/
    - Checks, that HTML response contains specified string.
    # FeatureContext::assertResponseContains()

# e.g. Then the response should not contain "Not Found"
 Then /^the response should not contain "(?P<text>(?:[^"]|\\")*)"$/
    - Checks, that HTML response doesn't contain specified string.
    # FeatureContext::assertResponseNotContains()

# e.g. Then I should see "Welcome!" in the "welcome-block" element
 Then /^(?:|I )should see "(?P<text>(?:[^"]|\\")*)" in the "(?P<element>[^"]*)" element$/
    - Checks, that element with specified CSS contains specified text.
    # FeatureContext::assertElementContainsText()

# e.g. Then I should not see "Please log in" in the "login-block" element
 Then /^(?:|I )should not see "(?P<text>(?:[^"]|\\")*)" in the "(?P<element>[^"]*)" element$/
    - Checks, that element with specified CSS doesn't contain specified text.
    # FeatureContext::assertElementNotContainsText()

# e.g. Then the "welcome-block" element should contain "Welcome!"
 Then /^the "(?P<element>[^"]*)" element should contain "(?P<value>(?:[^"]|\\")*)"$/
    - Checks, that element with specified CSS contains specified HTML.
    # FeatureContext::assertElementContains()

# e.g. Then the "login-block" element should not contain "Please log in"
 Then /^the "(?P<element>[^"]*)" element should not contain "(?P<value>(?:[^"]|\\")*)"$/
    - Checks, that element with specified CSS doesn't contain specified HTML.
    # FeatureContext::assertElementNotContains()

# e.g. Then I should see a "blog-post" element
 Then /^(?:|I )should see an? "(?P<element>[^"]*)" element$/
    - Checks, that element with specified CSS exists on page.
    # FeatureContext::assertElementOnPage()

# e.g. Then I should not see a "login-field" element
 Then /^(?:|I )should not see an? "(?P<element>[^"]*)" element$/
    - Checks, that element with specified CSS doesn't exist on page.
    # FeatureContext::assertElementNotOnPage()

# e.g. Then the "search" field should contain "Bananas"
 Then /^the "(?P<field>(?:[^"]|\\")*)" field should contain "(?P<value>(?:[^"]|\\")*)"$/
    - Checks, that form field with specified id|name|label|value has specified value.
    # FeatureContext::assertFieldContains()

# e.g. Then the "search" field should not contain "Apples"
 Then /^the "(?P<field>(?:[^"]|\\")*)" field should not contain "(?P<value>(?:[^"]|\\")*)"$/
    - Checks, that form field with specified id|name|label|value doesn't have specified value.
    # FeatureContext::assertFieldNotContains()

# e.g. Then the "Remember me" checkbox should be checked
 Then /^the "(?P<checkbox>(?:[^"]|\\")*)" checkbox should be checked$/
    - Checks, that checkbox with specified in|name|label|value is checked.
    # FeatureContext::assertCheckboxChecked()

# e.g. Then the checkbox "Remember me" should be checked
 Then /^the checkbox "(?P<checkbox>(?:[^"]|\\")*)" (?:is|should be) checked$/
    - Checks, that checkbox with specified in|name|label|value is checked.
    # FeatureContext::assertCheckboxChecked()

# e.g. Then the "Email me" checkbox should not be checked
 Then /^the "(?P<checkbox>(?:[^"]|\\")*)" checkbox should not be checked$/
    - Checks, that checkbox with specified in|name|label|value is unchecked.
    # FeatureContext::assertCheckboxNotChecked()

# e.g. Then the checkbox "Email me" should not be checked
 Then /^the checkbox "(?P<checkbox>(?:[^"]|\\")*)" should (?:be unchecked|not be checked)$/
    - Checks, that checkbox with specified in|name|label|value is unchecked.
    # FeatureContext::assertCheckboxNotChecked()

# e.g. Then the checkbox "Email is" is unchecked
 Then /^the checkbox "(?P<checkbox>(?:[^"]|\\")*)" is (?:unchecked|not checked)$/
    - Checks, that checkbox with specified in|name|label|value is unchecked.
    # FeatureContext::assertCheckboxNotChecked()

# e.g. Then I should see 10 "blog-post" elements
 Then /^(?:|I )should see (?P<num>\d+) "(?P<element>[^"]*)" elements?$/
    - Checks, that (?P<num>\d+) CSS elements exist on the page
    # FeatureContext::assertNumElements()

# e.g. Then print current URL
 Then /^print current URL$/
    - Prints current URL to console.
    # FeatureContext::printCurrentUrl()

# e.g. Then print last response
 Then /^print last response$/
    - Prints last response to console.
    # FeatureContext::printLastResponse()

# e.g. Then show last response
 Then /^show last response$/
    - Opens last response content in browser.
    # FeatureContext::showLastResponse()
```

---

### Step actions

All of these phrases point to a selenium action, defined in classes used by a Behat extension.

We can add new phrases -> actions in the ```features/bootstrap/FeatureContext.php``` file.  We currently have one for our DoSomething tests:

```php
    /**
     * @Given /^I fill in (?<field>.*?) with a random email$/
     * @And /^I fill in (?<field>.*?) with a random email$/
     */
    public function iFillInARandomEmail($field) {
      $field = $this->fixStepArgument($field);
      $value = $this->fixStepArgument('testing+' . time() . '@dosometing.org');
      $this->getSession()->getPage()->fillField($field, $value);
    }
```

We should not need to write any more actions, but if you need one please talk to Michael.

---

### Running Behat Tests

To run behat tests, execute the following command from the ```tests``` directory: 

```sh
# In the root behat directory
./bin/behat --profile local
```

Behat will automatically run all ```*.feature``` files found in the `tests/features` directory.
