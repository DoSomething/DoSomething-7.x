(function ($) {
  Drupal.behaviors.selectbox = {
    attach: function (context, settings) {
      console.log("your mom");
      $("select").selectBox();
      // $("select").selectBox('enable');
      //     $("SELECT").selectBox('settings', {
      //  'menuTransition': 'fade',
      //  'menuSpeed' : 'fast'
      // });
      // $("select").fadeOut('slow');
    }
  }
})(jQuery);  
