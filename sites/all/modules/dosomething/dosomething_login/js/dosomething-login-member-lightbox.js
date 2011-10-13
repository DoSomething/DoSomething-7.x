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
      $('#registration-dialog').hide();

      // Validate the form on click and open the dialog.
      $("#edit-first-submit").click(function(event) {
        if (form.valid()) {
          var birthDate = new Date($("#edit-year").val(), $("#edit-month").val() - 1, $("#edit-day").val()); 
          if (date.getTime() - birthDate.getTime() > 409968000000) {
            // TODO: Hide parent email?
          }
          else {
            // TODO: New form validation
            /*$("#edit-parent-email").rules("add", {
              parent_email: {
                required: true,
                email: true
              },
            });*/
          }
          $('#registration-dialog').dialog({modal:true, width:617, height:392});
          // TODO: Show/hide parent email based on birthday value.
        }
        event.preventDefault();
      });

      $("#edit-final-submit").click(function(event) {
        if (form.valid()) {
          // TODO: Set parent email and other values.
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
        }
      });
    }
  }
}(jQuery));

