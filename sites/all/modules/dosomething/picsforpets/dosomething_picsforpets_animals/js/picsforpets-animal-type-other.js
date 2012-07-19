(function ($) {

/**
 * Hides or shows other field on pet app form.
 */
Drupal.behaviors.picsforpetsOtherVisibility = {
  attach: function (context) {
    var select = '#edit-submitted-enter-animal-info-field-fb-app-animal-type-und';
    var other = '.field-name-field-fb-app-other';

    if ($(select).val() == 'Other') {
      $(other).show();
    }
    else {
      $(other).hide();
    }

    $(select).change(function () {
      if ($(select).val() == 'Other') {
        $(other).show('fast');
      }
      if ($(select).val() !== 'Other') {
        $(other).hide('fast');
        $('#edit-submitted-enter-animal-info-field-fb-app-other-und-0-value').val('');
      }
    });
  }
};

})(jQuery);
