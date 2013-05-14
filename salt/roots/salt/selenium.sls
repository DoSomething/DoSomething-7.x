{% if grains['os'] == 'Ubuntu' %}

default-jre:
  pkg:
    - installed

xvfb:
  pkg:
    - installed

ant:
  pkg:
    - installed
    - require:
      - pkg: default-jre

start-selenium:
  cmd.run:
    - name: /bin/sh /srv/salt/selenium/start-selenium.sh
    - require:
      - pkg: xvfb

{% endif %}
