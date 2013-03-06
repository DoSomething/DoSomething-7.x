(function ($) {
  Drupal.behaviors.sas = {
    attach: function(context, settings) { 
      // styles the choose file button
      var f = jQuery('.form-file');
      $('<div>').attr('id', 'upload-cover').insertBefore('.form-file');
      f.appendTo('#upload-cover').addClass('new');
      var n = $('<div>').addClass('fakefile').text('Upload Picture').appendTo('#upload-cover');


      $('#edit-submitted-field-share-your-own-image-und-0-upload').click(function() {
        var img = window.setInterval(function() {
          if ($('#edit-submitted-field-share-your-own-image-und-0-upload').val() != '') {
            window.clearInterval(img);
            $('[id^="webform-client-form-"]').submit();
          }
        });
      });
    }
  };
})(jQuery);