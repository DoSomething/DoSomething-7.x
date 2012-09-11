// SET UP
  1. Click the "Panelizer" tab and add the "cmp" id.
  2. Hop over to "Content" and remove everything from the following sections: 
  "Logo", "Mini Quick Info", "Social", "Stats", "Full Quick Info" and "PSA or
  Image". Do NOT delete "Sign Up" as this is still needed for the campaign.
  3. Remove all titles, content and CSS properties from existing panes.
  4. Create additional panes necessary and add administrative titles for
  reference.
  5. The basic HTML framework is as follows:

  <div class="s# section">
    <!-- content -->
  </div>

// THOUGHTS ON TAXONOMY
  I had been using a zero indexed "s#" system for the section classes. I think
  it makes sense to move forward with this system chaning out the letter for
  each version of the page we are creating (a0 = anonymous header, u0 = user
  header, etc.).

// GUIDE TO PARTIALS
 _base
  Contains all variable and mixin definitions for the microsite. 

 _breakpoints
  Contains all responsive styles.*
   
 _drupal
  Contains a lovely poem about Drupal.

 _framework
  This one is for the panes' content framework. Place all column sizing,
  general styles (copy color, etc.) and reusable classes in here.

 _panes
  Place all pane-specific styling here. Use this partial to override the
  base pane styles. 

 _reset
  Three cheers for the Meyer reset! Used to kill the insane baselines
  inherited from the global site.

 _typography
  Place all typography related styles in here. May also contain
  typography-related classes such as ".center" and ".legal-copy". 

  *I am considering killing this in favor of placing the media queries in the
  relevant partials rather than breaking it off and re-writing those styles.
  Still undecided. If you have any opinion either way, e-mail me.

// SASS PARTIALS
  1. cd into the base campaign directory
  2. run swnew

  ds_campaign.sass contains all the partial imports. In this file you will
  notice that a good number of partials are nested under "#cmp". This
  increases the specificity of the styles on the microsite to insure that
  there aren't any conflicts with the sitewide CSS by adding "#cmp" before
  every style declaration. It is messy but the best we have right now.

// HTML PARTIALS
  Everything lives in ../html and is added through Panelizer.
