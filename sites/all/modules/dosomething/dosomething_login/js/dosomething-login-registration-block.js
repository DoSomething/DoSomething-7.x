(function ($) {
  Drupal.behaviors.dosomethingRegisterAjax = {
    attach: function(context, settings) {
      var registerForm = $('#dosomething-login-register-popup-form');
      var webform = $('.webform-client-form');
      var submitButton = webform.find('.form-submit');

      webform.submit(function () {
        submitButton.attr('disabled', true);
        var progressBar = $('<div class="ajax-progress ajax-progress-throbber"><div class="throbber">&nbsp;</div></div>');
        progressBar.appendTo(webform.find('.form-actions'));
        $.post('/user/registration/ajax', registerForm.serialize(), function (data) {
          if (!data.success) {
            $('input').removeClass('error');
            $.each(data.missing, function (key, value) {
              $('input[name^='+key+']').addClass('error');
            });
            submitButton.removeAttr('disabled');
            progressBar.remove();
          }
          else {
            webform.unbind('submit').submit();
          }
        });
        return false;
      });
    }
  }
}(jQuery));
