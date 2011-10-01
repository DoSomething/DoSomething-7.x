(function ($) {
  Drupal.behaviors.selectbox = {
    attach: function (context, settings) {
      $("select").selectBox();
    }
  }
})(jQuery);  
