/**
 * Why become a member dialog popup.
 */

(function ($) {
  Drupal.behaviors.dosomethingLoginRegister = {
    attach: function(context, settings) {
      var popupForm = $("#dosomething-login-register-popup-form");
      var blockForm = $("#dosomething-login-register-block");
      var date = new Date();
      var dateValidAge = 90;
      var dateThreshold = new Date(date.getFullYear() - dateValidAge, 0, 1);
      var phoneField = popupForm.find('#edit-cell');
      var emailField = popupForm.find('#edit-email');

      function validEmail(email) {
        return /^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))$/i.test(email);
      }
      function validPhone(phone) {
        // Check for no spaces or dashes and remove country code.
        // We assume all users are US or Canada.
        phone = phone.replace(/^1/, '').replace(/[^0-9]/g, '');
        return phone.length == 10;
      }

      popupForm.hide();
      // We need a special validator for the email/mobile number field.
      jQuery.validator.addMethod("cell_or_email", function(value, element, params) {
        phone = validPhone(value);
        email = validEmail(value);
        return this.optional(element) || (phone || email);
      }, "Please enter a valid email address or phone number(no spaces).");

      // Conditional validation for parental email address.
      jQuery.validator.addMethod("parent_email", function(value, element, params) {
        var now = new Date();
        var year = $("#edit-year").val();
        var birthDate = new Date($("#edit-year").val(), $("#edit-month").val() - 1, $("#edit-day").val());
        var date13 = new Date(now.getFullYear() - 13, now.getMonth(), now.getDate());
        if (birthDate.getTime() >= date13.getTime() && year) {
          if (!value) {
            return false;
          }
          return validEmail(value);
        }
        return true;
      }, "Please enter a valid email address.");


      $("#edit-final-submit").click(function(event) {
        // The elements are disabled, but still need to actually post.
        popupForm.find('.dosomething-original-value').each(function() {
          $(this).removeAttr("disabled");
        });
        phoneField.removeAttr("disabled");
        emailField.removeAttr("disabled");
      });


      // Validate the form on click and open the dialog.
      $("#edit-first-submit").click(function(event) {
        blockForm.valid();
        popupForm.find('.dosomething-original-value').each(function() {
          var name = $(this).attr('name');
          var value = blockForm.find('input[name="' + name + '"]').val();
          $(this).val(value);
        });
        var cell_or_email = blockForm.find('#edit-cell-or-email').val();
        if (!blockForm.valid()) {
          event.preventDefault();
          return;
        }
        if (validEmail(cell_or_email)) {
          popupForm.find('input[name="email"]').val(cell_or_email);
          emailField.attr("disabled", true);
          // Hide the required field for phone.
          // For some reason the email required star is shown next to
          // the phone field and vice-versa.
          emailField.parent().next('span').hide();
        }
        else if (validPhone(cell_or_email)) {
          popupForm.find('input[name="cell"]').val(cell_or_email);
          phoneField.attr("disabled", true);
          // Hide the required field for emails.
          // For some reason the email required star is shown next to
          // the phone field and vice-versa.
          phoneField.parent().next('span').hide();
        }
        popupForm.find('.dosomething-original-value').each(function() {
          $(this).attr("disabled", true);
        });
        $(".under-13-field").hide();

        // Save registration data in case they don't sign up.
        var postData = {
          first_name: $("#edit-first-name").val(),
          last_name: $("#edit-last-name").val(),
          cell_or_email: cell_or_email,
          ds_api_key: Drupal.settings.dosomethingLogin.dsApiKey
        };
        $.post('dosomething/ajax/registration-data', postData);

        popupForm.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 550,
        });

        // TODO: How to do conditional validation of parental email?
        event.preventDefault();
      });

      // Validate registration popup form on keyup and submit
      popupForm.validate({
        rules: {
          first_name: "required",
          last_name: "required",
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
            range: [date.getFullYear() - dateValidAge, date.getFullYear()]
          },
          pass: {
            required: true,
            minlength: 6
          },
          parent_email: {
            parent_email: true
          }
        },
        messages: {
          day: {
            required: "",
            range: ""
          },
          month: {
            required: "",
            range: ""
          },
          year: {
            required: "",
            range: ""
          }
        }
      });

      // Validate visible block form on keyup and submit
      blockForm.validate({
        rules: {
          first_name: "required",
          last_name: "required",
          cell_or_email: {
            required: true,
            cell_or_email: true
          }
        },
        messages: {
          first_name: {
            required: ""
          },
          last_name: {
            required: ""
          },
          cell_or_email: {
            required: ""
          }
        }
      });
    }
  }
}(jQuery));

