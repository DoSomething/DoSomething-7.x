(function ($) {
  Drupal.behaviors.dosomethingPetitions = {
    attach: function (context, settings) {
      // check if the browser supports placeholder elements
      var placeholder = (function () {
        var i = document.createElement('input');
        return 'placeholder' in i;
      })();

      $reasonWrapper = $('.form-item-submitted-field-webform-petition-reason-und-0-value');
      $reasonBox = $reasonWrapper.find('.form-textarea-wrapper');
      $reasonLabel = $reasonWrapper.find('label');
      $signatureCheckbox = $('#edit-submitted-field-webform-petition-signature--2');
      $signShortcut = $('#sign-petition-scroller');

      $signatureCheckbox.appendTo($('.pane-node-webform .webform-client-form>div'));

      // add the "Add a reason" link
      $displayReasonLink = $('<a>')
        .attr('id', 'add-reason-link')
        .text('Add one')
        .click(function () {
          $reasonBox.slideToggle();
        });
      
      $reasonBox.hide();
      $reasonLabel.append($displayReasonLink);

      // make the secondary sign button do something
      $signShortcut.click(function () {
        $form = $('.pane-node-webform');
        $('html, body').animate({scrollTop: $form.offset().top}, 300);
        $form
          .css('-webkit-box-shadow', '#18408B 0 0 12px')
          .css('-moz-box-shadow', '#18408B 0 0 12px')
          .css('box-shadow', '#18408B 0 0 12px');
        return false;
      });

      // convert labels to placeholders
      if (placeholder) {
        var $form = $('.webform-client-form, #dosomething-petitions-email-form');
        $form.find('label').each(function (idx, e) {
          e = $(e);
          $field = $('#'+e.attr('for'));
          if ($field.attr('type') == 'text') {
            e.hide();
            $field.attr('placeholder', e.text());
          }
        });
      }
    }
  };

  // Define our own jQuery plugin so we can call it from Drupal's AJAX callback
  $.fn.extend({
    dsPetitionSubmit: function (url) {
      // Whelp, these were breaking things, so let's just destroy them.
      // This is probably bad practice.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingPetitions;
      
      var popupForm = $('#dosomething-login-register-popup-form');

      fName = $('#edit-submitted-field-webform-first-name-und-0-value--2').val();
      lName = $('#edit-submitted-field-webform-last-name-und-0-value--2').val();
      e_or_m = $('#edit-submitted-field-webform-email-or-cell-und-0-value--2').val();

      var is_email = Drupal.dsRegistration.validEmail(e_or_m);
      var is_mobile = Drupal.dsRegistration.validPhone(e_or_m);

      // set the values on the popup form based on user input
      if (is_email) {
        popupForm.find('input[name="email"]').val(e_or_m);
      }
      if (is_mobile) {
        popupForm.find('input[name="cell"]').val('e_or_m');
      }
      popupForm.find('input[name="first_name"]').val(fName);
      popupForm.find('input[name="last_name"]').val(lName);

      // change the text of the popup
      popupForm.find('#edit-title-text label')
        .text("You've Signed.")
        .after('<h2>Now get the benefits of being a full member.</h2>');

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination='+url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination='+url);
      $('#dosomething-login-login-popup-form').attr('action', '/user?destination='+url);

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


