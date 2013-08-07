#!/bin/bash

THISHOST=$(hostname -f)
HOST=${THISHOST: -5}

php ./scripts/run-tests.sh --verbose DoSomething
cd tests
if [ $HOST == 'local' ]
then
  bin/behat --profile local
else
  bin/behat
fi
