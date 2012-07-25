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
        width: 550
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
      event.preventDefault();
    });
  }
};

}(jQuery));
