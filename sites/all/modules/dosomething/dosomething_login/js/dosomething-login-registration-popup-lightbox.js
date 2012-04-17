/**
 * Why become a member dialog popup.
 */

(function ($) {

Drupal.behaviors.dosomethingLoginRegister = {
  attach: function (context, settings) {
    var popupForm = $('#dosomething-login-register-popup-form');
    var blockForm = $('#dosomething-login-register-block');
    var phoneField = popupForm.find('#edit-cell');
    var emailField = popupForm.find('#edit-email');

    popupForm
      .find('.already-member a')
        .click(function () {
          popupForm.dialog('close');
        });

    popupForm.hide();

    // We need a special validator for the email/mobile number field.
    jQuery.validator.addMethod('cell_or_email', function (value, element, params) {
      phone = Drupal.dsRegistration.validPhone(value);
      email = Drupal.dsRegistration.validEmail(value);
      return this.optional(element) || (phone || email);
    }, 'Please enter a valid email address or phone number.');

    // Run when the popup form submit is run.
    $('#edit-final-submit').click(function (event) {
      // The elements are disabled, but still need to actually post.
      popupForm.find('.dosomething-original-value').each(function () {
        $(this).removeAttr('disabled');
      });
      phoneField.removeAttr('disabled');
      emailField.removeAttr('disabled');
    });

    // Validate the form on click and open the dialog.
    $('#edit-first-submit').click(function (event) {
      blockForm.valid();
      popupForm.find('.dosomething-original-value').each(function () {
        var name = $(this).attr('name');
        var value = blockForm.find('input[name="' + name + '"]').val();
        $(this).val(value);
      });
      var cell_or_email = blockForm.find('#edit-cell-or-email').val();
      if (!blockForm.valid()) {
        event.preventDefault();
        return;
      }
      // Disable input access and set values depending on if
      // this is a valid email or cell phone number.
      if (Drupal.dsRegistration.validEmail(cell_or_email)) {
        popupForm.find('input[name="email"]').val(cell_or_email);
        emailField.attr('disabled', true);
        phoneField.removeAttr('disabled');
        phoneField.val('');
        // Hide the required field for phone.
        phoneField.next('span').hide();
      }
      else if (Drupal.dsRegistration.validPhone(cell_or_email)) {
        popupForm.find('input[name="cell"]').val(cell_or_email);
        phoneField.attr('disabled', true);
        emailField.removeAttr('disabled');
        emailField.val('');
        // Hide the required field for emails.
        emailField.next('span').hide();
      }
      popupForm.find('.dosomething-original-value').each(function () {
        $(this).attr('disabled', true);
      });
      $('.under-13-field').hide();

      // Save registration data in case they don't sign up.
      var postData = {
        first_name: $('#edit-first-name').val(),
        last_name: $('#edit-last-name').val(),
        cell_or_email: cell_or_email,
        ds_api_key: Drupal.settings.dosomethingLogin.dsApiKey
      };
      $.post('dosomething/ajax/registration-data', postData);

      // Open the dialog.
      popupForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
      });

      // Update form to show/hide conditional fields.
      Drupal.dsRegistration.updateForm();

      event.preventDefault();
    });

    // Validate visible block form on keyup and submit
    blockForm.validate({
      errorPlacement: function(label, element) {
        // Don't show any messages.
      },
      rules: {
        first_name: 'required',
        last_name: 'required',
        cell_or_email: {
          required: true,
          cell_or_email: true
        }
      },
      messages: {
        first_name: {
          required: ''
        },
        last_name: {
          required: ''
        },
        cell_or_email: {
          required: ''
        }
      }
    });
  }
};

}(jQuery));
