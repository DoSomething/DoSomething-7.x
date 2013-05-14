{% if grains['os'] == 'Ubuntu' %}

php5-pkgs:
  pkg.installed:
    - names:
      - php5
      - php5-mysql
      - php5-curl
      - php5-cli
      - php5-cgi
      - php5-dev
      - php-pear
      - php5-gd
      - php5-memcache
  file.managed:
    - name: /etc/php5/apache2/php.ini
    - source: salt://php5/apache2/php.ini
    - require:
      - pkg: php5-pkgs

php5-cli-config:
  file.managed: 
    - name: /etc/php5/cli/php.ini
    - source: salt://php5/cli/php.ini
    - require:
      - pkg: php5-pkgs

apache2:
  pkg:
    - installed
  file.managed:
    - name: /etc/apache2/ports.conf
    - source: salt://apache2/ports.conf
    - require:
      - pkg: apache2

apache2-vhosts:
  file.managed:
    - name: /etc/apache2/sites-available/default
    - source: salt://apache2/vhost.conf
    - require:
      - pkg: apache2

apache2-mods:
  cmd.run:
    - name: sudo a2enmod rewrite ; sudo service apache2 restart
    - require:
      - pkg: apache2
      - pkg: php5-pkgs

drupal-files:
  cmd.run:
    - name: mkdir /vagrant/files ; chmod 777 /vagrant/files

libapache2-mod-php5:
  pkg:
    - installed
    - require:
      - pkg: apache2

memcached:
  pkg:
    - installed

varnish:
  pkg:
    - installed

pear-drush:
  cmd.run:
    - name: sudo pear channel-discover pear.drush.org ; sudo pear install drush/drush
    - require:
      - pkg: php5-pkgs
      - pkg: curl

mysql-common:
  pkg:
    - installed

mysql-client:
  pkg:
    - installed
    - require:
      - pkg: mysql-common

mysql-server:
  pkg:
    - installed
    - require:
      - pkg: mysql-client

apt-update:
  cmd.run:
    - name: sudo apt-get update

git:
  pkg:
    - installed

{% endif %}
