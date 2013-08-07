<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Behat\MinkExtension\Context\MinkContext;
use Behat\Behat\Context\Step;

//
// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';
//

require_once dirname(__FILE__) . '/../../../sites/all/modules/dosomething/dosomething_testing_suite/factory.inc';
chdir(dirname(__FILE__) . '/../../');

/**
 * Features context.
 */
class FeatureContext extends MinkContext
{
    /**
     * Initializes context.
     * Every scenario gets it's own context object.
     *
     * @param array $parameters context parameters (set them up through behat.yml)
     */
    public function __construct(array $parameters)
    {
        $this->factory = Factory::instance();
    }

    /**
     * @Given /^there is a (?<factory>[A-Za-z0-9]+) with:$/
     * @And /^there is a (?<factory>[A-Za-za-z0-9]+) with:$/
     */
    public function thereIsAFactoryWithTheFollowingData($factory, TableNode $data)
    {
      $this->factory->create($factory, $data->getRowsHash());
    }

    /**
     * @Given /^there is a (?<factory>[A-Za-z0-9]+)$/
     * @And /^there is a (?<factory>[A-Za-z0-9]+)$/
     */
    public function thereIsAFactory($factory)
    {
      $this->factory->create($factory);
    }

    /**
     * @Given /^I am logged in as an? (?<role>regular user|administrator)$/
     * @And /^I am logged in as an? (?<role>regular user|administrator)$/
     */
    public function iAmLoggedInAsRole($role)
    {
      if ($role == 'regular user') {
        $role = $this->factory->create('User');
      }
      else if ($role == 'administrator') {
        $role = $this->factory->create('User', array('roles' => array(3 => 'administrator')));
      }

      // Return the required steps to log in our logged in user.
      return array(
        new Step\Given('I am on "/user/login"'),
        new Step\When('I fill in "edit-name" with "' . $this->factory->getDefault('User', 'name') . '"'),
        new Step\When('I fill in "edit-pass" with "' . $this->factory->getDefault('User', 'pass') . '"'),
        new Step\When('I press "Log in"'),
        new Step\Then('I should see "CAMPAIGNS"'),
      );
    }

    /**
     * @Given /^I am logged in as "(?<user>[^"]*)" with pass "(?<pass>[^"]*)"$/
     * @And /^I am logged in as "(?<user>[^"]*)" with pass "(?<pass>[^"]*)"$/
     */
    public function iAmLoggedInAs($user, $pass)
    {
      // Return the required steps to log in as an existing user.
      return array(
        new Step\Given('I am on "/user/login"'),
        new Step\When('I fill in "edit-name" with "' . $user . '"'),
        new Step\When('I fill in "edit-pass" with "' . $pass . '"'),
        new Step\When('I press "Log in"'),
        new Step\Then('I should see "CAMPAIGNS"'),
      );
    }

    /**
     * @Given /^I log out$/
     * @And /^I log out$/
     */
    public function iLogOut()
    {
      return array(
        // Click "Log out"
        new Step\When('I follow "Log out"'),
      );
    }

    /**
     * @Given /^I fill in (?<field>.*?) with a random email$/
     * @And /^I fill in (?<field>.*?) with a random email$/
     */
    public function iFillInARandomEmail($field)
    {
      $field = $this->fixStepArgument($field);
      $value = $this->fixStepArgument('testing+' . time() . '@dosometing.org');
      $this->getSession()->getPage()->fillField($field, $value);
    }

    /**
     * Take screenshot when step fails. Works only with Selenium2Driver.
     * To use this, you must prefix your scenario with @javascript.
     * Screenshot is saved at [Date]/[Feature]/[Scenario]/[Step].jpg
     *
     * @AfterStep @javascript
     */
    public function takeScreenshotAfterFailedStep(Behat\Behat\Event\StepEvent $event)
    {
      if ($event->getResult() === 4) {
        $driver = $this->getSession()->getDriver();
        if ($driver instanceof Behat\Mink\Driver\Selenium2Driver) {
          $step = $event->getStep();
          $path = array(
             'date' => date("Ymd-Hi"),
             'feature' => $step->getParent()->getFeature()->getTitle(),
             'scenario' => $step->getParent()->getTitle(),
             'step' => $step->getType() . ' ' . $step->getText()
          );
          $path = preg_replace('/[^\-\.\w]/', '_', $path);
          $filename = __DIR__ . '/../screenshots/' .  implode('/', $path) . '.jpg';

          // Create directories if needed
          if (!@is_dir(dirname($filename))) {
            @mkdir(dirname($filename), 0775, TRUE);
          }

          file_put_contents($filename, $driver->getScreenshot());
        }
      }
    }
}
