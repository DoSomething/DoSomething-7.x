# DoSomething Beta

Connects to the beta app to handle remaining legacy nodes that should remain
live after beta launch.

If this module is enabled, it means beta app has launched, and we are now storing
signups in the beta app, and no longer in this legacy app.


## Usage

This module is only used for node 731115, Mind on my Money.

When this module is enabled, the legacy gate system which redirects a user to
user/login?destination=731115 will no longer in place.

When navigating to node 731115, the beta app is queried to see if the current
user has exists up for 850 (the corresponding beta nid).

* If the user is anonymous, redirect to the beta node (displays a login pitch).
    * The beta app then will redirect to the legacy node upon signup.

* If a signup exists, the node is displayed.
     * If there is no value in the `data` column, the school modal is displayed.
     * If there is data, the campaign is displayed (no modal).

* If a signup does not exist, the auth user is redirected to the legacy pitch page.


## Installation / Configuration

Module assumes there is a 'beta' DB config defined in your settings file:

````
$databases['beta'] = array(
  'default' => array(
    'database' => 'drupal_db',
    'username' => 'drupal',
    'password' => 'drupal',
    'host' => '1.2.3.4',
    'port' => '',
    'driver' => 'mysql',
    'prefix' => '',
  )
);
````
