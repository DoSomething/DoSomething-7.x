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

  <?php print $styles; ?>
  <?php print $shiv; ?>
  <?php if (extension_loaded('newrelic')) print newrelic_get_browser_timing_header(); ?>
  <?php print $scripts; ?>
  <?php print $selectivizr; ?>
  <?php print $placeholder_shiv; ?>

  <!-- ds-neue style overrides for header and footer -->
  <style type="text/css">
  @font-face {
    font-family: "Proxima Nova";
    font-weight: 400;
    src: url('sites/all/libraries/ds-neue/assets/fonts/proxima-nova/ProximaNova-Regular.eot');
    src: url('sites/all/libraries/ds-neue/assets/fonts/proxima-nova/ProximaNova-Regular.eot?') format('eot'),
      url('sites/all/libraries/ds-neue/assets/fonts/proxima-nova/ProximaNova-Regular.woff') format('woff');
  }

  @font-face {
    font-family: 'icomoon';
    src: url('sites/all/libraries/ds-neue/assets/fonts/icomoon/icomoon.eot?#{1}');
    src: url('sites/all/libraries/ds-neue/assets/fonts/icomoon/icomoon.eot?#{1}#iefix') format('embedded-opentype'),
      url('sites/all/libraries/ds-neue/assets/fonts/icomoon/icomoon.ttf?#{1}') format('truetype'),
      url('sites/all/libraries/ds-neue/assets/fonts/icomoon/icomoon.woff?#{1}') format('woff'),
      url('sites/all/libraries/ds-neue/assets/fonts/icomoon/icomoon.svg?#{1}#icomoon') format('svg');
    font-weight: normal;
    font-style: normal;
  }

  .nav--wrapper{background:transparent;position:absolute;top:0;z-index:1;width:100%;/*max-width:1200px*/}@media screen and (min-width:768px){.nav--wrapper .main{*zoom:1;max-width:1200px;margin-left:auto;margin-right:auto;padding:1rem 0}.nav--wrapper .main:after,.nav--wrapper .main:before{content:" ";display:table}.nav--wrapper .main:after{clear:both}}.nav--wrapper .main.is-visible{display:block;position:fixed;top:0;width:100%;height:100%;background:#222;z-index:9997}.nav--wrapper .main.is-visible .menu{display:block;position:static;width:auto;height:auto;background:0 0;margin-top:4rem}@media screen and (min-device-height:960px){.nav--wrapper .main.is-visible .menu{margin-top:5rem}}.nav--wrapper .main.is-visible .hamburger{color:#fff}.nav--wrapper .logo{position:absolute;top:.5rem;left:.5rem}@media screen and (min-width:768px){.nav--wrapper .logo{position:static;padding:0 1rem;text-align:center;float:left;display:block;margin-right:1.35135%;width:11.31757%}.nav--wrapper .logo:last-child{margin-right:0}}.nav--wrapper .logo img{min-width:80px;width:80px;height:70px}.nav--wrapper .hamburger{float:right;color:#fff;font-size:32px;text-decoration:none;margin:.5rem;font-family:icomoon;speak:none;font-style:normal;font-weight:400;font-variant:normal;text-transform:none;line-height:1;-webkit-font-smoothing:antialiased;-moz-osx-font-smoothing:grayscale}@media screen and (min-width:768px){.nav--wrapper .hamburger{display:none}}.nav--wrapper .menu{display:none}@media screen and (min-width:768px){.nav--wrapper .menu{display:block}}.nav--wrapper .primary-nav li{line-height:1.4;font-size:1rem;text-align:center;padding:1rem 0}@media screen and (min-device-height:960px){.nav--wrapper .primary-nav li{padding:.75rem 0}}@media screen and (min-width:768px){.nav--wrapper .primary-nav li{float:left;display:block;text-align:left;margin:0 5.59492% 0 0;padding:1.25rem 0;border-bottom:0}}@media screen and (min-width:1080px){.nav--wrapper .primary-nav li{padding:.75rem 0}}.nav--wrapper .primary-nav a{display:block;color:#fff;text-decoration:none}@media screen and (min-width:768px){.nav--wrapper .primary-nav a{color:#fff}}.nav--wrapper .primary-nav strong{display:block;font-family:'Proxima Nova','Trebuchet MS',sans-serif;font-size: 16px;font-weight: 600;}.nav--wrapper .primary-nav span{text-transform:uppercase;font-size:12px;font-family: 'Proxima Nova','Trebuchet MS',sans-serif;font-weight: normal;}@media screen and (min-width:768px){.nav--wrapper .primary-nav span{display:none}}@media screen and (min-width:1080px){.nav--wrapper .primary-nav span{display:block}}.nav--wrapper .secondary-nav{position:fixed;bottom:0;width:100%;margin-right:2rem}@media screen and (min-width:768px){.nav--wrapper .secondary-nav{position:static;float:right;width:auto}}.nav--wrapper .secondary-nav ul{display:block}.nav--wrapper .secondary-nav li{line-height:1.4;font-size:1rem;text-align:center;padding:1.5rem 0;margin:1rem;box-sizing:border-box}@media screen and (min-width:768px){.nav--wrapper .secondary-nav li{float:left;display:block;text-align:left;padding:1.25rem 0;margin:0 1rem;border-bottom:0}}@media screen and (min-width:1080px){.nav--wrapper .secondary-nav li{padding:1.15rem 0}}.nav--wrapper .secondary-nav input[type=search]{margin-top:-.25rem;-webkit-transition:width .5s;-moz-transition:width .5s;transition:width .5s;color:#000;}@media screen and (min-width:768px){.nav--wrapper .secondary-nav input[type=search]{width:150px;border:1px solid #fff;background-color:transparent;color:#fff;}}@media screen and (min-width:1080px){.nav--wrapper .secondary-nav input[type=search]{width:200px}}.nav--wrapper .secondary-nav a{display:block;color:#fff;font-weight:bold;text-decoration:none;font-size:16px;font-family:'Proxima Nova','Trebuchet MS',sans-serif;}@media screen and (min-width:768px){.nav--wrapper .secondary-nav a{color:#fff}}
  .footer--wrapper{width:100%;background:#000}.footer--wrapper .main{*zoom:1;max-width:1200px;margin:0 auto}.footer--wrapper .main:after,.footer--wrapper .main:before{content:" ";display:table}.footer--wrapper .main:after{clear:both}@media screen and (min-width:768px){.footer--wrapper .main{padding:1rem}}.footer--wrapper .main h4{position:relative;color:#fff;padding:0 1rem;margin:0;cursor:pointer;font-size: 16px;font-family: 'Proxima Nova','Trebuchet MS',sans-serif;font-weight: 600;}.footer--wrapper .main h4:after{font-family:icomoon;speak:none;font-style:normal;font-weight:400;font-variant:normal;text-transform:none;line-height:1;-webkit-font-smoothing:antialiased;-moz-osx-font-smoothing:grayscale;content:"\e609";color:#555;font-size:32px;position:absolute;right:.25rem;top:-.2rem;-webkit-transform:rotate(0);-moz-transform:rotate(0);-ms-transform:rotate(0);-o-transform:rotate(0);transform:rotate(0);-webkit-transition-property:-webkit-transform;-moz-transition-property:-moz-transform;transition-property:transform;-webkit-transition-duration:.25s;-moz-transition-duration:.25s;transition-duration:.25s}@media screen and (min-width:768px){.footer--wrapper .main h4{cursor:auto;margin:1rem 0 .5rem;padding:0}.footer--wrapper .main h4:after{content:''}}.footer--wrapper .main ul{height:auto;list-style-type:none;padding:.25rem;-webkit-transition:height .25s,padding .5s;-moz-transition:height .25s,padding .5s;transition:height .25s,padding .5s}@media screen and (min-width:768px){.footer--wrapper .main ul{padding:0}}.footer--wrapper .main li{line-height:1rem;margin-bottom:.25rem}.footer--wrapper .main a{display:block;color:#ddd;font-family:'Proxima Nova','Trebuchet MS',sans-serif;font-size: 12px;line-height: 16px;text-decoration:none;padding:.25rem .75rem}.footer--wrapper .main a:hover{color:#fff;text-decoration:underline}@media screen and (min-width:768px){.footer--wrapper .main a{padding:0}}.footer--wrapper .col{padding:.5rem 0}@media screen and (min-width:768px){.footer--wrapper .col{float:left;display:block;margin-right:1.35135%;width:17.65203%;margin-bottom:2rem}.footer--wrapper .col:last-child{margin-right:0}}.footer--wrapper .col.is-collapsed h4:after{-webkit-transform:rotate(-90deg);-moz-transform:rotate(-90deg);-ms-transform:rotate(-90deg);-o-transform:rotate(-90deg);transform:rotate(-90deg)}.footer--wrapper .col.is-collapsed ul{overflow:hidden;padding:0 .25rem;height:0}@media screen and (min-width:768px){.footer--wrapper .col.is-collapsed h4:after{content:''}.footer--wrapper .col.is-collapsed ul{height:auto;padding:0;-webkit-transition:none;-moz-transition:none;transition:none}}.footer--wrapper .about,.footer--wrapper .help,.footer--wrapper .knowus{border-top:1px solid #333}@media screen and (min-width:768px){.footer--wrapper .about,.footer--wrapper .help,.footer--wrapper .knowus{border-top:0;border-bottom:0}}.footer--wrapper .about{border-bottom:1px solid #333}@media screen and (min-width:768px){.footer--wrapper .about{border-bottom:0;margin-right:0}}.footer--wrapper .social{text-align:center}.footer--wrapper .social.mobile{padding-top:1rem}@media screen and (min-width:768px){.footer--wrapper .social.mobile{display:none}}.footer--wrapper .social.tablet{display:none}@media screen and (min-width:768px){.footer--wrapper .social.tablet{display:block}}@media screen and (min-width:768px){.footer--wrapper .social{border-top:0;margin-top:1.65rem;text-align:left;float:left;display:block;margin-right:1.35135%;width:42.98986%}.footer--wrapper .social:last-child{margin-right:0}}.footer--wrapper .social li{display:inline-block;margin-right:16px}.footer--wrapper .social .social-link{font-family:icomoon;speak:none;font-style:normal;font-weight:400;font-variant:normal;text-transform:none;line-height:1;-webkit-font-smoothing:antialiased;-moz-osx-font-smoothing:grayscale;font-size:24px;color:#555;text-decoration:none}.footer--wrapper .social .social-link:hover{color:#ddd;text-decoration:none}.footer--wrapper .subfooter{clear:both;font-size:.75rem;padding:.5rem 0;*zoom:1;display:block}.footer--wrapper .subfooter:after,.footer--wrapper .subfooter:before{content:" ";display:table}.footer--wrapper .subfooter:after{clear:both}.footer--wrapper .subfooter a{display:inline;color:#555}.footer--wrapper .subfooter .tagline{display:none}@media screen and (min-width:768px){.footer--wrapper .subfooter .tagline{display:block;float:left;text-align:left;color: #444;font-family: 'Proxima Nova';line-height: 18px;font-size: 12px;}}.footer--wrapper .subfooter .utility{text-align:center;list-style-type:none}.footer--wrapper .subfooter .utility li{display:inline}.footer--wrapper .subfooter .utility a{margin:0 .5rem}@media screen and (min-width:768px){.footer--wrapper .subfooter .utility a{margin:0 0 0 1rem}}@media screen and (min-width:768px){.footer--wrapper .subfooter .utility{float:right}}

  #page{margin-top:100px;}
  body{background-image:none !important;}
  </style>

  <script>
  (function($) {
    "use strict";

    $(document).ready(function() {
      // Toggle dropdown menu navigation on mobile:
      $(".js-toggle-mobile-menu").on("click", function() {
        $(".nav--wrapper .main").toggleClass("is-visible");
      });

      // Hide footer on mobile until clicked
      $(".footer--wrapper .col").addClass("is-collapsed");
      $(".js-footer-col h4").on("click", function() {
        if( window.matchMedia("screen and (max-width: 768px)").matches ) {
          $(this).closest(".col").toggleClass("is-collapsed");
        }
      });

    });

  })(jQuery);
  </script>

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
