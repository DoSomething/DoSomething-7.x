-- MySQL dump 10.11
--
-- Host: localhost    Database: dosomething
-- ------------------------------------------------------
-- Server version	5.0.95

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `field_revision_field_fb_app_address`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_address`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_address` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_address_value` varchar(255) default NULL,
  `field_fb_app_address_format` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_address_format` (`field_fb_app_address_format`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 563 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_address`
--

LOCK TABLES `field_revision_field_fb_app_address` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_address` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_address` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'3612 11th Avenue',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'19 East Ridge Pike P.O. box 222',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'1044 Mantua Pike',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'350 South Huntington Ave',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'350 South Huntington Ave',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'1577 Falmouth Rd',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'1577 Falmouth Rd',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'12370 Murphy Avenue',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'1577 Falmouth Road',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'1577 Falmouth Rd',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'1577 Falmouth Rd',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'150 Miller Pl.',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'150 Miller Pl',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'1577 Falmouth Rd',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'1577 Falmouth Rd',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'12370 Murphy Ave',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'1959 West Fulton Street, 1st Floor',NULL);
/*!40000 ALTER TABLE `field_revision_field_fb_app_address` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_adopted`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_adopted`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_adopted` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_adopted_value` int(11) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_adopted_value` (`field_fb_app_adopted_value`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 564 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_adopted`
--

LOCK TABLES `field_revision_field_fb_app_adopted` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_adopted` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_adopted` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,0),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,0);
/*!40000 ALTER TABLE `field_revision_field_fb_app_adopted` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_age`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_age`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_age` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_age_value` varchar(60) default NULL,
  `field_fb_app_age_format` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_age_format` (`field_fb_app_age_format`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 565 (field_fb_app_age)';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_age`
--

LOCK TABLES `field_revision_field_fb_app_age` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_age` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_age` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'2',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'2',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'6 months',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'.5',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'1',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'12',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,'2',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'1',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,'6',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'4',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'6',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'8',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'7',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'4',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'3',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'10',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'11',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'6',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,'2',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'4',NULL);
/*!40000 ALTER TABLE `field_revision_field_fb_app_age` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_animal_name`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_animal_name`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_animal_name` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_animal_name_value` varchar(60) default NULL,
  `field_fb_app_animal_name_format` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_animal_name_format` (`field_fb_app_animal_name_format`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 566 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_animal_name`
--

LOCK TABLES `field_revision_field_fb_app_animal_name` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_animal_name` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_animal_name` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'Vanilla',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'Rover',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'Domino',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'Ginger',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'Cash',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'Daisy',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,'Calypson',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'Charlie',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,'Brandy',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'Kasey',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'McLeod',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'Dale',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'Red',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'Jack',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'Kingsley',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'Twila',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'Mitchie',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'Dakota',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,'Zeus',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'Kane',NULL);
/*!40000 ALTER TABLE `field_revision_field_fb_app_animal_name` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_animal_type`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_animal_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_animal_type` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_animal_type_value` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_animal_type_value` (`field_fb_app_animal_type_value`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 567 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_animal_type`
--

LOCK TABLES `field_revision_field_fb_app_animal_type` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_animal_type` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_animal_type` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'Cat'),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'Cat'),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,'Cat'),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'Cat'),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'Cat'),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'Dog'),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,'Cat'),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'Dog');
/*!40000 ALTER TABLE `field_revision_field_fb_app_animal_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_city`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_city`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_city` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_city_value` varchar(255) default NULL,
  `field_fb_app_city_format` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_city_format` (`field_fb_app_city_format`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 568 (field_fb_app_city)';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_city`
--

LOCK TABLES `field_revision_field_fb_app_city` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_city` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_city` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'Los Angeles',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'Conshohocken',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'Thorofare',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'Boston',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'Boston',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'Centerville',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'Centerville',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'San Martin',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'Centerville',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'Centerville',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'Centerville',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'Syosset',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'Syosset',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'Centerville',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'Centerville',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'San Martin',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'Chicago',NULL);
/*!40000 ALTER TABLE `field_revision_field_fb_app_city` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_image`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_image`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_image` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_image_fid` int(10) unsigned default NULL COMMENT 'The file_managed.fid being referenced in this field.',
  `field_fb_app_image_alt` varchar(512) default NULL COMMENT 'Alternative image text, for the image’s ’alt’ attribute.',
  `field_fb_app_image_title` varchar(1024) default NULL COMMENT 'Image title text, for the image’s ’title’ attribute.',
  `field_fb_app_image_width` int(10) unsigned default NULL COMMENT 'The width of the image in pixels.',
  `field_fb_app_image_height` int(10) unsigned default NULL COMMENT 'The height of the image in pixels.',
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_image_fid` (`field_fb_app_image_fid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 569 (field_fb_app_image)';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_image`
--

LOCK TABLES `field_revision_field_fb_app_image` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_image` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_image` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,201474,'','',600,800),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,201478,'','',339,292),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,201492,'','',720,480),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,201491,'','',640,480),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,201496,'','',640,480),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,201493,'','',240,320),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,201499,'','',320,198),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,201500,'','',823,1020),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,201501,'','',480,320),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,201506,'','',1024,768),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,201505,'','',762,1102),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,201507,'','',300,225),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,201513,'','',136,250),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,201516,'','',300,200),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,201519,'','',300,200),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,201524,'','',240,320),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,201528,'','',240,320),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,201527,'','',500,500),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,201531,'','',640,480),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,201532,'','',612,612);
/*!40000 ALTER TABLE `field_revision_field_fb_app_image` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_other`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_other`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_other` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_other_value` varchar(60) default NULL,
  `field_fb_app_other_format` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_other_format` (`field_fb_app_other_format`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 570 (field_fb_app_other)';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_other`
--

LOCK TABLES `field_revision_field_fb_app_other` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_other` DISABLE KEYS */;
/*!40000 ALTER TABLE `field_revision_field_fb_app_other` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_published`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_published`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_published` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_published_value` int(11) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_published_value` (`field_fb_app_published_value`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 571 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_published`
--

LOCK TABLES `field_revision_field_fb_app_published` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_published` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_published` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,1);
/*!40000 ALTER TABLE `field_revision_field_fb_app_published` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_share_count`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_share_count`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_share_count` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_share_count_value` int(11) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 572 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_share_count`
--

LOCK TABLES `field_revision_field_fb_app_share_count` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_share_count` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_share_count` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,2),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,2),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,1),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,2),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,2);
/*!40000 ALTER TABLE `field_revision_field_fb_app_share_count` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_shelter_name`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_shelter_name`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_shelter_name` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_shelter_name_value` varchar(255) default NULL,
  `field_fb_app_shelter_name_format` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_shelter_name_format` (`field_fb_app_shelter_name_format`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 573 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_shelter_name`
--

LOCK TABLES `field_revision_field_fb_app_shelter_name` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_shelter_name` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_shelter_name` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'South LA animal shelter',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'Montgomery Count ASCPA',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'All They Need is Love Rescue',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'MSPCA Boston Animal Care and Adoption Center',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'MSPCA Boston Animal Care and Adoption Center',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'Cape Cod MSPCA',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'Cape Cod MSPCA',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'Santa Clara County Animal Shelter',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'Cape Cod MSPCA',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'Cape Cod MSPCA',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'Cape Cod MSPCA',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'Town of Oyster Bay Animal Shelter',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'Town of Oyster Bay Animal Shelter',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'Cape Cod MSPCA',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'Cape Cod MSPCA',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'Santa Clara County Animal Shelter',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'K94Keeps',NULL);
/*!40000 ALTER TABLE `field_revision_field_fb_app_shelter_name` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_shelter_reference`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_shelter_reference`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_shelter_reference` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_shelter_reference_target_id` int(10) unsigned default NULL COMMENT 'The id of the target entity',
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_shelter_reference_target_id` (`field_fb_app_shelter_reference_target_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 574 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_shelter_reference`
--

LOCK TABLES `field_revision_field_fb_app_shelter_reference` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_shelter_reference` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_shelter_reference` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,724650),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,724650),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,724681);
/*!40000 ALTER TABLE `field_revision_field_fb_app_shelter_reference` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_state`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_state`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_state` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_state_value` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_state_value` (`field_fb_app_state_value`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 575 (field_fb_app_state)';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_state`
--

LOCK TABLES `field_revision_field_fb_app_state` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_state` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_state` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'CA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'PA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'NJ'),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'CA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'NY'),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'NY'),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'MA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'CA'),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'IL');
/*!40000 ALTER TABLE `field_revision_field_fb_app_state` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_three_words`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_three_words`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_three_words` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_three_words_value` varchar(60) default NULL,
  `field_fb_app_three_words_format` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_three_words_format` (`field_fb_app_three_words_format`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 576 (field_fb_app...';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_three_words`
--

LOCK TABLES `field_revision_field_fb_app_three_words` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_three_words` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_three_words` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'Friendly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',1,'Lovable',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',2,'Cuddly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'Friendly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',1,'Relaxed',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',2,'Cuddly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'Playful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',1,'Beautiful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',2,'Puppy',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'Playful ',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',1,'Affectionate',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',2,'Independent',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'Playful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',1,'Spunky',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',2,'Cuddly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'Social',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',1,'Affectionate',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',2,'Quiet',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',0,'Loving',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',1,'Playful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387316,1387316,'und',2,'Cute',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'Rambunctious',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',1,'Young',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',2,'Beautiful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',0,'Fluffy',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',1,'Loving',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387320,1387320,'und',2,'Pretty',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'Sweetest',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',1,'Dog',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',2,'Ever!',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'Shy',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',1,'Beautiful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',2,'Large',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'Outgoing',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',1,'Lovable',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',2,'Energetic',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'Small',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',1,'Energetic',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',2,'Lovable',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'House-trained',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',1,'Playful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',2,'Loving',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'Child-friendly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',1,'Silly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',2,'Adorable',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'Playful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',1,'Beautiful',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',2,'Shy',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'Affectionate',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',1,'Mellow',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',2,'Irresistible',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'Kind',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',1,'Gentle',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',2,'Sweet',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',0,'Friendly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',1,'Frisky',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387394,1387394,'und',2,'Fun',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'Child-friendly',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',1,'Happy',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',2,'Smiley',NULL);
/*!40000 ALTER TABLE `field_revision_field_fb_app_three_words` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `field_revision_field_fb_app_zip`
--

DROP TABLE IF EXISTS `field_revision_field_fb_app_zip`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `field_revision_field_fb_app_zip` (
  `entity_type` varchar(128) NOT NULL default '' COMMENT 'The entity type this data is attached to',
  `bundle` varchar(128) NOT NULL default '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL default '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `language` varchar(32) NOT NULL default '' COMMENT 'The language for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_fb_app_zip_value` varchar(255) default NULL,
  `field_fb_app_zip_format` varchar(255) default NULL,
  PRIMARY KEY  (`entity_type`,`entity_id`,`revision_id`,`deleted`,`delta`,`language`),
  KEY `entity_type` (`entity_type`),
  KEY `bundle` (`bundle`),
  KEY `deleted` (`deleted`),
  KEY `entity_id` (`entity_id`),
  KEY `revision_id` (`revision_id`),
  KEY `language` (`language`),
  KEY `field_fb_app_zip_format` (`field_fb_app_zip_format`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Revision archive storage for field 577 (field_fb_app_zip)';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_revision_field_fb_app_zip`
--

LOCK TABLES `field_revision_field_fb_app_zip` WRITE;
/*!40000 ALTER TABLE `field_revision_field_fb_app_zip` DISABLE KEYS */;
INSERT INTO `field_revision_field_fb_app_zip` VALUES ('webform_submission_entity','fb_app_data_gathering_form',0,1387264,1387264,'und',0,'90210',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387276,1387276,'und',0,'19428',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387300,1387300,'und',0,'19428',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387306,1387306,'und',0,'02130',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387310,1387310,'und',0,'02130',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387311,1387311,'und',0,'02632',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387319,1387319,'und',0,'02632',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387327,1387327,'und',0,'95046',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387328,1387328,'und',0,'02632',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387336,1387336,'und',0,'02632',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387357,1387357,'und',0,'02632',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387368,1387368,'und',0,'11791',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387374,1387374,'und',0,'11791',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387386,1387386,'und',0,'02632',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387387,1387387,'und',0,'02632',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387389,1387389,'und',0,'95046',NULL),('webform_submission_entity','fb_app_data_gathering_form',0,1387398,1387398,'und',0,'60612',NULL);
/*!40000 ALTER TABLE `field_revision_field_fb_app_zip` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-09-19 13:49:25
