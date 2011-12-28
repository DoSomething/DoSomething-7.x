(function ($) {
  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {
      $('#edit-profile-main-field-user-address-und-0-administrative-area', context).bind('change', function () {
        var stateVal = $(this).val();//context.value;
        $('#edit-profile-main-field-school-reference-und-0-target-id-state').val(stateVal);
      });
      $('#edit-profile-main-field-school-reference-und-0-target-id-state', context).change(function () {
        $('#edit-profile-main-field-user-address-und-0-administrative-area').unbind();
      });
    }
  };
}(jQuery));
