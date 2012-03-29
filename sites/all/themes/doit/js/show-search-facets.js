/**
 * Hide or show search facets.
 */

(function ($) {
  Drupal.behaviors.show_search_facets = {
    attach: function(context, settings) {
      // initially hide filters
      $(".block-facetapi ul.facetapi-facetapi-checkbox-links").hide();
      // set cursors to hand
      $(".block-facetapi h2").css('cursor', 'pointer').css('cursor', 'hand');
      $(".block-facetapi h2").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $(".block-facetapi ul.facetapi-facetapi-checkbox-links").slideUp('400');
        }
        else {
          $(this).addClass('active');
          $(".block-facetapi ul.facetapi-facetapi-checkbox-links").slideDown('400');
        }
      });
    }
  }
}(jQuery));
