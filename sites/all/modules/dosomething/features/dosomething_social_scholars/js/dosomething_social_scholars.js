(function ($) {
  $.fn.extend({
    dsSocialScholarsSubmit: function (url) {
      delete Drupal.behaviors.dosomethingLoginRegister;
      
      var form = $('[id^="webform-client-form-"]');
      var name = form.find('#edit-submitted-referall-your-info-referral-first-name').val();
      var cell = form.find('#edit-submitted-referall-your-info-referral-phone-number').val();

      var popupForm = $('#dosomething-login-register-popup-form');
      var loginForm = $('#dosomething-login-login-popup-form');

      // Populates cell on register form.
      popupForm.find('input[name="cell"]').val(cell);
      // Populates first name on regiser form.
	    popupForm.find('input[name="first_name"]').val(name);
      // Weirdness of the day: If we use loginForm.find here, we lose the modal background
      // when a user switches to the login form.  However, if we do it this way it works.  Huh?
      $('#dosomething-login-login-popup-form').find('input[name="name"]').val(cell);

      // Set actions to return users to the correct page.
      popupForm.attr('action', '/user/registration?destination=' + url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination=' + url);
      loginForm.attr('action', '/user?destination=' + url);

      popupForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550
      });
    }
  });
})(jQuery);