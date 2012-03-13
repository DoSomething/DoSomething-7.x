<?php
/**
 * @file
 * dosomething_about.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dosomething_about_taxonomy_default_vocabularies() {
  return array(
    'about_us' => array(
      'name' => 'About Us',
      'machine_name' => 'about_us',
      'description' => 'Determines which items get displayed on the About Us page.',
      'hierarchy' => '0',
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
