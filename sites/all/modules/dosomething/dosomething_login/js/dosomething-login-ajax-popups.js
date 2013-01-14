(function ($) {
  $.fn.extend({
    dsAjaxPopup: function (url, is_user, options, fields) {
      var settings = $.extend( {
        'replaceText'      : null,
        'afterReplaceText' : null,
      }, options);
      if (Drupal.settings.login) {
        if (Drupal.settings.login.replaceText) {
          settings.replaceText = Drupal.settings.login.replaceText;
        }
        if (Drupal.settings.login.afterReplaceText) {
          settings.afterReplaceText = Drupal.settings.login.afterReplaceText;
        }
      }

      // Whelp, these were breaking things, so let's just destroy them.
      // This is probably terrible.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingLoginLogin;
      delete Drupal.behaviors.dosomethingPetitions;
      
      var popupForm = $('#dosomething-login-register-popup-form');
      var loginForm = $('#dosomething-login-login-popup-form');

      // set the values on the popup form based on user input
      for (var fieldName in fields) {
        loginForm.find('input[name="'+fieldName+'"]').val(fields[fieldName]);
        popupForm.find('input[name="'+fieldName+'"]').val(fields[fieldName]);
      }

      // change the text of the popup
      if (settings.replaceText) {
        popupForm.find('#edit-title-text label')
          .text(settings.replaceText);
      }
      if (settings.afterReplaceText) {
        $new = $('<div>').text(settings.afterReplaceText);
        $element = popupForm.find('#edit-title-text label');
        $element.nextAll().remove();
        $element.after($new);
      }

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination='+url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination='+url);
      loginForm.attr('action', '/user?destination='+url);

      var form = popupForm;
      if (is_user) {
        form = loginForm;
      }
      // popup!
      form.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 'auto',
        height: 'auto'
      });
    }
  });
})(jQuery);
