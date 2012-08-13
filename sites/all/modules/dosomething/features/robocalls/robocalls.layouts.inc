<?php
/**
 * @file
 * robocalls.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function robocalls_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'cause_calls';
  $layout->admin_title = 'Cause Calls';
  $layout->admin_description = '';
  $layout->category = 'DoSomething';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
          2 => 2,
          3 => 3,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'celeb_information',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '30.01912406220719',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'celeb_information' => array(
        'type' => 'region',
        'title' => 'Celeb Information',
        'width' => '69.98087593779282',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'robocalls-call-information',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'who_should_____call_',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'who_should_____call_' => array(
        'type' => 'region',
        'title' => 'Who should ... Call?',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'choose_another',
        ),
        'parent' => 'main',
        'class' => 'Choose Another',
      ),
      'choose_another' => array(
        'type' => 'region',
        'title' => 'Choose Another',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'robocalls-choose-another-inspiring-celeb',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'about_robocalls',
          1 => 'sponsor_zone',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'about_robocalls' => array(
        'type' => 'region',
        'title' => 'About RoboCalls',
        'width' => '66.29715687223674',
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      'sponsor_zone' => array(
        'type' => 'region',
        'title' => 'Sponsor Zone',
        'width' => '33.70284312776326',
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
    ),
  );
  $export['cause_calls'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'cause_calls_landing';
  $layout->admin_title = 'Cause Calls Landing';
  $layout->admin_description = '';
  $layout->category = 'DoSomething';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'here_s_how_it_works',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Social Buttons',
        'width' => '24.96967928797849',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'here_s_how_it_works' => array(
        'type' => 'region',
        'title' => 'Here\'s How it Works',
        'width' => '75.0303207120215',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'how-it-works',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'robocalls-choose-celeb-and-information',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'abasdcasdf',
          1 => 'asdfasdf',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'abasdcasdf' => array(
        'type' => 'region',
        'title' => 'About This',
        'width' => '65.57976924122232',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      'asdfasdf' => array(
        'type' => 'region',
        'title' => 'Sponsors',
        'width' => '34.42023075877768',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $export['cause_calls_landing'] = $layout;

  return $export;
}
