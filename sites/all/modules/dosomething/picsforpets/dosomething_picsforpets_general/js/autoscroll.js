(function ($) {

Drupal.behaviors.dspfpAutoscroll = {
  attach: function(context, settings) {
    // We want to scroll the page as soon as the FB code is loaded but the
    // way it is loaded we can't ensure we come next (see fb_social_page_alter())
    // so we set an interval and check until we find it.
    id = window.setInterval(
      function () {
        if (typeof FB != 'undefined') {
          // Scroll the containing window.
          FB.Canvas.scrollTo(0,0);
          // Stop running this code.
          window.clearInterval(id);
        }
      },
      5
    );
  }
};

})(jQuery);
