(function ($) {
  Drupal.behaviors.jeans12_registration = {
    attach: function (context, settings) {

    // kill old asterisks from required fields
    $('#dosomething-login-register-popup-form .popup-content .field-suffix').remove();

    if ($('body').hasClass('not-logged-in')) {
      $('#super-secret-bindable-id').click(function (e) {
        e.preventDefault();
        $('#dosomething-login-register-popup-form').attr('action', '/user/registration?destination=spit/sign-up');
        $('#dosomething-login-login-popup-form').attr('action', '/user?destination=spit/sign-up');
        $('#dosomething-login-register-popup-form').dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 550
        });
      });
    }
  
    // le sigh
    $('#dosomething-login-register-popup-form').prepend($('#dosomething-login-register-popup-form .already-member'));

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
