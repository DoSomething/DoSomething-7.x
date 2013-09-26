# DRUPAL-SPECIFIC NEUE FILES

## What is this?
This directory contains all of the Drupal-specific CSS files that are required for pages using the Neue DS library as these pages are not loading any of Drupal's default CSS.

## How is everything structured?
Add component-specific stylesheets to be included with the Neue DS library here. Individual files do not need to make use of partials and will compile to their own CSS files in `doit/css/`.

## How do I use it?
SASS can be compiled with Compass from the Do It theme root. First `cd` into `doit/` then run either `compass compile -s compressed` to compile and minify the your SASS. All files must be included individually in `/doit/template.php` as they should only be loaded within their specific contexts (e.g. admin-only on all nodes using Neue DS) and not included en masse.

## **NOTE**
If your file's intended page is a Project (using the Project Content Type) the file *must* be added to the whitelist array within the `doit_css_alter` function in `doit/template.php`. Your CSS file **will not load** if it is not added to the whitelist. Alternately, you can include "neue" in your filename as all files containing the keyword "neue" will be preserved.
