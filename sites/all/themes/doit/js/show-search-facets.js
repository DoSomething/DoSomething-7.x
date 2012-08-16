/**
 * Hide or show search facets.
 */

(function ($) {

Drupal.behaviors.show_search_facets = {
  attach: function (context, settings) {
    // Initially hide filters.
    var $facets = $('.block-facetapi');
    var $filters = $facets.find('ul.facetapi-facetapi-checkbox-links');
    $filters.hide();
    // Set cursors to hand.
    $facets.find('h2')
      .css('cursor', 'pointer')
      .css('cursor', 'hand')
      .click(function () {
        $(this).toggleClass('active');
        $('.block-facetapi ul.facetapi-facetapi-checkbox-links').slideToggle('400');
      });
  }
};

}(jQuery));
