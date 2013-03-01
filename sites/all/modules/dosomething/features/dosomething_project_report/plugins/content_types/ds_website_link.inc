<?php

/**
 * Information for DoSomething page content - Project Report pages
 */
$plugin = array(
	'single' => TRUE,
	'title' => t('Project website link'),
	'description' => t('Display the website link, only if it already exists!'),
	'all contexts' => TRUE,
	'category' => t('dosomething'),
	'defaults' => '',
	'render callback' => 'dosomething_project_report_website_link_render'
);

/**
 * Creates a dynamic website section of Project Page.
 * If there is a title and a website, display both -- otherwise just show whatever is there.
 */
function dosomething_project_report_website_link_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  if (empty($context)) {
    return $block;
  }

  $argument = reset($context);
  list(, $type, $entity_type) = $argument->type;
  if ($type != 'entity') {
    return $block;
  }

  $wrapper = entity_metadata_wrapper($entity_type, $args[0]);
  $entity_id = $wrapper->getIdentifier();
  $bundle = $wrapper->getBundle();
  $output = array();

  $info = $title = $link = '';
  if ($entity_type == 'webform_submission_entity' && $bundle == 'project_report') {
    $info = (array)$wrapper->value();
    if ($info['field_link'][LANGUAGE_NONE][0]['url'] || $info['field_link'][LANGUAGE_NONE][0]['title']) {
       $link = (isset($info['field_link'][LANGUAGE_NONE][0]['url']) ? $info['field_link'][LANGUAGE_NONE][0]['url'] : '');
       $title = (isset($info['field_link'][LANGUAGE_NONE][0]['title']) ? $info['field_link'][LANGUAGE_NONE][0]['title'] : '');
       if ($link && $title) {
         // Website title AND url (show both with - in between)
         $markup = $title . ' - ' . l($link, $link);
       }
       else if ($link && !$title) {
         // Website URL only
         $markup = l($link, $link);
       }
       else if ($title && !$link) {
         // Website title only (possible?)
         $markup = $title;
       }

       // "For More Info" section heading
       $output['title'] = array(
         '#prefix' => '<h2 style="margin-top: 10px">',
         '#suffix' => '</h2>',
         '#markup' => t('For More Info'),
       );

       // Show the website link(s)
       $output['website_link'] = array(
         '#type' => 'container',
         '#attributes' => array(
            'class' => array(
                'dosomething-project-website'
            )
          ),
          'webby' => array(
            '#markup' => $markup
          ),
        );
    }

    $block->content = $output;
  }

  return $block;
}