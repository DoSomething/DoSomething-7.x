TESTING WITH VAGRANT
--------------------

mholford@dosomething.org
16 May 2013


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


DRUPAL CONFIGURATION
--------------------

See sites/default/site-settings.vagrant.php for details.


ACTIVE PORTS
------------

The Drupal site should be available at 

http://localhost:8888/

The Varnish-served site should be available at

http://localhost:9999/

Jenkins should be available at

http://localhost:11111/jenkins

Solr should be available at

http://localhost:11111/solr

