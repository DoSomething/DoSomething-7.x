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

pear-drush:
  cmd.run:
    - name: sudo pear config-set auto_discover 1 > /dev/null ; sudo pear channel-discover pear.drush.org > /dev/null ; sudo pear install drush/drush  > /dev/null
    - require:
      - pkg: php5-pkgs
      - pkg: curl

pear-misc:
  cmd.run:
    - name: /bin/sh /srv/salt/php5/pear-install.sh > /dev/null
    - require:
      - pkg: php5-pkgs

apache2-env:
  file.managed:
    - name: /etc/apache2/envvars
    - source: salt://apache2/envvars

apache2:
  pkg:
    - installed
    - require:
      - file: apache2-env
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

apache2-conf:
  file.managed:
    - name: /etc/apache2/apache2.conf
    - source: salt://apache2/apache2.conf
    - require:
      - file: apache2-vhosts

apache2-mods:
  cmd.run:
    - name: sudo a2enmod rewrite
    - require:
      - file: apache2-conf
      - pkg: php5-pkgs

apache2-restart:
  cmd.run:
    - name: sudo chown -R vagrant:vagrant /var/log/apache2 ; sudo chown -R vagrant:vagrant /var/lock/apache2 ; sudo service apache2 restart
    - require:
      - cmd: apache2-mods  

drupal-files:
  cmd.run:
    - name: mkdir -p /vagrant/files ; chmod 777 /vagrant/files

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
  service.running:
    - enable: True
    - restart: True
    - watch:
      - file: /etc/varnish/default.vcl

varnish-config:
  file.managed:
    - name: /etc/varnish/default.vcl
    - source: salt://varnishd/default.vcl
    - require:
      - pkg: varnish

solr-tomcat:
  pkg:
    - installed
  file.managed:
    - name: /var/lib/tomcat6/conf/server.xml
    - source: salt://tomcat/server.xml
    - require:
      - pkg: solr-tomcat

solr-drupal-conf:
  file.managed:
    - name: /etc/solr/conf/schema.xml
    - source: salt://solr/schema.xml
    - require:
      - pkg: solr-tomcat

solr-solr-conf:
  file.managed:
    - name: /etc/solr/conf/solrconfig.xml
    - source: salt://solr/solrconfig.xml
    - require:
      - pkg: solr-tomcat

tomcat6:
  service.running:
    - enable: True
    - restart: True
    - watch:
      - file: /var/lib/tomcat6/conf/*
    - require:
      - pkg: solr-tomcat

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