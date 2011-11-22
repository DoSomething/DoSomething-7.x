/**
 * Why become a member dialog popup.
 */

(function ($) {
  Drupal.behaviors.dosomethingBirthdayCheck = {
    attach: function(context, settings) {
      var popupForm = $("#dosomething-login-register-popup-form, #dosomething-login-register-facebook");
      function updateForm() {
        var birthDate = new Date($("#edit-year").val(), $("#edit-month").val() - 1, $("#edit-day").val());
        var date = new Date();
        var dateValidAge = 90;
        var dateThreshold = new Date(date.getFullYear() - dateValidAge, 0, 1);
        var date26 = new Date(date.getFullYear() - 26, date.getMonth(), date.getDate());
        var date13 = new Date(date.getFullYear() - 13, date.getMonth(), date.getDate());
        var year = $("#edit-year").val();

        // Check if user is over 25.
        if (birthDate.getTime() <= date26.getTime() && year) {
          popupForm.find('.form-item, .captcha, .age-question').hide();
          popupForm.find('.over-25-field, .form-submit').show();
          popupForm.find('.ds-signup-always-show .form-item, .over-25-field .form-item').show();
          popupForm.find('.dosomething-original-value').parent().show();
        }
        // Check if user is under 13.
        else if (birthDate.getTime() >= date13.getTime() && year) {
          // Show/hide parent email based on birthday value.
          popupForm.find('.form-item, .captcha, .age-question, .under-13-field').show();
          $("#edit-signup-title, #edit-signup-message").hide();
          $(".over-25-field").hide();
        }
        else {
          popupForm.find('.form-item, .captcha, .age-question').show();
          $(".under-13-field").hide();
          $(".over-25-field").hide();
        }
      }
      popupForm.find("#edit-year, #edit-month, #edit-day").change(updateForm);
      updateForm();
    }
  }
}(jQuery));

