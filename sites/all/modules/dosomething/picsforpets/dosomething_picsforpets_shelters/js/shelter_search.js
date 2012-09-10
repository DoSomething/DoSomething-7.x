(function ($) {
  Drupal.behaviors.picsforpetsShelterSearch = {
    attach: function (context, settings) {
      $next = $('.shelter-form-button .next');
      if ($('#shelter-results').children().length > 0) {
        $next.show();
      }
      else {
        $next.hide();
      }
    }
  };
})(jQuery);
