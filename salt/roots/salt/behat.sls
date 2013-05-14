{% if grains['os'] == 'Ubuntu' %}

behat:
  cmd.run:
    - name: pushd /vagrant ; curl http://getcomposer.org/installer | php ; php composer.phar install
    - require: 
      - pkg: php5-pkgs
      - pkg: curl

{% endif %}
