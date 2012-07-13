(function($) {
  Drupal.behaviors.hideShowWeightsLink = {
    attach: function(context, settings) {
      $('.tabledrag-toggle-weight-wrapper').each(function(i) {
        $(this).hide();
      });
    }
  }
}(jQuery));
