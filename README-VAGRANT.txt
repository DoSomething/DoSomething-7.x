WORKING WITH VAGRANT
--------------------

mholford@dosomething.org
20 June 2013


PREREQUISITES
-------------

You'll need a GitHub account and access to the Do Something account. Make sure
you've checked out the qa branch of the DoSomething-7.x project. Instructions
below generally assume you're starting out from the docroot of this project
(i.e., the docroot of the Drupal app).

You'll know you're in the right branch if the docroot includes

Vagrantfile

and the "salt/" directory.


INSTALLATION
------------

This Vagrant image provisions a full server stack from a base Ubuntu 64-bit 
box. You need three pieces of software installed before this will work:

* Virtual Box

Download the latest at https://www.virtualbox.org/wiki/Downloads

* Vagrant

Download the latest at http://downloads.vagrantup.com/

* Salty Vagrant

Follow the instructions at https://github.com/saltstack/salty-vagrant


SALT CONFIGURATION
------------------

Salt is a Python-based server provisioning and configuration tool. You can see
the configuration in the directory

salt/roots/salt

The main configuration files are

* top.sls

This is where Salt starts. Only Salt files (.sls files) listed here will get
executed.

* utils.sls

This installs some useful system packages.

* lamp-drupal.sls

Needs refactoring. This installs and configures the vast majority of the LAMP
stack and supporting technologies (Memcached, Solr, Varnish, drush, etc.).

* selenium.sls

This installs packages necessary for Selenium to run, and to drive a headless 
Firefox instance for functional testing.

ALL of these will be executed during "vagrant up". After you run this once,
Salt will check on subsequent calls to vagrant up/vagrant reload that the 
machine is up to date with the Salt configuration files listed above, but it
won't rebuild the entire box from scratch every time.

To force a rebuild, simply

vagrant destroy
vagrant up

...And you'll get a freshly-built box.

To enable the Tomcat 6-related services (Solr, Jenkins), you need to edit the 
main Salt file to install and load these packages. The main Salt file is here:

  salt/roots/salt/top.sls
  
This needs an entry to load the "tomcat" file (.sls is implicit):

  base:
  '*':
    - utils
    - lamp-drupal
    - selenium
    - tomcat

If you edit any Salt config file or Salt-managed file, you need to run

vagrant reload

From the host (i.e., your machine, not within Vagrant). This will shut down 
the Vagrant instance, reload the config files, restart Vagrant, and rerun
Salt.


DRUPAL CONFIGURATION
--------------------

1. See sites/default/site-settings.vagrant.php for details on file config.

2. JS Injector is possibly broken, and at least useless. Disable: 

  % vagrant ssh
  % cd /vagrant
  % drush dis js_injector --yes


ACTIVE PORTS
------------

The Drupal site should be available at 

http://localhost:8888/

The Varnish-served site should be available at

http://localhost:9999/

Port 11111 is available for Tomcat 6, but these services are not running by 
default (see SALT CONFIGURATION for details):

* Jenkins: http://localhost:11111/jenkins

* Solr: http://localhost:11111/solr


GETTING STARTED
---------------

To get vagrant running, you run "vagrant up" from a directory where a Vagrantfile exists.  
For the DS site, this file exists in the root directory when you have the QA branch checked out.

You can then SSH into the box using "vagrant ssh".

Once that finishes, cd into the vagrant directory, and then into the tests/selenium directory.
From there, you need to start selenium in order to run tests: sh start-selenium.sh

You can then run specific tests: phpunit PetitionsTest.php


You will also need to edit your settings.php, * at the very end of the file *:
include_once('site-settings.php')

site-settings.php has all the configurations for memcache, etc.

