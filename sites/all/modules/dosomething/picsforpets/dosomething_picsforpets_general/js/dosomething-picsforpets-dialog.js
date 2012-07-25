(function ($) {

Drupal.behaviors.dosomethingPicsforpetsDialog = {
  attach: function (context, settings) {
    var $furtographyForm = $('#picsforpets-modal-data');
    $('a.pics-for-pets-modal').click(function() {
      var linkPath = $(this).attr('href');
      $furtographyForm.load(linkPath + ' #main-wrapper form', function() {
        $furtographyForm.attr('title', $furtographyForm.find('form').attr('title'));
        $furtographyForm.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 550,
        });
      });
      return false;
    });
  }
};

}(jQuery));
