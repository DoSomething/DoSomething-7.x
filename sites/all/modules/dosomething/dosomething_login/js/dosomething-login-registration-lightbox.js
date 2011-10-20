/**
 * Why become a member dialog popup.
 */

(function ($) {
  Drupal.behaviors.dosomethingBirthdayCheck = {
    attach: function(context, settings) {
      var forms = new Array("#dosomething-login-register-popup-form", "#dosomething_login_register_facebook");
      for (var form in forms) {
        var popupForm = $("form");
        function updateForm() {
          var birthDate = new Date($("#edit-year").val(), $("#edit-month").val() - 1, $("#edit-day").val());
          var date = new Date();
          // Check if user is over 25.
          if (date.getTime() - birthDate.getTime() > 819936000000 && birthDate.getTime() > 0) {
            popupForm.find('.form-item, .captcha, .age-question').hide();
            popupForm.find('.over-25-field .form-item, .form-submit').show();
            popupForm.find('.dosomething-original-value').parent().show();
          }
          // Check if user is under 13.
          else if (date.getTime() - birthDate.getTime() < 409968000000 && birthDate.getTime() > 0) {
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
        }
        popupForm.find("#edit-year, #edit-month, #edit-day").change(updateForm);
        updateForm();
      }
    }
  }
}(jQuery));

