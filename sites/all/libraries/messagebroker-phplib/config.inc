<?php
/*
 * Configuration values that should not be in the repo
 */
if (isset($argv) && ($argv[0] == TRUE || $_GET['test'] == TRUE)) {
  putenv("MANDRILL_APIKEY=ythTDugF5Cm6T3sybpYDEg");
}
else {
  putenv("MANDRILL_APIKEY=451c01b4-7b72-4d1d-ae0a-1d50d7d638d1");
}

// @todo Consider connecting using different Rabbit user based on application
// making the connection. Set enviroment vars based on application in config.inc

// RabbitMQ
putenv("RABBITMQ_HOST=localhost");
putenv("RABBITMQ_PORT=5672");
putenv("RABBITMQ_USERNAME=guest");
putenv("RABBITMQ_PASSWORD=guest");

// RabbitMQ names
putenv("TRANSACTIONAL_EXCHANGE=transactionals-exchange");
putenv("TRANSACTIONAL_QUEUE=transactionals-queue");