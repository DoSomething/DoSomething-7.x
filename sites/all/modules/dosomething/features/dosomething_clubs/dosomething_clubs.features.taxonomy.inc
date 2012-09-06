<?php
/**
 * @file
 * dosomething_clubs.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dosomething_clubs_taxonomy_default_vocabularies() {
  return array(
    'clubs_todo_list' => array(
      'name' => 'Clubs Todo List',
      'machine_name' => 'clubs_todo_list',
      'description' => 'Make your To-Do\'s here',
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
