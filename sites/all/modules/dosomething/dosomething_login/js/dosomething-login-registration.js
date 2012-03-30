/**
 * Why become a member dialog popup.
 */

(function ($) {
  Drupal.behaviors.dosomethingBirthdayCheck = {
    attach: function(context, settings) {
      var popupForm = $("#dosomething-login-register-popup-form, #dosomething-login-register-facebook");
      function updateForm() {
        var now = new Date();
        var birthDate = new Date($("#edit-year").val(), $("#edit-month").val() - 1, $("#edit-day").val());
        var date13 = new Date(now.getFullYear() - 13, now.getMonth(), now.getDate());
        var year = $("#edit-year").val();

        // Show/hide parent email based on birthday value.
        if (birthDate.getTime() >= date13.getTime() && year) {
          $(".under-13-field").show();
        }
        else {
          $(".under-13-field").hide();
        }
      }
      popupForm.find("#edit-year, #edit-month, #edit-day").change(updateForm);
      updateForm();
    }
  }
}(jQuery));

