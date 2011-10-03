<?php
/**
 * @file
 * dosomething_causes_landing_page.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dosomething_causes_landing_page_taxonomy_default_vocabularies() {
  return array(
    'vocabulary_5' => array(
      'name' => 'Issues',
      'machine_name' => 'vocabulary_5',
      'description' => '',
      'hierarchy' => '2',
      'module' => 'taxonomy',
      'weight' => '-5',
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
