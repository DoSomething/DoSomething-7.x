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
      var date26 = new Date(date.getFullYear() - 26, date.getMonth(), date.getDate());
      var date13 = new Date(date.getFullYear() - 13, date.getMonth(), date.getDate());

      popupForm.hide();
      // We need a special validator for the email/mobile number field.
      jQuery.validator.addMethod("cell_or_email", function(value, element, params) { 
      var email = /^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))$/i.test(value);
        // Check for no spaces or dashes.
        var phone = /^\d+$/.test(value) && value.length >= 10;
        if (!phone) {
          // Check for dashes
          phone = /^\(?(\d{3})\)?[- ]?(\d{3})[- ]?(\d{4})$/.test(value) && value.length >= 12;
        }
        return this.optional(element) || (phone || email);
      }, "Please enter a valid email address or phone number(no spaces).");

      $("#edit-final-submit").click(function(event) {
        // The elements are disabled, but still need to actually post.
        popupForm.find('.dosomething-original-value').each(function() {
          $(this).removeAttr("disabled");
        });
      });


      // Validate the form on click and open the dialog.
      $("#edit-first-submit").click(function(event) {
        blockForm.valid();
        popupForm.find('.dosomething-original-value').each(function() {
          var name = $(this).attr('name');
          var value = blockForm.find('input[name="' + name + '"]').val();
          $(this).val(value);
        });
        var birthDate = new Date($("#edit-year").val(), $("#edit-month").val() - 1, $("#edit-day").val());
        if (!blockForm.valid()) {
          event.preventDefault();
          return;
        }

        // Save registration data in case they don't sign up.
        var postData = {
          first_name: $("#edit-first-name").val(),
          last_name: $("#edit-last-name").val(),
          cell_or_email: $("#edit-cell-or-email").val(),
          birthday: (birthDate.getMonth() + 1) + '/' + birthDate.getDate() + '/' + birthDate.getFullYear(),
          ds_api_key: '8hSyfEZIeBrlcgrdM6QbS63F6NjUvgqQ'
        };
        $.post('dosomething/ajax/registration-data', postData);

        popupForm.dialog({modal:true, width:592});

        // Check if user is over 25.
        if (birthDate.getTime() <= date26.getTime()) {
          popupForm.find('.form-item, .captcha, .age-question').hide();
          popupForm.find('.ds-signup-always-show .form-item, .over-25-field, .over-25-field .form-item, .form-submit').show();
        }
        // Check if user is under 13.
        else if (birthDate.getTime() >= date13.getTime()) {
          // Show/hide parent email based on birthday value.
          popupForm.find('.form-item, .captcha, .age-question').show();
          $("#edit-signup-title").hide();
          $(".under-13-field").show();
        }
        else {
          popupForm.find('.form-item, .captcha, .age-question').show();
          $(".under-13-field").hide();
          $("#edit-signup-title").hide();
        }
        // TODO: Auto-validate form at this point
        // without validating new required fields.
        //popupForm.valid();
        event.preventDefault();
      });

      // Validate registration popup form on keyup and submit
      popupForm.validate({
        rules: {
          first_name: "required",
          last_name: "required",
          cell_or_email: {
            required: true,
            cell_or_email: true
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
            range: [date.getFullYear() - dateValidAge, date.getFullYear()]
          },
        },
        messages: {
          day: {
            required: "",
            range: "",
          },
          month: {
            required: "",
            range: "",
          },
          year: {
            required: "",
            range: "",
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
            range: [date.getFullYear() - dateValidAge, date.getFullYear()]
          },
        },
        messages: {
          first_name: {
            required: "",
          },
          last_name: {
            required: "",
          },
          cell_or_email: {
            required: "",
          },
          day: {
            required: "",
            range: "",
          },
          month: {
            required: "",
            range: "",
          },
          year: {
            required: "",
            range: "",
          }
        }
      });
    }
  }
}(jQuery));

