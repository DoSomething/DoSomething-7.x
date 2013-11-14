#!/bin/bash

THISHOST=$(hostname -f)
HOST=${THISHOST: -5}
drush test-run DoSomething --uri=http://qa.dosomething.org --verbose
cd tests
if [ $HOST == 'local' ]
then
  bin/behat --profile local --tags ~@footlocker --verbose
else
  bin/behat --tags ~@footlocker --verbose
fi
