(function ($) {
  // Define our own jQuery plugin so we can call it from Drupal's AJAX callback
  $.fn.extend({
    dsShareStatSubmit: function (url, name, cell) {
      // Whelp, these were breaking things, so let's just destroy them.
      // This is probably bad practice.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingPetitions;
      
      var popupForm = $('#dosomething-login-register-popup-form');
      //var infoForm = $('.dosomething-share-a-stat-share-with-friends');
      //fName = infoForm.find('input[name="fname"]').val();
      //e_or_m = infoForm.find('input[name="cell_phone"]').val();
      fName = name;
      e_or_m = cell;

      var is_email = Drupal.dsRegistration.validEmail(e_or_m);
      var is_mobile = Drupal.dsRegistration.validPhone(e_or_m);

      // set the values on the popup form based on user input
      if (is_email) {
        popupForm.find('input[name="email"]').val(e_or_m);
      }
      if (is_mobile) {
        popupForm.find('input[name="cell"]').val(e_or_m);
      }
      popupForm.find('input[name="first_name"]').val(fName);

      // change the text of the popup
      popupForm.find('#edit-title-text label')
        .text("You're almost there.")
      //var hash2 = ($('#register-benefits').length);
      //if (!hash2)
      //{
      //  popupForm.find('#edit-title-text label').after('<h2 id="register-benefits">Now get the benefits of being a full member at DoSomething.org.</h2>');
      //}

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination=' + url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination=' + url);
      $('#dosomething-login-login-popup-form').attr('action', '/user?destination=' + url);

      // popup!
      popupForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550
      });
    }
  });
})(jQuery);