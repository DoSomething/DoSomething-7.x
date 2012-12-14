Setting up the Crazy $#!T Campaign
==============

1. Enable the "Crazy $#!T Campaign" module
2. Run "drush updb" from the command line for any updates.
3. Clear cache.
4. The page can be found at /crazy

A few things to note
--------------

The campaign sits within the "doit" theme, but has two stylesheets that handle the submission flow, and everything else, respectively:

crazy-form.css (crazy-form.sass) handles the submission flow: /crazy/submit, etc.
crazy.css (crazy.sass) handles everything else, and is called on all "crazy" pages.

The plugin file found at [/sites/all/modules/dosomething/crazyshit/plugin.php] contains a number of options and settings for the campaign.  It is documented but if you have any questions, feel free to ask.

All "about" pages are HTML files, found in [/sites/all/modules/dosomething/crazyshit/html].  The name of the html file is the name of the page, so for example if you had a scholarships.html, you could access it at /crazy/about/scholarships.  The "/submit/start" template can also be found in the html folder, as "about-submit.html".

Have fun and let me know if you have any questions.