<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Behat\MinkExtension\Context\MinkContext;

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
    /**
     * Initializes context.
     * Every scenario gets it's own context object.
     *
     * @param array $parameters context parameters (set them up through behat.yml)
     */
    public function __construct(array $parameters)
    {
        // Initialize your context here
    }

    /**
     * @Given /^I fill in (?<field>.*?) with a random email$/
     * @And /^I fill in (?<field>.*?) with a random email$/
     */
    public function iFillInARandomEmail($field) {
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
    public function takeScreenshotAfterFailedStep(Behat\Behat\Event\StepEvent $event) {
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

// Place your definition and hook methods here:
//
//    /**
//     * @Given /^I have done something with "([^"]*)"$/
//     */
//    public function iHaveDoneSomethingWith($argument)
//    {
//        doSomethingWith($argument);
//    }
//
}
