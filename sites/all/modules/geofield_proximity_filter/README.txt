This module integrates with the Search API Solr server to provide a Views proximity filter for Geofield fields 

To use this module you must be running the 7.x-1.x-entity-integration branch of the Geofield module, and the latest dev versions of Search API and Search API Solr.

It also depends on the D7 version of Geocode available here: https://github.com/phayes/geocode

1. Copy the provided schema.xml into your solr instance
2. Set your geofield fields to LatLonType in Search API's Workflow configuration screen -- you'll see the option under callbacks.  After doing this you'll see a PHP notice when viewing your field list in the Search API interface.  This isn't solvable 'til this issue is resolved: http://drupal.org/node/1260834 
3. Rebuild your index and you should be able to filter on your geofield in a view using an address and a radius.   