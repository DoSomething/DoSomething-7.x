(function ($) {
  Drupal.behaviors.contactPicker = {
    attach: function (context, settings) {
      $('.contact-picker').click(function() {
        var popup = $('<div></div>').attr('id', 'contact-picker-dialog').css({
          'height': '250px',
          'overflow': 'hidden',
        });
        popup.append($('<div id="loading-scraper" class="remove-that-loader"><img src="/sites/all/modules/dosomething/dosomething_contact_picker/images/loading.gif" alt="" /></div>'));
        popup.append($('<iframe></iframe>').attr('id', 'email-scraper').css('width', '500px').css('min-height', '700px').height('700px').css('border', '0px').css('background', '#fff').attr('src', '/contact-picker/' + $(this).attr('data-nid')));
        // popup!
        popup.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 550,
          height: 250,
          dialogClass: 'contact-picker-dialog',
          open: function() {
          },
          close: function() {
          }
        });

      	return false;
      });
    }
  };
})(jQuery);