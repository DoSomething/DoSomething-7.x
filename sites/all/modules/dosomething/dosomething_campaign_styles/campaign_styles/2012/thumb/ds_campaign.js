(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      $('#contest_info').hide(); 
      $('#contest_button').click(function () { 
        $('#contest_info').slideToggle();
      });
    }
  };
})(jQuery);
