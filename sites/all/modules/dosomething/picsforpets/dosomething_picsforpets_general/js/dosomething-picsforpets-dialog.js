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
        top: 180,
        position: { my: 'top', at: 'top', of: 'body', offset: '0 180' },
        width: 600,
        // Autofocus confuses placeholder text.
        open: function(event, ui) {
          if (typeof FB != 'undefined') { 
            FB.Canvas.scrollTo(0,0);
          }
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
