(function ($) {

Drupal.behaviors.dosomethingRegisterAjax = {
  attach: function(context, settings) {
    var registerForm = $('#dosomething-login-register-popup-form');
    var webform = $('.webform-client-form');
    var submitButton = webform.find('.form-submit');
    var wfEmailField = $('#edit-submitted-field-webform-email');
    var wfCellField = $('#edit-submitted-field-webform-mobile');
    wfEmailField.hide();
    wfCellField.hide();

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
          if (wfEmailField.length > 0) {
            wfEmailField.find('input').val($('#edit-email').val());
          }
          if (wfCellField.length > 0) {
            wfCellField.find('input').val($('#edit-cell').val());
          }

          webform.unbind('submit');
          var actionButton = webform.find('input[name="op"]');
          actionButton.removeAttr('disabled').click().attr('disabled', true);
        }
      });
      return false;
    });
  }
};

}(jQuery));
