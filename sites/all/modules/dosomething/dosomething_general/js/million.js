(function ($) {
  // Define our own jQuery plugin so we can call it from Drupal's AJAX callback
  $.fn.extend({
    dsMillionSubmit: function (url, is_user) {
      // Whelp, these were breaking things, so let's just destroy them.
      // This is bad practice.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingLoginLogin;
 
      if (!url) {
        url = document.location.pathname.replace(/\//, '');
      }

      var popupForm = $('#dosomething-login-register-popup-form');
      var loginForm = $('#dosomething-login-login-popup-form');

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination='+url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination='+url);
      loginForm.attr('action', '/user?destination='+url);

      var form = popupForm;
      var other = loginForm;
      if (is_user) {
        form = loginForm;
        other = popupForm;
      }

      // popup!
      form.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
        dialogClass: 'petition-pop-up',
        open: function(event, ui) {},
      });
    }
  });
})(jQuery);