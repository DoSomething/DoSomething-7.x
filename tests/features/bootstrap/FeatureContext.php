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

/**
 * Features context.
 */
class FeatureContext extends MinkContext
{
    protected static $factory;
    private static $bootstrapped = false;
    private static $roles = array();
    private static $sids = array();

    /**
     * Initializes context.
     * Every scenario gets it's own context object.
     *
     * @param array $parameters context parameters (set them up through behat.yml)
     */
    public function __construct(array $parameters)
    {
    }

    /**
     * Only bootstrap if necessary.
     */
    protected function bootstrap()
    {
      if (!isset($this->factory) || !($this->factory instanceof Factory) && !self::$bootstrapped) {
        // This fixes that frustrating "Undefined index: REMOTE_ADDR" error.
        $_SERVER['REMOTE_ADDR'] = '127.0.0.1';
        require_once dirname(__FILE__) . '/../../../sites/all/modules/dosomething/dosomething_testing_suite/factory.inc';
        self::$factory = Factory::instance();
        self::$bootstrapped = true;
      }
    }

    /**
     * @Given /^there is a (?<factory>[A-Za-z0-9]+) with:$/
     * @And /^there is a (?<factory>[A-Za-za-z0-9]+) with:$/
     */
    public function thereIsAFactoryWithTheFollowingData($factory, TableNode $data)
    {
      $this->bootstrap();
      self::$factory->create($factory, $data->getRowsHash());
    }

    /**
     * @Given /^there is a (?<factory>[A-Za-z0-9]+)$/
     * @And /^there is a (?<factory>[A-Za-z0-9]+)$/
     */
    public function thereIsAFactory($factory)
    {
      $this->bootstrap();
      self::$factory->create($factory);
    }

    /**
     * @Given /^I am logged in as an? (?<role>regular user|administrator|staff|product team)$/
     * @And /^I am logged in as an? (?<role>regular user|administrator|staff|product team)$/
     */
    public function iAmLoggedInAsRole($type)
    {
      $this->bootstrap();
      if ($type == 'regular user') {
        $role = self::$factory->create('User');
      }
      else if ($type == 'administrator') {
        $role = self::$factory->create('User', array('roles' => array('administrator')));
      }
      else if ($type == 'staff') {
        $role = self::$factory->create('User', array('roles' => array('staff')));
      }
      else if ($type == 'product team') {
        $role = self::$factory->create('User', array('roles' => array('staff', 'product team')));
      }

      self::$roles[$type] = $role;

      // Return the required steps to log in our logged in user.
      return array(
        new Step\Given('I am on "/user/login"'),
        new Step\When('I fill in "edit-name" with "' . self::$factory->getDefault('User', 'name') . '"'),
        new Step\When('I fill in "edit-pass" with "' . self::$factory->getDefault('User', 'pass') . '"'),
        new Step\When('I press "Log in"'),
        // new Step\Then('I should see "Log out"'),
      );
    }

    /**
     * @Given /^I fill (?:in|out) "(.*?)" with my logged in email$/
     */
    public function iFillInXWithMyLoggedInEmail($field)
    {
       $use = current(self::$roles);
       return array(new Step\When('I fill in "' . $field . '" with "' . $use->mail . '"'));
    }

    /**
     * @Then /^I fill out the report back form$/
     */
     public function iFillOutTheReportBackForm() {
       $mocks_dir = getcwd() . '/tests/mocks';
       return array(
         new Step\When('I fill in "edit-submitted-field-webform-pictures-und-0-upload" with "' . $mocks_dir . '/test.jpg"'),
         new Step\When('I fill in "edit-submitted-how-many-cans-were-collected" with "50"'),
         new Step\When('I fill in "edit-submitted-how-many-people-helped-out" with "1"'),
         new Step\When('I fill in "edit-submitted-in-50-words-or-fewer-why-is-recycling-important-to-you" with "Because"'),
         new Step\Then('I press "Submit"'),
       );
     }

    /**
     * @Then /^remember the current SID$/
     */
    public function RememberTheCurrentSid()
    {
       preg_match('#sid=(\d+)#i', $this->getSession()->getCurrentUrl(), $qs);
       $sid = intval($qs[1]);

       self::$sids[] = $sid;
    }

    /**
     * @When /^I go to "(.*?)" with the last SID$/
     */
    public function IGoToXWithTheLastSid($path)
    {
       $sid = end(self::$sids);
       return array(new Step\Given('I am on "' . $path . '?sid=' . $sid . '"'));
    }

    /**
     * @When /^I fill out the foot locker recommendation form$/
     */
    public function iFillOutTheFootLockerRecommendationRequestForm()
    {
       $form = new Behat\Gherkin\Node\TableNode('
            | edit-submitted-field-webform-name-und-0-value | me |
            | edit-submitted-relationship-to-you | me |
            | edit-submitted-field-webform-email-und-0-email | testing+abc123@dosomething.org |
            | edit-submitted-phone-number | 555-555-5555 |
        ');
       return array(new Step\When('I fill in the following:', $form));
    }

    /**
     * @Given /^I have filled out the footlocker application$/
     * @When /^I fill out the footlocker application$/
     */
    public function iHaveFilledOutTheFootLockerApplication()
    {
      $page1 = new Behat\Gherkin\Node\TableNode('
          | edit-submitted-email | ' . self::$roles['regular user']->mail . ' |
          | edit-submitted-phone-number | 6105552222 |
          | edit-submitted-street-address-1 | 123 Sunrise Hill |
          | edit-submitted-state | NY |
          | edit-submitted-zip-code | 10010 |
          | edit-submitted-birthday-month | 6 |
          | edit-submitted-birthday-day   | 5 |
          | edit-submitted-birthday-year  | 1999 |
          | edit-submitted-fafsa | 10000 |
      ');
      $page2 = new Behat\Gherkin\Node\TableNode('
          | edit-submitted-roles | n/a |
          | edit-submitted-cumulative-sat-score | 1600 |
          | edit-submitted-cumulative-act-score | 1600 |
          | edit-submitted-pre-sat-score | 1600 |
          | edit-submitted-plan-score | 1600 |
          | edit-submitted-activities | n/a |
      ');
      $page3 = new Behat\Gherkin\Node\TableNode('
          | edit-submitted-essay-1-question | essay 1 |
          | edit-submitted-essay-2-question | essay 2 |
     ');
      $page4 = new Behat\Gherkin\Node\TableNode('
          | edit-submitted-photo-album-url | http://flickr.com |
          | edit-submitted-youtube-or-video-url | http://www.youtube.com |
      ');

      return array(
        new Step\Given('I am on "/footlocker/apply/status/application"'),
        new Step\When('I fill in the following:', $page1),
        new Step\When('I fill in "edit-submitted-gender-2" with "male "'),
        new Step\When('I check "edit-submitted-race-6"'),
        new Step\When('I press "Next"'),

        new Step\Then('I should see "page 2"'),
        new Step\When('I fill in "edit-submitted-what-sports-do-you-play-29" with "rugby "'),
        new Step\When('I fill in the following:', $page2),
        new Step\When('I fill in "edit-submitted-unweighted-gpa" with "3.8 "'),
        new Step\When('I fill in "edit-submitted-fl-employee-2" with "no "'),
        new Step\When('I press "Next"'),

        new Step\Then('I should see "page 3"'),
        new Step\When('I fill in the following:', $page3),
        new Step\When('I press "Next"'),

        new Step\Then('I should see "page 4"'),
        new Step\When('I fill in the following:', $page4),
        new Step\When('I fill in "edit-submitted-how-did-you-hear-about-this-scholarship-opportunity" with "coach "'),
        new Step\When('I check "edit-submitted-legal-stuff-1"'),
        new Step\When('I check "edit-submitted-confirm-true-1"'),
        new Step\When('I check "edit-submitted-permission-1"'),
        new Step\When('I press "Submit"'),
      );
    }

    /**
     * @Given /^I am logged in as "(?<user>[^"]*)" with pass "(?<pass>[^"]*)"$/
     * @And /^I am logged in as "(?<user>[^"]*)" with pass "(?<pass>[^"]*)"$/
     */
    public function iAmLoggedInAsPersonWithPass($user, $pass)
    {
      // Return the required steps to log in as an existing user.
      return array(
        new Step\Given('I am on "/user/login"'),
        new Step\When('I fill in "edit-name" with "' . $user . '"'),
        new Step\When('I fill in "edit-pass" with "' . $pass . '"'),
        new Step\When('I press "Log in"'),
        new Step\Then('I should see "Log out"'),
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

    /**
     * @AfterSuite
     */
    public static function tearDown(Behat\Behat\Event\SuiteEvent $event)
    {
      if (self::$bootstrapped) {
        self::$factory->collectGarbage();
      }
    }
}
