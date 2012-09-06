(function ($) {
  
  Drupal.behaviors.furtogForm = {
    attach: function (context, settings) {
      var addressForm = $('#furtographer-address');
      addressForm.hide();
      $('.form-type-checkbox input').bind('click', function() {
        if ($(this).attr('checked')) {
          addressForm.show(400);
        }
        else {
          addressForm.hide(400);
        }
        addressForm.css({'overflow' : ''});
      });
    }
  };

})(jQuery);
