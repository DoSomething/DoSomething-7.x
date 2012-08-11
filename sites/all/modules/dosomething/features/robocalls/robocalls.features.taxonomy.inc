<?php
/**
 * @file
 * robocalls.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function robocalls_taxonomy_default_vocabularies() {
  return array(
    'vocabulary_99' => array(
      'name' => 'Cause your birthday celebrities',
      'machine_name' => 'vocabulary_99',
      'description' => 'Celebrities for the "Cause Your Birthday" thing.',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
