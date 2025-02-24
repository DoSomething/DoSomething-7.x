<?php
// $Id: html.tpl.php,v 1.1.2.2 2011/01/22 23:47:01 timplunkett Exp $

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 */
?><!DOCTYPE html>
<!--[if lt IE 7 ]>              <html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?> class="no-js ie ie6"> <![endif]-->
<!--[if IE 7 ]>                 <html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?> class="no-js ie ie7"> <![endif]-->
<!--[if IE 8 ]>                 <html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?> class="no-js ie ie8"> <![endif]-->
<!--[if IE 9 ]>                 <html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?> class="no-js ie ie9"> <![endif]-->
<!--[if (gte IE 10)|!(IE)]><!--> <html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?> class="no-js"> <!--<![endif]-->

<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>
 
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
  <title><?php print $head_title; ?></title>

  <?php print $user_styles; ?>
  <?php print $shiv; ?>
  <?php if (extension_loaded('newrelic')) print newrelic_get_browser_timing_header(); ?>
  <?php print $scripts; ?>
  <?php print $selectivizr; ?>
  <?php print $placeholder_shiv; ?>

</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <!--[if IE 7 ]><img style="position: absolute; top: 0; left: 0; z-index: 1;" src="/sites/all/themes/doit/css/images/ie-upgrade.png"><![endif]-->
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <?php if (extension_loaded('newrelic')) print newrelic_get_browser_timing_footer(); ?>
</body>
</html>
