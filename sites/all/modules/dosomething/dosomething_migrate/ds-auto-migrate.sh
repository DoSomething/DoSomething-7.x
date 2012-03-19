#! /bin/bash

# Get start time.
START=`date +%s`
ERROR=0

BACKDIR="/home/webadmin/dosomething-backup-script"
#D7ALIAS="@dosomething.local"
#D7DATABASE="dosomething"
#D7DATABASE="dosomething"
#D6ALIAS="@dosomething6.local"
#D6DATABASE="dosomething6"

# Testing values
D7ALIAS="@dsmtest"
D6ALIAS="@ds6mtest"
D7DATABASE="dosomething_mtest"
D6DATABASE="dosomething6_mtest"


# Get the latest database from the backup server.
SERVERSUM=`ssh dosomething@184.106.153.161 'md5sum dosomething_prod.sql.gz' | awk '{ print $1 }'`
echo "scp dosomething@184.106.153.161:dosomething_prod.sql.gz $BACKDIR/ds6-daily-backup.sql.gz"
ERROR=$(expr $ERROR + 1)
scp dosomething@184.106.153.161:dosomething_prod.sql.gz $BACKDIR/ds6-daily-backup.sql.gz
if  [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds. Failed to download the database"
  exit $ERROR
fi

#Assuming we got the file now test the md5sum
ERROR=$(expr $ERROR + 1)
LOCALSUM=`md5sum $BACKDIR/ds6-daily-backup.sql.gz | awk '{ print $1 }'`
if  [ -z $LOCALSUM || -z $SERVERSUM ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds. Failed to get a checksum."
  exit $ERROR
fi

#compare the checksums
ERROR=$(expr $ERROR + 1)
if [ $SERVERSUM != $LOCALSUM ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds. Check sums don't match"
  exit $ERROR
fi
echo "md5 checksums match"

echo "removing old backup database file"
rm $BACKDIR/ds6-daily-backup.sql
echo "unpacking new database backup"
ERROR=$(expr $ERROR + 1)
gunzip -c $BACKDIR/ds6-daily-backup.sql.gz > $BACKDIR/ds6-daily-backup.sql
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "downloaded and extracted the backup production database"
fi

# Import the new DS6 database.
echo "drop the old d6 database"
drush $D6ALIAS sql-drop -y
echo "Importing the database. Go grab a cocktail, this'll be some time."
ERROR=$(expr $ERROR + 1)
mysql $D6DATABASE < $BACKDIR/ds6-daily-backup.sql
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "sucessfully imported the drupal6 database"
fi

# Get the og history table and move it into D7 site.
echo "exporting the og history table from the d6 site"
ERROR=$(expr $ERROR + 1)
mysqldump $D6DATABASE dosome_migrating_og_membership_change > $BACKDIR/ds-og-history.sql
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "exported the history of og"
fi

echo "dropping the og history table from the d7 site."
ERROR=$(expr $ERROR + 1)
mysql $D7DATABASE -e "DROP TABLE IF EXISTS dosome_migrating_og_membership_change;"
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
fi

echo "importing the og history table into the d7 site."
ERROR=$(expr $ERROR + 1)
mysql $D7DATABASE < $BACKDIR/ds-og-history.sql
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "imported the og history into d7 site."
fi

# Clear the caches for good measure.
echo "clearing d7 caches"
ERROR=$(expr $ERROR + 1)
drush $D7ALIAS cc all
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
fi

echo "clearing d6 caches"
ERROR=$(expr $ERROR + 1)
drush $D6ALIAS cc all
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "caches flushed"
fi

# Enable the migration module
echo "enabling dosomething migration module"
ERROR=$(expr $ERROR + 1)
drush $D7ALIAS en dosomething_migrate -y
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "module enabled successfully"
fi

# List of migrations to run.
echo "running new user migration"
ERROR=$(expr $ERROR + 1)
drush $D7ALIAS mi dsjsonnewuser
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "ran the new user migration."
fi

echo "running updated user migration"
ERROR=$(expr $ERROR + 1)
drush $D7ALIAS mi dsjsonchangeduser
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "ran the changed user migration."
fi

echo "running the club migration"
ERROR=$(expr $ERROR + 1)
drush $D7ALIAS mi dsjsonclub
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "ran the club migration."
fi

echo "rerunning og history"
ERROR=$(expr $ERROR + 1)
drush $D7ALIAS dsmog
if [ $? -ne 0 ]
then
  DIFF=$(expr `date +%s` - $START)
  echo "Error" $ERROR "encountered after" $DIFF "seconds"
  exit $ERROR
else
  echo "ran the og replay."
fi

END=`date +%s`
DIFF=$(expr $END - $START)
echo "script completed in" $DIFF "seconds"
# If no errors, we return exit 0
exit 0
