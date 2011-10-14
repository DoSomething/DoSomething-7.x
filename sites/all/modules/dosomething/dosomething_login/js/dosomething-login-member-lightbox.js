/**
 * Why become a member dialog popup.
 */

(function ($) {
  Drupal.behaviors.dosomethingLoginMemberLightbox = {
    attach: function(context, settings) {
      $('#member-dialog').hide();
      $("#block-dosomething-login-become-member .why-member a").click(function(event) {
        event.preventDefault();
        $('#member-dialog').dialog({modal:true, width:617, height:392});
      });
    }
  }
  Drupal.behaviors.dosomethingLoginRegister = {
    attach: function(context, settings) {
      jQuery.validator.addMethod("cell_or_email", function(value, element, params) { 
        var email = /^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))$/i.test(value);
        var phone = /^\d+$/.test(value) && value.length >= 10; 
        return this.optional(element) || (phone || email);
      }, "Please enter a valid email address or phone number(no spaces).");

      // TODO: jquery validation for rest of form.
      var form = $("#dosomething-login-register-block");
      var date = new Date();
      if (!Drupal.settings.dosomethingLogin.showExtraFields) {
        $('#registration-dialog').hide();
      }

      // Validate the form on click and open the dialog.
      $("#edit-first-submit").click(function(event) {
        if (!Drupal.settings.dosomethingLogin.showExtraFields) {
          if (form.valid()) {
            $('#registration-dialog').dialog({modal:true, width:617, height:392});
            var birthDate = new Date($("#edit-year").val(), $("#edit-month").val() - 1, $("#edit-day").val()); 
            // Check if user is over 13.
            if (date.getTime() - birthDate.getTime() > 409968000000) {
              // TODO: Show/hide parent email based on birthday value.
            }
          }
          event.preventDefault();
        }
      });

      // Submit the form on second form submit.
      $("#edit-final-submit").click(function(event) {
        if (!Drupal.settings.dosomethingLogin.showExtraFields) {
          var newForm = $("#registration-dialog");
          form.append(newForm);
          form.submit();
        }
      });

      // Validate registration form on keyup and submit
      $("#dosomething-login-register-block").validate({
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
            range: [1970, date.getFullYear()]
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
    }
  }
}(jQuery));

