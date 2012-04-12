/**
 * Why become a member dialog popup.
 */

(function ($) {
  Drupal.behaviors.dosomethingBirthdayCheck = {
    attach: function(context, settings) {
      var popupForm = $("#dosomething-login-register-popup-form, #dosomething-login-register-facebook");
      popupForm.find("#edit-year, #edit-month, #edit-day").change(Drupal.dsRegistration.updateForm);
      Drupal.dsRegistration.updateForm();
    }
  }

  Drupal.dsRegistration = Drupal.dsRegistration || {};
  Drupal.dsRegistration.updateForm = function() {
    var now = new Date();
    var birthDate = new Date($("#edit-year").val(), $("#edit-month").val() - 1, $("#edit-day").val());
    var date13 = new Date(now.getFullYear() - 13, now.getMonth(), now.getDate());
    var year = $("#edit-year").val();
    var under13 = $(".under-13-field");

    // Show/hide parent email based on birthday value.
    if (birthDate.getTime() >= date13.getTime() && year) {
      under13.show();
    }
    else {
      under13.hide();
    }
  }
}(jQuery));

