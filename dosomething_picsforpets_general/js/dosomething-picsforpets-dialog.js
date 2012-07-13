(function ($) {

Drupal.behaviors.dosomethingPicsforpetsDialog = {
  attach: function (context, settings) {
    var furtographyForm = $('#dosomething-picsforpets-furtographer-dialog')
      .hide();
    $('.footer-furtography').click(function (event) {
      furtographyForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
      });
      event.preventDefault();
    });
  }
};

}(jQuery));
