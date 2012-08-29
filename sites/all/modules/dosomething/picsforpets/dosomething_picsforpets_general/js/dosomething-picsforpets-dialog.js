(function ($) {

Drupal.behaviors.dosomethingPicsforpetsDialog = {
  attach: function (context, settings) {
    var $furtographyForm = $('#dosomething-picsforpets-general-furtographer-form');
    $furtographyForm.hide();
    $('a.pics-for-pets-modal').click(function() {
      var dialog = $furtographyForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
        // Autofocus confuses placeholder text.
        open: function(event, ui) {
          $("input").blur();
        }
      });
      // Drupal.attachBehaviors();
      $furtographyForm.validate({
        rules: {
          email: {
            required: true,
            email: true
          }
        }
      });
      return false;
    });
  }
};

}(jQuery));
