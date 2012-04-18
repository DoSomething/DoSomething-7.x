/**
 * Why become a member dialog popup.
 */

(function ($) {

Drupal.behaviors.dosomethingBirthdayCheck = {
  attach: function(context, settings) {
    var now = new Date();
    var dateValidAge = 90;
    var dateThreshold = new Date(now.getFullYear() - dateValidAge, 0, 1);
    var popupForm = $('#dosomething-login-register-popup-form, #dosomething-login-register-facebook');
    var email = popupForm.find('#edit-email');
    var cell = popupForm.find('#edit-cell');
    popupForm
      .find('#edit-year, #edit-month, #edit-day').change(Drupal.dsRegistration.updateForm);
    Drupal.dsRegistration.updateForm(); 

    // Conditional validation for parental email address.
    jQuery.validator.addMethod('parent_email', function (value, element, params) {
      var year = popupForm.find('#edit-year').val();
      var birthDate = new Date(year, popupForm.find('#edit-month').val() - 1, popupForm.find('#edit-day').val());
      var date13 = new Date(now.getFullYear() - 13, now.getMonth(), now.getDate());
      if (birthDate.getTime() >= date13.getTime() && year) {
        if (!value) {
          return false;
        }
        return Drupal.dsRegistration.validEmail(value);
      }
      return true;
    }, 'Please enter a valid email address.');

    // Conditional validation for ensuring uniqueness of parental email.
    jQuery.validator.addMethod('unique_parent_email', function (value, element, params) {
      return !(email.val() && email.val() == value);
    }, "Your parent/guardian email cannot be the same as your own. If you use your parent's email address as your own then please email help@dosomething.org.");

    // Conditional validation for ensuring uniqueness of parental email.
    jQuery.validator.addMethod('conditional_on_empty_field', function (value, element, param) {
      return (value || param.val());
    }, "This is a required field.");

    // We need a special validator for the mobile number field.
    jQuery.validator.addMethod('phone', function (value, element, params) {
      return this.optional(element) || Drupal.dsRegistration.validPhone(value);
    }, 'Please enter a valid phone number.');


    // Validate registration popup form on keyup and submit
    popupForm.validate({
      errorPlacement: function(label, element) {
        // Don't show empty messages.
        if (label.text() != "") {
          label.insertAfter(element);
        }
      },
      rules: {
        first_name: 'required',
        last_name: 'required',
        email: {
          email: true,
          conditional_on_empty_field: popupForm.find('#edit-cell')
        },
        cell: {
          phone: true,
          conditional_on_empty_field: popupForm.find('#edit-email')
        },
        day: {
          required: true,
          range: [01, 31]
        },
        month: {
          required: true,
          range: [01, 12]
        },
        year: {
          required: true,
          range: [now.getFullYear() - dateValidAge, now.getFullYear()]
        },
        pass: {
          required: true,
          minlength: 6
        },
        parent_email: {
          parent_email: true,
          unique_parent_email: true
        }
      },
      messages: {
        first_name: {
          required: ''
        },
        last_name: {
          required: ''
        },
        email: {
          conditional_on_empty_field: Drupal.t('You must enter either an email address or cell phone number.')
        },
        cell: {
          conditional_on_empty_field: ''
        },
        pass: {
          required: '',
        },
        day: {
          required: '',
          range: ''
        },
        month: {
          required: '',
          range: ''
        },
        year: {
          required: '',
          range: ''
        }
      }
    });

  }
};

Drupal.dsRegistration = Drupal.dsRegistration || {};

// Function for showing hiding fields based on birthday of registration form.
Drupal.dsRegistration.updateForm = function() {
  var now = new Date();
  var year = $('#edit-year').val();
  var birthDate = new Date(year, $('#edit-month').val() - 1, $('#edit-day').val());
  var date13 = new Date(now.getFullYear() - 13, now.getMonth(), now.getDate());
  var under13 = $('.under-13-field');

  // Show/hide parent email based on birthday value.
  if (birthDate.getTime() >= date13.getTime() && year) {
    under13.show();
  }
  else {
    under13.hide();
  }
};

// Function for validating an email available for all.
Drupal.dsRegistration.validEmail = function(email) {
  return /^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))$/i.test(email);
};

// Function for validating a phone number available for all.
Drupal.dsRegistration.validPhone = function(phone) {
  // Check for no spaces or dashes and remove country code.
  // We assume all users are US or Canada.
  phone = phone.replace(/^1/, '').replace(/[^0-9]/g, '');
  return phone.length == 10;
};

}(jQuery));
